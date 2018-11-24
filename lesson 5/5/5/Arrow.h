#pragma once
#include "Polygon.h"

class Arrow : public Shape
{
public:
	Arrow(const Point& a, const Point& b, const string& type, const string& name);
	~Arrow();

	virtual void draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board);
	virtual void clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board);

	// override functions if need (virtual + pure virtual)
	double getArea() const;
	double getPerimeter() const;
private:
	Point _p1;
	Point _p2;
};