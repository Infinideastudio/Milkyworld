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
#include "Functions.h"
/************************************************
函数块:类型转换函数
功能:在几个常用类型之间转换
备注:无
************************************************/
string int_2_string(int i)
{
	char temp[10];
	sprintf(temp, "%d", i, 10);
	string s = temp;
	return s;
}
double string_2_double(string i)
{
	string str = i;
	return atof(str.c_str());
}
int string_2_int(string i)
{
	string str = i;
	int j = atoi(str.c_str());
	return j;
}
bool string_2_bool(string i)
{
	string str = i;
	int j = atoi(str.c_str());
	if (j == 0)return false;
	return true;
}
/************************************************
变量:命名空间变量定义
功能:定义变量
备注:无
************************************************/
int world_vars::game_load_schedule;