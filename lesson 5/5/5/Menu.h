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

	int getNum(string msg);
	string& getString(string msg);
	int getChoise();
	// prints to user
	void clearScreen();
	void choiseMainScreen();
	void choiseAddShape();
	void printShape();
	void printShapes();

	// work with shapes
	void addChoiseShape();
	void shapeModify();
	void clearAndDraw();
	void clearBoard();
	void exit();

private: 
	vector<Shape*> _shapes;
	int _choice;
	cimg_library::CImg<unsigned char>* _board;
	cimg_library::CImgDisplay* _disp;
};

