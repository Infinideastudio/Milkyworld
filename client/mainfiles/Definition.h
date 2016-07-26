/*关于定义和常数的头文件*/
#ifndef __DEFINITION_H__
#define __DEFINITION_H__
/************************************************/
//宏定义
/************************************************/
#define length_of_block_size  16
#define block_size_of_chunk  256
#define picture_length  32
#define uint  unsigned int
#define ushort  unsigned short
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
	hydrogen,//氢气6
};
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