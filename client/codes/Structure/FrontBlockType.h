#ifndef __STRUCTURE_FRONTBLOCKTYPE_H__
#define __STRUCTURE_FRONTBLOCKTYPE_H__
#include "..\Algorithm\Definition.h"
/************************************************
ö������:ǰ����������
����:��ʾ���������
��ע:ǰ���������������ײ�䣬��С��ֲ���Լ����嶼����ǰ������
************************************************/
enum class FrontBlockType : ushort
{
	vacuum,//���0
	air,//����1
	rock,//��ʯ2
	stone,//Բʯ3
	dirt,//����4
	grass,//�ݵ�5
	water,//ˮ6
};
#endif