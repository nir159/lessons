#include "threads.h"

#define ZERO 0
#define ONE 1 
#define START 2 

std::mutex mtx;

/* Function saves all the prime nums from begin to end in the vector
Input: beginning, end, vector of primes*/
void getPrimes(int begin, int end, std::vector<int>& primes) {
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

void writePrimesToFile(int begin, int end, std::ofstream& file) {
	std::vector<int> primes;
	std::vector<int>::iterator it;

	if (!file.is_open()) { // check if the file has been opened
		std::cout << "Error occurred" << std::endl;
		exit(1);
	}
	getPrimes(begin, end, primes);
	std::lock_guard<std::mutex> lck(mtx);
	for (it = primes.begin(); it != primes.end(); ++it) {
		file << *it << std::endl; // write to the file
	}
}

void callWritePrimesMultipleThreads(int begin, int end, std::string filePath, int N) {
	double duration;
	std::ofstream file;
	std::thread thread;

	file.open(filePath);
	if (!file.is_open()) { // check if the file has been opened
		std::cout << "Error occurred" << std::endl;
		exit(1);
	}
	// Write the primes to file
	while (begin + N < end) {
		thread = std::thread(writePrimesToFile, begin, begin + N, std::ref(file));
		thread.detach();
		begin += N + ONE;
	}

	thread = std::thread(writePrimesToFile, begin, end, std::ref(file));
	thread.join(); // waiting for the last thread to finish

	std::cout << "Done." << std::endl;
}
