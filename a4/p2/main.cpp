/*
CH08-320143
a4 p2.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    srand(time(NULL));
    set<int> s;
    while(s.size() < 6){
        int tmp = rand()%49 + 1;
        s.insert(tmp);
    }

    for(auto el : s){
        cout << el << " ";
    }
    cout << endl;

    return 0;
}