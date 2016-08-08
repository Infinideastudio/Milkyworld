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
#ifndef __GAMEUI_UIBLOCK_H__
#define __GAMEUI_UIBLOCK_H__
#include "cocos2d.h"
#include "..\Algorithm\AllAlgorithms.h"
#include "..\Structure\AllStructures.h"
USING_NS_CC;
/************************************************
����:UIblock
����:����UI��ʾblock
��ע:��
************************************************/
class UIBlock
{
public:
	Sprite *front_sprite;
	Sprite *mid_sprite;
	Sprite *back_sprite;
	//����ʾ��chunk����
	Vec2i chunk_location;
	//����ʾ��block��chunk�еı��
	Vec2i block_index;
	//��ײ��
	MyRectangle touch_box;
	//ʵ�ʴ�С
	Vec2 size;
	//���ڵ�ͼ����ѭ�������ԣ�UI�����λ�ò�����ȫ�������깫ʽ������
	//is_borrow���������UI��������Ӧ�ķ��鴦�ڵ�ͼ���⣬��˽��õ�ͼ��һ�˵ķ�����ʾ��
	//-1����chunk<0�����õ�ͼ���ұߵķ���
	//1����chunk>size�����õ�ͼ����ߵķ���
	//0�������÷��顣
	int is_borrow;
	void init_size(Vec2 _size);
	Vec2 get_position();
	void set_position(Vec2 _position);
	void create_sprite();
	void set_front_block(FrontBlock _block);
	void set_mid_block(MidBlock _block);
	void set_back_block(BackBlock _block);
private:
	Vec2 position;
	FrontBlock front_block;
	MidBlock mid_block;
	BackBlock back_block;
};
#endif