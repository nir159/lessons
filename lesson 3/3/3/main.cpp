#include "Vector.h"
#include <iostream>

int main() {
	Vector arr(2);
	Vector arr3 = NULL;
	arr.push_back(90);
	arr.push_back(30);
	arr.reserve(11);
	arr.push_back(30);
	arr.resize(20, 2);
	Vector arr2(arr);
	arr2.pop_back();
	arr2.pop_back();
	arr -= arr2;
	arr3 = arr - arr2;
	std::cout << arr << arr2 << arr3;
	arr.~Vector();
	arr2.~Vector();
	getchar();
	return 0;
}