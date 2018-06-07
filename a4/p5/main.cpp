/*
CH08-320143
a4 p5.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    ifstream in;
    in.open("data.txt", ios::in);
    map<unsigned long, string> db;
    while(!in.eof()){
        unsigned long matr;
        string first, last;
        in >> matr >> first >> last;
        db[matr] = first + " " + last;
    }
    in.close();

    while(true){
        unsigned long tmp;
        cout << "Enter matr num (0 to quit): ";
        cin >> tmp;
        if(tmp == 0){
            break;
        }
        if(db.find(tmp) == db.end()){
            cerr << "Matriculation number not found!\n";
        } else {
            cout << db[tmp] << endl;
        }
    }

    return 0;
}