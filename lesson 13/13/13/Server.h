#pragma once
#include <thread>
#include <vector>
#include <mutex>
#include <fstream>
#include <exception>
#include <iostream>
#include <algorithm>
#include <string>
#include <WinSock2.h>
#include <Windows.h>
#include "Helper.h"

#define  FIRST_IN_LINE 1
#define MAX_BYTES 20
#define UPDATE 204
#define FINISHED 207
#define EXIT 208
#define FILE "shared_doc.txt"

class Server
{
public:
	Server();
	~Server();
	void serve(int port);

private:
	std::vector<std::string> users;
	std::queue<std::string> messages;
	std::mutex firstInLine;
	std::condition_variable firstIsDone;
	void accept();
	void clientHandler(SOCKET clientSocket);

	SOCKET _serverSocket;
};

