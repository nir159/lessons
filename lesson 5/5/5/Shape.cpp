#include "Shape.h"

Shape::Shape(const string& name, const string& type) : _name(name), _type(type) 
{
}

void Shape::printDetails() const {
	std::cout << "Shape name ~ " << this->_name.c_str() << std::endl << "Shape type ~ " << this->_type.c_str() << std::endl;
}

string Shape::getType() const {
	return this->_type;
}

string Shape::getName() const {
	return this->_name;
}