#include "Rectangle.h"

myShapes::Rectangle::Rectangle(const Point& a, double length, double width, const string& type, const string& name) : Polygon(type, name), _p1(a), _length(length), _width(width) {
	if (length <= 0 || width <= 0) {
		std::cout << "Error: wrong size" << std::endl;
	}
}

myShapes::Rectangle::~Rectangle()
{
}

void myShapes::Rectangle::draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char WHITE[] = { 255, 255, 255 };
	board.draw_rectangle(_points[0].getX(), _points[0].getY(),
		_points[1].getX(), _points[1].getY(), WHITE, 100.0f).display(disp);
}

void myShapes::Rectangle::clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char BLACK[] = { 0, 0, 0};
	board.draw_rectangle(_points[0].getX(), _points[0].getY(),
		_points[1].getX(), _points[1].getY(), BLACK, 100.0f).display(disp);
}

double myShapes::Rectangle::getArea() const {
	return this->_length * this->_width;
}

double myShapes::Rectangle::getPerimeter() const {
	return this->_length * 2 + this->_width * 2;
}