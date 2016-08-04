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