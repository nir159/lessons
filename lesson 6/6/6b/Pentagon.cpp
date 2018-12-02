#include "Pentagon.h"
#include "shapeexception.h"
#include "MathUtils.h"

Pentagon::Pentagon(std::string nam, std::string col, double member) : Shape(col, nam)
{
	if (member < 0) {
		throw shapeException();
	}
	setMember(member);
}

Pentagon::~Pentagon()
{
}

void Pentagon::draw() {
	std::cout << "Color is " << getColor() << std::endl << "Name is " << getName() << std::endl << "member is " << getMember() << std::endl << "Area: " << MathUtils::CalPentagonArea(member) << std::endl;
}

double Pentagon::getMember() {
	return member;
}

void Pentagon::setMember(double mem) {
	if (mem < 0) {
		throw shapeException();
	}
	member = mem;
}

double Pentagon::CalArea() {
	return MathUtils::CalPentagonArea(member);
}