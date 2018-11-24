#include "Arrow.h"

Arrow::Arrow(const Point& a, const Point& b, const string& type, const string& name) : Shape(type, name), _p1(a), _p2(b) {
	if (a.getX() == b.getX() && a.getY() == b.getY()) {
		std::cout << "Error: no arrow" << std::endl;
	}
}

Arrow::~Arrow() 
{
}

void Arrow::draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char RED[] = { 255, 0, 0 };

	board.draw_arrow(_p1.getX(), _p1.getY(),
		_p2.getX(), _p2.getY(), RED, 100.0f).display(disp);
}
void Arrow::clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char BLACK[] = { 0, 0, 0 };

	board.draw_arrow(_p1.getX(), _p1.getY(),
		_p2.getX(), _p2.getY(), BLACK, 100.0f).display(disp);
}

double Arrow::getArea() const{
	return 0;
}

double Arrow::getPerimeter() const {
	return this->_p1.distance(this->_p2);
}
