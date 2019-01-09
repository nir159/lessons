#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include<vector>
#include <Windows.h>
#include <thread>

#define START 2 

using namespace std;

// Function prints the message
void I_Love_Threads() {
	std::cout << "I Love Threads" << std::endl;
}

// Calls the print function using thread
void call_I_Love_Threads() {
	HANDLE WINAPI thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)I_Love_Threads, NULL, 0, NULL); // creates the thread
	WaitForSingleObject(thread, INFINITE); // wait until finished the function 
	CloseHandle(thread); // close thread
}

void printVector(vector<int> primes) {
	std::vector<int>::iterator it;
	for (it = primes.begin(); it != primes.end(); ++it) {
		std::cout << *it << endl;
	}
}

/* Function saves all the prime nums from begin to end in the vector
Input: beginning, end, vector of primes*/
void getPrimes(int begin, int end, vector<int>& primes) {
	int i = 0;
	bool prime = true;
	while (begin <= end) { // loop over the numbers
		prime = true;
		i = START;
		while (i <= begin / START && prime) // check if the current number is not prime if not prime leaves the loop
		{
			if (begin % i == 0)
			{
				prime = false; // not prime
			}
			i++;
		}
		if (prime) {
			primes.insert(primes.end(), begin);
		}
		begin++;
	}
}

vector<int> callGetPrimes(int begin, int end) {
	vector<int> primes;
	std::thread getPrimes(getPrimes, begin, end, std::ref(primes));// creates the thread
	getPrimes.join(); // wait until finished the function
	return primes;
}


void writePrimesToFile(int begin, int end, ofstream& file);
void callWritePrimesMultipleThreads(int begin, int end, string filePath, int N);
