#include "Vector.h"
#include <iostream>


// constructor with size only
Vector::Vector(int n) {
	// can't be lower than 2
	if (n < 2) {
		n = 2;
	}
	this->_capacity = n;
	this->_resizeFactor = n;
	this->_size = n;
	this->_elements = new int[n];
}

// destructor clears the memory located
Vector::~Vector() {
	delete[] this->_elements;
	this->_elements = nullptr;
}


