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
#ifndef __STRUCTURE_FRONTBLOCKTYPE_H__
#define __STRUCTURE_FRONTBLOCKTYPE_H__
#include "..\Algorithm\Definition.h"
/************************************************
ö������:ǰ����������
����:��ʾ���������
��ע:ǰ���������������ײ�䣬��С��ֲ���Լ����嶼����ǰ������
************************************************/
enum class FrontBlockType : ushort
{
	vacuum,//���0
	air,//����1
	rock,//��ʯ2
	stone,//Բʯ3
	dirt,//����4
	grass,//�ݵ�5
	water,//ˮ6
};
#endif