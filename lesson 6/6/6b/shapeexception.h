#pragma once
#include <exception>

class shapeException : public std::exception
{
public: // this was private(inaccessible)
	virtual const char* what() const
	{
		return "This is a shape exception!";
	}
};

class inputException : public std::exception
{
public: // this was private(inaccessible)
	virtual const char* what() const
	{
		return "This is an input exception!";
	}
};