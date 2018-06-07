/*
CH08-320143
a2 p1.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/
#include <bits/stdc++.h>
#include "Complex.h"
using namespace std;

template <class T>
T array_min(T arr[], int size){
    T minn = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] < minn){
            minn = arr[i];
        }
    }
    return minn;
}

int main(){

    int size;
    cin >> size;
    int arr[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    int min_int = array_min(arr, size);
    cout << min_int << endl;

    cin >> size;
    float arr_floats[size];
    for(int i = 0; i < size; i++){
        cin >> arr_floats[i];
    }

    float min_float = array_min(arr_floats, size);
    cout << min_float << endl;

    cin >> size;
    Complex arr_c[size];
    for(int i = 0; i < size; i++){
        cin >> arr_c[i];
    }

    Complex minn_c = array_min(arr_c, size);
    cout << minn_c << endl;

    return 0;
}