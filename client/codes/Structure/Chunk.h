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
#ifndef __STRUCTURE_CHUNK_H__
#define __STRUCTURE_CHUNK_H__
#include "FrontBlock.h"
#include "MidBlock.h"
#include "BackBlock.h"
#include "..\Algorithm\AllAlgorithms.h"
#include "cocos2d.h"
using namespace cocos2d;
/************************************************
����:����
����:16*16��С�ķ�������
��ע:ÿ��λ�����������ڲ�ͬͼ���ϵķ��飬��ǰ���Ϊ0��
�м��Ϊ1��������Ϊ2��
************************************************/
class Chunk
{
public:
	//ǰ�к󾰷���
	FrontBlock front_block[block_size_of_chunk];
	MidBlock mid_block[block_size_of_chunk];
	BackBlock back_block[block_size_of_chunk];
	//�ɼ��ԣ��Ƿ�����Ļ��
	bool visible;
	//����chunk����
	void load();
	//����ǰ������
	void set_front_block(Vec2i position, FrontBlock front_block);
	//��ȡǰ������
	FrontBlock& get_front_block(Vec2i location);
	//����chunk��planet��ľ�������
	void set_location(Vec2i p);
	//��ȡchunk��planet��ľ�������
	Vec2i get_location();
	//����chunk����
	void save_chunk(string world_name, string planet_name);
	//��ȡchunk����
	void load_chunk(string world_name, string planet_name);
private:
	Vec2i location;//chunk�ľ�������
};

#endif