#include<iostream>
#include"Camera.h"
#include"Scene.h"
#include"Intergrator.h"
int main() {
	Scene sc;
	Material m,m2,m3,m4, m5;
	m.color = Vector3f(1, 1, 1);
	m2.color = Vector3f(.75, .25, .25);
	m3.color = Vector3f(.25, .25, .75);
	m4.color = Vector3f(.75, .75, .75);
	m5.color = Vector3f();

	sc.AddSphere(Sphere(1e5 + 1, 40.8, 81.6, 1e5, m2));
	sc.AddSphere(Sphere(-1e5 + 99, 40.8, 81.6, 1e5, m3));
	sc.AddSphere(Sphere(50, 40.8, 1e5, 1e5, m4));
	sc.AddSphere(Sphere(50, 40.8, -1e5 + 170, 1e5, m5));
	sc.AddSphere(Sphere(50, 1e5, 81.6, 1e5, m4));
	sc.AddSphere(Sphere(50, -1e5 + 81.6, 81.6, 1e5, m4));
	sc.AddSphere(Sphere(27, 16.5, 47, 16.5, m));
	sc.AddSphere(Sphere(73, 16.5, 78, 16.5, m));
	sc.AddLight(Sphere(50, 41.6 - .27, 81.6, 0.6, m));
	Camera cam(Vector3f(50, 52, 165.6), Vector3f(0, -1, 0), Vector3f(0, -0.042612, -1), Vector3f(1, 0, 0), 90);
	MonteCarloIntergrator intergrator(cam, 16);
	Photo p(500, 500);
	intergrator.Shot(500, 500, sc, p);
	p.SaveAsPPM("test.ppm");
}