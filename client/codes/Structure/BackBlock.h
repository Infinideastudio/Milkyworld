#ifndef __STRUCTURE_BACKBLOCK_H__
#define __STRUCTURE_BACKBLOCK_H__
#include "Block.h"
#include "BackBlockType.h"
/************************************************
����:�󾰷���
����:��ʾһ������
��ע:װ�η���
************************************************/
class BackBlock :public Block
{
public:
	BackBlockType type;
};
#endif