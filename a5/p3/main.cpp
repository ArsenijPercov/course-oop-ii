/*
CH08-320143
a5 p3.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/
#include <bits/stdc++.h>
using namespace std;

class Motor{

public: 

    Motor(){
        throw "This motor has problems";
    }
};

class Car{

    Motor *motor = NULL;

public: 

    Car(){
        try{
            motor = new Motor();
        } catch(char const* e){
            cerr << e << endl;
            throw "The car in this garage has problems with the motor";
        }
    }
};

class Garage{

    Car *car = NULL;

public:

    Garage(){
        try{
           car = new Car(); 
        } catch (char const* e){
            throw e;
        }
    }

    void close(){
        cout << "Garage is closing!\n";
    }
};

int main(){

    Garage *garage = NULL;
    try{
        garage = new Garage();
    } catch(char const* e){
        cerr << e << endl;
        return 1;
    }

    garage->close();

    return 0;
}