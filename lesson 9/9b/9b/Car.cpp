#include "Car.h"

Car::Car() : color("White") {}

Car::Car(std::string c): color(c) {}

Car::~Car(){}

std::ostream& operator<<(std::ostream& os, Car c)
{
	printf("%s", c.color.c_str());
	return os;
}

bool Car::operator==(const Car& c) {
	if (color.compare(c.color) == NULL) {
		return true;
	}
	return false;
}

bool Car::operator<(const Car& c) {
	if (color.compare(c.color) < NULL) {
		return true;
	}
	return false;
}

Car& Car::operator=(const Car& c) {
	color = c.color;
	return *this;
}