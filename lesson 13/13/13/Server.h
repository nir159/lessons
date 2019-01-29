#pragma once
#include <queue>
#include <thread>
#include <mutex>
#include <exception>
#include <iostream>
#include <string>
#include <WinSock2.h>
#include <Windows.h>
#include "Helper.h"

#define MAX_BYTES 500

class Server
{
public:
	Server();
	~Server();
	void serve(int port);

private:
	
	std::queue<std::string> messages;
	void accept();
	void clientHandler(SOCKET clientSocket);

	SOCKET _serverSocket;
};

