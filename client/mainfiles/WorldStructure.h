/*���ڷ������ͺ�������ͷ�ļ�*/
#ifndef __WORLDSTRUCTURE_H__
#define __WORLDSTRUCTURE_H__
/************************************************/
//�ļ�����
/************************************************/
#include "Definition.h"
#include "cocos2d.h"
#include <vector>
#include <.\otherfiles\MilkyworldMath.h>
using namespace std;
USING_NS_CC;
/************************************************
����:����
����:��ʾһ������
��ע:�������Ͷ����"definition.h"
************************************************/
class Block
{
public: 
};
/************************************************
����:ǰ������
����:��ʾһ������
��ע:��ʾ����ǰ��ķ���
************************************************/
class FrontBlock :public Block//ǰ������
{
public:
	bool enabled_touch;//��ײ��
	FrontBlockType type;
};
/************************************************
����:�о�����
����:��ʾһ������
��ע:��ʾ���м�ķ���
************************************************/
class MidBlock :public Block
{
public:
	MidBlockType type;
};
/************************************************
����:�󾰷���
����:��ʾһ������
��ע:װ�η���
************************************************/
class BackBlock :public Block
{
public:
	BackBlockType type;
};
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
/************************************************
����:����
����:һ������
��ע:��Ϊ����/��̬����/С����/����/�װ���/������/�ڶ���
************************************************/
class CelestialBody
{
public:
private:
};
/************************************************
����:����
����:һ������
��ע:��ͼ��Сn*64�����飬(16*n)*1024������,ͬʱ����17*17������
        n*16�������ֱ��
************************************************/
class Planet :public CelestialBody
{
public:
	vector<Chunk> chunk;//���ص�����
	Vec2 chunk_size;
	string name;
	//���ݾ���������chunk
	Chunk get_chunk(Vec2i _location);
	//���ݾ���������chunk��ID
	int get_chunk_id(Vec2i _location);
	//�洢һ�����ǵ����ݵ��ļ�
private:
};

/************************************************
����:����
����:һ������
��ע:�����������򣬵�һ��ֻ�ܼ���һ��
************************************************/
class World
{
public:
	Planet planet;
	string name;
private:
};
#endif