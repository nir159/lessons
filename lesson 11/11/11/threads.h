#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include<vector>
#include <Windows.h>
#include <thread>
#include <ctime>

#define ZERO 0
#define ONE 1 
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
		if (begin == ZERO || begin == ONE) {
			prime = false;
		}
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

void writePrimesToFile(int begin, int end, ofstream& file) {
	vector<int> primes;
	std::vector<int>::iterator it;
	if (!file.is_open()) { // check if the file has been opened
		cout << "Error occurred" << endl;
		exit(1);
	}
	getPrimes(begin, end, primes);
	for (it = primes.begin(); it != primes.end(); ++it) {
		file << *it << endl; // write to the file
	}
}

void callWritePrimesMultipleThreads(int begin, int end, string filePath, int N) {
	std::clock_t start; 
	double duration;
	ofstream file;
	std::thread thread;

	file.open(filePath);
	if (!file.is_open()) { // check if the file has been opened
		cout << "Error occurred" << endl;
		exit(1);
	}

	start = std::clock(); // calculate the time
	// Write the primes to file
	while (begin + N < end) {
		thread = std::thread(writePrimesToFile, begin, begin+N, std::ref(file));
		thread.detach();
		begin += N+ONE; // because I don't want the same number to appear twice
	}

	thread = std::thread(writePrimesToFile, begin, end, std::ref(file));
	thread.join(); // waiting for the last thread to finish

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC; // change to seconds

	std::cout << "The total time it took to write to file is: " << duration << " seconds." << std::endl;
}
