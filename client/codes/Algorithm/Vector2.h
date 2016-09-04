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
#ifndef __ALGORITHM_VECTOR2_H__
#define __ALGORITHM_VECTOR2_H__
/************************************************
类名:Vec2
功能:二维向量
备注:无
************************************************/
template <typename T>
class Vector2
{
public:
	T x, y;
	Vector2(){}
	~Vector2(){}
	Vector2(T xx, T yy) :x(xx), y(yy) {};
	Vector2& operator+= (const Vector2& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	Vector2& operator-= (const Vector2& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}
	Vector2<T>& operator*= (T value)
	{
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	Vector2<T>& operator/= (T value)
	{
		x /= value;
		y /= value;
		z /= value;
		return *this;
	}
	Vector2& operator+ (const Vector2& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	Vector2& operator- (const Vector2& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}
	Vector2<T> operator* (T value) const
	{
		return Vector2<T>(x * value, y * value);
	}

	Vector2<T> operator/ (T value) const
	{
		return Vector2<T>(x / value, y / value);
	}
	bool operator ==(const Vector2& rhs)
	{
		return(x==rhs.x&&y==rhs.y)
	}
};
using Vec2i = Vector2<int>;
using Vec2l = Vector2<long long>;
using Vec2f = Vector2<float>;
using Vec2d = Vector2<double>;
#endif
