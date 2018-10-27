#pragma once
#include"Ray.h"
#include"Sphere.h"
#include<vector>
class Scene {
public:
	Vector3f Intersect(const Ray& ray) const;
	void AddSphere(Sphere s) {
		spheres.push_back(s);
	};
private:
	std::vector<Sphere> spheres;
};