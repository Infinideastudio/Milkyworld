#ifndef __STRUCTURE_FRONTBLOCK_H__
#define __STRUCTURE_FRONTBLOCK_H__
#include "Block.h"
#include "FrontBlockType.h"
/************************************************
����:ǰ������
����:��ʾһ������
��ע:��ʾ����ǰ��ķ���
************************************************/
class FrontBlock :public Block//ǰ������
{
public:
	//��ײ��
	bool enabled_touch;
	FrontBlockType type;
	//MyRectangle hit_box;
	//void set_touch_box(MyRectangle _touch_box);
};
#endif