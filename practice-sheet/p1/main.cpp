#include <bits/stdc++.h>
using namespace std;

template<class T>
T sumArray(T arr[], int n){
    T sum = arr[0];
    for(int i = 1; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){

    int inum[5] = { 10, 20, 30, 40, 50 };
    double dnum[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    cout << "Sum of inum is: " << sumArray(inum, 5) << endl;
    cout << "Sum of dnum is: " << sumArray(dnum, 5) << endl;

    return 0;
}