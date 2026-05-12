#pragma once
#include <iostream>
#include <string>
using namespace std;
class Rectanagle
{
	double width;
	double height;
public:
	Rectanagle(double wid, double hei) {
		width = wid;
		height = hei;
		if (wid < 0) {
			wid = 1.0;
		}
		if (hei < 0) {
			hei = 1.0;
		}
	}
	double getWidth() const { return width; }
	double getHeight() const { return height; }
	double getArea() const { return width * height; }
	double getPerimeter() const { return 2 * (width + height); }
	bool isSquare() const { return width == height; }
	void printInfo() {
		cout << "Rectanagle: " << width << " x " << height << endl;
		cout << "Area: " << getArea() << endl;
		cout << "Perimeter: " << getPerimeter() << endl;
		cout << "Is Square: " << isSquare() << endl;
	}
};

