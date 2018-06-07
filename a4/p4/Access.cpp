/*
CH08-320143
a4 p4.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
#include "Access.h"
using namespace std;

void Access::activate(unsigned long code){
    this->activatedKeys.insert(code);
}
void Access::deactivate(unsigned long code){
    this->activatedKeys.erase(code);
}
bool Access::isactive(unsigned long code) const{
    auto pos = this->activatedKeys.find(code);
    return pos != this->activatedKeys.end();
}