#include "Scene.h"
#include<cmath>


//�򳡾��з������ߣ�����������ɫ

Scene::Scene(std::shared_ptr<Sampler> sampler) :sampler(sampler) {}

Vector3f Scene::Sample(const Ray & ray, int depth, const Sphere* self) const
{
	return sampler->Sample(*this, ray, depth, self);
}

RayIsectInfo Scene::Intersect(const Ray & ray,const Sphere* self) const
{
	RayIsectInfo rayIsect(ray);
	for (auto& s : spheres) {
		//��ֹ���ڵ�
		if (self == &s)continue;
		rayIsect.Intersect(s);
	}
	return rayIsect;
}
