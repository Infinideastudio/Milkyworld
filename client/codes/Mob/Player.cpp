#include "Player.h"
/************************************************
函数:设置绝对坐标
功能:设置玩家的绝对坐标
备注:
************************************************/
void Player::set_location(Vec2 _location)
{
	location = _location;
	touch_box = MyRectangle(Vec2(location.x - size.x / 2, location.y + size.y / 2)
		, Vec2(location.x + size.x / 2, location.y - size.y / 2));
}