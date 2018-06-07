/*
CH08-320143
a3 p4.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    /* Initialization and input */
    deque<double> dq;
    while(true){
        double tmp;
        cin >> tmp;
        if(tmp == 0){
            break;
        } else if(tmp < 0){
            dq.push_back(tmp);
        } else {
            dq.push_front(tmp);
        }
    }

    for(deque<double>::iterator it = dq.begin(); it != dq.end(); it++){
        cout << *it << " ";
    }
    cout << "\n\n";

    deque<double>::iterator it = dq.begin();
    while(*it > 0){
        it++;
    }
    dq.insert(it, 0);

    for(deque<double>::iterator it = dq.begin(); it != dq.end(); it++){
        if(it != dq.begin()){
            cout << ";";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}