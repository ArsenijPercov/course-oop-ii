/*
CH08-320143
a2 p4.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
#include "LinkedList.h"

int main(){

    LinkedList<int> list;

    for(int i = 0; i < 5; i++){
        list.push_front(i);
    }

    for(int i = 5; i < 10; i++){
        list.push_back(i);
    }

    std::cout << list.back() << std::endl;
    std::cout << list.front() << std::endl;

    while(list.getSize()){
        std::cout << list.pop_back() << std::endl;
        std::cout << list.pop_front() << std::endl;
    }

    std::cout.precision(2);

    LinkedList<float> list1;

    for(int i = 0; i < 5; i++){
        list1.push_front((float)i);
    }

    for(int i = 5; i < 10; i++){
        list1.push_back((float)i);
    }

    std::cout << std::fixed << list1.back() << std::endl;
    std::cout << std::fixed << list1.front() << std::endl;

    while(list1.getSize()){
        std::cout << std::fixed << list1.pop_back() << std::endl;
        std::cout << std::fixed << list1.pop_front() << std::endl;
    }

    return 0;
}