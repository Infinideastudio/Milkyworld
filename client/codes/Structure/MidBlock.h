#ifndef __STRUCTURE_MIDBLOCK_H__
#define __STRUCTURE_MIDBLOCK_H__
#include "Block.h"
#include "MidBlockType.h"
/************************************************
类名:中景方块
功能:表示一个方块
备注:显示在中间的方块
************************************************/
class MidBlock :public Block
{
public:
	MidBlockType type;
};
#endif