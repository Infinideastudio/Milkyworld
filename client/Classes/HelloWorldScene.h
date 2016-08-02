#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "cocos2d.h"
#include "mainfiles\WorldStructure.h"
#include "mainfiles\WorldAlgorithms.h"
#include ".\codes\Mob\AllMobs.h"
#include <vector>
/************************************************
����:������
����:������
��ע:�̳�layer��
************************************************/
class HelloWorld : public cocos2d::Layer
{
public:
	UICamera camera;
	vector<vector<UIBlock> > UI_block;
	Sprite* back_ground;
	World world;
	Label* label;
	//���ؽ�����
	Label* game_load_label;
	Player player;
	//UI��������ʼ������
	void UI_processor_init();
	bool keygroup_A_pressed[4];//wsad
	bool keygroup_B_pressed[4];//��������
	bool keygroup_C_pressed[1];//space
	//�Ƿ������,���������������ת����Ϸ����
	bool loading_flag;
	//����������
	EventListenerKeyboard *key_listener;
	//���㴥��������
	EventListenerTouchOneByOne *mouse_listener;
	//����scene����
    static cocos2d::Scene* createScene();
	//��ʼ��scene����
    virtual bool init();
	bool on_touch_began(cocos2d::Touch* touch, cocos2d::Event* event);
	void on_touch_ended(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void on_key_released(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void on_key_pressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void UI_printer(float dt);//UI�����߳�
	void game_processor(float dt);
	//��Ϸ����
	void game_load(float dt);
	//���̼߳�������
	void game_planet_load();
	//��Ϸ���ع����и��½������ĺ���
	void game_load_bar(float dt);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
