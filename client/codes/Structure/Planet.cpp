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
#include "Planet.h"
/************************************************
������:set_chunk_size
����:���õ�ͼ��chunk������
��ע:��
************************************************/
void Planet::set_chunk_size(Vec2i _size)
{
	chunk_size = _size;
	chunk.resize(_size.x*_size.y);
}
/************************************************
������:get_chunk_size
����:��ȡ��ͼ��chunk������
��ע:��
************************************************/
Vec2i Planet::get_chunk_size()
{
	return chunk_size;
}
/************************************************
������:get_chunk_id
����:���ݾ���������chunk��ID
��ע:��
************************************************/
int Planet::get_chunk_id(Vec2i _location)
{
	return _location.x*chunk_size.y + _location.y;
	/*for (int i = 0; i < chunk.size(); i++)
	if (chunk[i].get_location() == _location)
	return i;
	return -1;*/
}
/************************************************
������:get_chunk
����:���ݾ���������chunk
��ע:��
************************************************/
Chunk& Planet::get_chunk(Vec2i _location)
{
	return chunk[get_chunk_id(_location)];
}
/************************************************
������:front_block
����:ֱ�Ӳ���block
��ע:��
************************************************/
FrontBlock& Planet::front_block(Vec2i _location)
{
	Vec2i __location = _location;
	int world_block_width = chunk_size.x *length_of_block_size;
	if (__location.x >= world_block_width)__location.x -= world_block_width;
	else if (__location.x < 0)__location.x += world_block_width;
	Vec2i chunk_location = Vec2i(__location.x / length_of_block_size, __location.y / length_of_block_size);
	Vec2i block_location = Vec2i(__location.x % length_of_block_size, __location.y % length_of_block_size);
	int chunk_index = chunk_location.x*chunk_size.y + chunk_location.y;
	int block_index = block_location.x*length_of_block_size + block_location.y;
	return chunk[chunk_index].front_block[block_index];
}
/************************************************
������:hit_box
����:��ȡ������ײ��
��ע:����Ϊ��������
************************************************/
MyRectangle Planet::hit_box(Vec2i _location)
{
	return MyRectangle(Vec2(_location.x - 0.5, _location.y + 0.5)*picture_length, Vec2(_location.x + 0.5, _location.y - 0.5)*picture_length);
}
/************************************************
������:set_terrain_seed
����:���õ�������
��ע:��
************************************************/
void Planet::set_terrain_seed(ull seed)
{
	terrain_seed = seed;
	noise_perducer.seed = seed;
}
/************************************************
������:generate_terrain
����:���ɵ���
��ע:��
************************************************/
void Planet::generate_terrain()
{
	noise_perducer.frequency = 0.03;
	noise_perducer.amplitude = 3;
	int now = sea_level;//��ǰ�߶�
	int target = sea_level;//Ŀ��߶�
	int height;
	height = noise_perducer.perlin_noise(0) + sea_level;
	for (int i = 0; i < get_chunk_size().x*length_of_block_size; i++)
	{
		world_vars::game_load_schedule = i * 100 / (get_chunk_size().x*length_of_block_size);
		//if (height >= sea_level && height < sea_level + 3)//ƽԭ
		//{
		//	noise_perducer.frequency = 0.03;
		//	noise_perducer.amplitude = 1;
		//	sea_level = 768;
		//}
		//else
		//if (height >= sea_level + 3 && height < sea_level + 20)//����
		//{
		//	noise_perducer.frequency = 0.05;
		//	noise_perducer.amplitude = 3;
		//	sea_level = 768 + 3;
		//}
		//else
		//if (height >= sea_level + 20)//ɽ��
		//{
		//	noise_perducer.frequency = 0.5;//���ȱ仯,Ƶ�ʼӴ�
		//	noise_perducer.amplitude = 6;
		//	sea_level = 768 + 20;
		//}
		height = noise_perducer.perlin_noise(i) + sea_level;
		for (int j = 0; j < get_chunk_size().y*length_of_block_size; j++)
		{
			//front_block(Vec2i(i, j)).touch_box = MyRectangle(Vec2(i, j + 1)*picture_length, Vec2(i + 1, j)*picture_length);
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
			if (j < height || j<sea_level)
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