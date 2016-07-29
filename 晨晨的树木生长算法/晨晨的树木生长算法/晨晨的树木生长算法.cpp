// 晨晨的树木生长算法.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
char output[2] = {' ','#'};
class node
{
public:
	int hp;//生命值
	int type;
	vector<int> son_x;
	vector<int> son_y;
};
vector<vector<node> > map;
void print_map()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			cout << output[map[i][j].type];
		}
		cout << endl;
	}
	cout << endl;
}
void dfs(int now_x, int now_y)
{
	//在这里添加关于生长的代码
	for (int i = 0; i < map[now_x][now_y].son_x.size(); i++)
	{
		dfs(map[now_x][now_y].son_x[i], map[now_x][now_y].son_y[i]);
	}
}
void grow()
{
	dfs(29,14);
}
int _tmain(int argc, _TCHAR* argv[])
{
	map.resize(100);
	for (int i = 0; i < map.size(); i++)
	{
		map[i].resize(100);
	}
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			map[i][j].type = 0;
		}
	}
	map[29][14].type = 1;
	map[29][14].hp = 1;
	while (1)
	{
		_getch();
		grow();
		system("cls");
		print_map();
	}
	return 0;
}

