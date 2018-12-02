#include "MathUtils.h"

MathUtils::MathUtils()
{
}

MathUtils::~MathUtils()
{
}

double MathUtils::CalPentagonArea(double member) {
	return (sqrt(5 * (5 + 2 * (sqrt(5)))) * member * member) / 4;
}

double MathUtils::CalHexagonArea(double member) {
	return (3 * sqrt(3) * (member * member)) / 2;
}