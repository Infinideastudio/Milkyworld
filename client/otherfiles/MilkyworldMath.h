#ifndef __MILKYWORLDMATH_H__
#define __MILKYWORLDMATH_H__
/************************************************
����:������Vec2
����:��������
��ע:��
************************************************/
class Vec2l
{
public:
	long long x;
	long long y;
	Vec2l(){}
	~Vec2l(){}
	Vec2l(long xx, long yy)
	{
		x = xx; y = yy;
	}
	Vec2l operator +(const Vec2l &c)
	{
		Vec2l p;
		p.x = x + c.x; p.y = y + c.y;
		return p;
	}
	Vec2l operator -(const Vec2l &c)
	{
		Vec2l p;
		p.x = x - c.x; p.y = y - c.y;
		return p;
	}
	bool operator ==(Vec2l const &p)
	{
		if (p.x == x&&p.y == y)
			return true;
		return false;
	}
};
/************************************************
����:����Vec2
����:��������
��ע:��
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
	bool operator ==(Vec2i const &p)
	{
		if (p.x == x&&p.y == y)
			return true;
		return false;
	}
};
#endif