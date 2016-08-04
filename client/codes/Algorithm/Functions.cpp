#include "Functions.h"
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
/************************************************
变量:命名空间变量定义
功能:定义变量
备注:无
************************************************/
int world_vars::game_load_schedule;