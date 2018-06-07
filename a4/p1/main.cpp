/*
CH08-320143
a4 p1.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<char> letters;
    for(char ch = 'a'; ch <= 'z'; ch++){
        letters.push_back(ch);
    }

    reverse(letters.begin(), letters.end());
    for(vector<char>::iterator it = letters.begin(); it != letters.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    letters.push_back('f');
    replace(letters.begin(), letters.end(), 'f', '$');

    for(vector<char>::iterator it = letters.begin(); it != letters.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}