#include "Helper.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

// recieves the type code of the message from socket (3 bytes)
// and returns the code. if no message found in the socket returns 0 (which means the client disconnected)
int Helper::getMessageTypeCode(SOCKET sc)
{
	char* s = getPartFromSocket(sc, 3);
	std::string msg(s);

	if (msg == "")
		return 0;

	int res = std::atoi(s);
	delete s;
	return  res;
}



// send 204 message to specific client
void Helper::sendUpdateMessageToClient(SOCKET sc, std::string fileContent, std::string currUser, std::string nextUser, int position)
{
	std::string res;

	std::string code = std::to_string(MT_SERVER_UPDATE);
	std::string currFileSize = getPaddedNumber(fileContent.size(), 5);
	std::string currUserSize = getPaddedNumber(currUser.size(), 2);
	std::string nextUserSize = getPaddedNumber(nextUser.size(), 2);

	res = code + currFileSize + fileContent + currUserSize + currUser + nextUserSize + nextUser + std::to_string(position);

	TRACE("Send update message to celint: %d, currUser=%s, nextUser=%s, position=%d", sc, currUser.c_str(), nextUser.c_str(), position);
	sendData(sc, res);

}

// recieve data from socket according byteSize
// returns the data as int
int Helper::getIntPartFromSocket(SOCKET sc, int bytesNum)
{
	char* s = getPartFromSocket(sc, bytesNum, 0);
	return atoi(s);
}

// recieve data from socket according byteSize
// returns the data as string
std::string Helper::getStringPartFromSocket(SOCKET sc, int bytesNum)
{
	char* s = getPartFromSocket(sc, bytesNum, 0);
	std::string res(s);
	return res;
}

// return string after padding zeros if necessary
std::string Helper::getPaddedNumber(int num, int digits)
{
	std::ostringstream ostr;
	ostr << std::setw(digits) << std::setfill('0') << num;
	return ostr.str();

}

// recieve data from socket according byteSize
// this is private function
char* Helper::getPartFromSocket(SOCKET sc, int bytesNum)
{
	return getPartFromSocket(sc, bytesNum, 0);
}

char* Helper::getPartFromSocket(SOCKET sc, int bytesNum, int flags)
{
	if (bytesNum == 0)
	{
		return "";
	}

	char* data = new char[bytesNum + 1];
	int res = recv(sc, data, bytesNum, flags);

	if (res == INVALID_SOCKET)
	{
		std::string s = "Error while recieving from socket: ";
		s += std::to_string(sc);
		throw std::exception(s.c_str());
	}

	data[bytesNum] = 0;
	return data;
}

// send data to socket
// this is private function
void Helper::sendData(SOCKET sc, std::string message)
{
	const char* data = message.c_str();

	if (send(sc, data, message.size(), 0) == INVALID_SOCKET)
	{
		throw std::exception("Error while sending message to client");
	}
}