#pragma once
#include <iostream>

class Car {
public:
	std::string color;
	Car();
	Car(std::string c);
	~Car();

	bool operator==(const Car& c);
	bool operator<(const Car& lhs);
	Car& Car::operator=(const Car& c);
};

std::ostream& operator<<(std::ostream& os, Car c);