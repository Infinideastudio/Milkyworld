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
    this->addChild(label, 4);

    //// add "HelloWorld" splash screen"
    back_ground = Sprite::create("White.png");
	//back_ground->setColor(Color3B(255, 128, 0));
	back_ground->setColor(Color3B(215, 240, 247));
	
    // position the sprite on the center of the screen
	back_ground->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    // add the sprite as a child to this layer
	this->addChild(back_ground, 0);
	keygroup_A_pressed[0] = 0;
	keygroup_A_pressed[1] = 0;
	keygroup_A_pressed[2] = 0;
	keygroup_A_pressed[3] = 0;
	world.name = "MILKYWORLD_TEST_2016";
	world.planet.name = "TEST_PLANET";
	world.planet.set_chunk_size(Vec2i(1024, 64));
	world.planet.sea_level = 768;
	world.planet.set_terrain_seed((unsigned)time(0));
	world.planet.generate_terrain();
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
	schedule(schedule_selector(HelloWorld::UI_printer), 0.02f);//20msˢ����Ļһ��,FPS=50
	schedule(schedule_selector(HelloWorld::game_processor), 0.02f);//20ms����һ����Ϸ�¼�
    return true;
}
/************************************************
������:��Ϸ�¼�����
����:���ڴ�����Ϸ�����е��¼�
��ע:20msִ��һ��
************************************************/
void HelloWorld::game_processor(float dt)
{
	//�ĸ�����ֱ��ж��Ƿ��°��������������������ƫ����
	for (int i = 0; i <= 3; i++)
	{
		if (keygroup_A_pressed[i])
		{
			camera.location += delta[i] * 20;
		}
	}
	label->setString(int_2_string(camera.location.x) + "," + int_2_string(camera.location.y));//debug
	//�����ǹ��ڵ�ͼ����ѭ���Ĵ���
	int world_width = world.planet.get_chunk_size().x*length_of_block_size*picture_length;
	int reset_camera = -1 * UI_block.size()*picture_length - 3* picture_length;
	//over_map_flag=true��ʾcamera�Ѿ�������ȷ��λ�ã����з��鶼���ٽ��õ�ͼ��һ�˵ġ�
	bool over_map_flag = false;
	if (camera.location.x < reset_camera)
	{
		camera.location.x += world_width;
		over_map_flag = true;
	}
	else
	if (camera.location.x >= world_width + 7 * picture_length)
	{
		camera.location.x -= world_width;
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
������:UI��ӡ�߳�
����:����ˢ��UI��ʾ
��ע:20ms����һ��,FPS=50
************************************************/
void HelloWorld::UI_printer(float dt)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//���·���λ��
	for (int i = 0; i < UI_block.size(); i++)
	{
		for (int j = 0; j < UI_block[i].size(); j++)
		{
			Vec2 __position = UI_block[i][j].get_position();
			//�Ƿ�ת�Ƶı��
			bool move_flag = false;
			//UI����Խ��ת�ƴ���
			//world_chunk_width��ʾ��ͼ�Ŀ��(chunks�ں��������)
			int world_chunk_width = world.planet.get_chunk_size().x;
			//UI��������Խ��
			if (__position.x < -3 * picture_length)
			{
				move_flag = true;
				UI_block[i][j].block_index.x += UI_block.size();//����ת��size������
				while (UI_block[i][j].block_index.x >length_of_block_size-1)
				{
					UI_block[i][j].block_index.x -= length_of_block_size;
					UI_block[i][j].chunk_location.x++;
				}
				//��ͼ����Խ��ѭ�����ж�
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
			else //UI������Ҳ�Խ��
			if (__position.x > 3 * picture_length + visibleSize.width)
			{
				move_flag = true;
				UI_block[i][j].block_index.x -= UI_block.size();//����ת��size������
				while (UI_block[i][j].block_index.x <0)
				{
					UI_block[i][j].block_index.x += length_of_block_size;
					UI_block[i][j].chunk_location.x--;
				}
				//��ͼ����Խ��ѭ�����ж�
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
			//UI������·�Խ��
			if (__position.y < -3 * picture_length)
			{
				move_flag = true;
				//����ת��size������
				UI_block[i][j].block_index.y += UI_block[i].size();
				while (UI_block[i][j].block_index.y >length_of_block_size - 1)
				{
					UI_block[i][j].block_index.y -= length_of_block_size;
					UI_block[i][j].chunk_location.y++;
				}
			}
			else//UI������Ϸ�Խ��
			if (__position.y > 3 * picture_length + visibleSize.height)
			{
				move_flag = true;
				//����ת��size������
				UI_block[i][j].block_index.y -= UI_block[i].size();
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
			int world_width = world.planet.get_chunk_size().x*length_of_block_size*picture_length;
			__position.x += UI_block[i][j].is_borrow*world_width;
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
	camera.location = Vec2(300, world.planet.sea_level * picture_length);
	//��ʼ��UI��ʾ����
	UI_block.resize(36);//��Ļ��32�������Ҹ�����
	for (int i = 0; i < UI_block.size(); i++)
	{
		UI_block[i].resize(28);//��Ļ��24�������¸�����
	}
	//ö��ÿ��UI���飬����ʼ��
	for (int i = 0; i < UI_block.size(); i++)
	{
		for (int j = 0; j < UI_block[i].size(); j++)
		{
			UI_block[i][j].create_sprite();
			//��ʼʱ�趨����ǽ���
			UI_block[i][j].is_borrow = 0;
			//location�Ǿ����������꣬position����Ļ�������� i-2��������Ļ������������
			Vec2 UI_block_position = Vec2((i - 2)*picture_length, (j - 2)*picture_length);
			Vec2l UI_block_location;
			//chunk_location������chunk��planet�ϵľ������꣬block_location������block��chunk�е�ƫ������
			Vec2i UI_block_chunk_location;
			Vec2i UI_block_block_location;
			//���μ��������location�����ж���ʾ�����ĸ����顣
			UI_block_location.x = camera.location.x + (i - 2)*picture_length;
			UI_block_location.y = camera.location.y + (j - 2)*picture_length;
			//�����ͼ����ѭ��
			//world_width�����ͼ�Ŀ��(������)
			int world_width = world.planet.get_chunk_size().x*length_of_block_size*picture_length;
			if (UI_block_location.x < 0)
			{
				//�����Խ�磬��˽��õ�ͼ���ұߵķ�������ʾ
				UI_block[i][j].is_borrow = -1;
				UI_block_location.x += world_width;
			}
			else
			if (UI_block_location.x >= world_width)
			{
				//���Ҳ�Խ�磬��˽��õ�ͼ����ߵķ�������ʾ
				UI_block[i][j].is_borrow = 1;
				UI_block_location.x -= world_width;
			}
			//����UI��������Ӧ��chunk��λ��
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
			UI_block[i][j].set_position(UI_block_position);
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
