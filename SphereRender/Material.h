#pragma once
#include"Ray.h"

enum SurfaceType{
	SPEC,
	DIFF,
	REFR
};
class Material {
public:
	Vector3f color;
	Vector3f emit;
	SurfaceType type=DIFF;
};