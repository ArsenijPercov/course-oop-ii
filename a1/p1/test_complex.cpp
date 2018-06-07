/*
CH08-320143
a1 p1.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/
#include <bits/stdc++.h>
#include "Complex.h"
using namespace std;
 
int main(){

    ifstream file1;
    ifstream file2;
    ofstream output;

    /* Open and check the first input file */
    if(!file1.is_open()){
        file1.open("in1.txt", ios::in);
        if(file1.bad()){
            cerr << "Cannot open file 1\n";
        }
    }

    /* Open and check the second input file */
    if(!file2.is_open()){
        file2.open("in2.txt", ios::in);
        if(file2.bad()){
            cerr << "Cannot open file 2\n";
        }
    }

    /* Open and check the output file */
    if(!output.is_open()){
        output.open("output.txt", ios::out);
        if(output.bad()){
            cerr << "Cannot open output\n";
        }
    }

    /* Since we have overridden the << and >> operators
    and fstream objects, such as ifstream and ofstream,  can use
    << and >>, since they are stream objects. That is why
    I use << and >> here too. */
    Complex c1, c2;
    file1 >> c1;
    file2 >> c2;
    output << c1 << endl;
    output << c2 << endl;
    output << c1+c2 << endl;
    output << c1-c2 << endl;
    output << c1*c2 << endl;
    c2 = c1;
    output << c2 << endl;
 
    return 0;
}