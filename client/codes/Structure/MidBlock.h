#ifndef __STRUCTURE_MIDBLOCK_H__
#define __STRUCTURE_MIDBLOCK_H__
#include "Block.h"
#include "MidBlockType.h"
/************************************************
����:�о�����
����:��ʾһ������
��ע:��ʾ���м�ķ���
************************************************/
class MidBlock :public Block
{
public:
	MidBlockType type;
};
#endif