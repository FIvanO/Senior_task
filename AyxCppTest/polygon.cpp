#include "polygon.h"

Polygon::Polygon(std::initializer_list<std::pair<double, double> > pt) : v(pt)
{

}

bool Polygon::Contains(const AyxCppTest::Point &pt)
{
	double min_value = -999999;
	int count = 0;
	AyxCppTest::Point intr(0, 0);
	auto it = v.end()--;
	for (auto k = v.begin(); k != it; ++k) {
		count += intersect::LineIntersection(AyxCppTest::Point{k->first, k->second},
		AyxCppTest::Point{++k->first, k->second},
		AyxCppTest::Point{min_value, pt.m_y},
		AyxCppTest::Point{pt.m_x, pt.m_y}, intr);
		k--;
	}
	return (count % 2) == 1;
}
