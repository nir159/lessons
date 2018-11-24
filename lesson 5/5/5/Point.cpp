#include "Point.h"

Point::Point(double x, double y) : x(x), y(y)// Constructor
{
}

Point::Point(const Point& other) : x(other.getX()), y(other.getY())// copyConstructor
{
}

Point::~Point() // distructor
{ 
}

// overrides
Point Point::operator+(const Point& other) const {
	return Point(this->x + other.getX(), this->y + other.getY());
}

Point& Point::operator+=(const Point& other) {
	this->x = this->x + other.getX();
	this->y = this->y + other.getY();
	return *this;
}

// getters
double Point::getX() const {
	return this->x;
}

double Point::getY() const {
	return this->y;
}

double Point::distance(const Point& other) const {
		return sqrt(pow((this->x - other.getX()), 2.0) + pow((this->y - other.getY()), 2.0));
}