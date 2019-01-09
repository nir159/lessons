#include "threads.h"
#include <iostream>


int main()
{
	call_I_Love_Threads();

	vector<int> primes1;
	/*primes1 = callGetPrimes(0, 10000);
	printVector(primes1);
	primes1 = callGetPrimes(0, 100000);
	printVector(primes1);
	primes1 = callGetPrimes(0, 1000000);
	printVector(primes1);*/
	vector<int> primes3 = callGetPrimes(93, 289);

	callWritePrimesMultipleThreads(0, 1000, "primes2.txt", 2);
	//callWritePrimesMultipleThreads(0, 100000, "primes2.txt", 2);
	//callWritePrimesMultipleThreads(0, 1000000, "primes2.txt", 2);

	system("pause");
	return 0;
}