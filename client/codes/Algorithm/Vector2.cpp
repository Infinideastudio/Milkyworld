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
#include "Vector2.h"
/************************************************
函数名:Vector2
功能:构造函数
备注:无
************************************************/
Vector2::Vector2(T xx, T yy)
{
	x = xx; y = yy;
}
/************************************************
函数块:重载运算符
功能:重载运算符
备注:无
************************************************/
Vector2 Vector2::operator +(const Vector2 &c)
{
	Vector2 p;
	p.x = x + c.x; p.y = y + c.y;
	return p;
}
Vector2 Vector2::operator -(const Vector2 &c)
{
	Vector2 p;
	p.x = x - c.x; p.y = y - c.y;
	return p;
}
Vector2 Vector2::operator *(const int &c)
{
	Vector2 p;
	p.x = x * c; p.y = y * c;
	return p;
}
bool Vector2::operator ==(const Vector2 &p)
{
	return (p.x == x&&p.y == y)
}