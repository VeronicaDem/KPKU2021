#pragma once
class Point
{
	float x;
	float y;
	float z;
public:
	Point(float x, float y, float z);
	Point();
	~Point();

	float getX();
	float getY();
	float getZ();

	void setX(float x);
	void setY(float y);
	void setZ(float z);

	float dist(Point other);
};

