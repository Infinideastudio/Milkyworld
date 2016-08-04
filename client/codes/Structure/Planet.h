#ifndef __STRUCTURE_PLANET_H__
#define __STRUCTURE_PLANET_H__
#include "CelestialBody.h"
#include "Chunk.h"

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
#endif