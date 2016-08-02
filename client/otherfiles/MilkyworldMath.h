#ifndef __MILKYWORLDMATH_H__
#define __MILKYWORLDMATH_H__
#include <algorithm>
#include "cocos2d.h"
using namespace std;
using namespace cocos2d;
/************************************************
类名:MyLine
功能:直线
备注:无
************************************************/
class MyLine
{
public:
	MyLine(){}
	~MyLine(){}
	MyLine (Vec2 ul, Vec2 dr)
	{
		ul_point = ul;
		dr_point = dr;
	}
	Vec2 ul_point;
	Vec2 dr_point;
};
/************************************************
类名:MyRectangle
功能:矩形和碰撞检测
备注:无
************************************************/
class MyRectangle
{
public:
	MyRectangle(){}
	~MyRectangle(){}
	MyRectangle(Vec2 ul, Vec2 dr)
	{
		ul_point = ul;
		dr_point = dr;
		up_line = MyLine(Vec2(ul.x+5, ul.y), Vec2(dr.x-5, ul.y));
		down_line = MyLine(Vec2(ul.x+5, dr.y), Vec2(dr.x-5, dr.y));
		left_line = MyLine(Vec2(ul.x, ul.y-10), Vec2(ul.x, dr.y+10));
		right_line = MyLine(Vec2(dr.x, ul.y-10), Vec2(dr.x, dr.y+10));
	}
	//判断两个矩形是否相交
	bool is_touch(MyRectangle rec)
	{
		Vec2 max_point = Vec2(max(ul_point.x, rec.ul_point.x), min(ul_point.y, rec.ul_point.y));
		Vec2 min_point = Vec2(min(dr_point.x, rec.dr_point.x), max(dr_point.y, rec.dr_point.y));
		if (max_point.x <= min_point.x&&max_point.y >= min_point.y) return true;
		return false;
	}
	//求有向面积
	float get_area(Vec2 a0, Vec2 a1, Vec2 a2)
	{
		float s = a0.x*a1.y + a2.x*a0.y + a1.x*a2.y - a2.x*a1.y - a0.x*a2.y - a1.x*a0.y;
		return s;
	}
	//判断矩形和线段是否相交
	bool touch_line(MyLine line)
	{
		Vec2 A, B, C, D;
		MyLine this_line[4] = { up_line, down_line, left_line, right_line };
		C = line.ul_point;//start2
		D = line.dr_point;//end2
		//分别判断四个边与目标线段是否相交
		for (int i = 0; i <= 3; i++)
		{
			A = this_line[i].ul_point;//start1
			B = this_line[i].dr_point;//end1
			float s1 = get_area(A, B, C);
			float s2 = get_area(A, B, D);
			float s3 = get_area(C, D, A);
			float s4 = get_area(C, D, B);
			if (s1*s2 <= 0 && s3*s4 <= 0)
				return true;
		}
		if (ul_point.x <= line.ul_point.x&&line.ul_point.x <= dr_point.x&&dr_point.y <= line.ul_point.y&&line.ul_point.y <= ul_point.y)
			return true;
		if (ul_point.x <= line.dr_point.x&&line.dr_point.x <= dr_point.x&&dr_point.y <= line.dr_point.y&&line.dr_point.y <= ul_point.y)
			return true;
		return false;
	}
	//相交部分大小
	Vec2 overlap_size(MyRectangle rec)
	{
		Vec2 max_point = Vec2(max(ul_point.x, rec.ul_point.x), min(ul_point.y, rec.ul_point.y));
		Vec2 min_point = Vec2(min(dr_point.x, rec.dr_point.x), max(dr_point.y, rec.dr_point.y));
		return Vec2(min_point.x - max_point.x, max_point.y - min_point.y);
	}
	//四条边
	MyLine up_line;
	MyLine down_line;
	MyLine left_line;
	MyLine right_line;
	Vec2 ul_point;//左上角
	Vec2 dr_point;//右下角
private:
	
};
/************************************************
类名:perlin noise
功能:产生柏林噪声
备注:无
************************************************/
class PerlinNoise
{
public:
	double frequency;
	double amplitude;//幅度，可改，越大地形高度变化越大
	unsigned long long seed;
	double Noise(int x)//随机数发生器(未经过处理)
	{
		x = (x << 13) ^ x;
		return 1.0 - ((x * (x * x * seed + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0 + 1;
	}
	double smoothedNoise(double x)//平滑噪声(取平均值)
	{
		return Noise(x) / 2 + Noise(x - 1) / 4 + Noise(x + 1) / 4;
	}
	double interpolate(double a, double b, double x)//线性插值函数
	{
		return a*(1 - x) + b*x;
	}
	double interpolatedNoise(double x)//插值噪声
	{
		int int_x = int(x);
		double fractional_x = x - int_x;
		double v1 = smoothedNoise(int_x);
		double v2 = smoothedNoise(int_x + 1);
		return interpolate(v1, v2, fractional_x);
	}
	double perlin_noise(double x)//最终函数,传入x返回对应的y
	{
		double total = 0;
		double freq = frequency;
		double ampl = amplitude;
		double blockSize = 1;//每个格子的大小，可改
		for (int i = 0; i <= 4; i++) 
		{
			total += interpolatedNoise(x*freq)*ampl;
			freq *= 2; ampl /= 2.0;
		}
		return int(total * 5 * blockSize - amplitude*8);
	}
};
/************************************************
类名:长整型Vec2
功能:整数向量
备注:无
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
	Vec2l operator *(const long long &c)
	{
		Vec2l p;
		p.x = x * c; p.y = y * c;
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