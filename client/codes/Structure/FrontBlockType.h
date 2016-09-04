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
#ifndef __STRUCTURE_FRONTBLOCKTYPE_H__
#define __STRUCTURE_FRONTBLOCKTYPE_H__
#include "..\Algorithm\Definition.h"
/************************************************
枚举类名:前景方块类型
功能:表示方块的类型
备注:前景方块可以设置碰撞箱，中小型植物以及气体都属于前景方块
************************************************/
enum class FrontBlockType : ushort
{
	vacuum,//真空
	air,//空气
	rock,//岩石
	stone,//石头
	stone_brick,//石砖
	sand,//沙子
	black_sand,//黑沙
	grit,//砂砾
	clay,//粘土
	dirt,//泥土
	grass,//草地
	wood,//木材
	coal,//煤矿石
	chalcopyrite,//黄铜矿石(CuFeS2)
	cassiterite,//锡石(Sn)
	hematite,//赤铁矿石(Fe2O3)
	ilmenite,//钛铁矿石(FeTiO3)
	bauxite,//铝土矿石(Al2O3)
	uranium,//铀矿石(U)
	gold,//金矿石(Au)
	water,//水
	lava,//岩浆
};
#endif