#include "threads.h"
#include <iostream>


int main()
{
	call_I_Love_Threads();

	vector<int> primes1;
	primes1 = callGetPrimes(58, 100);
	printVector(primes1);
	vector<int> primes3 = callGetPrimes(93, 289);

	//callWritePrimesMultipleThreads(1, 100000, "primes2.txt", 2);

	system("pause");
	return 0;
}