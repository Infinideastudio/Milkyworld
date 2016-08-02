#ifndef __MOB_MOB_H__
#define __MOB_MOB_H__
#include <vector>
#include "..\Algorithm\AllAlgorithm.h"
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
#endif