#pragma once
#include"Scene.h"
class Scene;

class Sampler {
public:
	virtual Vector3f Sample(const Scene& sc, const Ray& ray, int depth = 4, const Sphere* self = nullptr) const = 0;
	virtual ~Sampler() {};
};

class ExplicitSampler : public Sampler {
	Vector3f Sample(const Scene& sc, const Ray& ray, int depth = 4, const Sphere* self = nullptr) const override;
};

class PathTracingSampler : public Sampler {
	Vector3f Sample(const Scene& sc, const Ray& ray, int depth = 4, const Sphere* self = nullptr) const override;
};