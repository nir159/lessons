#include "Vector.h"
#include <iostream>

int main() {
	Vector arr(2);
	arr.push_back(90);
	arr.push_back(30);
	arr.reserve(11);
	arr.push_back(30);
	arr.resize(20, 2);
	arr.~Vector();
	getchar();
	return 0;
}