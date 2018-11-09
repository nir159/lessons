#pragma once
#include <iostream>

class OutStream
{
protected:
	FILE* file = nullptr;
public:
	OutStream();
	~OutStream();

	OutStream& operator<<(const char *str);
	OutStream& operator<<(int num);
	OutStream& operator<<(void(*pf)(FILE* f));
};

class FileStream : public OutStream
{
private:
	std::string path = "";
public:
	FileStream(const char* p);
	~FileStream();
};

class OutStreamEncrypted : public OutStream
{
private:
	int offset;
public:
	OutStreamEncrypted(int offset);
	~OutStreamEncrypted();

	OutStreamEncrypted& operator<<(const char *str);
	OutStreamEncrypted& operator<<(int num);
	OutStreamEncrypted& operator<<(void(*pf)(FILE* f));
};

void endline(FILE* f);