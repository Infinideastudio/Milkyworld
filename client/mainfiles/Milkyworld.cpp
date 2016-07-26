/*Meoworld服务端主文件*/
/************************************************/
//文件引用
/************************************************/
#include "stdafx.h"//vs专用头文件，用其他编译器编译可注释掉
#include "blocks.h"
#include<iostream>
using namespace std;
/************************************************
函数名:main
功能:程序入口主函数
备注:无
************************************************/
int _tmain(int argc, _TCHAR* argv[])
{
	planet world;
	world.chunks.resize(289);
	for (int i = 0; i <= 16; i++)
	{
		for (int j = 0; j <= 16; j++)
		{
			chunk a;
			vec2i v=vec2i(i,j);
			block b;
			a.set_location(v);
			b.type = block_type::rock;
			for (int k = 0; k <= 15; k++)
			{
				for (int l = 0; l <= 15; l++)
				{
					vec2i pos;
					pos.x = k; pos.y = l;
					a.set_block(pos, b,0);	
				}
			}
			world.chunks[i * 17 + j] = a;
		}
	}
	while (1);
	return 0;
}



