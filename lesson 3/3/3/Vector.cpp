#include "Vector.h"
#include <iostream>

/*
function will copy one array to another and initialize empty space, delete src and place destination in source
input:
src - array to copy
dst - array to imitate
sizeSrc - size of source array
sizeDst - size of destination array
output:
the new array inizialized
* sizeDst needs to be bigger or equal to sizeSrc
*/
int* copyArr(int* src, int* dst, int sizeSrc, int sizeDst) {
	int i = 0;
	if (sizeDst >= sizeSrc) {
		for (i = 0; i < sizeSrc; i++) {
			dst[i] = src[i];
		}
		for (i = sizeSrc; i < sizeDst; i++) {
			dst[i] = 0;
		}
		delete[] src;
		src = dst;
		dst = NULL;
	}
	return src;
}

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
		this->_elements = copyArr(this->_elements, newArr, this->_size, this->_capacity + this->_resizeFactor);
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

/*
Function will make sure vector has at least n space(including the existing elements)
input:
new capacity
*/
void Vector::reserve(int n) {
	int resize = 0;
	int* newArr = NULL;
	if (n > this->_capacity) {
		if ((n % this->_resizeFactor) != 0){
			resize = ((n / this->_resizeFactor) + 1) * this->_resizeFactor;
		}
		else {
			resize = n;
		}
		newArr = new int[resize];
		this->_elements = copyArr(this->_elements, newArr, this->_size, resize);
		newArr = NULL;
		this->_capacity = resize;
	}
}

/*
changes the size of the array to n
input:
the new size
*/
void Vector::resize(int n) {
	int i = 0;
	if (n > this->_capacity) {
		reserve(n);
		for (i = this->_size; i < n; i++) {
			this->_elements[i] = VALUE;
		}
		this->_size = n;
	}
	else {
		while (n < this->_size) {
			pop_back();
		}
	}
}

/*
Assign the value to all existed elements
input:
value to assign
*/
void Vector::assign(int val) {
	int i = 0;
	while (this->_elements[i] != NULL) {
		this->_elements[i] = val;
	}
}

/*
changes the size of the array to n, if adds numbers assigns them to val
input:
the new size, the number to asssign to every new element
*/
void Vector::resize(int n, const int& val) {
	int i = 0;
	resize(n);
	for (i = 0; i < this->_capacity; i++) {
		if (this->_elements[i] == VALUE) {
			this->_elements[i] = val;
		}
	}
}