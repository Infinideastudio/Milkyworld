#include "WorldMob.h"
/************************************************
������:player�ຯ��
����:���ڳ�ʼ���������ݣ������������磬��ʼ����ʾ��
��ע:
************************************************/
//���þ�������
void Player::set_location(Vec2 _location)
{
	location = _location;
	touch_box = MyRectangle(location+size/2,location-size/2);
}