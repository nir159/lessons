#include <iostream>
#include "OutStream.h"
#include "Logger.h"

int main() {
	/*FileStream obj(msg.txt);
	obj << "I am the Doctor and I'm " << 1500 << " years old" << endline;
	OutStream os;
	os << "I am the Doctor and I'm " << 1500 << " years old" << endline;
	OutStreamEncrypted obj(1);
	obj << "I am the Doctor and I'm " << 1500 << " years old" << endline;*/
	Logger obj;
	Logger secondObj;
	obj << "I am the Doctor and I'm " << 1500 << " years old" << endline;
	secondObj << "this is line number " << 2 << " some more important information" << endline;
	obj << "this is the last line";
	getchar();
	return 0;
}