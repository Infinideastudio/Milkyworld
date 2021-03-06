﻿/*
* Milkyworld: A free game similar to “The Blockheads”.
* Copyright (C) 2016 Infinideas
*
* This file is part of Milkyworld.
* Milkyworld is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Milkyworld is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with Milkyworld.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "HelloWorldScene.h"
//#include "stdafx.h"//vs专用头文件，用其他编译器编译可注释掉
#include "..\Algorithm\AllAlgorithms.h"
#include "..\Structure\AllStructures.h"
#include "..\GameUI\AllGameUI.h"
#include "..\Mob\AllMobs.h"
#include<iostream>
using namespace std;
USING_NS_CC;
/************************************************
流程解释:游戏加载的过程
进入scene之后，首先进入默认的init函数
在默认的init函数中绘制loading字样，然后开启两个计时器
game_load:加载游戏，0.02s执行一次
game_load_bar:不断更新加载进度，0.02s执行一次
在加载过程中，第一次执行game_load时先绘制一部分必要的
sprite，然后开启分支线程game_planet_load来加载planet
的数据。线程开启后立即退出game_load。
之后每次执行game_load，若加载进度未达到100，则不执行
之后的代码。当某次执行game_load时加载进度达到100，
则停止game_load_bar，并且继续执行game_load中后续的UI
绘制等杂项，然后自行停止game_load计时器，世界加载完毕。
************************************************/
/************************************************
函数名:创建scene
功能:创建主场景
备注:
************************************************/
Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
/************************************************
函数名:主场景初始化函数
功能:初始化主场景
备注:
************************************************/
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	back_ground = Sprite::create("White.png");
	back_ground->setColor(Color3B(215, 240, 247));
	back_ground->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(back_ground, 5);
	game_load_label = Label::createWithTTF("Loading...0%", "fonts/Marker Felt.ttf", 48);
	game_load_label->setColor(Color3B(195, 195, 195));
	game_load_label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height/2));
	this->addChild(game_load_label, 6);
	loading_flag = false;
	schedule(schedule_selector(HelloWorld::game_load), 0.02f);//加载游戏
	schedule(schedule_selector(HelloWorld::game_load_bar), 0.02f);//更新加载进度条
    return true;
}
/************************************************
函数名:行星事件处理
功能:用于处理游戏过程中的事件
备注:20ms执行一次
************************************************/
void HelloWorld::game_processor(float dt)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	//四个方向分别判断是否按下按键，计算人物速度
	if (keygroup_A_pressed[2])
		player.velocity.x = -6*picture_length;
	else if (keygroup_A_pressed[3])
		player.velocity.x = 6*picture_length;
	else
		player.velocity.x = 0;
	//跳跃
	if (keygroup_C_pressed[0] && player.touch_ground)
	{
		player.velocity.y = 7 * picture_length;
	}
	//关于重力的代码
	if (player.enabled_gravity)
	{
		player.velocity.y += world.planet.gravitational_acceleration*dt;
	}
	//碰撞检测
	int world_width = world.planet.get_chunk_size().x*length_of_block_size*picture_length;
	player.touch_ground = false;
	bool x_flag=false, y_flag=false;
	//检测玩家周围每个方块
	Vec2i current;
	for (current.x = player.hit_test_start().x; current.x <= player.hit_test_end().x; current.x++)
	{
		for (current.y = player.hit_test_start().y; current.y <= player.hit_test_end().y; current.y++)
		{
			//新位置
			Vec2 new_location;
			MyRectangle new_hit_box;
			bool block_enabled_touch = world.planet.front_block(current).enabled_touch;
			if (!y_flag)
			{
				new_location = player.location;
				new_location.y += player.velocity.y * dt;
				new_hit_box = MyRectangle(Vec2(new_location.x - player.size.x / 2 , new_location.y + player.size.y / 2 )
					, Vec2(new_location.x + player.size.x / 2 , new_location.y - player.size.y / 2 ));
				//竖直移动时碰撞
				if (new_hit_box.is_touch(world.planet.hit_box(current)) && block_enabled_touch)
				{
					//防止浮点数误差
					if (new_hit_box.overlap_size(world.planet.hit_box(current)).x > 1)
					{
						player.velocity.y += (player.velocity.y != 0)*((player.velocity.y < 0) * 2 - 1)*new_hit_box.overlap_size(world.planet.hit_box(current)).y / dt;
						player.touch_ground = player.velocity.y < 0;
						y_flag = true;
					}
				}
				
			}
			if (!x_flag)
			{
				new_location = player.location;
				new_location.x += player.velocity.x * dt;
				new_hit_box = MyRectangle(Vec2(new_location.x - player.size.x / 2, new_location.y + player.size.y / 2)
					, Vec2(new_location.x + player.size.x / 2, new_location.y - player.size.y / 2));
				//水平移动时碰撞
				if (new_hit_box.is_touch(world.planet.hit_box(current)) && block_enabled_touch)
				{
					//防止浮点数误差
					if (new_hit_box.overlap_size(world.planet.hit_box(current)).y > 1)
					{
						player.velocity.x += (player.velocity.x != 0)*((player.velocity.x < 0) * 2 - 1)*new_hit_box.overlap_size(world.planet.hit_box(current)).x / dt;
						x_flag = true;
					}
				}
			}
			if (x_flag&&y_flag)break;
		}
		if (x_flag&&y_flag)break;
	}
	player.set_location(player.location+player.velocity*dt);
	camera.location = player.location - visibleSize / 2;
	label->setString(int_2_string(player.velocity.x) + "," + int_2_string(player.velocity.y));//debug
	//以下是关于地图左右循环的代码
	int reset_camera = -1 * UI_block.size()*picture_length - 3* picture_length;
	bool over_map_flag = false;
	//over_map_flag=true表示camera已经到了正确的位置，所有方块都不再借用地图另一端的。
	if (camera.location.x < reset_camera)
	{
		camera.location.x += world_width;
		player.location.x += world_width;
		over_map_flag = true;
	}
	else
	if (camera.location.x >= world_width + 7 * picture_length)
	{
		camera.location.x -= world_width;
		player.location.x -= world_width;
		over_map_flag = true;
	}
	if (over_map_flag)
	{
		for (int i = 0; i < UI_block.size(); i++)
		{
			for (int j = 0; j < UI_block[i].size(); j++)
			{
				UI_block[i][j].is_borrow = 0;
			}
		}
	}
}
/************************************************
函数名:UI打印线程
功能:用于刷新UI显示
备注:20ms运行一次,FPS=50
************************************************/
void HelloWorld::UI_printer(float dt)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//更新方块位置
	for (int i = 0; i < UI_block.size(); i++)
	{
		for (int j = 0; j < UI_block[i].size(); j++)
		{
			Vec2 __position = UI_block[i][j].get_position();
			//是否转移的标记
			bool move_flag = false;
			//UI方块越界转移代码
			//world_chunk_width表示地图的宽度(chunks在横向的数量)
			int world_chunk_width = world.planet.get_chunk_size().x;
			//UI方块从左侧越界
			if (__position.x < -3 * picture_length)
			{
				move_flag = true;
				UI_block[i][j].block_index.x += UI_block.size();//向右转移size个格子
				while (UI_block[i][j].block_index.x >length_of_block_size-1)
				{
					UI_block[i][j].block_index.x -= length_of_block_size;
					UI_block[i][j].chunk_location.x++;
				}
				//地图左右越界循环的判定
				if (UI_block[i][j].is_borrow == -1)
				{
					UI_block[i][j].is_borrow = 0;
					UI_block[i][j].chunk_location.x -= world_chunk_width;
				}
				if (UI_block[i][j].chunk_location.x >= world_chunk_width)
				{
					UI_block[i][j].chunk_location.x -= world_chunk_width;
					UI_block[i][j].is_borrow = 1;
				}
			}
			else //UI方块从右侧越界
			if (__position.x > 3 * picture_length + visibleSize.width)
			{
				move_flag = true;
				UI_block[i][j].block_index.x -= UI_block.size();//向左转移size个格子
				while (UI_block[i][j].block_index.x <0)
				{
					UI_block[i][j].block_index.x += length_of_block_size;
					UI_block[i][j].chunk_location.x--;
				}
				//地图左右越界循环的判定
				if (UI_block[i][j].is_borrow == 1)
				{
					UI_block[i][j].is_borrow = 0;
					UI_block[i][j].chunk_location.x += world_chunk_width;
				}
				if (UI_block[i][j].chunk_location.x < 0)
				{
					UI_block[i][j].chunk_location.x += world_chunk_width;
					UI_block[i][j].is_borrow = -1;
				}
			}
			//UI方块从下方越界
			if (__position.y < -3 * picture_length)
			{
				move_flag = true;
				//向上转移size个格子
				UI_block[i][j].block_index.y += UI_block[i].size();
				while (UI_block[i][j].block_index.y >length_of_block_size - 1)
				{
					UI_block[i][j].block_index.y -= length_of_block_size;
					UI_block[i][j].chunk_location.y++;
				}
			}
			else//UI方块从上方越界
			if (__position.y > 3 * picture_length + visibleSize.height)
			{
				move_flag = true;
				//向下转移size个格子
				UI_block[i][j].block_index.y -= UI_block[i].size();
				while (UI_block[i][j].block_index.y <0)
				{
					UI_block[i][j].block_index.y += length_of_block_size;
					UI_block[i][j].chunk_location.y--;
				}
			}
			if (move_flag)
			{
				UI_block[i][j].set_front_block(world.planet.get_chunk(UI_block[i][j].chunk_location).get_front_block(UI_block[i][j].block_index));
				UI_block[i][j].set_mid_block(world.planet.get_chunk(UI_block[i][j].chunk_location).
					mid_block[UI_block[i][j].block_index.x * length_of_block_size + UI_block[i][j].block_index.y]);
				UI_block[i][j].set_back_block(world.planet.get_chunk(UI_block[i][j].chunk_location).
					back_block[UI_block[i][j].block_index.x * length_of_block_size + UI_block[i][j].block_index.y]);
			}
			//计算UI_block在屏幕上的偏移坐标
			__position.x = UI_block[i][j].chunk_location.x*length_of_block_size*picture_length
				+ UI_block[i][j].block_index.x * picture_length - camera.location.x;
			__position.y = UI_block[i][j].chunk_location.y*length_of_block_size*picture_length
				+ UI_block[i][j].block_index.y * picture_length - camera.location.y;
			int world_width = world.planet.get_chunk_size().x*length_of_block_size*picture_length;
			__position.x += UI_block[i][j].is_borrow*world_width;
			UI_block[i][j].set_position(__position);
		}
	}
}
/************************************************
函数名:UI处理器初始化函数
功能:用于初始化各项与UI处理有关的事件
备注:结构完善后将从存档读取初始值
************************************************/
void HelloWorld::UI_processor_init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//设置摄像机坐标于原点
	camera.location = player.location - Vec2(visibleSize.width / 2, visibleSize.height / 2);
	//初始化UI显示方块
	UI_block.resize(36);//屏幕内32个，左右各两个
	for (int i = 0; i < UI_block.size(); i++)
	{
		UI_block[i].resize(28);//屏幕内24个，上下各两个
	}
	//枚举每个UI方块，并初始化
	for (int i = 0; i < UI_block.size(); i++)
	{
		for (int j = 0; j < UI_block[i].size(); j++)
		{
			UI_block[i][j].create_sprite();
			//初始时设定方块非借用
			UI_block[i][j].is_borrow = 0;
			//location是绝对像素坐标，position是屏幕像素坐标 i-2是由于屏幕外有两个方块
			Vec2 UI_block_position = Vec2((i - 2)*picture_length, (j - 2)*picture_length);
			Vec2l UI_block_location;
			//chunk_location是所属chunk在planet上的绝对坐标，block_location是所属block在chunk中的偏移坐标
			Vec2i UI_block_chunk_location;
			Vec2i UI_block_block_location;
			//依次计算出各个location，来判断显示的是哪个方块。
			UI_block_location.x = camera.location.x + (i - 2)*picture_length;
			UI_block_location.y = camera.location.y + (j - 2)*picture_length;
			//处理地图左右循环
			//world_width代表地图的宽度(像素数)
			int world_width = world.planet.get_chunk_size().x*length_of_block_size*picture_length;
			if (UI_block_location.x < 0)
			{
				//从左侧越界，因此借用地图最右边的方块来显示
				UI_block[i][j].is_borrow = -1;
				UI_block_location.x += world_width;
			}
			else
			if (UI_block_location.x >= world_width)
			{
				//从右侧越界，因此借用地图最左边的方块来显示
				
				UI_block[i][j].is_borrow = 1;
				UI_block_location.x -= world_width;
			}
			//计算UI方块所对应的chunk的位置
			UI_block_chunk_location.x = UI_block_location.x / (length_of_block_size*picture_length);
			UI_block_chunk_location.y = UI_block_location.y / (length_of_block_size*picture_length);
			if (UI_block_location.x < 0)UI_block_chunk_location.x--;
			if (UI_block_location.y < 0)UI_block_chunk_location.y--;
			//计算偏移像素坐标，由于上一步向下取整，于是作差得出偏移坐标
			UI_block_block_location.x = UI_block_location.x - 
				UI_block_chunk_location.x*(length_of_block_size*picture_length);
			UI_block_block_location.y = UI_block_location.y - 
				UI_block_chunk_location.y*(length_of_block_size*picture_length);
			//根据偏移像素坐标计算偏移坐标
			UI_block_block_location.x /= picture_length;
			UI_block_block_location.y /= picture_length;
			//找到并设置方块
			UI_block[i][j].chunk_location = UI_block_chunk_location;
			UI_block[i][j].block_index = UI_block_block_location;
			UI_block[i][j].set_front_block(world.planet.get_chunk(UI_block[i][j].chunk_location).get_front_block(UI_block[i][j].block_index));
			UI_block[i][j].set_mid_block(world.planet.get_chunk(UI_block_chunk_location).
				mid_block[UI_block_block_location.x * length_of_block_size + UI_block_block_location.y]);
			UI_block[i][j].set_back_block(world.planet.get_chunk(UI_block_chunk_location).
				back_block[UI_block_block_location.x * length_of_block_size + UI_block_block_location.y]);
			UI_block[i][j].mid_sprite->setVisible(false);
			UI_block[i][j].back_sprite->setVisible(false);
			UI_block[i][j].set_position(UI_block_position);
			this->addChild(UI_block[i][j].front_sprite, 3);
			this->addChild(UI_block[i][j].mid_sprite, 2);
			this->addChild(UI_block[i][j].back_sprite, 1);
		}
	}
	//加载玩家
	player.sprite = Sprite::create("texture/mob/player.png");
	player.sprite->setPosition(visibleSize / 2);
	this->addChild(player.sprite,5);
}
/************************************************
函数名:键盘释放事件
功能:键盘释放时触发，执行一系列动作
备注:无
************************************************/
void HelloWorld::on_key_released(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)  //方向上键
		keygroup_B_pressed[0] = false;
	if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)  //方向下键
		keygroup_B_pressed[1] = false;
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)  //方向左键
		keygroup_B_pressed[2] = false;
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)  //方向右键
		keygroup_B_pressed[3] = false;
	if (keyCode == EventKeyboard::KeyCode::KEY_W)  //w键
		keygroup_A_pressed[0] = false;
	if (keyCode == EventKeyboard::KeyCode::KEY_S)  //s键
		keygroup_A_pressed[1] = false;
	if (keyCode == EventKeyboard::KeyCode::KEY_A)  //a键
		keygroup_A_pressed[2] = false;
	if (keyCode == EventKeyboard::KeyCode::KEY_D)  //d键
		keygroup_A_pressed[3] = false;
	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)  //space
		keygroup_C_pressed[0] = false;
}
/************************************************
函数名:键盘按下事件
功能:键盘按下时触发，执行一系列动作
备注:无
************************************************/
void HelloWorld::on_key_pressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)  //方向上键
		keygroup_B_pressed[0] = true;
	if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)  //方向下键
		keygroup_B_pressed[1] = true;
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)  //方向左键
		keygroup_B_pressed[2] = true;
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)  //方向右键
		keygroup_B_pressed[3] = true;
	if (keyCode == EventKeyboard::KeyCode::KEY_W)  //w键
		keygroup_A_pressed[0] = true;
	if (keyCode == EventKeyboard::KeyCode::KEY_S)  //s键
		keygroup_A_pressed[1] = true;
	if (keyCode == EventKeyboard::KeyCode::KEY_A)  //a键
		keygroup_A_pressed[2] = true;
	if (keyCode == EventKeyboard::KeyCode::KEY_D)  //d键
		keygroup_A_pressed[3] = true;
	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)  //space
		keygroup_C_pressed[0] = true;
}
/************************************************
函数名:触摸开始事件
功能:触摸开始时触发，执行一系列动作
备注:无
************************************************/
bool HelloWorld::on_touch_began(Touch * touch, Event * event)
{
	Vec2 mouse_position = touch->getLocation();
	CCLOG("%d,%d",mouse_position.x,mouse_position.y);
	for (int i = 0; i < UI_block.size(); i++)
	{
		for (int j = 0; j < UI_block[i].size(); j++)
		{
			if
			(   mouse_position.x <= UI_block[i][j].get_position().x + picture_length / 2
				&& mouse_position.x > UI_block[i][j].get_position().x - picture_length / 2
				&& mouse_position.y <= UI_block[i][j].get_position().y + picture_length / 2
				&& mouse_position.y > UI_block[i][j].get_position().y - picture_length / 2
			)
			{
				if (world.planet.get_chunk(UI_block[i][j].chunk_location).get_front_block(UI_block[i][j].block_index).type == FrontBlockType::dirt)
				{
					world.planet.get_chunk(UI_block[i][j].chunk_location).get_front_block(UI_block[i][j].block_index).type = FrontBlockType::air;
					world.planet.get_chunk(UI_block[i][j].chunk_location).get_front_block(UI_block[i][j].block_index).enabled_touch = false;
				}
				else 
				if (world.planet.get_chunk(UI_block[i][j].chunk_location).get_front_block(UI_block[i][j].block_index).type == FrontBlockType::air)
				{
					MyRectangle new_hit_box;
					new_hit_box = MyRectangle(Vec2(player.location.x - player.size.x / 2 - camera.location.x, player.location.y + player.size.y / 2 - camera.location.y)
						, Vec2(player.location.x + player.size.x / 2 - camera.location.x, player.location.y - player.size.y / 2 - camera.location.y));
					if (UI_block[i][j].touch_box.is_touch(new_hit_box))return true;
					world.planet.get_chunk(UI_block[i][j].chunk_location).get_front_block(UI_block[i][j].block_index).type = FrontBlockType::dirt;
					world.planet.get_chunk(UI_block[i][j].chunk_location).get_front_block(UI_block[i][j].block_index).enabled_touch = true;
				}
				UI_block[i][j].set_front_block(world.planet.get_chunk(UI_block[i][j].chunk_location).get_front_block(UI_block[i][j].block_index));
				return true;
			}
		}
	}
	return true;
}
/************************************************
函数名:触摸结束事件
功能:触摸结束时触发，执行一系列动作
备注:无
************************************************/
void HelloWorld::on_touch_ended(Touch * touch, Event * event)
{
}
/************************************************
函数名:游戏加载
功能:用于初始化各项内容，包括加载世界，初始化显示等
备注:
************************************************/
void HelloWorld::game_load(float dt)
{
	//如果加载过一遍了就不能再加载
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	if (!loading_flag)
	{
		label = Label::createWithTTF("Hello MilkyWorld", "fonts/Marker Felt.ttf", 24);
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));
		// add the label as a child to this layer
		this->addChild(label, 4);
		keygroup_A_pressed[0] = 0;
		keygroup_A_pressed[1] = 0;
		keygroup_A_pressed[2] = 0;
		keygroup_A_pressed[3] = 0;
		keygroup_C_pressed[0] = 0;
		player.hp = 100;
		player.defence = 0;
		world.name = "MILKYWORLD_TEST_2016";
		world.planet.name = "TEST_PLANET";
		world.planet.set_chunk_size(Vec2i(1024, 64));
		world.planet.sea_level = 768;
		world.planet.set_terrain_seed((unsigned)time(0));
		world.planet.gravitational_acceleration = -19.6*picture_length;
		world_vars::game_load_schedule = 0;
		player.enabled_gravity = true;
		player.touch_ground = false;
		player.size = Vec2(20,45);
		player.set_location(Vec2(300, (world.planet.sea_level+20) * picture_length));
		//CCLOG
		//创建一个分支线程用来加载世界，回调到game_load函数里
		thread game_load_thread(&HelloWorld::game_planet_load, this);
		game_load_thread.detach();
		loading_flag = true;
	}
	//没有加载好就退出,等待下一次执行到这个函数再判断
	if (world_vars::game_load_schedule < 100)return;
	this->unschedule(schedule_selector(HelloWorld::game_load_bar));
	//while (world_vars::game_load_schedule < 100);
	/*for (int i = 0; i < world.planet.get_chunk_size().x; i++)
	{
	for (int j = 0; j < world.planet.get_chunk_size().y; j++)
	{
	int chunk_index = i * world.planet.get_chunk_size().y + j;
	world.planet.chunk[chunk_index].set_location(Vec2i(i, j));
	world.planet.chunk[chunk_index].save_chunk(world.name, world.planet.name);
	}
	}
	for (int i = 0; i < world.planet.get_chunk_size().x; i++)
	{
	for (int j = 0; j < world.planet.get_chunk_size().y; j++)
	{
	int chunk_index = i * world.planet.get_chunk_size().y + j;
	world.planet.chunk[chunk_index].set_location(Vec2i(i, j));
	world.planet.chunk[chunk_index].load_chunk(world.name, world.planet.name);
	}
	}*/
	UI_processor_init();
	key_listener = EventListenerKeyboard::create();
	key_listener->setEnabled(true);
	key_listener->onKeyReleased = CC_CALLBACK_2(HelloWorld::on_key_released, this);
	key_listener->onKeyPressed = CC_CALLBACK_2(HelloWorld::on_key_pressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(key_listener, this);
	mouse_listener = EventListenerTouchOneByOne::create();
	mouse_listener->setEnabled(true);
	mouse_listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::on_touch_began, this);
	mouse_listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::on_touch_ended, this);
	mouse_listener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouse_listener, this);
	back_ground->setZOrder(0);
	//game_load_label->setVisible(false);
	game_load_label->setString("Milkyworld Alpha0.0.1\nCopyright 2016 Infinideas");
	game_load_label->setScale(0.5);
	game_load_label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - game_load_label->getContentSize().height));
	this->unschedule(schedule_selector(HelloWorld::game_load));
	schedule(schedule_selector(HelloWorld::UI_printer), 0.02f);//20ms刷新屏幕一次,FPS=50
	schedule(schedule_selector(HelloWorld::game_processor), 0.02f);//20ms处理一次游戏事件
}
/************************************************
函数名:游戏加载进度条
功能:用于更新加载进度条
备注:
************************************************/
void HelloWorld::game_load_bar(float dt)
{
	game_load_label->setString("Milkyworld Alpha0.0.1,World creating..." + int_2_string(world_vars::game_load_schedule) + "%");
}
/************************************************
函数名:世界加载
功能:加载/生成世界
备注:分支线程调用
************************************************/
void HelloWorld::game_planet_load()
{
	//加载地形
	world.planet.generate_terrain();
	world_vars::game_load_schedule = 100;
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}