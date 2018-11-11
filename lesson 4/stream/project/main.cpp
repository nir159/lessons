#pragma comment(lib, "../Debug/stream")
#include <iostream>
#include "../stream/msl.h"

using namespace msl;

int main() {
	OutStream obj;
	obj << "I am the Doctor and I'm " << 1500 << " years old" << endline;
	getchar();
	return 0;
}
