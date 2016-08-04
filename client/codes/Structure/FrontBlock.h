#ifndef __STRUCTURE_FRONTBLOCK_H__
#define __STRUCTURE_FRONTBLOCK_H__
#include "Block.h"
#include "FrontBlockType.h"
/************************************************
类名:前景方块
功能:表示一个方块
备注:显示在最前面的方块
************************************************/
class FrontBlock :public Block//前景方块
{
public:
	//碰撞箱
	bool enabled_touch;
	FrontBlockType type;
	//MyRectangle hit_box;
	//void set_touch_box(MyRectangle _touch_box);
};
#endif