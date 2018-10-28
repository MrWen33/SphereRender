#include "IsectInfo.h"
void RayIsectInfo::Intersect(const Sphere & s) {
	float newDis = s.Intersect(ray);
	if (newDis > 0.01 && newDis<distance) {
		distance = newDis;
		obj = &s;
		point = ray.o.Add(ray.dir.Mult(distance));
		normal = point.Minus(s.GetPos()).Normalize();
		if (normal.Dot(ray.dir) > 0) {
			normal = normal.Mult(-1.f);
		}
	}
}
