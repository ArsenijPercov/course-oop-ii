/*
CH08-320143
a3 p5.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
using namespace std;

#ifndef _WIND_GAUGE_H
#define _WIND_GAUGE_H

class WindGauge{

public: 
    WindGauge(int period = 10);
    void currentWindSpeed(int speed);
    int highest() const;
    int lowest() const;
    int average() const;
    void dump() const;
private: 
    int period;
    deque<int> dq;
};

#endif // !_WIND_GAUGE_H

#include <bits/stdc++.h>
using namespace std;