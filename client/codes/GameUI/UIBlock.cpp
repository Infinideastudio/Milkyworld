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
#include "UIBlock.h"
/************************************************
函数名:get_position
功能:获得屏幕坐标 
备注:无
************************************************/
Vec2 UIBlock::get_position()
{
	return position;
}
/************************************************
函数名:set_position
功能:设置屏幕坐标
备注:无
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
函数名:init_size
功能:第一次设置大小
备注:无
************************************************/
void UIBlock::init_size(Vec2 _size)
{
	size = _size;
}
/************************************************
函数名:create_sprite
功能:创建sprite
备注:无
************************************************/
void UIBlock::create_sprite()
{
	front_sprite = Sprite::create("HelloWorld.png");
	mid_sprite = Sprite::create("HelloWorld.png");
	back_sprite = Sprite::create("HelloWorld.png");
	init_size(Vec2(picture_length, picture_length));
}
/************************************************
函数名:set_front_block
功能:设置前景方块
备注:无
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
函数名:set_mid_block
功能:设置中景方块
备注:无
************************************************/
void UIBlock::set_mid_block(MidBlock _block)
{
	mid_block = _block;
	mid_sprite->setTexture("HelloWorld.png");
}
/************************************************
函数名:set_back_block
功能:设置后景方块
备注:无
************************************************/
void UIBlock::set_back_block(BackBlock _block)
{
	back_block = _block;
	back_sprite->setTexture("HelloWorld.png");
}