#ifndef __MOB_MOB_H__
#define __MOB_MOB_H__
#include <vector>
#include "..\Algorithm\AllAlgorithms.h"
#include "cocos2d.h"
using namespace std;
USING_NS_CC;
/************************************************
����:Mob
����:����
��ע:��
************************************************/
class Mob
{
public:
	//Ѫ��
	int hp;
	//������
	int defence;
	//��С(����)
	Vec2 size;
	//������ײ��
	MyRectangle touch_box;
	//sprite
	Sprite* sprite;
	//�ŵ�
	bool touch_ground;
};
#endif