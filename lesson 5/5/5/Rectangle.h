#pragma once
#include "Polygon.h"

namespace myShapes
{
	// Calling it MyRectangle becuase Rectangle is taken by global namespace.
	class Rectangle : public Polygon
	{
		Point _p1;
		double _width;
		double _length;
	public:
		// There's a need only for the top left corner 
		Rectangle(const Point& a, double length, double width, const string& type, const string& name);
		virtual ~Rectangle();

		// override functions if need (virtual + pure virtual)
		double getArea() const;
		double getPerimeter() const;

		void draw(cimg_library::CImgDisplay & disp, cimg_library::CImg<unsigned char>& board);

		void clearDraw(cimg_library::CImgDisplay & disp, cimg_library::CImg<unsigned char>& board);

	};
}