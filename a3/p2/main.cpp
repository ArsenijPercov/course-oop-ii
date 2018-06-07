/*
CH08-320143
a3 p2.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
using namespace std;

template<class T>
void myswap(T& a, T& b){
    T tmp = a;
    a = b;
    b = tmp;
}

int main(){

    /* Input */
    vector<string> v;
    while(true){
        string tmp;
        getline(cin, tmp);
        if(tmp == "STOP"){
            break;
        }
        v.push_back(tmp);
    }

    /* Check if the second and/or forth exist */
    if(v.size() >= 4){
        myswap(v[1], v[3]);
    } else {
        cerr << "Vector size is less than 4\n";
    }

    /* Set last element to '?' */
    if(v.size()){
        v[v.size()-1] = "?";
    } else {
        cerr << "Vector has no elements\n";
    }

    /* Print using index operator */
    for(unsigned int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i < v.size()-1){
            cout << ";";
        }
    }
    cout << endl;

    /* Print using iterator */
    for(vector<string>::iterator it = v.begin(); it != v.end(); it++){
        if(it != v.begin()){
            cout << "-";
        }
        cout << *it;
    }
    cout << endl;

    /* Printing elements in reverse order */
    for(vector<string>::reverse_iterator it = v.rbegin(); it != v.rend(); it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}