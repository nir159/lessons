#include "Circle.h"

Circle::Circle(const Point& center, double radius, const string& type, const string& name) : Shape(type, name), _radius(radius), _center(center){
}

Circle::~Circle()
{
}

// getters
const Point& Circle::getCenter() const {
	return this->_center;
}

double Circle::getRadius() const {
	return this->_radius;
}

void Circle::draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char BLUE[] = { 0, 0, 255 };
	const Point& c = getCenter();
	board.draw_circle(c.getX(), c.getY(), getRadius(), BLUE, 100.0f).display(disp);	
}

void Circle::clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char BLACK[] = { 0, 0, 0 };
	const Point& c = getCenter();
}

void Circle::move(const Point& other) {
	this->_center += other;
}

double Circle::getArea() const {
	return PI * pow(this->_radius, 2.0);
}

double Circle::getPerimeter() const {
	return 2 * PI * this->_radius;
}
