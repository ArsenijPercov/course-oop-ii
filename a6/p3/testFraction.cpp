/*
CH08-320143
a6 p3.cpp
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

    try{
        Fraction f1 = Fraction(1, 2);
        Fraction f2 = Fraction(f1);
        Fraction f3 = Fraction("-1/2");
        Fraction f4 = Fraction(1, 4);
        Fraction sum = Fraction(2, 2);
        Fraction diff = Fraction(0, 2);
        Fraction pro = Fraction(1, 4);
        Fraction quot = Fraction(1, 1);

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

        test(f1+f2 == sum);
        test(f1-f2 == diff);
        test(f1*f2 == pro);
        test(f1/f2 == quot);

        Fraction f;
        cin >> f;
        cout << f << endl;

        cout << "Test Functions" << endl;
        cout << "Passed tests: " << pass << endl << "Failed tests: " << fail << endl;
    } catch(Fraction::Error& e){
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}