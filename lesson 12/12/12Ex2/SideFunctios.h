#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <thread>
#include <mutex>
#include <assert.h>
#include <chrono>
#include <future>
#include <condition_variable>

#define FILE "data.txt"

class SideFunctions
{
public:
	// This function keeps going until gets num from user and returns the number
	static int inputNum();
	// This function returns the index of a if string exists in a vector else returns -1
	static int vFind(std::vector<std::string> names, std::string search);
	// This function prints the vector
	static void printVector(std::vector<std::string> names);
};
