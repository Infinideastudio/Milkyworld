#ifndef __STRUCTURE_MIDBLOCKTYPE_H__
#define __STRUCTURE_MIDBLOCKTYPE_H__
#include "..\Algorithm\Definition.h"
/************************************************
枚举类名:中景方块类型
功能:表示方块的类型
备注:中景方块在后景方块上，存放没有碰撞箱的实体或者方块。
树干和树叶属于中景方块。
************************************************/
enum class MidBlockType :ushort
{
	_void,//空0
	wood,//原木1
	stone,//2
	dirt,//泥土3
	grass,//草地4
};
#endif