/*关于方块的类和函数声明头文件*/
#ifndef __WORLDSTRUCTURE_H__
#define __WORLDSTRUCTURE_H__
/************************************************/
//文件引用
/************************************************/
#include "Definition.h"
#include "cocos2d.h"
#include <vector>
#include <.\otherfiles\MilkyworldMath.h>
using namespace std;
USING_NS_CC;
/************************************************
类名:方块
功能:表示一个方块
备注:方块类型定义见"definition.h"
************************************************/
class Block
{
public: 
};
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
	//void set_touch_box(MyRectangle _touch_box);
};
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
/************************************************
类名:区块
功能:16*16大小的方块阵列
备注:每个位置有三个处在不同图层上的方块，最前面的为0，
       中间的为1，最后面的为2。
************************************************/
class Chunk
{
public:
	//前中后景方块
	FrontBlock front_block[block_size_of_chunk];
	MidBlock mid_block[block_size_of_chunk];
	BackBlock back_block[block_size_of_chunk];
	//可见性，是否在屏幕内
	bool visible;
	//加载chunk函数
	void load();
	//设置前景方块
	void set_front_block(Vec2i position, FrontBlock front_block);
	//获取前景方块
	FrontBlock& get_front_block(Vec2i location);
	//设置chunk在planet里的绝对坐标
	void set_location(Vec2i p);
	//获取chunk在planet里的绝对坐标
	Vec2i get_location();
	//保存chunk数据
	void save_chunk(string world_name, string planet_name);
	//读取chunk数据
	void load_chunk(string world_name, string planet_name);
private:
	Vec2i location;//chunk的绝对坐标
};
/************************************************
类名:天体
功能:一个天体
备注:分为行星/气态巨星/小行星/恒星/白矮星/中子星/黑洞等
************************************************/
class CelestialBody
{
public:
private:
};
/************************************************
类名:行星
功能:一个行星
备注:地图大小n*64个区块，(16*n)*1024个方块
        n*16是星球的直径
************************************************/
class Planet :public CelestialBody
{
public:
	string name;
	//海平面高度
	int sea_level;
	//重力加速度
	float gravitational_acceleration;
	//设置地图大小
	void set_chunk_size(Vec2i _size);
	//获取地图大小
	Vec2i get_chunk_size();
	//根据绝对坐标找chunk
	Chunk& get_chunk(Vec2i _location);
	//根据绝对坐标找chunk的ID
	int get_chunk_id(Vec2i _location);
	//不经过chunk直接操作block
	FrontBlock& front_block(Vec2i _location);
	//设置地形种子
	void set_terrain_seed(ull seed);
	//生成地形
	void generate_terrain();
private:
	Vec2i chunk_size;
	ull terrain_seed;
	PerlinNoise noise_perducer;
	vector<Chunk> chunk;//加载的区块
};

/************************************************
类名:世界
功能:一个世界
备注:包含许多星球，但一次只能加载一个
************************************************/
class World
{
public:
	Planet planet;
	string name;
private:
};
#endif
