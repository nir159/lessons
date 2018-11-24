#pragma once
#include "Circle.h"
#include "Arrow.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "CImg.h"
#include <vector>
#include <iostream>
#include <sstream>


class Menu
{
public:

	Menu();
	~Menu();

	// more functions..

private: 

	cimg_library::CImg<unsigned char>* _board;
	cimg_library::CImgDisplay* _disp;
};

