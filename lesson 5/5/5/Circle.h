#pragma once

#include "Shape.h"
#include "Point.h"
#include <vector>
#define PI 3.14

class Circle : public Shape
{
	Point _center;
	double _radius;
public:
	Circle(const Point& center, double radius, const string& type, const string& name);
	~Circle();


	const Point& getCenter() const;
	double getRadius() const;

	virtual void draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board);
	virtual void clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board);
	virtual void move(const Point& other);

	// override functions if need (virtual + pure virtual)
	double getArea() const;
	double getPerimeter() const;

};