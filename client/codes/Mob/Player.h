#ifndef __MOB_PLAYER_H__
#define __MOB_PLAYER_H__
#include <vector>
#include "..\Structure\ItemType.h"
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
};
#endif