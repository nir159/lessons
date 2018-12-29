#include "BSNode.h"
#include <iostream>
#include <string>
using namespace std;

#define ARR_LENGTH 15
#define FIRST 0
#define SECOND 1

int main()
{
	int i = 0;
	int intArr[ARR_LENGTH] = { 15, 53, 485, 1, 1568, 12, 54, 45, 65, 89, 65, 54, 45, 857, 455 };
	char charArr[ARR_LENGTH] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o'};
	std::cout << "Before sorting: " << std::endl;
	for (i = FIRST; i < ARR_LENGTH; i++) {
		std::cout << intArr[i] << " ";
	}
	std::cout << std::endl;
	for (i = FIRST; i < ARR_LENGTH; i++) {
		std::cout << charArr[i] << " ";
	}
	std::cout << std::endl << "After sorting: " << std::endl;
	BSNode<int>* bsi = new BSNode<int>(intArr[FIRST]);
	for (i = SECOND; i < ARR_LENGTH; i++) {
		bsi->insert(intArr[i]);
	}
	bsi->printNodes();
	BSNode<char>* bsc = new BSNode<char>(charArr[FIRST]);
	for (i = SECOND; i < ARR_LENGTH; i++) {
		bsc->insert(charArr[i]);
	}
	bsc->printNodes();
	system("PAUSE");
	return 0;
}