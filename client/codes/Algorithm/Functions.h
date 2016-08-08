/*
* Milkyworld: A free game similar to ��The Blockheads��.
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
������:����ת������
����:�������͵�ת��
��ע:��
************************************************/
string int_2_string(int i);
double string_2_double(string i);
bool string_2_bool(string i);
int string_2_int(string i);
/************************************************
�����ռ�:MilkyWorld
����:һЩ��Ϸ��ȫ�ֱ���
��ע:��
************************************************/
namespace world_vars
{
	//��Ϸ���ؽ���
	extern int game_load_schedule;
}
#endif