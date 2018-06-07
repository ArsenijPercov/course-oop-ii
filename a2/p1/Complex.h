/*
CH08-320143
a1 p1.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/
#ifndef _COMPLEX_H
#define _COMPLEX_H
 
#include <bits/stdc++.h>
using namespace std;
 
class Complex{
 
private:
 
    int real;
    int img;
 
public:
 
    // constructor methods
    Complex();
    Complex(const int &real, const int &img);
    // destructor
    ~Complex();
 
    // getter methods
    int getReal();
    int getImaginary();
 
    // setter methods
    void setReal(const int &real);
    void setImaginary(const int &img);
 
    // service methods
    // void print(); we do not need this one
    Complex getConjugation();
    // Complex add(const Complex &c); we don't need these anymore
    // Complex sub(const Complex &c);
    // Complex multi(const Complex &c);

    // operators
    bool operator<(const Complex& c);
    Complex operator+(const Complex&);
    Complex operator-(const Complex&);
    Complex operator*(const Complex&);
    Complex operator=(const Complex&);
    friend ostream& operator<<(ostream&, const Complex&);
    friend istream& operator>>(istream&, Complex&);
};
 
#endif