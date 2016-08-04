#ifndef __STRUCTURE_FRONTBLOCKTYPE_H__
#define __STRUCTURE_FRONTBLOCKTYPE_H__
#include "..\Algorithm\Definition.h"
/************************************************
枚举类名:前景方块类型
功能:表示方块的类型
备注:前景方块可以设置碰撞箱，中小型植物以及气体都属于前景方块
************************************************/
enum class FrontBlockType : ushort
{
	vacuum,//真空0
	air,//空气1
	rock,//岩石2
	stone,//圆石3
	dirt,//泥土4
	grass,//草地5
	water,//水6
};
#endif