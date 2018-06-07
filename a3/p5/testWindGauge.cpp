/*
CH08-320143
a3 p5.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
#include "WindGauge.h"
using namespace std;

int main(){

    WindGauge wg;
    wg.currentWindSpeed(14);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(13);
    wg.currentWindSpeed(15);
    wg.currentWindSpeed(15);

    wg.dump();

    wg.currentWindSpeed(15);
    wg.currentWindSpeed(17);
    wg.currentWindSpeed(17);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(20);
    wg.currentWindSpeed(15);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(20);

    wg.dump();

    return 0;
}