#ifndef __MOB_PLAYER_H__
#define __MOB_PLAYER_H__
#include <vector>
#include "..\mainfiles\Definition.h"
#include "Mob.h"
#include "cocos2d.h"
using namespace std;
USING_NS_CC;
/************************************************
����:Player
����:���
��ע:��
************************************************/
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