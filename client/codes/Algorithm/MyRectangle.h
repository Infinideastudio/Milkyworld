#ifndef __ALGORITHM_MYRECTANGLE_H__
#define __ALGORITHM_MYRECTANGLE_H__
#include "cocos2d.h"
#include "MyLine.h"
USING_NS_CC;
using namespace std;
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
		up_line = MyLine(ul, Vec2(dr.x, ul.y));
		down_line = MyLine(Vec2(ul.x, dr.y), dr);
		left_line = MyLine(ul, Vec2(ul.x, dr.y));
		right_line = MyLine(Vec2(dr.x, ul.y), dr);
	}
	//判断两个矩形是否相交
	bool is_touch(MyRectangle rec);
	//求有向面积
	float get_area(Vec2 a0, Vec2 a1, Vec2 a2);
	//判断矩形和线段是否相交
	bool touch_line(MyLine line);
	//相交部分大小
	Vec2 overlap_size(MyRectangle rec);
	//四条边
	MyLine up_line;
	MyLine down_line;
	MyLine left_line;
	MyLine right_line;
	Vec2 ul_point;//左上角
	Vec2 dr_point;//右下角
private:

};
#endif