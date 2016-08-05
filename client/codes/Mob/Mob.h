#ifndef __MOB_MOB_H__
#define __MOB_MOB_H__
#include <vector>
#include "..\Algorithm\AllAlgorithms.h"
#include "cocos2d.h"
using namespace std;
USING_NS_CC;
/************************************************
类名:Mob
功能:生物
备注:无
************************************************/
class Mob
{
public:
	//血量
	int hp;
	//防御力
	int defence;
	//大小(像素)
	Vec2 size;
	//矩形碰撞箱
	MyRectangle touch_box;
	//sprite
	Sprite* sprite;
	//着地
	bool touch_ground;
	//世界坐标
	Vec2 location;
	bool enabled_gravity;
	Vec2 velocity;
	void set_location(Vec2 _location);
	//中心所在的block坐标
	Vec2i on_block();
	Vec2i hit_test_start();
	Vec2i hit_test_end();
};
#endif