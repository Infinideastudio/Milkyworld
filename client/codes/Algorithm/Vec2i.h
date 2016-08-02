#ifndef __ALGORITHM_VEC2I_H__
#define __ALGORITHM_VEC2I_H__
/************************************************
类名:整型Vec2
功能:整数向量
备注:无
************************************************/
class Vec2i
{
public:
	int x;
	int y;
	Vec2i(){}
	~Vec2i(){}
	Vec2i(long xx, long yy)
	{
		x = xx; y = yy;
	}
	Vec2i operator +(const Vec2i &c)
	{
		Vec2i p;
		p.x = x + c.x; p.y = y + c.y;
		return p;
	}
	Vec2i operator -(const Vec2i &c)
	{
		Vec2i p;
		p.x = x - c.x; p.y = y - c.y;
		return p;
	}
	Vec2i operator *(const int &c)
	{
		Vec2i p;
		p.x = x * c; p.y = y * c;
		return p;
	}
	bool operator ==(Vec2i const &p)
	{
		if (p.x == x&&p.y == y)
			return true;
		return false;
	}
};

#endif