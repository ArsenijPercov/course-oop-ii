/** 
 * @file TestExceptions.cpp
 * Unit tests covering cases when exceptions are thrown.
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
	// Test the validity of data with exception throwing
	try {
		Date d3(2013, 4, 15);
		nPass++;
	}
	catch(Date::DateError e) {
		cerr << "Caught exception: " << e.what() << endl;
		nFail++;
	}
	try {
		Date d4("20130402");
		nPass++;
	}
	catch(Date::DateError e) {
		cerr << "Caught exception: " << e.what() << endl;
		nFail++;
	}
	
	cout << "Test Exceptions" << endl;
	cout << "Passed: " << nPass << " tests" << endl << "Failed: " << nFail << " tests" << endl;
	return 0;
}