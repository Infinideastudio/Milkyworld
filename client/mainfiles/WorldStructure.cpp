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
Chunk Planet::get_chunk(Vec2i _location)
{
	return chunk[get_chunk_id(_location)];
}
