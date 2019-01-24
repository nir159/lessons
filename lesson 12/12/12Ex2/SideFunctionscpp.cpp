#include "SideFunctios.h"

int SideFunctions::inputNum() {
	int choise;
	std::cin >> choise;
	while (!std::cin) {
		std::cout << "Bad value!" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> choise;
	}
	return choise;
}

int SideFunctions::vFind(std::vector<std::string> names, std::string search) {
	std::vector<std::string>::iterator it;
	for (it = names.begin(); it != names.end(); ++it) {
		if ((*it).compare(search) == 0) {
			return (it - names.begin());// returns index of iterator
		}
	}
	return -1;
}

void SideFunctions::printVector(std::vector<std::string> names) {
	std::vector<std::string>::iterator it;
	for (it = names.begin(); it != names.end(); ++it) {
		std::cout << *it << std::endl;
	}
}
