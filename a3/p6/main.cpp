/*
CH08-320143
a3 p6.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
using namespace std;

class Person{
private: 
    string name;
    int age;
public: 
    Person(string name = "Mike", int age = 15){
        this->name = name;
        this->age = age;
    }
    friend ostream& operator<<(ostream& os, const Person& p){
        os << "Name: " << p.name << endl;
        os << "Age: " << p.age;
        return os;
    }
    bool operator<(const Person& p) const{
        return this->age < p.age;
    }
};

class MyComparator{
public:
    bool operator()(const int& a, const int& b) const{
        return a > b;
    }
};

int main(){

    priority_queue<int> pq; // queue which keeps the maximum element on top
    // it is basically a max-heap
    for(int i = 0; i < 5; i++){
        pq.push(i); // pushesh element into a queue
    }

    cout << "The size of the priority queue is: " << pq.size() << endl; // .size() method
    
    while(!pq.empty()){ // returns true if empty, false otherwise
        int topElement = pq.top(); // returns the top(maximum) element
        pq.pop(); // pops the top element
        cout << topElement << " ";
    }
    cout << endl << endl;

    priority_queue<Person> q; // It can contain objects which have
    // < operator overriden
    q.push(Person("John", 20));
    q.push(Person());
    q.push(Person("Jack", 30));

    while(!q.empty()){
        cout << q.top() << endl;
        q.pop();
    }

    cout << endl;

    priority_queue<int, vector<int>, MyComparator> myq; // queue with a different ordering criterion
    for(int i = 5; i >= 1; i--){
        myq.push(i);
    }

    while(!myq.empty()){
        cout << myq.top() << " ";
        myq.pop();
    }
    cout << endl;

    return 0;
}