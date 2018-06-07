/*
CH08-320143
a4 p4.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
using namespace std;

#ifndef _ACCESS_H
#define _ACCESS_H

class Access{
public:
    void activate(unsigned long code);
    void deactivate(unsigned long code);
    bool isactive(unsigned long code) const;
private: 
    set<unsigned long> activatedKeys;
};

#endif // !_ACCESS_H