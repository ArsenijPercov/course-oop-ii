/*
CH08-320143
a4 p4.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
#include "Access.h"
using namespace std;

int main(){
    
    Access access;
    access.activate(123456);
    access.activate(999999);
    access.activate(187692);

    unsigned long code;
    while(true){
        cout << "Enter access code: ";
        cin >> code;
        if(access.isactive(code)){
            cout << "Access Granted!\n";
            break;
        } else {
            cout << "Access Denied!\n";
        }
    }

    access.deactivate(code);
    access.deactivate(999999);
    access.activate(111111);

    while(true){
        cout << "Enter access code: ";
        cin >> code;
        if(access.isactive(code)){
            cout << "Access Granted!\n";
            break;
        } else {
            cout << "Access Denied!\n";
        }
    }

    return 0;
}