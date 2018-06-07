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

    cout << "Testing IO Operators\n";
    try{
        Fraction f;
        cout << "Enter fraction (numerator and denominator separate by space or line)\nf=";
        cin >> f;
        test(true);
        cout << f << endl;
        test(true);
    } catch(Fraction::Error& e){
        cerr << e.what() << endl;
        test(false);
        test(false);
    }

    cout << "Test Functions" << endl;
    cout << "Passed tests: " << pass << endl << "Failed tests: " << fail << endl;

    return 0;
}