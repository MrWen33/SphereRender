#pragma once
#include"IsectInfo.h"
#include"Ray.h"
#include"Vector.h"
#include"Material.h"
class Sphere {
public:
	Sphere(float x=0, float y=0, float z=0, float r=0, Material material=Material()) {
		SetPos(x, y, z);
		this->r = r;
		this->material = material;
	}
	void SetPos(float x, float y, float z) {
		pos.Set(x, y, z);
	}
	auto GetPos() const { return pos; }
	
	float Intersect(const Ray& ray) const;
	bool IsIntersect(const Ray& ray) const;
	Material GetMaterial() const { return material; }
private:
	Material material;
	Vector3f pos;
	float r;
};