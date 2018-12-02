#include <iostream>
#include "shape.h"
class Hexagon : public Shape
{
public:
	Hexagon(std::string nam, std::string col, double member);
	~Hexagon();
	void draw();
	double CalArea();
	double getMember();
	void setMember(double member);
private:
	double member;
};