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
#ifndef __STRUCTURE_ITEMTYPE_H__
#define __STRUCTURE_ITEMTYPE_H__
#include "..\Algorithm\Definition.h"
/************************************************
枚举类名:物体类型
功能:表示物体的类型
备注:
************************************************/
enum class ItemType :ushort
{
	vacuum,//真空0
	rock,//岩石1
	stone,//圆石2
	dirt,//泥土3
	grass,//草地4
};
#endif