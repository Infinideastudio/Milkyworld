#include "WorldStructure.h"
#include "WorldAlgorithms.h"
#include "cocos2d.h"
#include <fstream>
using namespace std;
/************************************************
函数块:chunk类的函数定义
功能:定义chunk类的函数
备注:无
************************************************/
//设置前景方块
void Chunk::set_front_block(Vec2i position, FrontBlock _front_block)
{
	int _x = position.x * length_of_block_size + position.y;
	front_block[_x] = _front_block;
}
//获取前景方块
FrontBlock& Chunk::get_front_block(Vec2i location)
{
	int _x = location.x * length_of_block_size + location.y;
	return front_block[_x];
}
//设置chunk在地图上的绝对坐标
void Chunk::set_location(Vec2i p)
{
	location = p;
}
//获取chunk在地图上的绝对坐标
Vec2i Chunk::get_location()
{
	return location;
}
//保存行星数据到二进制文件
void Chunk::save_chunk(string world_name, string planet_name)
{
	ofstream file;
	//string file_path = ".\\save\\" + world_name + "\\" + planet_name
	//	+ "\\chunk" + int_2_string(location.x) + "_"
	//	+ int_2_string(location.y) + ".mwc";
	string file_path = "D:\\#program set\\Milkyworld\\client\\proj.win32\\Debug.win32\\save\\"
			+ world_name + "\\" + planet_name
			+ "\\chunk" + int_2_string(location.x) + "_"
			+ int_2_string(location.y) + ".mwc";
	file.open(file_path.c_str(), ios::out|ios::binary);
	//逐个输出block的数据
	for (int i = 0; i < block_size_of_chunk; i++)
	{
		file << static_cast<ushort>(front_block[i].type) << " " << front_block[i].enabled_touch << endl;
		file << static_cast<ushort>(mid_block[i].type) << endl;
	}

	file.close();
}
//从二进制文件读取chunk数据
void Chunk::load_chunk(string world_name, string planet_name)
{
	ifstream file;
	//string file_path = ".\\save\\" + world_name + "\\" + planet_name
	//	+ "\\chunk" + int_2_string(location.x) + "_"
	//	+ int_2_string(location.y) + ".mwc";
	string file_path = "D:\\#program set\\Milkyworld\\client\\proj.win32\\Debug.win32\\save\\"
		+ world_name + "\\" + planet_name
		+ "\\chunk" + int_2_string(location.x) + "_"
		+ int_2_string(location.y) + ".mwc";
	file.open(file_path.c_str(), ios::in | ios::binary);
	//逐个读入block的数据
	for (int i = 0; i < block_size_of_chunk; i++)
	{
		ushort front_type, mid_type;
		file >> front_type >> front_block[i].enabled_touch;
		file >> mid_type;
		front_block[i].type = static_cast<FrontBlockType>(front_type);
		mid_block[i].type = static_cast<MidBlockType>(mid_type);
	}
	file.close();
}
/************************************************
函数块:Block和其子类的函数定义
功能:Block和其子类的函数定义
备注:无
************************************************/

/************************************************
函数块:Planet类的函数定义
功能:定义Planet类的函数
备注:无
************************************************/
//设置地图中chunk的数量
void Planet::set_chunk_size(Vec2i _size)
{
	chunk_size = _size;
	chunk.resize(_size.x*_size.y);
}
//获取地图中chunk的数量
Vec2i Planet::get_chunk_size()
{
	return chunk_size;
}
//根据绝对坐标找chunk的ID
int Planet::get_chunk_id(Vec2i _location)
{
	return _location.x*chunk_size.y + _location.y;
	/*for (int i = 0; i < chunk.size(); i++)
		if (chunk[i].get_location() == _location)
			return i;
	return -1;*/
}
//根据绝对坐标找chunk
Chunk& Planet::get_chunk(Vec2i _location)
{
	return chunk[get_chunk_id(_location)];
}
//直接操作block
FrontBlock& Planet::front_block(Vec2i _location)
{
	Vec2i chunk_location = Vec2i(_location.x / length_of_block_size, _location.y / length_of_block_size);
	Vec2i block_location = Vec2i(_location.x % length_of_block_size, _location.y % length_of_block_size);
	int chunk_index = chunk_location.x*chunk_size.y + chunk_location.y;
	int block_index = block_location.x*length_of_block_size + block_location.y;
	return chunk[chunk_index].front_block[block_index];
}
//设置地形种子
void Planet::set_terrain_seed(ull seed)
{
	terrain_seed = seed;
	noise_perducer.seed = seed;
}
//生成地形
void Planet::generate_terrain()
{
	noise_perducer.frequency = 0.03;
	noise_perducer.amplitude = 3;
	int now = sea_level;//当前高度
	int target = sea_level;//目标高度
	int height;
	height = noise_perducer.perlin_noise(0) + sea_level;
	for (int i = 0; i < get_chunk_size().x*length_of_block_size; i++)
	{
		world_vars::game_load_schedule = i * 100 / (get_chunk_size().x*length_of_block_size);
		//if (height >= sea_level && height < sea_level + 3)//平原
		//{
		//	noise_perducer.frequency = 0.03;
		//	noise_perducer.amplitude = 1;
		//	sea_level = 768;
		//}
		//else
		//if (height >= sea_level + 3 && height < sea_level + 20)//丘陵
		//{
		//	noise_perducer.frequency = 0.05;
		//	noise_perducer.amplitude = 3;
		//	sea_level = 768 + 3;
		//}
		//else
		//if (height >= sea_level + 20)//山地
		//{
		//	noise_perducer.frequency = 0.5;//幅度变化,频率加大
		//	noise_perducer.amplitude = 6;
		//	sea_level = 768 + 20;
		//}
		height = noise_perducer.perlin_noise(i) + sea_level;
		for (int j = 0; j < get_chunk_size().y*length_of_block_size; j++)
		{
			if (j <= sea_level && j>height)
			{
				if (sea_level = 768)
					front_block(Vec2i(i, j)).type = FrontBlockType::water;
				else
					front_block(Vec2i(i, j)).type = FrontBlockType::dirt;
				front_block(Vec2i(i, j)).enabled_touch = true;
				continue;
			}
			else
			if (j < height||j<sea_level)
			{
				front_block(Vec2i(i, j)).type = FrontBlockType::dirt;
				front_block(Vec2i(i, j)).enabled_touch = true;
			}
			else
			if (j == height)
			{
				front_block(Vec2i(i, j)).type = FrontBlockType::grass;
				front_block(Vec2i(i, j)).enabled_touch = true;
			}
			else
			{
				front_block(Vec2i(i, j)).type = FrontBlockType::air;
				front_block(Vec2i(i, j)).enabled_touch = false;
			}
		}
	}
}