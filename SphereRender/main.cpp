#include<iostream>
#include"Camera.h"
#include"Scene.h"
int main() {
	Scene sc;
	Material m;
	m.color = Vector3f(1, 1, 1);
	
	sc.AddSphere(Sphere(0, 0, 0, 1, m));
	Camera cam(Vector3f(0, 0, 10), Vector3f(0, 1, 0), Vector3f(0, 0, -1), Vector3f(-1, 0, 0), 60);
	Photo p(500, 500);
	cam.Shot(500, 500, sc, p);
	p.SaveAsPPM("test.ppm");
}