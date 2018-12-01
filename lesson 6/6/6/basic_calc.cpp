#include <iostream>
#define INVALID 8200
#define ERROR -1

/*bool isInvalid(int num) {
	if (num == INVALID) {
		return true;
	}
	return false;
}

void printError() {
	std::cout << "This user is not authorized to access 8200, please enter different numbers, or try to get clearance in 1 year." << std::endl;
}

int add(int a, int b) {
	if (isInvalid(a) || isInvalid(b) || isInvalid(a + b)) {
		printError();
		return ERROR;
	}
  return a + b;
}

int  multiply(int a, int b) {
	if (isInvalid(a) || isInvalid(b)) {
		printError();
		return ERROR;
	}
  int sum = 0;
  for(int i = 0; i < b; i++) {
	  if (add(sum, a) == ERROR) {
		  printError();
		  return ERROR;
	  }
    sum = add(sum, a);
  };
  if (isInvalid(sum)) {
	  printError();
	  return ERROR;
  }
  return sum;
}

int  pow(int a, int b) {
  int exponent = 1;
  for(int i = 0; i < b; i++) {
	  if (multiply(exponent, a) == ERROR) {
		  printError();
		  return ERROR;
	  }
    exponent = multiply(exponent, a);
  };
  if (isInvalid(a) || isInvalid(b) || isInvalid(exponent)) {
	  printError();
	  return ERROR;
  }
  return exponent;
}

int main(void) {
	std::cout << add(1, 8199) << std::endl;
	system("PAUSE");
}*/