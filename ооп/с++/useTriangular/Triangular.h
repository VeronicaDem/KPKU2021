#pragma once
/*
* #ifndef Triangular
* #define Triangular_H_
* 
* 
* и в конце #endif
*/
#include "Point.h"
class Triangular
{
private:
	Point p1;
	Point p2;
	Point p3;
public:
	Triangular(Point p1, Point p2, Point p3);
	~Triangular();

	float s();
};
// #endif

