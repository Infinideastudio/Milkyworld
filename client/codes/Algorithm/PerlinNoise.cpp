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
#include"PerlinNoise.h"
/************************************************
������:Noise
����:�����������
��ע:δ��������
************************************************/
double PerlinNoise::Noise(__int64 x)
{
	x = (x << 13) ^ x;
	return 1.0 - ((x * (x * x * seed + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0 + 1;
}
/************************************************
������:smoothedNoise
����:ƽ������(ȡƽ��ֵ)
��ע:��
************************************************/
double PerlinNoise::smoothedNoise(double x)
{
	return Noise(x) / 2 + Noise(x - 1) / 4 + Noise(x + 1) / 4;
}
/************************************************
������:interpolate
����:���Բ�ֵ����
��ע:��
************************************************/
double PerlinNoise::interpolate(double a, double b, double x)
{
	return a*(1 - x) + b*x;
}
/************************************************
������:interpolatedNoise
����:��ֵ����
��ע:��
************************************************/
double PerlinNoise::interpolatedNoise(double x)
{
	int int_x = int(x);
	double fractional_x = x - int_x;
	double v1 = smoothedNoise(int_x);
	double v2 = smoothedNoise(int_x + 1);
	return interpolate(v1, v2, fractional_x);
}
/************************************************
������:perlin_noise
����:���պ���,����x���ض�Ӧ��y
��ע:��
************************************************/
double PerlinNoise::perlin_noise(double x)
{
	double total = 0;
	double freq = frequency;
	double ampl = amplitude;
	double blockSize = 1;//ÿ�����ӵĴ�С���ɸ�
	for (int i = 0; i <= 4; i++)
	{
		total += interpolatedNoise(x*freq)*ampl;
		freq *= 2; ampl /= 2.0;
	}
	return int(total * 5 * blockSize - amplitude * 8);
}