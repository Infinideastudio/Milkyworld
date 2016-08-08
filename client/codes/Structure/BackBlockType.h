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
#ifndef __STRUCTURE_BACKBLOCKTYPE_H__
#define __STRUCTURE_BACKBLOCKTYPE_H__
#include "..\Algorithm\Definition.h"
/************************************************
枚举类名:后景方块类型
功能:表示方块的类型
备注:后景方块仅仅用来装饰，没有任何实际作用，在2d视角下不启用，仅做备用。
************************************************/
enum class BackBlockType :ushort
{
	vacuum,//真空0
	air,//空气1
	rock,//岩石2
	stone,//圆石3
	dirt,//泥土4
	grass,//草地5
};
#endif