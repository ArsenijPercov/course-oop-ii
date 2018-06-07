#include <bits/stdc++.h>
using namespace std;

int main(){
    list<string> myList;
    while(true){
        string s;
        getline(cin, s);
        if(s == "ZZ"){
            break;
        }
        myList.push_back(s);
    }
    myList.sort();
    for(list<string>::iterator it = myList.begin(); it != myList.end(); it++){
        cout << *it << endl;
    }
    return 0;
}