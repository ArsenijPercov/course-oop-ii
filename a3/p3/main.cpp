/*
CH08-320143
a3 p3.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    /* Initialization and input */
    list<int> A, B;
    while(true){
        int tmp;
        cin >> tmp;
        if(tmp <= 0){
            break;
        }
        A.push_front(tmp);
        B.push_back(tmp);
    }

    /* Printing A in stdout */
    for(list<int>::iterator it = A.begin(); it != A.end(); it++){
        cout << *it << " ";
    }

    /* Printing B in 'listB.txt' */
    ofstream out;
    out.open("listB.txt", ios::out);
    for(list<int>::reverse_iterator it = B.rbegin(); it != B.rend(); it++){
        out << *it << " ";
    }
    out.close();

    cout << endl;

    /* Moving the last element to the beginning */
    int lastA = A.back();
    A.pop_back();
    int lastB = B.back();
    B.pop_back();
    A.push_front(lastA);     
    B.push_front(lastB);     

    /* Printing A and B in stdout */
    for(list<int>::iterator it = A.begin(); it != A.end(); it++){
        if(it != A.begin()){
            cout << ",";
        }
        cout << *it;
    }
    cout << endl;
    for(list<int>::iterator it = B.begin(); it != B.end(); it++){
        if(it != B.begin()){
            cout << ",";
        }
        cout << *it;
    }
    cout << endl;

    /* Merging A into B and sorting B */
    B.merge(A);
    B.sort();

    for(list<int>::iterator it = B.begin(); it != B.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}

