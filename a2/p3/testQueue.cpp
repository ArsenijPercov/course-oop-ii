/*
CH08-320143
a2 p3.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/
#include <bits/stdc++.h>
#include "Queue.h"

int main(){

    Queue<int> q;

    for(int i = 0; i < 5; i++){
        q.push(i);
    }

    while(q.getNumEntries() > 0){
        int curr;
        q.pop(curr);
        std::cout << curr << std::endl;
    }

    Queue<double> q1(5);

    for(int i = 0; i < 6; i++){
        q1.push(i);
    }

    Queue<double> q2(q1);

    std::cout.precision(2);
    while(q1.getNumEntries() > 0){
        std::cout << std::fixed << q1.front() << std::endl;
        std::cout << std::fixed << q1.back() << std::endl;
        double tmp;
        q1.pop(tmp);
        std::cout << std::fixed << tmp << std::endl;
    }

    q2.resize(4);
    std::cout << q2.getSize() << std::endl;
}