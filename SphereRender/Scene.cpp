#include "Scene.h"

Vector3f Scene::Intersect(const Ray & ray) const
{
	RayIsectInfo info(ray);
	for (auto& s : spheres) {
		info.Intersect(s);
	}
	if (info.IsIntersect()) {
		return info.obj->GetMaterial().color;
	}
	else {
		return Vector3f();
	}
}
