#include "Sphere.h"
#include<cmath>
float Sphere::Intersect(const Ray & ray) const
{
	const Vector3f& O1 = pos;
	const Vector3f& O2 = ray.o;
	const Vector3f& R = ray.dir;
	Vector3f O = O2.Minus(O1);
	float OdotR = O.Dot(R);
	float delta = 4.f*(OdotR*OdotR - R.Dot(R)*(O.Dot(O) - r));
	if (delta < 0) return 0;
	float sqrtDelta = std::sqrtf(delta);
	float d1 = (2 * OdotR + sqrtDelta) / 2.f;
	float d2 = (2 * OdotR - sqrtDelta) / 2.f;
	if (d1 < 0) {
		//0>d1>d2
		return 0;
	}
	if (d2 < 0) {
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
