#ifndef __ALGORITHM_FUNCTIONS_H__
#define __ALGORITHM_FUNCTIONS_H__
#include <iostream>
using namespace std;
/************************************************
������:����ת������
����:�������͵�ת��
��ע:��
************************************************/
string int_2_string(int i);
double string_2_double(string i);
bool string_2_bool(string i);
int string_2_int(string i);
/************************************************
�����ռ�:MilkyWorld
����:һЩ��Ϸ��ȫ�ֱ���
��ע:��
************************************************/
namespace world_vars
{
	//��Ϸ���ؽ���
	extern int game_load_schedule;
}
#endif