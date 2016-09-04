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
#include "UIBlock.h"
/************************************************
������:get_position
����:�����Ļ���� 
��ע:��
************************************************/
Vec2 UIBlock::get_position()
{
	return position;
}
/************************************************
������:set_position
����:������Ļ����
��ע:��
************************************************/
void UIBlock::set_position(Vec2 _position)
{
	position = _position;
	touch_box = MyRectangle(Vec2(_position.x - size.x / 2, _position.y + size.y / 2)
		, Vec2(_position.x + size.x / 2, _position.y - size.y / 2));
	front_sprite->setPosition(_position);
	mid_sprite->setPosition(_position);
	back_sprite->setPosition(_position);
}
/************************************************
������:init_size
����:��һ�����ô�С
��ע:��
************************************************/
void UIBlock::init_size(Vec2 _size)
{
	size = _size;
}
/************************************************
������:create_sprite
����:����sprite
��ע:��
************************************************/
void UIBlock::create_sprite()
{
	front_sprite = Sprite::create("HelloWorld.png");
	mid_sprite = Sprite::create("HelloWorld.png");
	back_sprite = Sprite::create("HelloWorld.png");
	init_size(Vec2(picture_length, picture_length));
}
/************************************************
������:set_front_block
����:����ǰ������
��ע:��
************************************************/
void UIBlock::set_front_block(FrontBlock _block)
{
	front_block = _block;
	if (front_block.type == FrontBlockType::air)
		front_sprite->setVisible(false);
	else
	{
		front_sprite->setVisible(true);
		front_sprite->setTexture("texture\\block\\"+int_2_string(static_cast<ushort>(front_block.type)) + ".png");
	}

}
/************************************************
������:set_mid_block
����:�����о�����
��ע:��
************************************************/
void UIBlock::set_mid_block(MidBlock _block)
{
	mid_block = _block;
	mid_sprite->setTexture("HelloWorld.png");
}
/************************************************
������:set_back_block
����:���ú󾰷���
��ע:��
************************************************/
void UIBlock::set_back_block(BackBlock _block)
{
	back_block = _block;
	back_sprite->setTexture("HelloWorld.png");
}