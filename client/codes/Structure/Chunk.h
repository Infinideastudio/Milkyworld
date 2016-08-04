#ifndef __STRUCTURE_CHUNK_H__
#define __STRUCTURE_CHUNK_H__
#include "FrontBlock.h"
#include "MidBlock.h"
#include "BackBlock.h"
#include "..\Algorithm\AllAlgorithms.h"
#include "cocos2d.h"
using namespace cocos2d;
/************************************************
����:����
����:16*16��С�ķ�������
��ע:ÿ��λ�����������ڲ�ͬͼ���ϵķ��飬��ǰ���Ϊ0��
�м��Ϊ1��������Ϊ2��
************************************************/
class Chunk
{
public:
	//ǰ�к󾰷���
	FrontBlock front_block[block_size_of_chunk];
	MidBlock mid_block[block_size_of_chunk];
	BackBlock back_block[block_size_of_chunk];
	//�ɼ��ԣ��Ƿ�����Ļ��
	bool visible;
	//����chunk����
	void load();
	//����ǰ������
	void set_front_block(Vec2i position, FrontBlock front_block);
	//��ȡǰ������
	FrontBlock& get_front_block(Vec2i location);
	//����chunk��planet��ľ�������
	void set_location(Vec2i p);
	//��ȡchunk��planet��ľ�������
	Vec2i get_location();
	//����chunk����
	void save_chunk(string world_name, string planet_name);
	//��ȡchunk����
	void load_chunk(string world_name, string planet_name);
private:
	Vec2i location;//chunk�ľ�������
};

#endif