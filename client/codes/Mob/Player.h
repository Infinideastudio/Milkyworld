#ifndef __MOB_PLAYER_H__
#define __MOB_PLAYER_H__
#include <vector>
#include "..\Structure\ItemType.h"
#include "Mob.h"
#include "cocos2d.h"
using namespace std;
USING_NS_CC;
/************************************************
类名:Player
功能:玩家
备注:无
************************************************/
class Player:public Mob
{
public:
	//背包
	vector<ItemType> inventory;
};
#endif