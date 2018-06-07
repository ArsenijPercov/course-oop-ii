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

    cout << "Testing arithmetic operators\n";

    Fraction f1 = Fraction(1, 2);
    Fraction f2 = Fraction("1/2");
    Fraction sum = Fraction(2, 2);
    Fraction diff = Fraction(0, 2);
    Fraction pro = Fraction(1, 4);
    Fraction quot = Fraction(1, 1);

    test(f1+f2 == sum);
    test(f1-f2 == diff);
    test(f1*f2 == pro);
    test(f1/f2 == quot);

    cout << "Test Functions" << endl;
    cout << "Passed tests: " << pass << endl << "Failed tests: " << fail << endl;

    return 0;
}