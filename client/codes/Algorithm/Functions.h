#ifndef __ALGORITHM_FUNCTIONS_H__
#define __ALGORITHM_FUNCTIONS_H__
#include <iostream>
using namespace std;
/************************************************
函数块:类型转换函数
功能:常用类型的转换
备注:无
************************************************/
string int_2_string(int i);
double string_2_double(string i);
bool string_2_bool(string i);
int string_2_int(string i);
/************************************************
命名空间:MilkyWorld
功能:一些游戏的全局变量
备注:无
************************************************/
namespace world_vars
{
	//游戏加载进度
	extern int game_load_schedule;
}
#endif