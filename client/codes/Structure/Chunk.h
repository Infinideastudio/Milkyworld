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
#ifndef __STRUCTURE_CHUNK_H__
#define __STRUCTURE_CHUNK_H__
#include "FrontBlock.h"
#include "MidBlock.h"
#include "BackBlock.h"
#include "..\Algorithm\AllAlgorithms.h"
#include "cocos2d.h"
using namespace cocos2d;
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

#endif