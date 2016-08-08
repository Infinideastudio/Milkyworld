/*
* Milkyworld: A free game similar to “The Blockheads”.
* Copyright (C) 2016 Infinideas
*
* This file is part of Milkyworld.
* Milkyworld is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Milkyworld is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with Milkyworld.  If not, see <http://www.gnu.org/licenses/>.
*/
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
	//根据坐标获取block的碰撞箱
	MyRectangle hit_box(Vec2i _location);
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