#ifndef __GAMEUI_UIBLOCK_H__
#define __GAMEUI_UIBLOCK_H__
#include "cocos2d.h"
#include "..\Algorithm\AllAlgorithms.h"
#include "..\Structure\AllStructures.h"
USING_NS_CC;
/************************************************
����:UIblock
����:����UI��ʾblock
��ע:��
************************************************/
class UIBlock
{
public:
	Sprite *front_sprite;
	Sprite *mid_sprite;
	Sprite *back_sprite;
	//����ʾ��chunk����
	Vec2i chunk_location;
	//����ʾ��block��chunk�еı��
	Vec2i block_index;
	//��ײ��
	MyRectangle touch_box;
	//ʵ�ʴ�С
	Vec2 size;
	//���ڵ�ͼ����ѭ�������ԣ�UI�����λ�ò�����ȫ�������깫ʽ������
	//is_borrow���������UI��������Ӧ�ķ��鴦�ڵ�ͼ���⣬��˽��õ�ͼ��һ�˵ķ�����ʾ��
	//-1����chunk<0�����õ�ͼ���ұߵķ���
	//1����chunk>size�����õ�ͼ����ߵķ���
	//0�������÷��顣
	int is_borrow;
	void init_size(Vec2 _size);
	Vec2 get_position();
	void set_position(Vec2 _position);
	void create_sprite();
	void set_front_block(FrontBlock _block);
	void set_mid_block(MidBlock _block);
	void set_back_block(BackBlock _block);
private:
	Vec2 position;
	FrontBlock front_block;
	MidBlock mid_block;
	BackBlock back_block;
};
#endif