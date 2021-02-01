#include <cmath>
#include "Point.h"
using namespace std;
Point::Point(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

float Point::getX() {
	return this->x;
}
float Point::getY() {
	return this->y;
}
float Point::getZ() {
	return this->z;
}

void Point::setX(float x) {
	this->x = x;
}
void Point::setY(float y) {
	this->y = y;
}
void Point::setZ(float z) {
	this->z = z;
}

float Point::dist(Point other) {
	return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2) + pow(other.z - z, 2));
}
Point::~Point() {

}
Point::Point() {
	x = y = z = 0;
}