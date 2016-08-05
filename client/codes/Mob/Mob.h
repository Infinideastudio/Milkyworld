#ifndef __MOB_MOB_H__
#define __MOB_MOB_H__
#include <vector>
#include "..\Algorithm\AllAlgorithms.h"
#include "cocos2d.h"
using namespace std;
USING_NS_CC;
/************************************************
����:Mob
����:����
��ע:��
************************************************/
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
	//��������
	Vec2 location;
	bool enabled_gravity;
	Vec2 velocity;
	void set_location(Vec2 _location);
	//�������ڵ�block����
	Vec2i on_block();
	Vec2i hit_test_start();
	Vec2i hit_test_end();
};
#endif