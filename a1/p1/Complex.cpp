/*
CH08-320143
a1 p1.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/
#include "Complex.h"
#include <bits/stdc++.h>
using namespace std;
 
// constructor methods
 
Complex::Complex(){
    this->real = this->img = 0;
}
 
Complex::Complex(const int &real, const int &img){
    this->real = real;
    this->img = img;
}
 
Complex::~Complex(){
}
 
// getter methods
 
int Complex::getReal(){
    return this->real;
}
 
int Complex::getImaginary(){
    return this->img;
}
 
// setter methods
 
void Complex::setReal(const int &real){
    this->real = real;
}
 
void Complex::setImaginary(const int &img){
    this->img = img;
}
 
Complex Complex::getConjugation(){
    return Complex(this->real, -this->img);
}

// operators

Complex Complex::operator+(const Complex& c){
    return Complex(this->real + c.real, this->img + c.img);
}

Complex Complex::operator-(const Complex& c){
    return Complex(this->real - c.real, this->img - c.img);
}

Complex Complex::operator*(const Complex& c){
    int new_real = (this->real*c.real - this->img*c.img);
    int new_img = (this->real*c.img + this->img*c.real);
    return Complex(new_real, new_img);
}

Complex Complex::operator=(const Complex& c){
    return Complex(c);
}

ostream& operator<<(ostream& os, const Complex& c){
    string sign1 = "";
    string sign2 = "+";
    if(c.real < 0){
        sign1 = "-";
    }
    if(c.img < 0){
        sign2 = "-";
    }
    os << sign1 << abs(c.real) << sign2 << abs(c.img) << "i";
    return os;
}

istream& operator>>(istream& is, Complex& c){
    is >> c.real;
    is >> c.img;
    return is;
}