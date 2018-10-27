#pragma once
#include"Sphere.h"
#include"Vector.h"
#include"Ray.h"

class Sphere;

struct IsectInfo {
	const Sphere* obj;
	Vector3f normal;
	Vector3f point;
	IsectInfo(Sphere* obj=nullptr) {
		this->obj = obj;
	}
	bool IsIntersect() {
		return obj != nullptr;
	}
	virtual ~IsectInfo() {};
};

struct RayIsectInfo:public IsectInfo {
	Ray ray;
	float distance;
	RayIsectInfo(Ray r) {
		ray = r;
		distance = 1000.0;
	}
	void Intersect(const Sphere& s);
};