#ifndef __STRUCTURE_ITEMTYPE_H__
#define __STRUCTURE_ITEMTYPE_H__
#include "..\Algorithm\Definition.h"
/************************************************
枚举类名:物体类型
功能:表示物体的类型
备注:
************************************************/
enum class ItemType :ushort
{
	vacuum,//真空0
	rock,//岩石1
	stone,//圆石2
	dirt,//泥土3
	grass,//草地4
};
#endif