#include "Logger.h"

Logger::Logger() : _startLine(true)
{
}
Logger::~Logger() 
{
}

void Logger::setStartLine() {
	if (this->_startLine) {
		this->_startLine = false;
	}
	else {
		this->_startLine = true;
	}
}

Logger& operator<<(Logger& l, const char *msg) {
	if (l._startLine) {
		std::cout << "LOG ";
		l.setStartLine();
	}
	l.os << msg;
	return l;
}

Logger& operator<<(Logger& l, int num) {
	if (l._startLine) {
		std::cout << "LOG ";
		l.setStartLine();
	}
	l.os << num;
	return l;
}

Logger& operator<<(Logger& l, void(*pf)(FILE* f)) {
	pf(l.os.getFile());
	l.setStartLine();
	return l;
}