#include "Hexagon.h"
#include "shapeexception.h"
#include "MathUtils.h"

Hexagon::Hexagon(std::string nam, std::string col, double member) : Shape(col, nam)
{
	if (member < 0) {
		throw shapeException();
	}
	setMember(member);
}

Hexagon::~Hexagon()
{
}

void Hexagon::draw() {
	std::cout << "Color is " << getColor() << std::endl << "Name is " << getName() << std::endl << "member is " << getMember() << std::endl << "Area: " << MathUtils::CalHexagonArea(getMember()) << std::endl;
}

double Hexagon::getMember() {
	return member;
}

void Hexagon::setMember(double mem) {
	if (mem < 0) {
		throw shapeException();
	}
	member = mem;
}

double Hexagon::CalArea() {
	return MathUtils::CalHexagonArea(member);
}