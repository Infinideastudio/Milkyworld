#include "Player.h"
/************************************************
����:���þ�������
����:������ҵľ�������
��ע:
************************************************/
void Player::set_location(Vec2 _location)
{
	location = _location;
	touch_box = MyRectangle(Vec2(location.x - size.x / 2, location.y + size.y / 2)
		, Vec2(location.x + size.x / 2, location.y - size.y / 2));
}