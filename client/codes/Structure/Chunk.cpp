/*
* Milkyworld: A free game similar to ��The Blockheads��.
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
#include "Chunk.h"
#include <vector>
#include <fstream>
using namespace std;
/************************************************
������:set_front_block
����:����ǰ������
��ע:��
************************************************/
void Chunk::set_front_block(Vec2i position, FrontBlock _front_block)
{
	int _x = position.x * length_of_block_size + position.y;
	front_block[_x] = _front_block;
}
/************************************************
������:get_front_block
����:��ȡǰ������
��ע:��
************************************************/
FrontBlock& Chunk::get_front_block(Vec2i location)
{
	int _x = location.x * length_of_block_size + location.y;
	return front_block[_x];
}
/************************************************
������:set_location
����:����chunk�ڵ�ͼ�ϵľ�������
��ע:��
************************************************/
void Chunk::set_location(Vec2i p)
{
	location = p;
}
/************************************************
������:get_location
����:��ȡchunk�ڵ�ͼ�ϵľ�������
��ע:��
************************************************/
Vec2i Chunk::get_location()
{
	return location;
}
/************************************************
������:save_chunk
����:����chunk���ݵ��������ļ�
��ע:��������ƴ洢�����Դ��󣬱��²�...
************************************************/
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
	file.open(file_path.c_str(), ios::out | ios::binary);
	//������block������
	for (int i = 0; i < block_size_of_chunk; i++)
	{
		file << static_cast<ushort>(front_block[i].type) << " " << front_block[i].enabled_touch << endl;
		file << static_cast<ushort>(mid_block[i].type) << endl;
	}
	file.close();
}
/************************************************
������:load_chunk
����:�Ӷ������ļ���ȡchunk����
��ע:��������ƶ�ȡ�����Դ��󣬱��²�...
************************************************/
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