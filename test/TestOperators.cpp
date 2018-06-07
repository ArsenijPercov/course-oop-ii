/** 
 * @file TestOperators.cpp
 * Unit tests for the usage of relational operators.
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
	Date today;
	Date myevebday("19950930");
	
	// Test the operators
	test(mybday < today);
	test(mybday <= today);
	test(mybday != today);
	test(mybday == mybday);
	test(mybday >= mybday);
	test(mybday <= mybday);
	test(myevebday < mybday);
	test(mybday > myevebday);
	test(mybday >= myevebday);
	test(mybday != myevebday);
	
	cout << "Test Operators" << endl;
	cout << "Passed: " << nPass << " tests" << endl << "Failed: " << nFail << " tests" << endl;
	return 0;
}