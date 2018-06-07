#ifndef _FRACTION_H
#define _FRACTION_H

#include <bits/stdc++.h>

class Fraction{

    int denom, num;

public: 

    class Error : public std::logic_error{
    public:
        Error(const std::string &msg = "") : std::logic_error(msg) {} 
    };

    /* CONSTRUCTORS AND DESTRUCTORS */
    Fraction();
    Fraction(const std::string& s);
    Fraction(const int& num, const int& denom);
    Fraction(const Fraction& f);
    ~Fraction();

    /* LOGIC OPERATORS */
    bool operator<(const Fraction& f) const;
    bool operator<=(const Fraction& f) const;
    bool operator>(const Fraction& f) const;
    bool operator>=(const Fraction& f) const;
    bool operator==(const Fraction& f) const;
    bool operator!=(const Fraction& f) const;

    /* ASSIGNMENT OPERATOR */
    Fraction operator=(const Fraction& f);

    /* STREAM OPERATORS */
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
    friend std::istream& operator>>(std::istream& is, Fraction& f);

    /* ARITHMETIC OPERATORS */
    Fraction operator+(const Fraction& f);
    Fraction operator-(const Fraction& f);
    Fraction operator*(const Fraction& f);
    Fraction operator/(const Fraction& f);
};

#endif // !_FRACTION_H