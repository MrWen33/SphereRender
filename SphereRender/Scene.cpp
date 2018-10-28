#include "Scene.h"
#include<iostream>
Vector3f Scene::Intersect(const Ray & ray) const
{
	RayIsectInfo info(ray);
	for (auto& s : spheres) {
		info.Intersect(s);
	}
	if (info.IsIntersect()) {
		return Vector3f(info.point.z, info.point.z, info.point.z);
	}
	else {
		return Vector3f();
	}
}
