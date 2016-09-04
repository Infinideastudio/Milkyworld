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
	vacuum,//���
	air,//����
	rock,//��ʯ
	stone,//ʯͷ
	stone_brick,//ʯש
	sand,//ɳ��
	black_sand,//��ɳ
	grit,//ɰ��
	clay,//ճ��
	dirt,//����
	grass,//�ݵ�
	wood,//ľ��
	coal,//ú��ʯ
	chalcopyrite,//��ͭ��ʯ(CuFeS2)
	cassiterite,//��ʯ(Sn)
	hematite,//������ʯ(Fe2O3)
	ilmenite,//������ʯ(FeTiO3)
	bauxite,//������ʯ(Al2O3)
	uranium,//�˿�ʯ(U)
	gold,//���ʯ(Au)
	water,//ˮ
	lava,//�ҽ�
};
#endif