#pragma once
#include <iostream>
#include <thread>
#include<vector>
#include <fstream>
#include <mutex>

void getPrimes(int begin, int end, std::vector<int>& primes);
void writePrimesToFile(int begin, int end, std::ofstream& file);
void callWritePrimesMultipleThreads(int begin, int end, std::string filePath, int N);