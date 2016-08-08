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