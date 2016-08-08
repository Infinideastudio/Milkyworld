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
#include "Mob.h"
/************************************************
函数:on_block
功能:获取玩家锚点所在的block的坐标
备注:
************************************************/
Vec2i Mob::on_block()
{
	Vec2i block_location;
	block_location.x = location.x/picture_length;
	block_location.y = location.y/picture_length;
	return block_location;
}
/************************************************
函数:hit_test_start_point
功能:获取玩家锚点所在的block的坐标-2
备注:
************************************************/
Vec2i Mob::hit_test_start()
{
	Vec2i start_point = on_block();
	start_point = start_point - Vec2i(2,2);
	return start_point;
}
/************************************************
函数:hit_test_end_point
功能:获取玩家锚点所在的block的坐标+2
备注:
************************************************/
Vec2i Mob::hit_test_end()
{
	Vec2i end_point = on_block();
	end_point = end_point + Vec2i(2, 2);
	return end_point;
}
/************************************************
函数:设置绝对坐标
功能:设置mob的绝对坐标
备注:
************************************************/
void Mob::set_location(Vec2 _location)
{
	location = _location;
	touch_box = MyRectangle(Vec2(location.x - size.x / 2, location.y + size.y / 2)
		, Vec2(location.x + size.x / 2, location.y - size.y / 2));
}