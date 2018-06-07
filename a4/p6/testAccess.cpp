/*
CH08-320143
a4 p6.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
#include "Access.h"
using namespace std;

int main(){
    
    Access a;
    a.activate(123456, 1);
    a.activate(999999, 5);
    a.activate(187692, 9);

    unsigned long code;
    while(true){
        cout << "Enter code: ";
        cin >> code;
        if(a.isactive(code, 5)){
            cout << "Access Granted!\n";
            break;
        } else {
            cout << "Access Denied!\n";
        }
    }

    a.deactivate(code);
    a.activate(999999, 8);
    a.activate(111111, 7);

    while(true){
        cout << "Enter code: ";
        cin >> code;
        if(a.isactive(code, 7)){
            cout << "Access Granted!\n";
            break;
        } else {
            cout << "Access Denied!\n";
        }
    }

    return 0;
}