#include "UIBlock.h"
/************************************************
������:UIBlock��
����:����UIBlock��ĺ���
��ע:��
************************************************/
//�����Ļ���� 
Vec2 UIBlock::get_position()
{
	return position;
}
//������Ļ����
void UIBlock::set_position(Vec2 _position)
{
	position = _position;
	touch_box = MyRectangle(Vec2(_position.x - size.x / 2, _position.y + size.y / 2)
		, Vec2(_position.x + size.x / 2, _position.y - size.y / 2));
	front_sprite->setPosition(_position);
	mid_sprite->setPosition(_position);
	back_sprite->setPosition(_position);
}
//��һ�����ô�С
void UIBlock::init_size(Vec2 _size)
{
	size = _size;
}
//����sprite
void UIBlock::create_sprite()
{
	front_sprite = Sprite::create("HelloWorld.png");
	mid_sprite = Sprite::create("HelloWorld.png");
	back_sprite = Sprite::create("HelloWorld.png");
	init_size(Vec2(picture_length, picture_length));
}
//���÷���
void UIBlock::set_front_block(FrontBlock _block)
{
	front_block = _block;
	if (front_block.type == FrontBlockType::air)
		front_sprite->setVisible(false);
	else
	{
		front_sprite->setVisible(true);
		front_sprite->setTexture(int_2_string(static_cast<ushort>(front_block.type)) + ".png");
	}

}
void UIBlock::set_mid_block(MidBlock _block)
{
	mid_block = _block;
	mid_sprite->setTexture("HelloWorld.png");
}
void UIBlock::set_back_block(BackBlock _block)
{
	back_block = _block;
	back_sprite->setTexture("HelloWorld.png");
}