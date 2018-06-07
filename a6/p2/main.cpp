/*
CH08-320143
a6 p2.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/
#include <iostream>
#include <sstream>
using namespace std;

void foo(int *array, int n, int *odds) { 
	for(int i=0; i<n; i++)
		if (array[i] % 2 == 1)
			*odds++; /* Printing odds gives an address. */
} /* with ++ operator we are increasing the memory address of odds and not the value. We should change it to (*odds)++ */

class Test {
	private:
		double *a;
		int n;
	public:
		Test() {
			a=NULL;
			n=0;
		}
		Test(double *a, int n) {
			this->n = n;
			if (this->a != NULL) {
				delete this->a;
			}
			this->a = new double[n];
			for(int i=0; i<n; i++)
				this->a[i] = a[i];
		}
		string toString() {
            /* For obj3, this causes segmentation fault, see results from gdb below */
            /* Program received signal SIGSEGV, Segmentation fault.
0x0000555555555401 in Test::toString[abi:cxx11]() (this=0x0)
 */
			ostringstream ss;
			ss << "Length: " << n << endl << "Elements: ";
			for(int i=0; i<n; i++)
				ss << a[i] << " ";
			ss << endl;
			return ss.str();
		}
		~Test() {
			delete a;
		}
};

int main() { /* Add breakpoints at line 6, 26 and 58. Now run */
	int array[3] = {1, 2, 3};
	int odd_values=0;
	foo(array, 3, &odd_values);
	cout << "Amount of odd values in the array=" << odd_values << endl;
	Test arr[5];
	double v[3] = {1.2, 2.3, 3.45};
	Test *obj1;
	obj1=&arr[0];
	Test *obj2 = new Test(v, 3);
	Test *obj3 = NULL;
	cout << obj1->toString();
	cout << obj2->toString();
	cout << obj3->toString(); /* Provokes segmentation fault because it's NULL */
	delete obj1;
	delete obj2;
	delete obj3;
	return 0;
}