/*Meoworld��������ļ�*/
/************************************************/
//�ļ�����
/************************************************/
#include "stdafx.h"//vsר��ͷ�ļ��������������������ע�͵�
#include "blocks.h"
#include<iostream>
using namespace std;
/************************************************
������:main
����:�������������
��ע:��
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



