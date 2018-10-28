#include "Intergrator.h"
#include<cmath>
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
			Vector3f sampleColor;
			for (int s = 0; s < ppm; ++s) {
				sampleColor = sampleColor.Add(sc.Sample(camera.GenRay(((i + random()) / (float)width), (j + random()) / (float)height)));
			}
			sampleColor = sampleColor.Div(ppm);
			p.Write(i, j, sampleColor);
		}
	}
}

float MonteCarloIntergrator::random()
{
	return 2 * (rand() / (float)RAND_MAX - 0.5);
}
