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

    cout << "Testing exceptions\n";

    try{
        Fraction f(1, 2);
        test(true);
    } catch(Fraction::Error& e){
        cerr << e.what() << endl;
        test(false);
    }

    try{
        Fraction f("1/2");
        test(true);
    } catch(Fraction::Error& e){
        cerr << e.what() << endl;
        test(false);
    }

    try{
        Fraction f("-1/2");
        test(true);
    } catch(Fraction::Error& e){
        cerr << e.what() << endl;
        test(false);
    }

    try{
        Fraction f("1/-2");
        test(true);
    } catch(Fraction::Error& e){
        cerr << e.what() << endl;
        test(false);
    }

    try{
        Fraction f("-1/-2");
        test(true);
    } catch(Fraction::Error& e){
        cerr << e.what() << endl;
        test(false);
    }

    try{
        Fraction f(1, -2);
        test(true);
    } catch(Fraction::Error& e){
        cerr << e.what() << endl;
        test(false);
    }

    try{
        Fraction f(1, 2);
        Fraction f1(f);
        test(true);
    } catch(Fraction::Error& e){
        cerr << e.what() << endl;
        test(false);
    }

    try{
        Fraction f(1, 2);
        Fraction f1 = f;
        test(true);
    } catch(Fraction::Error& e){
        cerr << e.what() << endl;
        test(false);
    }

    cout << "Testing functions\n";
    cout << "Passed tests: " << pass << endl << "Failed tests: " << fail << endl;

    return 0;
}