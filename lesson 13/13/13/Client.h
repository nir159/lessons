#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <string>

class Client
{
public:
	Client();
	~Client();
	void connect(std::string serverIP, int port);
	void startConversation();

private:
	SOCKET _clientSocket;
};