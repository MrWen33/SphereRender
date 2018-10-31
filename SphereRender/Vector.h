#pragma once
#include<cassert>
#include<cmath>

enum VecType {
	DIR,
	POINT,
	NORMAL
};
template<class T>
class Vector3 {
public:
	T x, y, z;
	VecType type;

	Vector3(T x=0, T y=0, T z=0, VecType type=DIR) {
		Set(x, y, z);
		this->type = type;
	}
	T operator[](int ind) const{
		assert(ind >= 0 && ind <= 2);
		if (ind == 0)return x;
		if (ind == 1)return y;
		return z;
	}
	void Set(T x, T y, T z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Vector3<T> Cross(const Vector3<T> v) const{
		return Vector3<T>(
			y*v.z - z * v.y,
			z*v.x - x * v.z,
			x*v.y - y * v.x
			);
	}
	T Dot(const Vector3<T> v) const{
		return v.x*x + v.y*y + v.z*z;
	}
	Vector3<T> Add(const Vector3<T> v) const{
		return Vector3<T>(
			x + v.x,
			y + v.y,
			z + v.z
			);
	}
	Vector3<T> Minus(const Vector3<T> v) const {
		return Vector3<T>(
			x - v.x,
			y - v.y,
			z - v.z
			);
	}
	T Length() const {
		return std::sqrtf(x*x + y * y + z * z);
	}
	template<class U>
	Vector3<T> Div(U n) const {
		return Vector3<T>(x / n, y / n, z / n);
	}
	template<class U>
	Vector3<T> Mult(U n) const {
		return Vector3<T>(x * n, y * n, z * n);
	}

	template<>
	Vector3<T> Mult(Vector3<T> n) const {
		return Vector3<T>(x * n.x, y * n.y, z * n.z);
	}

	Vector3<T> Normalize() const {
		return Div(Length());
	}

	bool IsZero() { return x==0&&y==0&&z==0; }
};

typedef Vector3<float> Vector3f;
typedef Vector3<int> Vector3i;