/*
* Milkyworld: A free game similar to ��The Blockheads��.
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
	MyRectangle(Vec2 ul, Vec2 dr);
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