#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "cocos2d.h"
#include "mainfiles\WorldStructure.h"
#include "mainfiles\WorldAlgorithms.h"
#include <vector>
/************************************************
类名:主场景
功能:主场景
备注:继承layer类
************************************************/
class HelloWorld : public cocos2d::Layer
{
public:
	UICamera camera;
	vector<vector<UIBlock> > UI_block;
	World world;
	Label* label;
	//UI处理器初始化函数
	void UI_processor_init();
	bool keygroup_A_pressed[4];//wsad
	bool keygroup_B_pressed[4];//上下左右
	//按键监听器
	EventListenerKeyboard *key_listener;
	//创建scene函数
    static cocos2d::Scene* createScene();
	//初始化scene函数
    virtual bool init();
	virtual void on_key_released(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void on_key_pressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void UI_printer(float dt);//UI绘制线程
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
