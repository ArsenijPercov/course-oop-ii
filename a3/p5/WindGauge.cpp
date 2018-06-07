/*
CH08-320143
a3 p5.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
#include "WindGauge.h"
using namespace std;

/**
 * Default constructor. Default value for {@code param} is
 * 10.
 * @param period the specified period of time
*/
WindGauge::WindGauge(int period){
    this->period = period;
}

/**
 * Adds another wind speed into the deque. If the number of
 * elements in the deque is more that the period, then the oldest
 * wind is discarded
 * @param speed
*/
void WindGauge::currentWindSpeed(int speed){
    if((int)dq.size() == this->period){
        dq.pop_back();
    }
    dq.push_front(speed);
}

/**
 * @return the highest wind speed in the current deque
*/
int WindGauge::highest() const{
    int ret = INT_MIN;
    for(deque<int>::const_iterator it = this->dq.begin(); it != this->dq.end(); it++){
        ret = max(ret, *it);
    }
    return ret;
}

/**
 * @return the lowest wind speed in the current deque
*/
int WindGauge::lowest() const{
    int ret = INT_MAX;
    for(deque<int>::const_iterator it = this->dq.begin(); it != this->dq.end(); it++){
        ret = min(ret, *it);
    }
    return ret;
}

/**
 * @return the average wind speed
*/
int WindGauge::average() const{
    int ret = 0;
    for(deque<int>::const_iterator it = this->dq.begin(); it != this->dq.end(); it++){
        ret += *it;
    }
    return ret/this->dq.size();
}

/**
 * Prints the lowest, highest and average wind speeds in 
 * the current history
*/
void WindGauge::dump() const{
    cout << "Highest: " << this->highest();
    cout << "; Lowest " << this->lowest();
    cout << "; Average: " << this->average() << endl;
}