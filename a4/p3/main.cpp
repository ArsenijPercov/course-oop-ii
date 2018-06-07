/*
CH08-320143
a4 p3.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
using namespace std;

void print(const set<int>& A, const multiset<int>& B){
    for(auto el : A){
        cout << el << " ";
    }
    cout << endl << endl;
    for(auto el : B){
        cout << el << " ";
    }
    cout << endl << endl;
}

void print(const multiset<int>& A){
    for(auto el : A){
        cout << el << " ";
    }
    cout << endl;
}

void print(const set<int>& A){
    for(auto el : A){
        cout << el << " ";
    }
    cout << endl;
}

int main(){

    set<int> A;
    multiset<int> B;
    while(true){
        int tmp;
        cin >> tmp;
        if(tmp < 0){
            break;
        }
        A.insert(tmp);
        B.insert(tmp);
    }

    print(A, B);

    A.erase(11);
    B.erase(11);

    print(A, B);

    A.insert(5);
    A.insert(421);

    multiset<int> u;
    set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(u, u.begin()));
    print(u);
    
    multiset<int> i;
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(i, i.begin()));
    print(i);

    set<int> diff;
    set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(diff, diff.begin()));
    print(diff);

    set<int> symm_diff;
    set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(symm_diff, symm_diff.begin()));
    print(diff);



    return 0;
}