/** 
 * @file TestDuration.cpp
 * Unit tests regarding the duration between two date objects.
*/
#include <iostream>
#include "Date3.h"
using namespace std;

/**
 * @brief Global integer variable for holding the total amount of passed tests.
 * 
 * Initialized with 0.
 */
int nPass = 0; 
/**
 * @brief Global integer variable for holding the total amount of failed tests.
 * 
 * Initialized with 0.
 */
int nFail = 0;
/**
 * Global function for counting the passed and the failed tests. 
 * The function uses two global variable nPass and nFail which are 
 * originally set to 0.
 * 
 * @param t Boolean used to pass to the testing function which 
 * is equivalent to passing or failing the unit test.
 */
void test(bool t) {
	if (t) 
		nPass++;
	else
		nFail++;
}

int main() {
	Date mybday(1995, 10, 1);
	
	// Test duration
	Date d2(2016, 4, 12);
	Duration dur = duration(mybday, d2);
	test(dur.years == 20);
	test(dur.months == 6);
	test(dur.days == 11);
	
	cout << "Test Duration" << endl;
	cout << "Passed: " << nPass << " tests" << endl << "Failed: " << nFail << " tests" << endl;
	return 0;
}