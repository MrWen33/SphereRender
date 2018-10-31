#include "Sampler.h"
#include"Utils.h"
Vector3f ExplicitSampler::Sample(const Scene & sc, const Ray & ray, int depth, const Sphere * self) const
{
	RayIsectInfo info = sc.Intersect(ray, self);
	auto lights = *sc.GetLights();
	auto spheres = *sc.GetSpheres();
	if (info.IsIntersect()) {
		if (!info.obj->GetMaterial().emit.IsZero()) {
			return info.obj->GetMaterial().emit.Mult(info.obj->GetMaterial().color);
		}
		Vector3f color;
		if (info.obj->GetMaterial().type == DIFF) {
			//遍历所有光源，通过计算阴影光线来计算各光源的贡献并累加。
			for (auto& l : lights) {
				Ray toLight;
				toLight.o = info.point;
				toLight.dir = l.GetPos().Minus(info.point).Normalize();
				RayIsectInfo shadowRay = sc.Intersect(toLight, info.obj);
				shadowRay.Intersect(l);
				if (shadowRay.obj == &l)
				{
					float cosTheta = std::fmax(0, toLight.dir.Dot(info.normal));
					color = color.Add(info.obj->GetMaterial().color.Mult(l.GetMaterial().color).Mult(cosTheta));
				}
			}
			return color;
		}
		if (info.obj->GetMaterial().type == SPEC)
		{
			//计算反射光线
			if (depth <= 0) {
				return Vector3f();
			}
			Ray specRay;
			Vector3f& normal = info.normal;
			Vector3f inDir = ray.dir;
			Vector3f offset = normal.Mult(normal.Dot(inDir.Mult(-1.f))).Minus(inDir.Mult(-1.f));
			Vector3f specDir = inDir.Mult(-1.f).Add(offset.Mult(2));
			specRay.o = info.point;
			specRay.dir = specDir;
			return Sample(sc, specRay, depth - 1, info.obj);
		}
		if (info.obj->GetMaterial().type == REFR) {
			return Vector3f();
		}
	}
	else {
		return Vector3f();
	}
}

Vector3f PathTracingSampler::Sample(const Scene & sc, const Ray & ray, int depth, const Sphere * self) const
{
	if (depth <= 0) {
		return Vector3f();
	}
	RayIsectInfo info = sc.Intersect(ray, self);
	auto lights = *sc.GetLights();
	auto spheres = *sc.GetSpheres();
	if (info.IsIntersect()) {
		if (!info.obj->GetMaterial().emit.IsZero()) {
			return info.obj->GetMaterial().emit.Mult(info.obj->GetMaterial().color);
		}
		Vector3f color;
		if (info.obj->GetMaterial().type == DIFF) {
			//漫反射：随机选择方向出射
			Vector3f randomDir = Vector3f(random(), random(), random()).Normalize();
			while (randomDir.Dot(info.normal) < 0) {
				randomDir = Vector3f(random(), random(), random()).Normalize();
			}
			Ray outRay;
			outRay.dir = randomDir;
			outRay.o = info.point;
			return info.obj->GetMaterial().color.Mult(Sample(sc, outRay, depth-1, info.obj));
		}
		if (info.obj->GetMaterial().type == SPEC)
		{
			//计算反射光线
			if (depth <= 0) {
				return Vector3f();
			}
			Ray specRay;
			Vector3f& normal = info.normal;
			Vector3f inDir = ray.dir;
			Vector3f offset = normal.Mult(normal.Dot(inDir.Mult(-1.f))).Minus(inDir.Mult(-1.f));
			Vector3f specDir = inDir.Mult(-1.f).Add(offset.Mult(2));
			specRay.o = info.point;
			specRay.dir = specDir;
			return Sample(sc, specRay, depth - 1, info.obj);
		}
		if (info.obj->GetMaterial().type == REFR) {
			return Vector3f();
		}
	}
}
