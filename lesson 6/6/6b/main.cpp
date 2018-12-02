#include <iostream>
#include "shape.h"
#include "circle.h"
#include "quadrilateral.h"
#include "rectangle.h"
#include "parallelogram.h"
#include <string>
#include "shapeException.h"
#include "Pentagon.h"
#include "Hexagon.h"

int main()
{
	std::string nam, col; double rad = 0, ang = 0, ang2 = 180; int height = 0, width = 0, member = 0;
	Circle circ(col, nam, rad);
	quadrilateral quad(nam, col, width, height);
	rectangle rec(nam, col, width, height);
	parallelogram para(nam, col, width, height, ang, ang2);
	Pentagon pen(nam, col, member);
	Hexagon hex(nam, col, member);

	Shape *ptrcirc = &circ;
	Shape *ptrquad = &quad;
	Shape *ptrrec = &rec;
	Shape *ptrpara = &para;
	Shape *ptrpen = &pen;
	Shape *ptrhex = &hex;

	
	std::cout << "Enter information for your objects" << std::endl;
	const char circle = 'c', quadrilateral = 'q', rectangle = 'r', parallelogram = 'p'; char shapetype; std::string shapeTypeCheck; // shapeTypeCheck was added for check
	char x = 'y';
	while (x != 'x') {
		std::cout << "which shape would you like to work with?.. \nc=circle, q = quadrilateral, r = rectangle, p = parallelogram, g = pentagon, h = Hexagon" << std::endl;
		std::cin >> shapeTypeCheck;
		while (shapeTypeCheck.length() > 1) {
			std::cout << "Warning - Don't try to build more than one shape at once" << std::endl;
			std::cin >> shapeTypeCheck;
		}
		shapetype = shapeTypeCheck[0]; // only one letter

try
		{

			switch (shapetype) {
			case 'c':
				std::cout << "enter color, name,  rad for circle" << std::endl;
				std::cin >> col >> nam >> rad;
				if (!std::cin) {
					throw inputException();
				}
				circ.setColor(col);
				circ.setName(nam);
				circ.setRad(rad);
				ptrcirc->draw();
				break;
			case 'q':
				std::cout << "enter name, color, height, width" << std::endl;
				std::cin >> nam >> col >> height >> width;
				if (!std::cin) {
					throw inputException();
				}
				quad.setName(nam);
				quad.setColor(col);
				quad.setHeight(height);
				quad.setWidth(width);
				ptrquad->draw();
				break;
			case 'r':
				std::cout << "enter name, color, height, width" << std::endl;
				std::cin >> nam >> col >> height >> width;
				if (!std::cin) {
					throw inputException();
				}
				rec.setName(nam);
				rec.setColor(col);
				rec.setHeight(height);
				rec.setWidth(width);
				ptrrec->draw();
				break;
			case 'p':
				std::cout << "enter name, color, height, width, 2 angles" << std::endl;
				std::cin >> nam >> col >> height >> width >> ang >> ang2;
				if (!std::cin) {
					throw inputException();
				}
				para.setName(nam);
				para.setColor(col);
				para.setHeight(height);
				para.setWidth(width);
				para.setAngle(ang, ang2);
				ptrpara->draw();
				break;
			case 'g':
				std::cout << "enter name, color, member" << std::endl;
				std::cin >> nam >> col >> member;
				if (!std::cin) {
					throw inputException();
				}
				pen.setName(nam);
				pen.setColor(col);
				pen.setMember(member);
				ptrpen->draw();
				break;
			case 'h':
				std::cout << "enter name, color, member" << std::endl;
				std::cin >> nam >> col >> member;
				if (!std::cin) {
					throw inputException();
				}
				hex.setName(nam);
				hex.setColor(col);
				hex.setMember(member);
				ptrhex->draw();
				break;
			default:
				std::cout << "you have entered an invalid letter, please re-enter" << std::endl;
				break;
			}
			std::cout << "would you like to add more object press any key if not press x" << std::endl;
			std::cin.get() >> x;
			if (!std::cin) {
				throw inputException();
			}
		}
		catch (shapeException e) // the type was std::exception which means the what() function wasn't the lower one.
		{			
			printf(e.what());
		}
		catch (inputException e)
		{
			printf(e.what());
			std::cin.clear();
			system("PAUSE");
			_exit(EXIT_FAILURE);
		}
		catch (...)
		{
			printf("caught a bad exception. continuing as usual\n");
		}
	}



		system("pause");
		return 0;
	
}