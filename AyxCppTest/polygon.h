#ifndef POLYGON_H
#define POLYGON_H
#include "spatial.h"
#include <initializer_list>
#include <vector>

class Polygon : public AyxCppTest::Area
{
public:
	Polygon(std::initializer_list <std::pair<double, double>> pt);
	bool Contains(const AyxCppTest::Point &pt);
private:
	std::vector <std::pair<double, double>> v;
};

#endif // POLYGON_H
