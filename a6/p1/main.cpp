/*
CH08-320143
a6 p1.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/
#include <iostream>
using namespace std;

/* Start reading the comments in main */

int find(int a[], int nr, int el) {
	for(int i=0; i<=nr; i++)
		if (a[i] == el) /* print i and print a[i], a[nr] is 0 */
			return i;
	return -1;
}

unsigned long difference(unsigned long a, unsigned long b) {
	if (a-b < 0) /* a-b is a big number because a and b are unsigned <-- wrong result*/
		return b-a; /* I used 'print a-b' to check */
	else
		return a-b;
}

int main() { /* run the program with gdb */
	int n, val;
	cout << "n=";
	cin >> n;
	int *v=new int[n];
	cout << "Elements the elements of array:" << endl;
	for(int i=0; i<n; i++)
		cin >> v[i];
	cout << "val=";
	cin >> val;
	int result = find(v, n, val); /* First gdb command: break 36. Continue step by step using 's' */
	cout << "Position of the searched element=" << result << endl;
	delete v; /* Not whole array is deleted. Using 'p v' I made sure that is not deleted */
	unsigned long x, y;
	x=550000;
	y=550005;
	cout << "Difference=" << difference(x, y) << endl;
	return 0;
}