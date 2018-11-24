#include "Triangle.h"


Triangle::Triangle(const Point& a, const Point& b, const Point& c, const string& type, const string& name) : Polygon(type, name), _p1(a), _p2(b), _p3(c) {
	if ((a.getX() == b.getX() && b.getX() == c.getX()) || (a.getY() == b.getY() && b.getY() == c.getY())) {
		std::cout << "Error: Wrong coordinates" << std::endl;
	}
}

Triangle::~Triangle()
{
}

void Triangle::draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char GREEN[] = { 0, 255, 0 };
	board.draw_triangle(_points[0].getX(), _points[0].getY(),
		_points[1].getX(), _points[1].getY(),
		_points[2].getX(), _points[2].getY(), GREEN, 100.0f).display(disp);
}

void Triangle::clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char BLACK[] = { 0, 0, 0 };
	board.draw_triangle(_points[0].getX(), _points[0].getY(),
		_points[1].getX(), _points[1].getY(),
		_points[2].getX(), _points[2].getY(), BLACK, 100.0f).display(disp);
}

double Triangle::getArea() const {
	return (this->_p1.getX() * (this->_p2.getY() - this->_p3.getY()) + this->_p2.getX() * (this->_p3.getY() - this->_p1.getY()) + this->_p3.getX() * (this->_p1.getY() - this->_p2.getY())) / 2;
}

double Triangle::getPerimeter() const {
	return this->_p1.distance(this->_p2) + this->_p2.distance(this->_p3) + this->_p3.distance(this->_p1);
}