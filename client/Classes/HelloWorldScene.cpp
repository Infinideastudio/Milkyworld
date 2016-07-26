#include "HelloWorldScene.h"
//#include "stdafx.h"//vsר��ͷ�ļ��������������������ע�͵�
#include "mainfiles\Definition.h"
#include "mainfiles\WorldStructure.h"
#include<iostream>
using namespace std;
using namespace AlgorithmVar;
USING_NS_CC;
/************************************************
������:����scene
����:����������
��ע:
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
������:��������ʼ������
����:��ʼ��������
��ע:
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
	schedule(schedule_selector(HelloWorld::UI_printer), 0.02f);//20msˢ����Ļһ��,FPS=50
    return true;
}
/************************************************
������:UI��ӡ�߳�
����:����ˢ��UI��ʾ
��ע:20ms����һ��,FPS=50
************************************************/
void HelloWorld::UI_printer(float dt)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//�ĸ�����ֱ��жϺͼ��������������ƫ����
	for (int i = 0; i <= 3; i++)
		if (keygroup_B_pressed[i])
			camera.location += delta[i] * 5;
	for (int i = 0; i < UI_block.size(); i++)
	{
		for (int j = 0; j < UI_block[i].size(); j++)
		{
			Vec2 __position = UI_block[i][j].get_position();
			Vec2i a, b;
			bool move_flag = false;//ת�Ʊ��
			//Խ��ת�ƴ���
			if (__position.x < -3 * picture_length)
			{
				move_flag = true;
				UI_block[i][j].block_index.x += UI_block.size();//����ת��size������
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
				UI_block[i][j].block_index.x -= UI_block.size();//����ת��size������
				while (UI_block[i][j].block_index.x <0)
				{
					UI_block[i][j].block_index.x += length_of_block_size;
					UI_block[i][j].chunk_location.x--;
				}
			}
			if (__position.y < -3 * picture_length)
			{
				move_flag = true;
				UI_block[i][j].block_index.y += UI_block[i].size();//����ת��size������
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
				UI_block[i][j].block_index.y -= UI_block[i].size();//����ת��size������
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
			//����UI_block����Ļ�ϵ�ƫ������
			__position.x = UI_block[i][j].chunk_location.x*length_of_block_size*picture_length
				+ UI_block[i][j].block_index.x * picture_length - camera.location.x;
			__position.y = UI_block[i][j].chunk_location.y*length_of_block_size*picture_length
				+ UI_block[i][j].block_index.y * picture_length - camera.location.y;
			UI_block[i][j].set_position(__position);
		}
	}
}
/************************************************
������:UI��������ʼ������
����:���ڳ�ʼ��������UI�����йص��¼�
��ע:�ṹ���ƺ󽫴Ӵ浵��ȡ��ʼֵ
************************************************/
void HelloWorld::UI_processor_init()
{
	//���������������ԭ��
	camera.location = Vec2(0, 0);
	//��ʼ��UI��ʾ����
	UI_block.resize(36);//��Ļ��32�������Ҹ�����
	for (int i = 0; i < UI_block.size(); i++)
	{
		UI_block[i].resize(28);//��Ļ��24�������¸�����
	}
	for (int i = 0; i < UI_block.size(); i++)
	{
		for (int j = 0; j < UI_block[i].size(); j++)
		{
			UI_block[i][j].create_sprite();
			//location�Ǿ����������꣬position����Ļ�������� i-2��������Ļ������������
			Vec2l UI_block_position = Vec2l((i - 2)*picture_length, (j - 2)*picture_length);
			Vec2l UI_block_location;
			//chunk_location������chunk��planet�ϵľ������꣬block_location������block��chunk�е�ƫ������
			Vec2i UI_block_chunk_location;
			Vec2i UI_block_block_location;
			//���μ��������location�����ж���ʾ�����ĸ����顣
			UI_block_location.x = camera.location.x + (i - 2)*picture_length;
			UI_block_location.y = camera.location.y + (j - 2)*picture_length;
			UI_block_chunk_location.x = UI_block_location.x / (length_of_block_size*picture_length);
			UI_block_chunk_location.y = UI_block_location.y / (length_of_block_size*picture_length);
			if (UI_block_location.x < 0)UI_block_chunk_location.x -= 1;
			if (UI_block_location.y < 0)UI_block_chunk_location.y -= 1;
			//����ƫ���������꣬������һ������ȡ������������ó�ƫ������
			UI_block_block_location.x = UI_block_location.x - 
				UI_block_chunk_location.x*(length_of_block_size*picture_length);
			UI_block_block_location.y = UI_block_location.y - 
				UI_block_chunk_location.y*(length_of_block_size*picture_length);
			//����ƫ�������������ƫ������
			UI_block_block_location.x /= picture_length;
			UI_block_block_location.y /= picture_length;
			//�ҵ������÷���
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
������:�����ͷ��¼�
����:�����ͷ�ʱ������ִ��һϵ�ж���
��ע:��
************************************************/
void HelloWorld::on_key_released(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)  //�����ϼ�
		keygroup_B_pressed[0] = false;
	if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)  //�����¼�
		keygroup_B_pressed[1] = false;
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)  //�������
		keygroup_B_pressed[2] = false;
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)  //�����Ҽ�
		keygroup_B_pressed[3] = false;
	if (keyCode == EventKeyboard::KeyCode::KEY_W)  //w��
		keygroup_A_pressed[0] = false;
	if (keyCode == EventKeyboard::KeyCode::KEY_S)  //s��
		keygroup_A_pressed[1] = false;
	if (keyCode == EventKeyboard::KeyCode::KEY_A)  //a��
		keygroup_A_pressed[2] = false;
	if (keyCode == EventKeyboard::KeyCode::KEY_D)  //d��
		keygroup_A_pressed[3] = false;
}
/************************************************
������:���̰����¼�
����:���̰���ʱ������ִ��һϵ�ж���
��ע:��
************************************************/
void HelloWorld::on_key_pressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)  //�����ϼ�
		keygroup_B_pressed[0] = true;
	if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)  //�����¼�
		keygroup_B_pressed[1] = true;
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)  //�������
		keygroup_B_pressed[2] = true;
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)  //�����Ҽ�
		keygroup_B_pressed[3] = true;
	if (keyCode == EventKeyboard::KeyCode::KEY_W)  //w��
		keygroup_A_pressed[0] = true;
	if (keyCode == EventKeyboard::KeyCode::KEY_S)  //s��
		keygroup_A_pressed[1] = true;
	if (keyCode == EventKeyboard::KeyCode::KEY_A)  //a��
		keygroup_A_pressed[2] = true;
	if (keyCode == EventKeyboard::KeyCode::KEY_D)  //d��
		keygroup_A_pressed[3] = true;
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
