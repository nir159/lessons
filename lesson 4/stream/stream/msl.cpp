#pragma warning(disable : 4996)

#include <iostream>
#include <fstream>
#include "msl.h"

namespace msl {

	// outstream
	OutStream::OutStream()
	{
		this->file = stdout;
	}

	OutStream::~OutStream()
	{
	}

	FILE* OutStream::getFile() {
		return this->file;
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

	// filestream
	FileStream::FileStream(const char* p) : path(p)
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

	// outstream
	OutStreamEncrypted::OutStreamEncrypted(int offset) : offset(offset)
	{
		this->file = stdout;
	}

	OutStreamEncrypted::~OutStreamEncrypted()
	{
	}

	OutStreamEncrypted& OutStreamEncrypted::operator<<(const char *str)
	{
		unsigned int i = 0;
		std::string encryptedStr(str);
		for (i = 0; i < encryptedStr.length(); i++) {
			if (encryptedStr[i] + this->offset < 126 && encryptedStr[i] + this->offset > 32) {
				encryptedStr[i] = (encryptedStr[i] + this->offset) % 126;
			}
		}
		fprintf(this->file, "%s", encryptedStr.c_str());
		return *this;
	}

	OutStreamEncrypted& OutStreamEncrypted::operator<<(int num)
	{
		fprintf(this->file, "%d", num);
		return *this;
	}

	OutStreamEncrypted& OutStreamEncrypted::operator<<(void(*pf)(FILE* f))
	{
		pf(this->file);
		return *this;
	}
}