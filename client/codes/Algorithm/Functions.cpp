#include "Functions.h"
/************************************************
������:����ת������
����:�ڼ�����������֮��ת��
��ע:��
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
����:�����ռ��������
����:�������
��ע:��
************************************************/
int world_vars::game_load_schedule;