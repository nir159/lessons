#include "Menu.h"

int main()
{
	/*
	oid clearScreen();
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
	*/
	Menu m;
	while (m.getChoice() != 3) {
		m.clearScreen();
		m.choiceMainScreen();
		switch (m.getChoice()) {
			case 0:
				m.clearScreen();
				m.choiceAddShape();
				m.addChoiceShape();
				break;
			case 1:
				m.clearScreen();
				m.shapeModify();
				break;
			case 2:
				m.clearBoard();
				break;
			case 3:
				m.exit();
		}
	}
	system("PAUSE");
	return 0;
}