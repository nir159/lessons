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
	void clearScreen();
	void choiseMainScreen();
	int getChoise();
private: 
	vector<Shape> shapes;
	int _choise;
	cimg_library::CImg<unsigned char>* _board;
	cimg_library::CImgDisplay* _disp;
};

