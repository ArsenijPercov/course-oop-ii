/*
CH08-320143
a3 p1.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<string> v;
    while(true){
        string tmp;
        cin >> tmp;
        if(tmp == "stop"){
            break;
        }
        v.push_back(tmp);
    }

    for(unsigned int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i < v.size()-1){
            cout << ", ";
        }
    }
    cout << endl;

    for(vector<string>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}