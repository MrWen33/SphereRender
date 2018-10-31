#pragma once
#include<cmath>

inline float random()
{
	return 2 * (rand() / (float)RAND_MAX - 0.5);
}