#include "catch/catch.hpp" 
#include "Add.h"
#include <string>
#include <iostream>

namespace AyxCppTest
{
	/**
	* Add two arbitrarily long numbers encoded as strings and return the result
	* as a number encoded as a string.  Each character in the input and output
	* strings is a single digit in the range of [0,9] inclusive.
	*
	* Sample test cases are provided as a starting point.
	*
	* Tasks:
	*   -Complete the Add function.
	*   -Add and repair test cases as appropriate.
	*/
	std::string Add(std::string lhs, std::string rhs)
	{
		bool overfl = false;
		int a[1000];
		int b[1000];
		int ls = lhs.length();
		int rs = rhs.length();
		if (ls < rs) {
			std::string ss = lhs;
			lhs = rhs;
			rhs = ss;
			int lss = ls;
			ls = rs;
			rs = lss;
		}
		int j = 0;
		for (int i = ls - 1; i >= 0; --i) {
			a[j++] = int(lhs[i] - '0');
		}
		j = 0;
		for (int i = rs - 1; i >= 0; --i) {
			b[j++] = int(rhs[i] - '0');
		}
		std::string retval = "";
		for (int i = 0; i < rs; ++i) {
			int c = a[i] + b[i];
			if (overfl) {
				c++;
			}
			retval = std::to_string(c % 10) + retval;
			overfl = c > 9;
		}
		for (int i = rs; i < ls; ++i) {
			int c = a[i];
			if (overfl) {
				c++;
			}
			retval = std::to_string(c % 10) + retval;
			overfl = c > 9;
		}
		if (overfl) {
			retval = "1" + retval;
		}
		return retval;
	}

	TEST_CASE("exercise5")
	{
		// enable to run exercise 6 tests
#if 1
		REQUIRE(Add("1", "2") == "3");

		std::string                       BigNum("1000000000000000000000000000000000000000000000000000000000000");
		REQUIRE(Add(BigNum, "1")   == "1000000000000000000000000000000000000000000000000000000000001");
		REQUIRE(Add(BigNum, "10")  == "1000000000000000000000000000000000000000000000000000000000010");
		REQUIRE(Add(BigNum, "100") == "1000000000000000000000000000000000000000000000000000000000100");
		REQUIRE(Add("12345678999999", "123456789") == "12345802456788"); // new test case
		REQUIRE(Add("99999999999999999999", "99999999999999999999") == "199999999999999999998"); // new test case
		REQUIRE(Add("0", "99999") == "99999"); // new test case
		REQUIRE(Add("1", "99999") == "100000"); // new test case
		REQUIRE(Add("11", "99999") == "100010"); // new test case
#endif
	}
}
