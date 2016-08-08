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
#ifndef __ALGORITHM_FUNCTIONS_H__
#define __ALGORITHM_FUNCTIONS_H__
#include <iostream>
using namespace std;
/************************************************
函数块:类型转换函数
功能:常用类型的转换
备注:无
************************************************/
string int_2_string(int i);
double string_2_double(string i);
bool string_2_bool(string i);
int string_2_int(string i);
/************************************************
命名空间:MilkyWorld
功能:一些游戏的全局变量
备注:无
************************************************/
namespace world_vars
{
	//游戏加载进度
	extern int game_load_schedule;
}
#endif