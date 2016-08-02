#ifndef __ALGORITHM_MYLINE_H__
#define __ALGORITHM_MYLINE_H__
#include "cocos2d.h"
USING_NS_CC;
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
	MyLine(Vec2 ul, Vec2 dr)
	{
		ul_point = ul;
		dr_point = dr;
	}
	Vec2 ul_point;
	Vec2 dr_point;
};
#endif