#include"MyRectangle.h"
/************************************************
函数名:is_touch
功能:判断两个矩形是否相交
备注:无
************************************************/
bool MyRectangle::is_touch(MyRectangle rec)
{
	Vec2 max_point = Vec2(max(ul_point.x, rec.ul_point.x), min(ul_point.y, rec.ul_point.y));
	Vec2 min_point = Vec2(min(dr_point.x, rec.dr_point.x), max(dr_point.y, rec.dr_point.y));
	if (max_point.x <= min_point.x&&max_point.y >= min_point.y) return true;
	return false;
}
/************************************************
函数名:get_area
功能:求有向面积
备注:无
************************************************/
float MyRectangle::get_area(Vec2 a0, Vec2 a1, Vec2 a2)
{
	float s = a0.x*a1.y + a2.x*a0.y + a1.x*a2.y - a2.x*a1.y - a0.x*a2.y - a1.x*a0.y;
	return s;
}
/************************************************
函数名:touch_line
功能:判断矩形和线段是否相交
备注:无
************************************************/
bool MyRectangle::touch_line(MyLine line)
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
/************************************************
函数名:overlap_size
功能:相交部分大小
备注:无
************************************************/
Vec2 MyRectangle::overlap_size(MyRectangle rec)
{
	Vec2 max_point = Vec2(max(ul_point.x, rec.ul_point.x), min(ul_point.y, rec.ul_point.y));
	Vec2 min_point = Vec2(min(dr_point.x, rec.dr_point.x), max(dr_point.y, rec.dr_point.y));
	return Vec2(min_point.x - max_point.x, max_point.y - min_point.y);
}