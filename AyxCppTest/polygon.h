#ifndef POLYGON_H
#define POLYGON_H
#include "spatial.h"
#include "spatial.cpp"
#include <initializer_list>
#include <vector>

namespace intersect
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


class Polygon : public AyxCppTest::Area
{
public:
	Polygon(std::initializer_list <std::pair<double, double>> pt);
	bool Contains(const AyxCppTest::Point &pt);
private:
	std::vector <std::pair<double, double>> v;
};

#endif // POLYGON_H
