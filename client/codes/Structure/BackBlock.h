#ifndef __STRUCTURE_BACKBLOCK_H__
#define __STRUCTURE_BACKBLOCK_H__
#include "Block.h"
#include "BackBlockType.h"
/************************************************
类名:后景方块
功能:表示一个方块
备注:装饰方块
************************************************/
class BackBlock :public Block
{
public:
	BackBlockType type;
};
#endif