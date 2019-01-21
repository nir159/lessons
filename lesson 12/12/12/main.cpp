
#include "threads.h"

int main()
{
	callWritePrimesMultipleThreads(0, 1000, "primes2.txt", 2);
	//callWritePrimesMultipleThreads(0, 100000, "primes2.txt", 2);
	//callWritePrimesMultipleThreads(0, 1000000, "primes2.txt", 2);

	system("pause");
	return 0;
}