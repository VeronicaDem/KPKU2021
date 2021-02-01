#include <cmath>
#include "Triangular.h"
#include "Point.h"
Triangular::Triangular(Point p1, Point p2, Point p3) {
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}
Triangular::~Triangular() {

}
float Triangular::s() {
	float a = p1.dist(p2);
	float b = p1.dist(p3);
	float c = p2.dist(p3);

	float p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}