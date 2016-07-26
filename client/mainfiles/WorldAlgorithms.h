#ifndef __WORLDALGORITHMS_H__
#define __WORLDALGORITHMS_H__
#include "cocos2d.h"
#include "WorldStructure.h"
#include <.\otherfiles\MilkyworldMath.h>
#include <vector>
USING_NS_CC;
/************************************************
����:�����
����:���ڸ���UI����
��ע:��
************************************************/
class UICamera
{
public:
	Vec2 location;
};
/************************************************
����:UIblock
����:����UI��ʾblock 
��ע:��
************************************************/
class UIBlock
{
public:
	Sprite *front_sprite;
	Sprite *mid_sprite;
	Sprite *back_sprite;
	//����ʾ��chunk����
	Vec2i chunk_location;
	//����ʾ��block��chunk�еı��
	Vec2i block_index;
	Vec2 get_position(); 
	void set_position(Vec2 _position);
	void create_sprite();
	void set_front_block(FrontBlock _block);
	void set_mid_block(MidBlock _block);
	void set_back_block(BackBlock _block);
private:
	Vec2 position;
	FrontBlock front_block;
	MidBlock mid_block;
	BackBlock back_block;
};

/************************************************
�����ռ�:�㷨�ñ���
����:�洢�㷨�ñ���
��ע:��
************************************************/
namespace AlgorithmVar
{
	const Vec2 delta[4] = { Vec2(0, 1), Vec2(0, -1), Vec2(-1, 0), Vec2(1, 0)};
}
/************************************************
������:����ת������
����:�������͵�ת��
��ע:��
************************************************/
string int_2_string(int i);
double string_2_double(string i);
bool string_2_bool(string i);
int string_2_int(string i);
#endif