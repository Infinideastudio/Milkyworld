#include "WorldAlgorithms.h"
#include "cocos2d.h"
#include <string.h>
using namespace std; 
/************************************************
函数块:UIBlock类 
功能:定义UIBlock类的函数 
备注:无
************************************************/
//获得屏幕坐标 
Vec2 UIBlock::get_position()
{
	return position;
}
//设置屏幕坐标
void UIBlock::set_position(Vec2 _position)
{
	position = _position;
	front_sprite->setPosition(_position);
	mid_sprite->setPosition(_position);
	back_sprite->setPosition(_position);
}
//创建sprite
void UIBlock::create_sprite()
{
	front_sprite = Sprite::create("HelloWorld.png");
	mid_sprite = Sprite::create("HelloWorld.png");
	back_sprite = Sprite::create("HelloWorld.png");
}
//设置方块
void UIBlock::set_front_block(FrontBlock _block)
{
	front_block = _block;
	front_sprite->setTexture(int_2_string(static_cast<ushort>(front_block.type)) + ".png");
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

/************************************************
函数块:类型转换函数
功能:在几个常用类型之间转换
备注:无
************************************************/
string int_2_string(int i)
{
	char temp[10];
	sprintf(temp, "%d", i, 10);
	string s = temp;
	return s;
}
double string_2_double(string i)
{
	string str = i;
	return atof(str.c_str());
}
int string_2_int(string i)
{
	string str = i;
	int j = atoi(str.c_str());
	return j;
}
bool string_2_bool(string i)
{
	string str = i;
	int j = atoi(str.c_str());
	if (j == 0)return false;
	return true;
}
