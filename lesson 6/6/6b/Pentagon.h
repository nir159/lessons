#include <iostream>
#include "shape.h"
class Pentagon : public Shape
{
public:
	Pentagon(std::string nam, std::string col, double member);
	~Pentagon();
	void draw();
	double CalArea();
	double getMember();
	void setMember(double member);
private:
	double member;
};

