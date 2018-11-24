#pragma once
#include "Polygon.h"

class Triangle : public Polygon
{
	Point _p1;
	Point _p2;
	Point _p3;
public:
	Triangle(const Point& a, const Point& b, const Point& c, const string& type, const string& name);
	virtual ~Triangle();
	
	void draw(cimg_library::CImgDisplay & disp, cimg_library::CImg<unsigned char>& board);

	void clearDraw(cimg_library::CImgDisplay & disp, cimg_library::CImg<unsigned char>& board);

	// override functions if need (virtual + pure virtual)
	double getArea() const;
	double getPerimeter() const;
};