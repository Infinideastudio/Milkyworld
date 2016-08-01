#ifndef __MILKYWORLDMATH_H__
#define __MILKYWORLDMATH_H__
#include <algorithm>
using namespace std;
/************************************************
����:MyRectangle
����:���κ���ײ���
��ע:��
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
	}
	//�ж����������Ƿ��ཻ
	bool is_touch(MyRectangle rec)
	{
		Vec2 max_point = Vec2(max(ul_point.x, rec.ul_point.x), max(ul_point.y, rec.ul_point.y));
		Vec2 min_point = Vec2(min(dr_point.x, rec.dr_point.x), min(dr_point.y, rec.dr_point.y));
		if (max_point.x < min_point.x&&max_point.y < min_point.y) return true;
		return false;
	}
	//�ཻ���ִ�С
	Vec2 overlap_size(MyRectangle rec)
	{
		Vec2 max_point = Vec2(max(ul_point.x, rec.ul_point.x), max(ul_point.y, rec.ul_point.y));
		Vec2 min_point = Vec2(min(dr_point.x, rec.dr_point.x), min(dr_point.y, rec.dr_point.y));
		return Vec2(min_point - max_point);
	}
private:
	Vec2 ul_point;//���Ͻ�
	Vec2 dr_point;//���½�
};
/************************************************
����:perlin noise
����:������������
��ע:��
************************************************/
class PerlinNoise
{
public:
	double frequency;
	double amplitude;//���ȣ��ɸģ�Խ����θ߶ȱ仯Խ��
	unsigned long long seed;
	double Noise(int x)//�����������(δ��������)
	{
		x = (x << 13) ^ x;
		return 1.0 - ((x * (x * x * seed + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0 + 1;
	}
	double smoothedNoise(double x)//ƽ������(ȡƽ��ֵ)
	{
		return Noise(x) / 2 + Noise(x - 1) / 4 + Noise(x + 1) / 4;
	}
	double interpolate(double a, double b, double x)//���Բ�ֵ����
	{
		return a*(1 - x) + b*x;
	}
	double interpolatedNoise(double x)//��ֵ����
	{
		int int_x = int(x);
		double fractional_x = x - int_x;
		double v1 = smoothedNoise(int_x);
		double v2 = smoothedNoise(int_x + 1);
		return interpolate(v1, v2, fractional_x);
	}
	double perlin_noise(double x)//���պ���,����x���ض�Ӧ��y
	{
		double total = 0;
		double freq = frequency;
		double ampl = amplitude;
		double blockSize = 1;//ÿ�����ӵĴ�С���ɸ�
		for (int i = 0; i <= 4; i++) 
		{
			total += interpolatedNoise(x*freq)*ampl;
			freq *= 2; ampl /= 2.0;
		}
		return int(total * 5 * blockSize - amplitude*8);
	}
};
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