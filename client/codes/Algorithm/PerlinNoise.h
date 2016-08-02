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
	double Noise(int x)//随机数发生器(未经过处理)
	{
		x = (x << 13) ^ x;
		return 1.0 - ((x * (x * x * seed + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0 + 1;
	}
	double smoothedNoise(double x)//平滑噪声(取平均值)
	{
		return Noise(x) / 2 + Noise(x - 1) / 4 + Noise(x + 1) / 4;
	}
	double interpolate(double a, double b, double x)//线性插值函数
	{
		return a*(1 - x) + b*x;
	}
	double interpolatedNoise(double x)//插值噪声
	{
		int int_x = int(x);
		double fractional_x = x - int_x;
		double v1 = smoothedNoise(int_x);
		double v2 = smoothedNoise(int_x + 1);
		return interpolate(v1, v2, fractional_x);
	}
	double perlin_noise(double x)//最终函数,传入x返回对应的y
	{
		double total = 0;
		double freq = frequency;
		double ampl = amplitude;
		double blockSize = 1;//每个格子的大小，可改
		for (int i = 0; i <= 4; i++)
		{
			total += interpolatedNoise(x*freq)*ampl;
			freq *= 2; ampl /= 2.0;
		}
		return int(total * 5 * blockSize - amplitude * 8);
	}
};
#endif