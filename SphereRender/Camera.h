#pragma once
#include"Vector.h"
#include<vector>
#include<fstream>
#include<string>
#include"Ray.h"
#include"Scene.h"

struct Photo {
	int width;
	int height;
	Vector3f *data;

	Photo(int width, int height);

	void SaveAsPPM(std::string filename);

	void Write(int x, int y, Vector3f color);

	static int to255(float n) {
		return n * 255;
	}

	~Photo(){
		delete[] data;
	}
};

class Camera {
public:
	Camera(Vector3f pos, Vector3f up, Vector3f front, Vector3f right, float fov)
	:pos(pos), up(up), front(front), right(right), fov(fov){
		fovScale = std::tanf(fov*0.5*3.1415926 / 180) * 2;
	};
	void Shot(int width, int height,const Scene& sc, Photo& photo);

	Ray GenRay(float x, float y) {
		Vector3f r = right.Mult((x - 0.5)*fovScale);
		Vector3f u = up.Mult((y - 0.5)*fovScale);
		Ray ray;
		ray.dir = front.Add(r).Add(u);
		ray.o = pos;
		return ray;
	}
private:
	Vector3f pos;
	Vector3f up;
	Vector3f front;
	Vector3f right;
	float fov;
	float fovScale;
};
