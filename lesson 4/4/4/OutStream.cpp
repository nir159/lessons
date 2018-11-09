#pragma warning(disable : 4996)
#include "OutStream.h"
#include <iostream>
#include <fstream>

OutStream::OutStream()
{
	this->file = stdout;
}

OutStream::~OutStream()
{
}

OutStream& OutStream::operator<<(const char *str)
{
	fprintf(this->file, "%s", str);
	return *this;
}

OutStream& OutStream::operator<<(int num)
{
	fprintf(this->file, "%d", num);
	return *this;
}

OutStream& OutStream::operator<<(void(*pf)(FILE* f))
{
	pf(this->file);
	return *this;
}


void endline(FILE* f)
{
	fprintf(f, "\n");
}

FileStream::FileStream(const char* p): path(p)
{
	const char* ch = this->path.c_str();
	this->file = fopen(ch, "w");
	if (this->file == NULL) {
		std::cerr << "Error: wrong path";
		_exit(1);
	}
}

FileStream::~FileStream()
{
	fclose(this->file);
}