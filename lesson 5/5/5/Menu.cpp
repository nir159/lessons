#include "Menu.h"


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
	cin >> this->_choise;
	while (!cin || (this->_choise < 0 && this->_choise > 3)) {
		cout << "Error: number is needed(0~3)" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max());
	}
}

void Menu::choiseAddShape() {
	cout << "Enter 0 to add a circle.\nEnter 1 to add an arrow.\nEnter 2 to add a triangle.\nEnter 3 to add a rectangle." << endl;
	cin >> this->_choise;
	while (!cin || (this->_choise < 0 && this->_choise > 3)) {
		cout << "Error: number is needed" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max());
	}
}

void Menu::addChoiseShape() {
	int x = 0;
	int y = 0;
	double radius = 0;
	string name;
	Point p1 = Point(0, 0);
	Point p2 = Point(0, 0);

	switch (this->_choise) {
		case 0:
			cout << "Please enter X: " << endl;
			while (!cin >> x) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter X: " << endl;
			}
			cout << "Please enter Y: " << endl;
			while (!cin >> y) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter Y: " << endl;
			}
			cout << "Please enter radius: " << endl;
			cin >> radius;
			while (!cin || radius < 1) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter radius: " << endl;
			}
			cout << "Please enter the name of the shape: " << endl;
			while (!(cin >> name)) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter valid name: " << endl;
			}
			this->_shapes.push_back(Circle(Point(x, y), radius, "circle", name));
			this->_shapes[this->_shapes.size()-1].draw(*(this->_disp), *(this->_board));
		case 1:
			cout << "Please enter X: " << endl;
			while (!cin >> x) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter X: " << endl;
			}
			cout << "Please enter Y: " << endl;
			while (!cin >> y) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter Y: " << endl;
			}
			p1 = Point(x, y);
			cout << "Please enter X: " << endl;
			while (!cin >> x) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter X: " << endl;
			}
			cout << "Please enter Y: " << endl;
			while (!cin >> y) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter Y: " << endl;
			}
			cout << "Please enter the name of the shape: " << endl;
			while (!(cin >> name)) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter valid name: " << endl;
			}
			this->_shapes.push_back(Arrow(p1, Point(x, y), "arrow", name));
			this->_shapes[this->_shapes.size() - 1].draw(*(this->_disp), *(this->_board));
		case 2:
			cout << "Please enter X: " << endl;
			while (!cin >> x) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter X: " << endl;
			}
			cout << "Please enter Y: " << endl;
			while (!cin >> y) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter Y: " << endl;
			}
			p1 = Point(x, y);
			cout << "Please enter X: " << endl;
			while (!cin >> x) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter X: " << endl;
			}
			cout << "Please enter Y: " << endl;
			while (!cin >> y) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter Y: " << endl;
			}
			p2 = Point(x, y);
			cout << "Please enter X: " << endl;
			while (!cin >> x) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter X: " << endl;
			}
			cout << "Please enter Y: " << endl;
			while (!cin >> y) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter Y: " << endl;
			}
			cout << "Please enter the name of the shape: " << endl;
			while (!(cin >> name)) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter valid name: " << endl;
			}
			this->_shapes.push_back(Triangle(p1, p2, Point(x, y), "triangle", name));
			this->_shapes[this->_shapes.size() - 1].draw(*(this->_disp), *(this->_board));
		case 3:
			cout << "Please enter X: " << endl;
			while (!cin >> x) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter X: " << endl;
			}
			cout << "Please enter Y: " << endl;
			while (!cin >> y) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter Y: " << endl;
			}
			p1 = Point(x, y);
			cout << "Please enter the length of the shape: " << endl;
			while (!cin >> x) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter the length of the shape: " << endl;
			}
			cout << "Please enter the width of the shape: " << endl;
			while (!cin >> y) {
				cout << "Error: number is needed" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				cout << "Please enter the width of the shape: " << endl;
			}
			this->_shapes.push_back(myShapes::Rectangle(p1, x, y, "rectangle", name));
			this->_shapes[this->_shapes.size() - 1].draw(*(this->_disp), *(this->_board));
	}
}

void Menu::clearBoard() {
	int i = 0;
	for (i = 0; i < this->_shapes.size(); i++) {
		this->_shapes[i].clearDraw();
	}
	this->_shapes.clear();
}

void Menu::exit() {
	clearBoard();
	clearScreen();
	cout << "Good Bye! " << endl;
}