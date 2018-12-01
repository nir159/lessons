#include <iostream>
#include <string.h>
#define INVALID 8200

bool isInvalid(int num) {
	if (num == INVALID) {
		return true;
	}
	return false;
}

int add(int a, int b) {
	if (isInvalid(a) || isInvalid(b) || isInvalid(a + b)) {
		throw std::string("This user is not authorized to access 8200, please enter different numbers, or try to get clearance in 1 year.");
	}
  return a + b;
}

int  multiply(int a, int b) {
	if (isInvalid(a) || isInvalid(b)) {
		throw std::string("This user is not authorized to access 8200, please enter different numbers, or try to get clearance in 1 year.");
	}
  int sum = 0;
  for(int i = 0; i < b; i++) {
	  if (add(sum, a)) {
		  throw std::string("This user is not authorized to access 8200, please enter different numbers, or try to get clearance in 1 year.");
	  }
    sum = add(sum, a);
  };
  if (isInvalid(sum)) {
	  throw std::string("This user is not authorized to access 8200, please enter different numbers, or try to get clearance in 1 year.");
  }
  return sum;
}

int  pow(int a, int b) {
	if (isInvalid(a) || isInvalid(b)) {
		throw std::string("This user is not authorized to access 8200, please enter different numbers, or try to get clearance in 1 year.");
	}
  int exponent = 1;
  for(int i = 0; i < b; i++) {
	  if (isInvalid(multiply(exponent, a))) {
		  throw std::string("This user is not authorized to access 8200, please enter different numbers, or try to get clearance in 1 year.");
	  }
    exponent = multiply(exponent, a);
  };
  if (isInvalid(exponent)) {
	  throw std::string("This user is not authorized to access 8200, please enter different numbers, or try to get clearance in 1 year.");
  }
  return exponent;
}

int main(void) {
	try {
		std::cout << add(5, 8200) << std::endl;
	}
	catch(const std::string& error) {
		std::cout << "Error: " << error.c_str() << std::endl;
	}
	system("PAUSE");
	return 0;
}