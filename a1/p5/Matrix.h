/*
CH08-320143
a1 p5.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
#include "Vector.h"
using namespace std;

#ifndef _MATRIX_H
#define _MATRIX_H

class Vector;

class Matrix{

    int n, m;
    double** mat;

    public: 

    /* Constructors and desctructors */
    Matrix();
    Matrix(const int& n, const int& m);
    Matrix(const int& n, const int& m, double** mat);
    ~Matrix();

    /* Operators */
    friend ostream& operator<<(ostream& os, const Matrix& mat);
    friend istream& operator>>(istream& is, Matrix& mat);
    Matrix operator+(const Matrix& mat);
    Matrix operator-(const Matrix& mat);
    Matrix operator*(const Matrix& mat);
    Vector operator*(Vector& v);

    /* Getters and setters */
    int getN();
    int getM();
    double getMat(const int& i, const int &j);
};

#endif // !_MATRIX_H