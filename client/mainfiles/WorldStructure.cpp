#include "WorldStructure.h"
#include "WorldAlgorithms.h"
#include "cocos2d.h"
#include <fstream>
using namespace std;
/************************************************
������:chunk��ĺ�������
����:����chunk��ĺ���
��ע:��
************************************************/
//����ǰ������
void Chunk::set_front_block(Vec2i position, FrontBlock _front_block)
{
	int _x = position.x * length_of_block_size + position.y;
	front_block[_x] = _front_block;
}
//����chunk�ڵ�ͼ�ϵľ�������
void Chunk::set_location(Vec2i p)
{
	location = p;
}
//��ȡchunk�ڵ�ͼ�ϵľ�������
Vec2i Chunk::get_location()
{
	return location;
}
//�����������ݵ��������ļ�
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
	//������block������
	for (int i = 0; i < block_size_of_chunk; i++)
	{
		file << static_cast<ushort>(front_block[i].type) << " " << front_block[i].enabled_touch << endl;
		file << static_cast<ushort>(mid_block[i].type) << endl;
	}
	file.close();
}
//�Ӷ������ļ���ȡchunk����
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
	//�������block������
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
������:Block��������ĺ�������
����:Block��������ĺ�������
��ע:��
************************************************/

/************************************************
������:Planet��ĺ�������
����:����Planet��ĺ���
��ע:��
************************************************/
//���õ�ͼ��chunk������
void Planet::set_chunk_size(Vec2i _size)
{
	chunk_size = _size;
	chunk.resize(_size.x*_size.y);
}
//��ȡ��ͼ��chunk������
Vec2i Planet::get_chunk_size()
{
	return chunk_size;
}
//���ݾ���������chunk��ID
int Planet::get_chunk_id(Vec2i _location)
{
	return _location.x*chunk_size.y + _location.y;
	/*for (int i = 0; i < chunk.size(); i++)
		if (chunk[i].get_location() == _location)
			return i;
	return -1;*/
}
//���ݾ���������chunk
Chunk Planet::get_chunk(Vec2i _location)
{
	return chunk[get_chunk_id(_location)];
}
