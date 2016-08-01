#ifndef __WORLDMOB_H__
#define __WORLDMOB_H__
#include <vector>
#include "Definition.h"
#include <.\otherfiles\MilkyworldMath.h>
#include "cocos2d.h"
using namespace std;
USING_NS_CC;
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
};
class Player:public Mob
{
public:
	//背包
	vector<ItemType> inventory;
	//世界坐标
	Vec2 location;
	bool enabled_gravity;
	Vec2 velocity;
	void set_location(Vec2 _location);
};
#endif