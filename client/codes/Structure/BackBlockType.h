#ifndef __STRUCTURE_BACKBLOCKTYPE_H__
#define __STRUCTURE_BACKBLOCKTYPE_H__
#include "..\Algorithm\Definition.h"
/************************************************
ö������:�󾰷�������
����:��ʾ���������
��ע:�󾰷����������װ�Σ�û���κ�ʵ�����ã���2d�ӽ��²����ã��������á�
************************************************/
enum class BackBlockType :ushort
{
	vacuum,//���0
	air,//����1
	rock,//��ʯ2
	stone,//Բʯ3
	dirt,//����4
	grass,//�ݵ�5
};
#endif