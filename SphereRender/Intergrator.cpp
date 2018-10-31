#include "Intergrator.h"
#include<cmath>
#include"Utils.h"
#include<iostream>
void SimpleIntergrator::Shot(int width, int height, const Scene & sc, Photo & p)
{
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			p.Write(i, j, sc.Sample(camera.GenRay(i / (float)width, j / (float)height)));
		}
	}
}

void MonteCarloIntergrator::Shot(int width, int height, const Scene & sc, Photo & p)
{
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			std::cout << ((i + 1)*width + (j + 1)) / (float)(width*height) << std::endl;
			Vector3f sampleColor;
			for (int s = 0; s < ppm; ++s) {
				sampleColor = sampleColor.Add(sc.Sample(camera.GenRay(((i + random()) / (float)width), (j + random()) / (float)height)));
			}
			sampleColor = sampleColor.Div(ppm);
			p.Write(i, j, sampleColor);
		}
	}
}
