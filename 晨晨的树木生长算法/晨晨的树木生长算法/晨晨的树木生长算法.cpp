// ��������ľ�����㷨.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
using namespace std;
char output[2] = {' ','#'};
class node
{
public:
	int hp;//����ֵ
	vector<int> son;
	int x, y;
};
int map[30][60];
vector<node> wood;
void print_map()
{
	system("cls");
	memset(map, 0, sizeof(map));
	for (int i = 1; i < wood.size(); i++)
	{
		map[wood[i].x][wood[i].y] = wood[i].hp;
	}
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			if (map[i][j] == 0)
				cout << " ";
			else cout << map[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void move_dfs(int now,int dx,int dy)//����ƽ�Ƶ�����
{
	for (int i = 0; i < wood[now].son.size(); i++)
	{
		//����ÿһ�����ӣ�����һ��
		move_dfs(wood[now].son[i], dx,dy);
	}
	wood[now].x += dx;
	wood[now].y += dy;
}
int get_wood(int x, int y)
{
	for (int i = 0; i < wood.size(); i++)
		if (wood[i].x == x&&wood[i].y == y)
			return i;
	return -1;
}
void dfs(int now,int last)
{
	if (now==last)return;
	//��������ӹ��������Ĵ���
	//�����������ڵ��Ǹ�ԭľ������ֵ��ȥ�����������ֵ����1�����ԭľ�������ֵ��10%�ĸ�������1
	if (wood[last].hp - wood[now].hp > 1)
	{
		int rd = rand() % 10 + 1;
		if (rd == 1)wood[now].hp++;
	}
	//�����ڵ㷽��ԭľ�������ֵ��һ����Χ֮����������1ʱ����һ�������ڸ��м�λ���ӳ�һ��ԭľ�飬���������ϵ�����ԭľ�鶼��÷���ƽ��һ��
	if (wood[last].hp >= 3 && wood[last].hp <= 20 && wood[last].hp - wood[now].hp > 1)
	{
		int rd = rand() % 10 + 1;
		if (rd == 1)
		{
			int dir,dx=0,dy=0;
			if (wood[now].y > wood[last].y)dy = 1;
			if (wood[now].y < wood[last].y)dy = -1;
			if (wood[now].x > wood[last].x)dx = 1;
			if (wood[now].x < wood[last].x)dx = -1;
			node new_wood;
			new_wood.x = wood[now].x;
			new_wood.y = wood[now].y;
			new_wood.hp = wood[now].hp+1;
			new_wood.son.push_back(now);
			wood.push_back(new_wood);
			for (int i = 0; i < wood[last].son.size(); i++)
			{
				if (wood[last].son[i] == now)
				{
					wood[last].son.erase(wood[last].son.begin() + i);
					break;
				}
			}
			wood[last].son.push_back(wood.size()-1);
			move_dfs(now,dx,dy);
		}
	}
	//������ԭľ�������ֵ��һ����Χ(�ݶ�Ϊ3-20)֮��ʱ���и������Ա�����һ�����������ϣ�����ֵС������ԭľ��
	if (wood[last].hp >= 3 && wood[last].hp <= 20)
	{
		int rd = rand() % 10 + 1;
		if (rd == 1)
		{
			node new_wood;
			if (get_wood(wood[now].x, wood[now].y - 1) == -1)
			{
				new_wood.x = wood[now].x;
				new_wood.y = wood[now].y - 1;
				new_wood.hp = wood[now].hp / 2;
				wood.push_back(new_wood);
				wood[now].son.push_back(wood.size()-1);
			}
			else if (get_wood(wood[now].x, wood[now].y + 1) == -1)
			{
				new_wood.x = wood[now].x;
				new_wood.y = wood[now].y + 1;
				new_wood.hp = wood[now].hp / 2;
				wood.push_back(new_wood);
				wood[now].son.push_back(wood.size()-1);
			}
		}
	}
	for (int i = 0; i < wood[now].son.size(); i++)
	{
		//����ÿһ�����ӣ�����һ��
		dfs(wood[now].son[i], now);
	}
}
void grow(int root)
{
	dfs(root, 0);
}
int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(0));
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			map[i][j] = 0;
		}
	}
	wood.resize(3);
	wood[0].hp = -999;
	wood[1].x = 29;
	wood[1].y = 30;
	wood[1].hp = 9;
	wood[1].son.push_back(2);
	wood[2].x = 28;
	wood[2].y = 30;
	wood[2].hp = 5;
	while (1)
	{
		_getch();
		grow(1);
		print_map();
	}
	return 0;
}

