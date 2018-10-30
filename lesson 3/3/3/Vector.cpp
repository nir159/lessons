#include "Vector.h"
#include <iostream>

// part A

// constructor with size only
Vector::Vector(int n) {
	int i = 0;
	// can't be lower than 2
	if (n < 2) {
		n = 2;
	}
	this->_size = 0; // no elements yet
	this->_capacity = n;
	this->_resizeFactor = n;
	this->_elements = new int[n];
	for (i = 0; i < n; i++) {
		this->_elements[i] = 0;
	}
}

// destructor clears the memory located
Vector::~Vector() {
	delete[] this->_elements;
	this->_elements = nullptr;
}


// getters
int Vector::size() const {
	return this->_size;
}

int Vector::capacity() const {
	return this->_capacity;
}

int Vector::resizeFactor() const {
	return this->_resizeFactor;
}

bool Vector::empty() const {
	return (this->_size == 0);
}

// part B

/*
Adds an element to the end of the vector
input:
The new value to add to the array
*/
void Vector::push_back(const int& val) {
	int i = 0;
	int* newArr = NULL;
	if (this->_size < this->_capacity) {
		while (this->_elements[i] != NULL) {
			i++;
		}
		this->_elements[i] = val;
		this->_size++;
	}
	else {
		// creating new array with bigger capacity
		newArr = new int[(this->_capacity + this->_resizeFactor)];
		// initialize the array
		for (i = 0; i < this->_capacity; i++) {
			newArr[i] = this->_elements[i];
		}
		for (i = this->_capacity; i < this->_capacity + this->_resizeFactor; i++) {
			newArr[i] = 0;
		}
		delete[] this->_elements;
		this->_elements = newArr;
		newArr = NULL;
		this->_capacity += this->_resizeFactor;
		push_back(val);
	}
}

/*
Removes an element from the end of the vector
output:
if the vector is empty returns -9999 else returns the element
*/
int Vector::pop_back() {
	int val = 0, i = 0;
	if (empty()) {
		std::cout << "error: pop from empty vector";
		val = -9999;
	}
	else {
		val = this->_elements[this->_size - 1];
		this->_elements[this->_size - 1] = 0;
		this->_size--;
	}
	return val;
}