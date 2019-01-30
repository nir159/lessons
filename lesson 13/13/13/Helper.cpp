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

/*
Function will return the index of the string in the vector
If string doesn't exists returns -1
*/
int Helper::vFind(std::vector<std::string> names, std::string search) {
	std::vector<std::string>::iterator it;
	for (it = names.begin(); it != names.end(); ++it) {
		if ((*it).compare(search) == 0) {
			return (it - names.begin());// returns index of iterator
		}
	}
	return -1;
}

/*
Function returns the next user after the current one
In case there is no username returns an empty string
*/
std::string Helper::getNextUser(std::vector<std::string> names, std::string currentName) {
	std::vector<std::string>::iterator it;
	for (it = names.begin(); it != names.end(); ++it) {
		if ((*it).compare(currentName) == 0 && it != names.begin()) {
			--it;
			return *it;
		}
	}
	return "";
}

/*
Function will print the vector
*/
void Helper::printVector(std::vector<std::string> names) {
	std::vector<std::string>::iterator it;
	for (it = names.begin(); it != names.end(); ++it) {
		std::cout << *it << std::endl;
	}
}

/*
Function reads the data file and returns the content
*/
std::string Helper::readFile(std::string name) {
	std::ifstream inputFile;
	std::string fileContent;
	inputFile.open(name);
	inputFile.seekg(0, std::ios::end);
	fileContent.reserve(inputFile.tellg());
	inputFile.seekg(0, std::ios::beg);
	fileContent.assign((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
	inputFile.close();
	return fileContent;
}

/*
Function update the data in file
*/
void Helper::updateFile(std::string fileName, std::queue<std::string> data) {
	std::ofstream outputFile(fileName, std::ios::out);
	while (!data.empty()) {
		outputFile << data.front();
		data.pop();
	}
	outputFile.close();
}

/*
Function will return the index of the last one in a vector
if the vector is empty will return -1
*/
int Helper::getLastVector(std::vector<std::string> names) {
	std::vector<std::string>::iterator it;
	if (!names.empty()) {
		it = names.begin();
		while (it != names.end()) {
			++it;
		}
		--it;
		return (it - names.begin());
	}
	return -1;
}