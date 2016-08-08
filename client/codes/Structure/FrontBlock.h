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
#ifndef __STRUCTURE_FRONTBLOCK_H__
#define __STRUCTURE_FRONTBLOCK_H__
#include "Block.h"
#include "..\Algorithm\AllAlgorithms.h"
#include "FrontBlockType.h"
/************************************************
类名:前景方块
功能:表示一个方块
备注:显示在最前面的方块
************************************************/
class FrontBlock :public Block//前景方块
{
public:
	//碰撞箱
	bool enabled_touch;
	FrontBlockType type;
};
#endif