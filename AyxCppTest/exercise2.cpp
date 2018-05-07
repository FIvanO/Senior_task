#include "catch/catch.hpp" 
#include <memory>
#include "spatial.h"
#include "polygon.h"

namespace AyxCppTest
{
	// for exercise 2 we want to extend Area to have a class Polygon
	// a png (exercise2.png) is supplied in the current directory to show the test polygons and points.
	// tasks
	//		Add new files polygon.h and polygon.cpp with a new class "Polygon" inheriting from Area
	//		Add a constructor that takes an initializer list of points
	//		Add a Contains function
	//
	// FYI - The algorithm for the Contains function should be the classic ray casting algorithm:
	//		"One simple way of finding whether the point is inside or outside a simple polygon
	//		is to test how many times a ray, starting from the point and going in any fixed direction (often left),
	//		intersects the edges of the polygon.  If the point is on the outside of the polygon the ray
	//		will intersect its edge an even number of times.  If the point is on the inside of the
	//		polygon then it will intersect the edge an odd number of times."
	//		https://en.wikipedia.org/wiki/Point_in_polygon
	//
	// also for simplicity, points on the border can be left undefined.  No tests are provided for points on the border.
	//
	// In order to make this not about remembering Geometry, an example line intersection function is provided.


	TEST_CASE("exercise2")
	{
// enable to run exercise 2 tests
#if 1
		Polygon poly1{ {1, -1},{6, -1},{1, -5},{1, -1} };
		REQUIRE(!poly1.Contains({ 4, -4 }));
		REQUIRE(poly1.Contains({ 4, -2 }));

		Polygon poly2{ {0, 3},{4, 7},{8, 5},{6, 0},{5, 1},{5, 5},{3, 5},{3, 4},{4, 4},{4, 1},{0, 3} };

		REQUIRE(!poly2.Contains({8, 0} ));
		REQUIRE(poly2.Contains({6, 1} ));
		REQUIRE(!poly2.Contains({8, 1} ));
		REQUIRE(poly2.Contains({6, 2} ));
		REQUIRE(poly2.Contains({2, 3} ));
		REQUIRE(!poly2.Contains({4.5, 3} ));
		REQUIRE(!poly2.Contains({-3, 4} ));
		REQUIRE(poly2.Contains({2, 4} ));
		REQUIRE(!poly2.Contains({ 11, 4 }));
		REQUIRE(!poly2.Contains({3.5, 4.5} ));
		REQUIRE(poly2.Contains({6, 5} ));
		REQUIRE(poly2.Contains({4, 6} ));
		REQUIRE(!poly2.Contains({ 0, 7 }));
		REQUIRE(!poly2.Contains({ 8, 7 }));
		REQUIRE(!poly2.Contains({4, 10} ));
#endif
	}
}
