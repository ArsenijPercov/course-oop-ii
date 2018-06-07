/*
CH08-320143
a4 p6.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
#include "Access.h"
using namespace std;

void Access::activate(unsigned long code, unsigned int level){
    this->activatedKeys[code] = level;
}
void Access::deactivate(unsigned long code){
    this->activatedKeys[code] = -1;
}
bool Access::isactive(unsigned long code, unsigned int level) {
    if(this->activatedKeys.find(code) == this->activatedKeys.end()){
        return false;
    }
    int tmp = this->activatedKeys[code];
    if(tmp >= (int)level){
        return true;
    }
    return false;
}