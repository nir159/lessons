#include "functions.h"
#include <iostream>
#include "Car.h"



int main() {

	//check compare
	std::cout << "correct print is 1 -1 0" << std::endl;
	std::cout << compare<double>(1.0, 2.5) << std::endl;
	std::cout << compare<double>(4.5, 2.4) << std::endl;
	std::cout << compare<double>(4.4, 4.4) << std::endl;

	std::cout << "correct print is 1 -1 0" << std::endl;
	std::cout << compare<char>('2', '3') << std::endl;
	std::cout << compare<char>('z', 'a') << std::endl;
	std::cout << compare<char>('a', 'a') << std::endl;

	std::cout << "correct print is 1 -1 0" << std::endl;
	std::cout << compare<Car>(Car("Red"), Car("yellow")) << std::endl;
	std::cout << compare<Car>(Car("blue"), Car("Orange")) << std::endl;
	std::cout << compare<Car>(Car("Green"), Car("Green")) << std::endl;

	//check bubbleSort
	std::cout << "correct print is sorted array" << std::endl;

	const int arr_size = 5;
	double doubleArr[arr_size] = { 1000.0, 2.0, 3.4, 17.0, 50.0 };
	bubbleSort<double>(doubleArr, arr_size);
	for (int i = 0; i < arr_size; i++) {
		std::cout << doubleArr[i] << " ";
	}
	std::cout << std::endl;

	//char
	char charArr[arr_size] = { 'a', 'r', '3', 'z', 'g' };
	bubbleSort<char>(charArr, arr_size);
	for (int i = 0; i < arr_size; i++) {
		std::cout << charArr[i] << " ";
	}
	std::cout << std::endl;

	//Car
	Car carArr[arr_size] = { Car("Yellow"), Car("Red"), Car("Blue"), Car("Orange"), Car("Green") };
	bubbleSort<Car>(carArr, arr_size);
	for (int i = 0; i < arr_size; i++) {
		std::cout << carArr[i] << " ";
	}
	std::cout << std::endl;

	//check printArray
	std::cout << "correct print is sorted array" << std::endl;
	printArray<double>(doubleArr, arr_size);
	std::cout << std::endl;

	printArray<char>(charArr, arr_size);
	std::cout << std::endl;

	printArray<Car>(carArr, arr_size);
	std::cout << std::endl;

	system("pause");
	return 1;
}