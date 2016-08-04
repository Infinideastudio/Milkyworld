#ifndef __STRUCTURE_PLANET_H__
#define __STRUCTURE_PLANET_H__
#include "CelestialBody.h"
#include "Chunk.h"

/************************************************
����:����
����:һ������
��ע:��ͼ��Сn*64�����飬(16*n)*1024������
n*16�������ֱ��
************************************************/
class Planet :public CelestialBody
{
public:
	string name;
	//��ƽ��߶�
	int sea_level;
	//�������ٶ�
	float gravitational_acceleration;
	//���õ�ͼ��С
	void set_chunk_size(Vec2i _size);
	//��ȡ��ͼ��С
	Vec2i get_chunk_size();
	//���ݾ���������chunk
	Chunk& get_chunk(Vec2i _location);
	//���ݾ���������chunk��ID
	int get_chunk_id(Vec2i _location);
	//������chunkֱ�Ӳ���block
	FrontBlock& front_block(Vec2i _location);
	//���õ�������
	void set_terrain_seed(ull seed);
	//���ɵ���
	void generate_terrain();
private:
	Vec2i chunk_size;
	ull terrain_seed;
	PerlinNoise noise_perducer;
	vector<Chunk> chunk;//���ص�����
};
#endif