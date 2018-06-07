/*
CH08-320143
a1 p5.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#ifndef _VECTOR_H
#define _VECTOR_H
#include <bits/stdc++.h>
#include "Matrix.h"
using namespace std;
 
class Vector{
 
private:
 
    int size;
    double *comp;
 
public:
 
    // constructors
    Vector();
    Vector(const Vector&);
    Vector(const int&, const double*);
 
    // destructor
    ~Vector();
 
    // getters
    int getSize() const;
    double* getComponents() const;
    int getComponent(const int& i);
 
    // setters
    void setSize(const int&);
    void setComponents(const double*, const int&);
 
    // service methods
    // void print() const; not needed anyomore
    double norm() const;
    // Vector sub(const Vector&) const; // not needed anymore
    // Vector add(const Vector&) const; // not needed anymore
    double scalar(const Vector&) const;
    Vector operator+(const Vector&);
    Vector operator-(const Vector&);
    friend ostream& operator<<(ostream&, const Vector&);
    friend istream& operator>>(istream&, Vector&);
    Vector operator*(Matrix& mat);
};
 
#endif