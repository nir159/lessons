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
	switch (this->_choise) {
		case 0:

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

}