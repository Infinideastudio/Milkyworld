#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "cocos2d.h"
#include "mainfiles\WorldStructure.h"
#include "mainfiles\WorldAlgorithms.h"
#include ".\codes\Mob\AllMobs.h"
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
	Sprite* back_ground;
	World world;
	Label* label;
	//加载进度条
	Label* game_load_label;
	Player player;
	//UI处理器初始化函数
	void UI_processor_init();
	bool keygroup_A_pressed[4];//wsad
	bool keygroup_B_pressed[4];//上下左右
	bool keygroup_C_pressed[1];//space
	//是否加载中,如果加载中则不能跳转到游戏界面
	bool loading_flag;
	//按键监听器
	EventListenerKeyboard *key_listener;
	//单点触摸监听器
	EventListenerTouchOneByOne *mouse_listener;
	//创建scene函数
    static cocos2d::Scene* createScene();
	//初始化scene函数
    virtual bool init();
	bool on_touch_began(cocos2d::Touch* touch, cocos2d::Event* event);
	void on_touch_ended(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void on_key_released(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void on_key_pressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void UI_printer(float dt);//UI绘制线程
	void game_processor(float dt);
	//游戏加载
	void game_load(float dt);
	//多线程加载世界
	void game_planet_load();
	//游戏加载过程中更新进度条的函数
	void game_load_bar(float dt);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
