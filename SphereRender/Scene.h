#pragma once
#include"Ray.h"
#include"Sphere.h"
#include<vector>
#include"Sampler.h"
#include<memory>
class Sampler;

class Scene {
public:
	//向场景中发射射线，返回最终颜色
	Scene(std::shared_ptr<Sampler> sampler);;
	Vector3f Sample(const Ray& ray, int depth=2, const Sphere* self=nullptr) const;
	void AddSphere(Sphere s) {
		spheres.push_back(s);
	};
	void AddLight(Sphere s) {
		lights.push_back(s);
		s.SetR(s.GetR()*0.9f);
		spheres.push_back(s);
	}
	const std::vector<Sphere>* GetSpheres() const {
		return &spheres;
	}
	const std::vector<Sphere>* GetLights() const {
		return &lights;
	}
	RayIsectInfo Intersect(const Ray & ray,const Sphere* self=nullptr) const;
private:
	std::shared_ptr<Sampler> sampler;
	std::vector<Sphere> spheres;
	std::vector<Sphere> lights;
};