/*
CH08-320143
a1 p5.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
#include "Matrix.h"
#include "Vector.h"
using namespace std;

Matrix::Matrix(){
    this->n = 0;
    this->m = 0;
}
Matrix::Matrix(const int& n, const int& m){
    this->n = n;
    this->m = m;
    this->mat = new double*[n];
    if(this->mat == NULL){
        exit(1);
    }
    for(int i = 0; i < n; i++){
        this->mat[i] = new double[m];
        if(this->mat[i] == NULL){
            exit(1);
        }
        for(int j = 0; j < m; j++){
            this->mat[i][j] = 0;
        }
    }
}

Matrix::Matrix(const int& n, const int& m, double** mat){
    this->n = n;
    this->m = m;
    this->mat = new double*[n];
    if(this->mat == NULL){
        exit(1);
    }
    for(int i = 0; i < n; i++){
        this->mat[i] = new double[m];
        if(this->mat[i] == NULL){
            exit(1);
        }
        for(int j = 0; j < m; j++){
            this->mat[i][j] = mat[i][j];
        }
    }
}

Matrix::~Matrix(){
    for(int i = 0; i < this->n; i++){
        delete [] this->mat[i];
    }
    delete [] this->mat;
    this->n = this->m = 0;
}

/* Operators */
ostream& operator<<(ostream& os, const Matrix& mat){
    os << mat.n << " " << mat.m << endl;
    os.precision(2);
    for(int i = 0; i < mat.n; i++){
        for(int j = 0; j < mat.m; j++){
            os << fixed << mat.mat[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

istream& operator>>(istream& is, Matrix& mat){
    is >> mat.n >> mat.m;
    mat.mat = NULL;
    mat.mat = new double*[mat.n];
    if(mat.mat == NULL){
        exit(1);
    }
    for(int i = 0; i < mat.n; i++){
        mat.mat[i] = new double[mat.m];
        if(mat.mat[i] == NULL){
            exit(1);
        }
        for(int j = 0; j < mat.m; j++){
            is >> mat.mat[i][j];
        }
    }
    return is;
}

Matrix Matrix::operator+(const Matrix& mat){
    if(this->n != mat.n || this->m != mat.m){
        return Matrix();
    }
    double **new_mat = new double*[this->n];
    for(int i = 0; i < this->n; i++){
        new_mat[i] = new double[this->m];
    }
    for(int i = 0; i < this->n; i++){
        for(int j = 0; j < this->m; j++){
            new_mat[i][j] = this->mat[i][j] + mat.mat[i][j];
        }
    }
    return Matrix(this->n, this->m, new_mat);
}

Matrix Matrix::operator-(const Matrix& mat){
    if(this->n != mat.n || this->m != mat.m){
        return Matrix();
    }
    double **new_mat = new double*[this->n];
    for(int i = 0; i < this->n; i++){
        new_mat[i] = new double[this->m];
    }
    for(int i = 0; i < this->n; i++){
        for(int j = 0; j < this->m; j++){
            new_mat[i][j] = this->mat[i][j] - mat.mat[i][j];
        }
    }
    return Matrix(this->n, this->m, new_mat);
}

Matrix Matrix::operator*(const Matrix& mat){
    if(this->m == mat.n){
        double **new_mat = new double*[this->n];
        for(int i = 0; i < this->n; i++){
            new_mat[i] = new double[mat.m];
        }
        for(int i = 0; i < this->n; i++){
            for(int j = 0; j < mat.m; j++){
                new_mat[i][j] = 0;
                for(int k = 0; k < this->m; k++){
                    new_mat[i][j] += (this->mat[i][k]*mat.mat[k][j]);
                }
            }
        }
        return Matrix(this->n, mat.m, new_mat);
    } else {
        return Matrix();
    }
}

Vector Matrix::operator*(Vector& v){
    if(v.getSize() == this->m){
        double *comp = new double[this->n];
        if(comp == NULL){
            exit(1);
        }
        for(int i = 0; i < this->n; i++){
            comp[i] = 0; 
            for(int j = 0; j < this->m; j++){
                comp[i] += this->mat[i][j]*v.getComponent(j);
            }
        }
        return Vector(this->n, comp);
    } else {
        return Vector();
    }
}

int Matrix::getN(){
    return this->n;
}

int Matrix::getM(){
    return this->m;
}

double Matrix::getMat(const int& i, const int &j){
    if(i >= this->n || j >= this->m || i < 0 || j < 0 || this->mat == NULL){
        return 0;
    }
    return this->mat[i][j];
}