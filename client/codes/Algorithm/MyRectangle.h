#ifndef __ALGORITHM_MYRECTANGLE_H__
#define __ALGORITHM_MYRECTANGLE_H__
#include "cocos2d.h"
#include "MyLine.h"
USING_NS_CC;
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
		up_line = MyLine(ul, Vec2(dr.x, ul.y));
		down_line = MyLine(Vec2(ul.x, dr.y), dr);
		left_line = MyLine(ul, Vec2(ul.x, dr.y));
		right_line = MyLine(Vec2(dr.x, ul.y), dr);
	}
	//�ж����������Ƿ��ཻ
	bool is_touch(MyRectangle rec);
	//���������
	float get_area(Vec2 a0, Vec2 a1, Vec2 a2);
	//�жϾ��κ��߶��Ƿ��ཻ
	bool touch_line(MyLine line);
	//�ཻ���ִ�С
	Vec2 overlap_size(MyRectangle rec);
	//������
	MyLine up_line;
	MyLine down_line;
	MyLine left_line;
	MyLine right_line;
	Vec2 ul_point;//���Ͻ�
	Vec2 dr_point;//���½�
private:

};
#endif