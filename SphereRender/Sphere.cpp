#include "Sphere.h"
#include<cmath>
#include<iostream>
float Sphere::Intersect(const Ray & ray) const
{
	const Vector3f& O1 = pos;
	const Vector3f& O2 = ray.o;
	const Vector3f& D = ray.dir;
	Vector3f O = O2.Minus(O1);
	float OdotD = O.Dot(D);
	float delta = 4.f*(OdotD*OdotD - D.Dot(D)*(O.Dot(O) - r*r));
	if (delta < 0.001) return 0;
	float sqrtDelta = std::sqrtf(delta);
	float d1 = (-2 * OdotD + sqrtDelta) / 2.f*D.Dot(D);
	float d2 = (-2 * OdotD - sqrtDelta) / 2.f*D.Dot(D);
	if (d1 < 0.001) {
		//0>d1>d2
		return 0;
	}
	if (d2 < 0.001) {
		//d1>0>d2
		return d1;
	}
	//d1>d2>0
	return d2;
}

bool Sphere::IsIntersect(const Ray & ray) const
{
	const Vector3f& O1 = pos;
	const Vector3f& O2 = ray.o;
	const Vector3f& R = ray.dir;
	Vector3f O = O2.Minus(O1);
	float OdotR = O.Dot(R);
	float delta = 4.f*(OdotR*OdotR - R.Dot(R)*(O.Dot(O) - r));
	return delta > 0;
}
