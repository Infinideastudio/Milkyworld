#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "cocos2d.h"
#include "mainfiles\WorldStructure.h"
#include "mainfiles\WorldAlgorithms.h"
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
	World world;
	Label* label;
	//UI��������ʼ������
	void UI_processor_init();
	bool keygroup_A_pressed[4];//wsad
	bool keygroup_B_pressed[4];//��������
	//����������
	EventListenerKeyboard *key_listener;
	//����scene����
    static cocos2d::Scene* createScene();
	//��ʼ��scene����
    virtual bool init();
	virtual void on_key_released(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void on_key_pressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void UI_printer(float dt);//UI�����߳�
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
