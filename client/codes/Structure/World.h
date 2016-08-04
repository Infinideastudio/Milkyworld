#ifndef __STRUCTURE_WORLD_H__
#define __STRUCTURE_WORLD_H__
#include "Planet.h"
/************************************************
类名:世界
功能:一个世界
备注:包含许多星球，但一次只能加载一个
************************************************/
class World
{
public:
	Planet planet;
	string name;
private:
};
#endif