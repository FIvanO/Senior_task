#include "polygon.h"
#include <iostream>

namespace inters
{
bool LineIntersection(AyxCppTest::Point line1Pt1, AyxCppTest::Point line1Pt2, AyxCppTest::Point line2Pt1, AyxCppTest::Point line2Pt2, AyxCppTest::Point &r_Out)
{
	double s1_x = line1Pt2.m_x - line1Pt1.m_x;
	double s1_y = line1Pt2.m_y - line1Pt1.m_y;
	double s2_x = line2Pt2.m_x - line2Pt1.m_x;
	double s2_y = line2Pt2.m_y - line2Pt1.m_y;

	double s, t;
	s = (-s1_y * (line1Pt1.m_x - line2Pt1.m_x) + s1_x * (line1Pt1.m_y - line2Pt1.m_y)) / (-s2_x * s1_y + s1_x * s2_y);
	t = (s2_x * (line1Pt1.m_y - line2Pt1.m_y) - s2_y * (line1Pt1.m_x - line2Pt1.m_x)) / (-s2_x * s1_y + s1_x * s2_y);

	if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
	{
		// Collision detected
		r_Out.m_x = line1Pt1.m_x + (t * s1_x);
		r_Out.m_y = line1Pt1.m_y + (t * s1_y);
		return true;
	}

	return false; // No collision
}
}

Polygon::Polygon(std::initializer_list<std::pair<double, double> > pt) : v(pt)
{
}

bool Polygon::Contains(const AyxCppTest::Point &pt)
{
	double min_value = -999999;
	int count = 0;
	AyxCppTest::Point intr(0, 0);
	int sz = v.size();
	sz--;
	for (int i = 0; i < sz; ++i) {
		count += inters::LineIntersection(AyxCppTest::Point{v[i].first, v[i].second},
		AyxCppTest::Point{v[i + 1].first, v[i + 1].second},
		AyxCppTest::Point{min_value, pt.m_y + 1},
		AyxCppTest::Point{pt.m_x, pt.m_y}, intr);
	}

	return (count % 2) == 1;
}
