#include "Logger.h"

Logger::Logger() : _startLine(true)
{
}
Logger::~Logger() 
{
}

void Logger::setStartLine() {
	static unsigned int counter = 0;
	if (this->_startLine) {
		std::cout << "LOG <" << counter  << "> ";
		counter++;
		this->_startLine = false;
	}
	else {
		this->_startLine = true;
	}
}

Logger& operator<<(Logger& l, const char *msg) {
	if (l._startLine) {
		l.setStartLine();
	}
	l.os << msg;
	return l;
}

Logger& operator<<(Logger& l, int num) {
	if (l._startLine) {
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