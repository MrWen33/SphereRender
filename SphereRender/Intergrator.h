#pragma once
#include"Camera.h"
class Camera;

class Intergrator {
public:
	Intergrator(const Camera& cam) : camera(cam) {};
	virtual void Shot(int width, int height, const Scene&sc, Photo& p) = 0;
protected:
	const Camera& camera;
};

class SimpleIntergrator : public Intergrator {
public:
	SimpleIntergrator(const Camera& cam) : Intergrator(cam) {};
	void Shot(int width, int height, const Scene&sc, Photo& p) override;
};

class MonteCarloIntergrator : public Intergrator {
public:
	MonteCarloIntergrator(const Camera& cam, int ppm) : Intergrator(cam), ppm(ppm) {};
	void Shot(int width, int height, const Scene&sc, Photo& p) override;
private:
	int ppm;
};