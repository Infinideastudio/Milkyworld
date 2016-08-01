#ifndef __WORLDALGORITHMS_H__
#define __WORLDALGORITHMS_H__
#include "cocos2d.h"
#include "WorldStructure.h"
#include <.\otherfiles\MilkyworldMath.h>
#include <vector>
USING_NS_CC;
/************************************************
类名:摄像机
功能:用于辅助UI计算
备注:无
************************************************/
class UICamera
{
public:
	Vec2 location;
};
/************************************************
类名:UIblock
功能:用于UI显示block 
备注:无
************************************************/
class UIBlock
{
public:
	Sprite *front_sprite;
	Sprite *mid_sprite;
	Sprite *back_sprite;
	//所显示的chunk坐标
	Vec2i chunk_location;
	//所显示的block在chunk中的标记
	Vec2i block_index;
	//碰撞箱
	MyRectangle touch_box;
	//实际大小
	Vec2 size;
	//由于地图左右循环的特性，UI方块的位置不能完全按照坐标公式来计算
	//is_borrow变量代表该UI方块所对应的方块处于地图以外，因此借用地图另一端的方块显示。
	//-1代表chunk<0，借用地图最右边的方块
	//1代表chunk>size，借用地图最左边的方块
	//0代表不借用方块。
	int is_borrow;
	void init_size(Vec2 _size);
	Vec2 get_position(); 
	void set_position(Vec2 _position);
	void create_sprite();
	void set_front_block(FrontBlock _block);
	void set_mid_block(MidBlock _block);
	void set_back_block(BackBlock _block);
private:
	Vec2 position;
	FrontBlock front_block;
	MidBlock mid_block;
	BackBlock back_block;
};
/************************************************
命名空间:算法用变量
功能:存储算法用变量
备注:无
************************************************/
namespace AlgorithmVar
{
	const Vec2 delta[4] = { Vec2(0, 1), Vec2(0, -1), Vec2(-1, 0), Vec2(1, 0) };
}
/************************************************
命名空间:MilkyWorld
功能:一些游戏的全局变量
备注:无
************************************************/
namespace world_vars
{
	//游戏加载进度
	extern int game_load_schedule;
}
/************************************************
函数块:类型转换函数
功能:常用类型的转换
备注:无
************************************************/
string int_2_string(int i);
double string_2_double(string i);
bool string_2_bool(string i);
int string_2_int(string i);
#endif