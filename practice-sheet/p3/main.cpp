#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq;
    for(int i = 5; i <= 500; i += 5){
        dq.push_back(i);
    }
    for(deque<int>::iterator it = dq.begin(); it != dq.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}