#include "Camera.h"

Photo::Photo(int width, int height) {
	data = new Vector3f[width*height];
	this->width = width;
	this->height = height;
}

void Photo::SaveAsPPM(std::string filename) {
	std::ofstream out(filename);
	out << "P3\n";
	out << width << " " << height << " " << "255 ";
	for (int i = 0; i < width*height; ++i) {
		Vector3f& color = data[i];
		out << to255(color.x) << " " << to255(color.y) << " " << to255(color.z) << " ";
	}
	out.close();
}

void Photo::Write(int x, int y, Vector3f color) {
	data[y*width + x] = color;
}
