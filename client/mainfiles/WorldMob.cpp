#include "WorldMob.h"
/************************************************
函数块:player类函数
功能:用于初始化各项内容，包括加载世界，初始化显示等
备注:
************************************************/
//设置绝对坐标
void Player::set_location(Vec2 _location)
{
	location = _location;
	touch_box = MyRectangle(Vec2(location.x - size.x / 2, location.y + size.y / 2)
		, Vec2(location.x + size.x / 2, location.y - size.y / 2));
}