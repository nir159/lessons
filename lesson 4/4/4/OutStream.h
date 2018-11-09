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

void endline(FILE* f);