#pragma once

#include <vector>
#include <string>
#include <WinSock2.h>
#include <queue>

enum MessageType : byte
{
	MT_CLIENT_LOG_IN = 200,
	MT_CLIENT_UPDATE = 204,
	MT_CLIENT_FINISH = 207,
	MT_CLIENT_EXIT = 208,
	MT_SERVER_UPDATE = 101,
};


class Helper
{
public:


	static int getMessageTypeCode(SOCKET sc);
	static int getIntPartFromSocket(SOCKET sc, int bytesNum);
	static std::string getStringPartFromSocket(SOCKET sc, int bytesNum);
	static void sendData(SOCKET sc, std::string message);
	static void sendUpdateMessageToClient(SOCKET sc, std::string fileContent, std::string currUser, std::string nextUser, int position);
	static std::string getPaddedNumber(int num, int digits);
	static int vFind(std::vector<std::string> names, std::string search);
	static std::string getNextUser(std::vector<std::string> names, std::string currentName);
	static void printVector(std::vector<std::string> names);
	static std::string readFile(std::string name);
	static void updateFile(std::string fileName, std::queue<std::string> data);
	static int getLastVector(std::vector<std::string> names);

private:
	static char* Helper::getPartFromSocket(SOCKET sc, int bytesNum);
	static char* getPartFromSocket(SOCKET sc, int bytesNum, int flags);

};


#ifdef _DEBUG // vs add this define in debug mode
#include <stdio.h>
// Q: why do we need traces ?
// A: traces are a nice and easy way to detect bugs without even debugging
// or to understand what happened in case we miss the bug in the first time
#define TRACE(msg, ...) printf(msg "\n", __VA_ARGS__);
// for convenient reasons we did the traces in stdout
// at general we would do this in the error stream like that
// #define TRACE(msg, ...) fprintf(stderr, msg "\n", __VA_ARGS__);

#else // we want nothing to be printed in release version
#define TRACE(msg, ...) printf(msg "\n", __VA_ARGS__);
#define TRACE(msg, ...) // do nothing
#endif