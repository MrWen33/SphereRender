#include "Scene.h"
#include<cmath>
Vector3f Scene::Sample(const Ray & ray) const
{
	RayIsectInfo info(ray);
	for (auto& s : spheres) {
		info.Intersect(s);
	}
	if (info.IsIntersect()) {
		Vector3f color;
		for (auto& l : lights) {
			Ray toLight;
			toLight.o = info.point;
			toLight.dir = l.GetPos().Minus(info.point).Normalize();
			RayIsectInfo shadowRay(toLight);
			for (auto&s : spheres) {
				if (&s == info.obj) continue;
				shadowRay.Intersect(s);
			}
			shadowRay.Intersect(l);
			if (shadowRay.obj == &l) 
			{
				float cosTheta = std::fmax(0, toLight.dir.Dot(info.normal));
				color = color.Add(info.obj->GetMaterial().color.Mult(l.GetMaterial().color).Mult(cosTheta));
			}
		}
		return color;
	}
	else {
		return Vector3f();
	}
}
