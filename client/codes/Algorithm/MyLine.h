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
#ifndef __ALGORITHM_MYLINE_H__
#define __ALGORITHM_MYLINE_H__
#include "cocos2d.h"
USING_NS_CC;
/************************************************
类名:MyLine
功能:直线
备注:无
************************************************/
class MyLine
{
public:
	MyLine(){}
	~MyLine(){}
	MyLine(Vec2 ul, Vec2 dr);
	Vec2 ul_point;
	Vec2 dr_point;
};
#endif