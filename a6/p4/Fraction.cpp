/*
CH08-320143
a6 p4.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>
#include "Fraction.h"
using namespace std;

/* CONSTRUCTORS AND DESTRUCTORS */

Fraction::Fraction(){}

Fraction::Fraction(const string& s){
    if(s.length() == 0){
        throw Error("Invalid data or logical error");
    }
    size_t slashPos = s.find('/');
    if(slashPos == string::npos){
        throw Error("Invalid data or logical error");
    }
    string buf = s.substr(0, slashPos);
    for(size_t i = 0; i < buf.length(); i++){
        if(i == 0){
            if(buf[i] == '-' || buf[i] == '+' || isdigit(buf[i])){
                continue;
            } else {
                throw Error("Invalid data or logical error");
            }
        } else {
            if(isdigit(buf[i])){
                continue;
            } else {
                throw Error("Invalid data or logical error");
            }
        }
    }
    int num = atoi(buf.c_str());
    buf = s.substr(slashPos+1);
    for(size_t i = 0; i < buf.length(); i++){
        if(i == 0){
            if(buf[i] == '-' || buf[i] == '+' || isdigit(buf[i])){
                continue;
            } else {
                throw Error("Invalid data or logical error");
            }
        } else {
            if(isdigit(buf[i])){
                continue;
            } else {
                throw Error("Invalid data or logical error");
            }
        }
    }
    int denom = atoi(buf.c_str());
    if(denom == 0){
        throw Error("Invalid data or logical error");
    }
    int GCD = __gcd( abs(num), abs(denom));
    this->denom = denom/GCD;
    this->num = num/GCD;
    if(this->denom < 0 && this->num < 0){
        this->denom = abs(this->denom);
        this->num = abs(this->num);
    } else if(this->denom < 0 || this->num < 0){
        this->num = -abs(this->num);
        this->denom = abs(this->denom);
    }
}

Fraction::Fraction(const int& num, const int& denom){
    if(denom == 0){
        throw Error("Invalid data or logical error");
    }
    int GCD = __gcd(abs(num), abs(denom));
    this->denom = denom/GCD;
    this->num = num/GCD;
    if(this->denom < 0 && this->num < 0){
        this->denom = abs(this->denom);
        this->num = abs(this->num);
    } else if(this->denom < 0 || this->num < 0){
        this->num = -abs(this->num);
        this->denom = abs(this->denom);
    }
}

Fraction::Fraction(const Fraction& f){
    this->denom = f.denom;
    this->num = f.num;
}

Fraction::~Fraction(){}

/* LOGIC OPERATORS */

bool Fraction::operator<(const Fraction& f) const{
    if(this->denom == f.denom){
        return this->num < f.num;
    } else {
        return this->num*f.denom < f.num*this->denom;
    }
}

bool Fraction::operator<=(const Fraction& f) const{
    if(this->denom == f.denom){
        return this->num <= f.num;
    } else {
        return this->num*f.denom <= f.num*this->denom;
    }
}

bool Fraction::operator>(const Fraction& f) const{
    if(this->denom == f.denom){
        return this->num > f.num;
    } else {
        return this->num*f.denom > f.num*this->denom;
    }
}

bool Fraction::operator>=(const Fraction& f) const{
    if(this->denom == f.denom){
        return this->num >= f.num;
    } else {
        return this->num*f.denom >= f.num*this->denom;
    }
}

bool Fraction::operator==(const Fraction& f) const{
    if(this->denom == f.denom){
        return this->num == f.num;
    } else {
        return this->num*f.denom == f.num*this->denom;
    }
}

bool Fraction::operator!=(const Fraction& f) const{
    if(this->denom == f.denom){
        return this->num != f.num;
    } else {
        return this->num*f.denom != f.num*this->denom;
    }
}

/* ASSIGNMENT OPERATOR */

Fraction Fraction::operator=(const Fraction& f){
    return Fraction(f);
}

/* STREAM OPERATORS */
ostream& operator<<(ostream& os, const Fraction& f){
    os << f.num << "/" << f.denom;
    return os;
}

istream& operator>>(istream& is, Fraction& f){
    is >> f.num >> f.denom;
    if(f.denom == 0){
        throw Fraction::Error("Invalid data or logical error");
    }
    int GCD = __gcd( abs(f.num), abs(f.denom));
    f.num /= GCD;
    f.denom /= GCD;
    if(f.num < 0 && f.denom < 0){
        f.num = abs(f.num);
        f.denom = abs(f.denom);
    } else if(f.denom < 0 || f.num < 0){
        f.num = -abs(f.num);
        f.denom = abs(f.denom);
    }
    return is;
}

/* ARITHMETIC OPERATORS */

Fraction Fraction::operator+(const Fraction& f){
    if(this->denom == f.denom){
        return Fraction(this->num + f.num, this->denom);
    } else {
        return Fraction(this->num*f.denom + this->denom*f.num, this->denom*f.denom);
    }
}

Fraction Fraction::operator-(const Fraction& f){
    if(this->denom == f.denom){
        return Fraction(this->num - f.num, this->denom);
    } else {
        return Fraction(this->num*f.denom - this->denom*f.num, this->denom*f.denom);
    }
}

Fraction Fraction::operator*(const Fraction& f){
    return Fraction(this->num*f.num, this->denom*f.denom);
}

Fraction Fraction::operator/(const Fraction& f){
    return Fraction(this->num*f.denom, this->denom*f.num);
}