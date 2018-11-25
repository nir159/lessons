#include "Menu.h"

int Menu::getNum(string msg) {
	int x;
	cout << msg << endl;
	while (!cin >> x) {
		cout << "Error: wrong value" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max());
		cout << msg << endl;
	}
	return x;
}

string& Menu::getString(string msg) {
	string x;
	cout << msg << endl;
	while (!(cin >> x)) {
		cout << "Error: wrong value" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max());
		cout << msg << endl;
	}
	return x;
}

Menu::Menu() 
{
	_board  = new cimg_library::CImg<unsigned char>(700, 700, 1, 3, 1);
	_disp = new cimg_library::CImgDisplay(*_board, "Super Paint");
}

Menu::~Menu()
{
	_disp->close();
	delete _board;
	delete _disp;
}

int Menu::getChoise() {
	return this->getChoise;
}

void Menu::clearScreen() {
	cout << string(100, '\n');
}

void Menu::choiseMainScreen(){
	cout << "Enter 0 to add a new shape.\nEnter 1 to modify or get information from a current shape.\nEnter 2 to delete all of the shapes.\nEnter 3 to exit." << endl;
	cin >> this->_choice;
	while (!cin || (this->_choice < 0 && this->_choice > 3)) {
		cout << "Error: number is needed(0~3)" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max());
	}
}

void Menu::choiseAddShape() {
	cout << "Enter 0 to add a circle.\nEnter 1 to add an arrow.\nEnter 2 to add a triangle.\nEnter 3 to add a rectangle." << endl;
	cin >> this->_choice;
	while (!cin || (this->_choice < 0 && this->_choice > 3)) {
		cout << "Error: number is needed" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max());
	}
}

void Menu::printShape() {
	cout << this->_shapes[this->_choice]->getType() << "		" << this->_shapes[this->_choice]->getName() << "		" << this->_shapes[this->_choice]->getArea() << "		" << this->_shapes[this->_choice]->getPerimeter();
}

void Menu::printShapes() {
	int i = 0;
	for (i = 0; i < this->_shapes.size(); i++) {
		cout << "Enter " << i << " for " << this->_shapes[i]->getType() << "(" << this->_shapes[i]->getName() << ")" << endl;
	}
}

void Menu::addChoiseShape() {
	int x = 0;
	int y = 0;
	double radius = 0;
	string name;
	Point p1 = Point(0, 0);
	Point p2 = Point(0, 0);

	switch (this->_choice) {
		case 0:
			x = getNum("Please enter X: ");
			y = getNum("Please enter Y: ");
			cout << "Please enter radius: " << endl;
			cin >> radius;
			while (!cin || radius < 1) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter radius: " << endl;
			}
			name = getString("Please enter the name of the shape: ");
			this->_shapes.push_back(&Circle(Point(x, y), radius, "Circle", name));
			this->_shapes[this->_shapes.size()-1]->draw(*(this->_disp), *(this->_board));
		case 1:
			x = getNum("Please enter X: ");
			y = getNum("Please enter Y: ");
			p1 = Point(x, y);
			x = getNum("Please enter X: ");
			y = getNum("Please enter Y: ");
			name = getString("Please enter the name of the shape: ");
			this->_shapes.push_back(&Arrow(p1, Point(x, y), "Arrow", name));
			this->_shapes[this->_shapes.size() - 1]->draw(*(this->_disp), *(this->_board));
		case 2:
			x = getNum("Please enter X: ");
			y = getNum("Please enter Y: ");
			p1 = Point(x, y);
			x = getNum("Please enter X: ");
			y = getNum("Please enter Y: ");
			p2 = Point(x, y);
			x = getNum("Please enter X: ");
			y = getNum("Please enter Y: ");
			name = getString("Please enter the name of the shape: ");
			this->_shapes.push_back(&Triangle(p1, p2, Point(x, y), "Triangle", name));
			this->_shapes[this->_shapes.size() - 1]->draw(*(this->_disp), *(this->_board));
		case 3:
			x = getNum("Please enter X: ");
			y = getNum("Please enter Y: ");
			p1 = Point(x, y);
			x = getNum("Please enter the length of the shape: ");
			y = getNum("Please enter the width of the shape: ");
			this->_shapes.push_back(&myShapes::Rectangle(p1, x, y, "Rectangle", name));
			this->_shapes[this->_shapes.size() - 1]->draw(*(this->_disp), *(this->_board));
	}
}

void Menu::clearAndDraw() {
	int i = 0;
	for (i = 0; i < this->_shapes.size(); i++) {
		this->_shapes[i]->clearDraw(*(this->_disp), *(this->_board));
	}
	for (i = 0; i < this->_shapes.size(); i++) {
		this->_shapes[i]->draw(*(this->_disp), *(this->_board));
	}
}

void Menu::shapeModify() {
	int x = 0, y = 0;
	int option = 0;
	printShapes();
	do {
		this->_choice = getNum("Enter choice");
	} while (this->_choice < 0 || this->_choice > (this->_shapes.size() - 1));
	option = getNum("Enter 0 to move the shape\nEnter 1 to get its details.\nEnter 2 to remove the shape.");
	while (option < 0 || option > 2) {
		cout << "(0~2)" << endl;
		option = getNum("Enter 0 to move the shape\nEnter 1 to get its details.\nEnter 2 to remove the shape.");
	}
	switch (option) {
		case 0:
			clearScreen();
			do {
				x = getNum("Please enter the X moving scale: ");
			} while (x > 100 || x < -100);
			do {
				y = getNum("Please enter the Y moving scale: ");
			} while (y > 100 || y < -100);
			this->_shapes[this->_choice]->move(Point(x, y));
			clearAndDraw();
			clearScreen();
		case 1:
			printShape();
			system("PAUSE");
			clearScreen();
		case 2:
			this->_shapes[this->_choice]->clearDraw(*(this->_disp), *(this->_board));
			this->_shapes.erase(this->_shapes.begin() + this->_choice);
			clearAndDraw();
			clearScreen();
	}
}

void Menu::clearBoard() {
	int i = 0;
	for (i = 0; i < this->_shapes.size(); i++) {
		this->_shapes[i]->clearDraw(*(this->_disp), *(this->_board));
	}
	this->_shapes.clear();
}

void Menu::exit() {
	clearBoard();
	clearScreen();
	cout << "Good Bye! " << endl;
}