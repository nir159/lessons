#include <iostream>
#include "OutStream.h"

int main() {
	FileStream obj("msg.txt");
	obj << "I am the Doctor and I'm " << 1500 << " years old" << endline;
	getchar();
	return 0;
}