#ifndef __STRUCTURE_BACKBLOCKTYPE_H__
#define __STRUCTURE_BACKBLOCKTYPE_H__
#include "..\Algorithm\Definition.h"
/************************************************
枚举类名:后景方块类型
功能:表示方块的类型
备注:后景方块仅仅用来装饰，没有任何实际作用，在2d视角下不启用，仅做备用。
************************************************/
enum class BackBlockType :ushort
{
	vacuum,//真空0
	air,//空气1
	rock,//岩石2
	stone,//圆石3
	dirt,//泥土4
	grass,//草地5
};
#endif