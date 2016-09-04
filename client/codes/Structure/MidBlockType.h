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
#ifndef __STRUCTURE_MIDBLOCKTYPE_H__
#define __STRUCTURE_MIDBLOCKTYPE_H__
#include "..\Algorithm\Definition.h"
/************************************************
枚举类名:中景方块类型
功能:表示方块的类型
备注:中景方块在后景方块上，存放没有碰撞箱的实体或者方块。
树干和树叶属于中景方块。
************************************************/
enum class MidBlockType :ushort
{
	_void,//空0
	oak,//橡树
	pine,//松树
	orange_tree,//橘子树
	apple_tree,//苹果树
	cherry_tree,//樱桃树
};
#endif