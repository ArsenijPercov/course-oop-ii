/*
CH08-320143
a5 p1.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/
#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<char> v;
    for(int i = 0; i < 15; i++){
        v.push_back('@');
    }

    try{
       cout << v.at(15) << endl; 
    } catch (out_of_range& e){
        cerr << e.what() << endl;
    }

    return 0;
}