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
#ifndef __ALGORITHM_MYRECTANGLE_H__
#define __ALGORITHM_MYRECTANGLE_H__
#include "cocos2d.h"
#include "MyLine.h"
USING_NS_CC;
using namespace std;
/************************************************
类名:MyRectangle
功能:矩形和碰撞检测
备注:无
************************************************/
class MyRectangle
{
public:
	MyRectangle(){}
	~MyRectangle(){}
	MyRectangle(Vec2 ul, Vec2 dr);
	//判断两个矩形是否相交
	bool is_touch(MyRectangle rec);
	//求有向面积
	float get_area(Vec2 a0, Vec2 a1, Vec2 a2);
	//判断矩形和线段是否相交
	bool touch_line(MyLine line);
	//相交部分大小
	Vec2 overlap_size(MyRectangle rec);
	//四条边
	MyLine up_line;
	MyLine down_line;
	MyLine left_line;
	MyLine right_line;
	Vec2 ul_point;//左上角
	Vec2 dr_point;//右下角
private:

};
#endif