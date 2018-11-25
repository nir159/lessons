#include "Menu.h"

int Menu::getNum(string msg) {
	int x;
	cout << msg << endl;
	if (!(cin >> x)) {
		cout << "Error: wrong value" << endl;
		cin.clear();
		system("PAUSE");
		_exit(EXIT_FAILURE);
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

int Menu::getChoice() {
	return this->_choice;
}

void Menu::clearScreen() {
	system("CLS");
}

void Menu::choiceMainScreen(){
	this->_choice = getNum("Enter 0 to add a new shape.\nEnter 1 to modify or get information from a current shape.\nEnter 2 to delete all of the shapes.\nEnter 3 to exit.");
	while (this->_choice < 0 || this->_choice > 3) {
		cout << "only 0~3" << endl;
		this->_choice = getNum("Enter 0 to add a new shape.\nEnter 1 to modify or get information from a current shape.\nEnter 2 to delete all of the shapes.\nEnter 3 to exit.");
	}
}

void Menu::choiceAddShape() {
	this->_choice = getNum("Enter 0 to add a circle.\nEnter 1 to add an arrow.\nEnter 2 to add a triangle.\nEnter 3 to add a rectangle.");
	while (this->_choice < 0 || this->_choice > 3) {
		cout << "only 0~3" << endl;
		this->_choice = getNum("Enter 0 to add a circle.\nEnter 1 to add an arrow.\nEnter 2 to add a triangle.\nEnter 3 to add a rectangle.");
	}
}

void Menu::printShape() {
	cout << this->_shapes[this->_choice]->getType() << "		" << this->_shapes[this->_choice]->getName() << "		" << this->_shapes[this->_choice]->getArea() << "		" << this->_shapes[this->_choice]->getPerimeter() << endl;
}

void Menu::printShapes() {
	int i = 0;
	for (i = 0; i < this->_shapes.size(); i++) {
		cout << "Enter " << i << " for " << this->_shapes[i]->getType() << "(" << this->_shapes[i]->getName() << ")" << endl;
	}
}

void Menu::addChoiceShape() {
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
			if (!cin || radius < 1) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				system("PAUSE");
				_exit(EXIT_FAILURE);
			}
			cout << "Please enter the name of the shape: " << endl;
			if (!(cin >> name)) {
				cout << "Error: wrong value" << endl;
				cin.clear();
				system("PAUSE");
				_exit(EXIT_FAILURE);
			}
			this->_shapes.push_back(new Circle(Point(x, y), radius, name, "Circle"));
			this->_shapes[this->_shapes.size()-1]->draw(*(this->_disp), *(this->_board));
			break;
		case 1:
			x = getNum("Please enter X: ");
			y = getNum("Please enter Y: ");
			p1 = Point(x, y);
			x = getNum("Please enter X: ");
			y = getNum("Please enter Y: ");
			cout << "Please enter the name of the shape: " << endl;
			if (!(cin >> name)) {
				cout << "Error: wrong value" << endl;
				cin.clear();
				system("PAUSE");
				_exit(EXIT_FAILURE);
			}
			this->_shapes.push_back(new Arrow(p1, Point(x, y), name, "Arrow"));
			this->_shapes[this->_shapes.size() - 1]->draw(*(this->_disp), *(this->_board));
			break;
		case 2:
			x = getNum("Please enter X: ");
			y = getNum("Please enter Y: ");
			p1 = Point(x, y);
			x = getNum("Please enter X: ");
			y = getNum("Please enter Y: ");
			p2 = Point(x, y);
			x = getNum("Please enter X: ");
			y = getNum("Please enter Y: ");
			cout << "Please enter the name of the shape: " << endl;
			if (!(cin >> name)) {
				cout << "Error: wrong value" << endl;
				cin.clear();
				system("PAUSE");
				_exit(EXIT_FAILURE);
			}
			this->_shapes.push_back(new Triangle(p1, p2, Point(x, y), name, "Triangle"));
			this->_shapes[this->_shapes.size() - 1]->draw(*(this->_disp), *(this->_board));
			break;
		case 3:
			x = getNum("Please enter X: ");
			y = getNum("Please enter Y: ");
			p1 = Point(x, y);
			x = getNum("Please enter the length of the shape: ");
			y = getNum("Please enter the width of the shape: ");
			cout << "Please enter the name of the shape: " << endl;
			if (!(cin >> name)) {
				cout << "Error: wrong value" << endl;
				cin.clear();
				system("PAUSE");
				_exit(EXIT_FAILURE);
			}
			this->_shapes.push_back(new myShapes::Rectangle(p1, x, y, name, "Rectangle"));
			this->_shapes[this->_shapes.size() - 1]->draw(*(this->_disp), *(this->_board));
			this->_choice = 0;
	}
}

void Menu::clearAll () {
	int i = 0;
	for (i = 0; i < this->_shapes.size(); i++) {
		this->_shapes[i]->clearDraw(*(this->_disp), *(this->_board));
	}
}


void Menu::addAll() {
	int i = 0;
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
			x = getNum("Please enter the X moving scale: ");
			y = getNum("Please enter the Y moving scale: ");
			clearAll();
			this->_shapes[this->_choice]->move(Point(x, y));
			addAll();
			clearScreen();
			break;
		case 1:
			printShape();
			system("PAUSE");
			clearScreen();
			break;
		case 2:
			clearAll();
			this->_shapes.erase(this->_shapes.begin() + this->_choice);
			addAll();
			clearScreen();
			break;
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
	cout << string(100, '\n');
	cout << "Good Bye! " << endl;
}