/*
* Milkyworld: A free game similar to ��The Blockheads��.
* Copyright (C) 2016 Infinideas
*
* This file is part of Milkyworld.
* Milkyworld is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Milkyworld is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with Milkyworld.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __ALGORITHM_PERLINNOISE_H__
#define __ALGORITHM_PERLINNOISE_H__
/************************************************
����:perlin noise
����:������������
��ע:��
************************************************/
class PerlinNoise
{
public:
	double frequency;
	double amplitude;//���ȣ��ɸģ�Խ����θ߶ȱ仯Խ��
	unsigned long long seed;
	//�����������(δ��������)
	double Noise(__int64 x);
	//ƽ������(ȡƽ��ֵ)
	double smoothedNoise(double x);
	//���Բ�ֵ����
	double interpolate(double a, double b, double x);
	//��ֵ����
	double interpolatedNoise(double x);
	//���պ���,����x���ض�Ӧ��y
	double perlin_noise(double x);
};
#endif