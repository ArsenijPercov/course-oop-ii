/*
CH08-320143
a6 p4.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/
#include <bits/stdc++.h>
#include "Fraction.h"
using namespace std;

int pass, fail;
int cnt;

void test(bool b){
    if(b){
        cout << "Test " << cnt << " passes\n";
        pass++;
    } else {
        cout << "Test " << cnt << " fails\n";
        fail++;
    }
    cnt++;
}

int main(){

    cout << "Testing logical operators\n";

    Fraction f1 = Fraction(1, 2);
    Fraction f2 = Fraction("1/2");
    Fraction f3 = Fraction("-1/2");
    Fraction f4 = Fraction(1, 4);

    test(f1 == f2);
    test(f1 <= f2);
    test(f1 >= f2);

    test(f3 < f1);
    test(f3 < f2);
    test(f3 < f4);
    test(f4 < f1);
    test(f4 < f2);
    test(f3 <= f1);
    test(f3 <= f2);
    test(f3 <= f4);
    test(f4 <= f1);
    test(f4 <= f2);

    cout << "Test Functions" << endl;
    cout << "Passed tests: " << pass << endl << "Failed tests: " << fail << endl;

    return 0;
}