/*
CH08-320143
a1 p5.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
#include "Vector.h"
#include "Matrix.h"
using namespace std;
 
// constructors
Vector::Vector(){
    this->size = 0;
    this->comp = NULL;
}
 
Vector::Vector(const Vector& v){
    this->size = v.size;
    this->comp = new double[this->size];
    for(int i = 0; i < this->size; i++){
        this->comp[i] = v.comp[i];
    }
}
 
Vector::Vector(const int &size, const double *comp){
    this->size = size;
    this->comp = new double[this->size];
    for(int i = 0; i < this->size; i++){
        this->comp[i] = comp[i];
    }
}
 
// destructor
Vector::~Vector(){
    delete [] this->comp;
    this->size = 0;
}
 
// getters
int Vector::getSize() const{
    return this->size;
}
 
double* Vector::getComponents() const{
    return this->comp;
}
 
// setters
void Vector::setSize(const int &size){
    this->size = size;
    delete [] this->comp;
    this->comp = new double[this->size];
}
 
void Vector::setComponents(const double *comp, const int &size){
    if(size != this->size){
        return;
    }
    for(int i = 0;  i < this->size; i++){
        this->comp[i] = comp[i];
    }
}
 
 
double Vector::norm() const{
    double res = 0;
    for(int i = 0; i < this->size; i++){
        res += this->comp[i];
    }
    return sqrt(res);
}
 
double Vector::scalar(const Vector &v) const{
    double res = 0;
    for(int i = 0; i < this->size; i++){
        res += this->comp[i]*v.comp[i];
    }
    return res;
}

Vector Vector::operator+(const Vector& v){
    if(this->size != v.size){
        return Vector();
    }
    Vector ret;
    ret.setSize(this->size);
    for(int i = 0; i < this->size; i++){
        ret.comp[i] = this->comp[i] + v.comp[i];
    }
    return ret;
}

Vector Vector::operator-(const Vector& v){
    if(this->size != v.size){
        return Vector();
    }
    Vector ret;
    ret.setSize(this->size);
    for(int i = 0; i < this->size; i++){
        ret.comp[i] = this->comp[i] - v.comp[i];
    }
    return ret;
}

ostream& operator<<(ostream& os, const Vector& v){
    os << v.size << endl;
    for(int i = 0; i < v.size; i++){
        os << v.comp[i] << " ";
    }
    return os;
}

istream& operator>>(istream& is, Vector& v){
    int size;
    is >> size;
    v.setSize(size);
    for(int i = 0; i < v.size; i++){
        is >> v.comp[i];
    }
    return is;
}

Vector Vector::operator*(Matrix& mat){
    if(this->size == mat.getN()){
        double* comp = new double[mat.getM()];
        if(comp == NULL){
            exit(1);
        }
        for(int i = 0; i < mat.getM(); i++){
            comp[i] = 0;
            for(int j = 0; j < this->size; j++){
                comp[i] += this->comp[j]*mat.getMat(i, j);
            }
        }
        return Vector(mat.getM(), comp);
    } else {
        return Vector();
    }
}

int Vector::getComponent(const int& i){
    if(i < 0 || i > this->size || this->comp == NULL){
        return 0;
    }
    return this->comp[i];
}
