/*
* Milkyworld: A free game similar to “The Blockheads”.
* Copyright (C) 2016 Infinideas
*
* This file is part of Milkyworld.
* Milkyworld is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Milkyworld is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with Milkyworld.  If not, see <http://www.gnu.org/licenses/>.
*/
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