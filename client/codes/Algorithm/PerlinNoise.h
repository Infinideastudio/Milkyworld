/*
* Milkyworld: A free game similar to “The Blockheads”.
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
类名:perlin noise
功能:产生柏林噪声
备注:无
************************************************/
class PerlinNoise
{
public:
	double frequency;
	double amplitude;//幅度，可改，越大地形高度变化越大
	unsigned long long seed;
	//随机数发生器(未经过处理)
	double Noise(__int64 x);
	//平滑噪声(取平均值)
	double smoothedNoise(double x);
	//线性插值函数
	double interpolate(double a, double b, double x);
	//插值噪声
	double interpolatedNoise(double x);
	//最终函数,传入x返回对应的y
	double perlin_noise(double x);
};
#endif