#include "HelloWorldScene.h"
//#include "stdafx.h"//vs专用头文件，用其他编译器编译可注释掉
#include "mainfiles\Definition.h"
#include "mainfiles\WorldStructure.h"
#include<iostream>
using namespace std;
using namespace AlgorithmVar;
USING_NS_CC;
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

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    // create menu, it's an autorelease object

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    label = Label::createWithTTF("Hello MilkyWorld", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
		   origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 2);

    //// add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");

    //// position the sprite on the center of the screen
    //sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    //// add the sprite as a child to this layer
    //this->addChild(sprite, 0);
	world.name = "MILKYWORLD_TEST_2016";
	world.planet.name = "TEST_PLANET";
	world.planet.chunk.resize(289);
	
	for (int i = -8; i <= 8; i++)
	{
		for (int j = -8; j <= 8; j++)
		{
			int chunk_index = (i+8) * 16 + (j+8);
			world.planet.chunk[chunk_index].set_location(Vec2i(i, j));
			for (int k = 0; k <= 15; k++)
			{
				for (int l = 0; l <= 15; l++)
				{
					world.planet.chunk[chunk_index].front_block[k * 16 + l].type = FrontBlockType::rock;
					world.planet.chunk[chunk_index].front_block[k * 16 + l].enabled_touch = true;
					world.planet.chunk[chunk_index].mid_block[k * 16 + l].type = MidBlockType::_void;
				}
			}
			world.planet.chunk[chunk_index].save_chunk(world.name, world.planet.name);
		}
	}
	for (int i = 0; i <= 16; i++)
	{
		for (int j = 0; j <= 16; j++)
		{
			int chunk_index = i * 16 + j;
			world.planet.chunk[chunk_index].set_location(Vec2i(i-8, j-8));
			world.planet.chunk[chunk_index].load_chunk(world.name, world.planet.name);
		}
	}
	UI_processor_init();
	key_listener = EventListenerKeyboard::create();
	key_listener->setEnabled(true);
	key_listener->onKeyReleased = CC_CALLBACK_2(HelloWorld::on_key_released, this);
	key_listener->onKeyPressed = CC_CALLBACK_2(HelloWorld::on_key_pressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(key_listener, this);
	schedule(schedule_selector(HelloWorld::UI_printer), 0.02f);//20ms刷新屏幕一次,FPS=50
    return true;
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
	//四个方向分别判断和计算摄像机的坐标偏移量
	for (int i = 0; i <= 3; i++)
		if (keygroup_B_pressed[i])
			camera.location += delta[i] * 5;
	for (int i = 0; i < UI_block.size(); i++)
	{
		for (int j = 0; j < UI_block[i].size(); j++)
		{
			Vec2 __position = UI_block[i][j].get_position();
			Vec2i a, b;
			bool move_flag = false;//转移标记
			//越界转移代码
			if (__position.x < -3 * picture_length)
			{
				move_flag = true;
				UI_block[i][j].block_index.x += UI_block.size();//向右转移size个格子
				a = UI_block[i][j].block_index;
				b = UI_block[i][j].chunk_location;
				while (UI_block[i][j].block_index.x >length_of_block_size-1)
				{
					UI_block[i][j].block_index.x -= length_of_block_size;
					UI_block[i][j].chunk_location.x++;
				}
			}
			else 
			if (__position.x > 3 * picture_length + visibleSize.width)
			{
				move_flag = true;
				UI_block[i][j].block_index.x -= UI_block.size();//向左转移size个格子
				while (UI_block[i][j].block_index.x <0)
				{
					UI_block[i][j].block_index.x += length_of_block_size;
					UI_block[i][j].chunk_location.x--;
				}
			}
			if (__position.y < -3 * picture_length)
			{
				move_flag = true;
				UI_block[i][j].block_index.y += UI_block[i].size();//向上转移size个格子
				while (UI_block[i][j].block_index.y >length_of_block_size - 1)
				{
					UI_block[i][j].block_index.y -= length_of_block_size;
					UI_block[i][j].chunk_location.y++;
				}
			}
			else
			if (__position.y > 3 * picture_length + visibleSize.height)
			{
				move_flag = true;
				UI_block[i][j].block_index.y -= UI_block[i].size();//向下转移size个格子
				while (UI_block[i][j].block_index.y <0)
				{
					UI_block[i][j].block_index.y += length_of_block_size;
					UI_block[i][j].chunk_location.y--;
				}
			}
			if (move_flag)
			{
				UI_block[i][j].set_front_block(world.planet.get_chunk(UI_block[i][j].chunk_location).
					front_block[UI_block[i][j].block_index.x * length_of_block_size + UI_block[i][j].block_index.y]);
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
	//设置摄像机坐标于原点
	camera.location = Vec2(0, 0);
	//初始化UI显示方块
	UI_block.resize(36);//屏幕内32个，左右各两个
	for (int i = 0; i < UI_block.size(); i++)
	{
		UI_block[i].resize(28);//屏幕内24个，上下各两个
	}
	for (int i = 0; i < UI_block.size(); i++)
	{
		for (int j = 0; j < UI_block[i].size(); j++)
		{
			UI_block[i][j].create_sprite();
			//location是绝对像素坐标，position是屏幕像素坐标 i-2是由于屏幕外有两个方块
			Vec2l UI_block_position = Vec2l((i - 2)*picture_length, (j - 2)*picture_length);
			Vec2l UI_block_location;
			//chunk_location是所属chunk在planet上的绝对坐标，block_location是所属block在chunk中的偏移坐标
			Vec2i UI_block_chunk_location;
			Vec2i UI_block_block_location;
			//依次计算出各个location，来判断显示的是哪个方块。
			UI_block_location.x = camera.location.x + (i - 2)*picture_length;
			UI_block_location.y = camera.location.y + (j - 2)*picture_length;
			UI_block_chunk_location.x = UI_block_location.x / (length_of_block_size*picture_length);
			UI_block_chunk_location.y = UI_block_location.y / (length_of_block_size*picture_length);
			if (UI_block_location.x < 0)UI_block_chunk_location.x -= 1;
			if (UI_block_location.y < 0)UI_block_chunk_location.y -= 1;
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
			UI_block[i][j].set_front_block(world.planet.get_chunk(UI_block_chunk_location).
				front_block[UI_block_block_location.x * length_of_block_size + UI_block_block_location.y]);
			UI_block[i][j].set_mid_block(world.planet.get_chunk(UI_block_chunk_location).
				mid_block[UI_block_block_location.x * length_of_block_size + UI_block_block_location.y]);
			UI_block[i][j].set_back_block(world.planet.get_chunk(UI_block_chunk_location).
				back_block[UI_block_block_location.x * length_of_block_size + UI_block_block_location.y]);
			UI_block[i][j].mid_sprite->setVisible(false);
			UI_block[i][j].back_sprite->setVisible(false);
			UI_block[i][j].set_position(Vec2((i - 2)*picture_length - camera.location.x,
				(j - 2)*picture_length - camera.location.y));
			this->addChild(UI_block[i][j].front_sprite, 3);
			this->addChild(UI_block[i][j].mid_sprite, 2);
			this->addChild(UI_block[i][j].back_sprite, 1);
		}
	}
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
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
