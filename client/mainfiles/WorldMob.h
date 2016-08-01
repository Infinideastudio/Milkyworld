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
	//Ѫ��
	int hp;
	//������
	int defence;
	//��С(����)
	Vec2 size;
	//������ײ��
	MyRectangle touch_box;
	//sprite
	Sprite* sprite;
	//�ŵ�
	bool touch_ground;
};
class Player:public Mob
{
public:
	//����
	vector<ItemType> inventory;
	//��������
	Vec2 location;
	bool enabled_gravity;
	Vec2 velocity;
	void set_location(Vec2 _location);
};
#endif