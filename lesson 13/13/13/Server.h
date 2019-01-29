#pragma once
#include <queue>
#include <thread>
#include <vector>
#include <mutex>
#include <fstream>
#include <exception>
#include <iostream>
#include <string>
#include <WinSock2.h>
#include <Windows.h>
#include "Helper.h"

#define MAX_BYTES 20
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
	void accept();
	void clientHandler(SOCKET clientSocket);

	SOCKET _serverSocket;
};

