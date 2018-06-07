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

/**
 * This function is used to open a file input stream with a specific
 * filename
 * @param filename the name of the file
 * @param ifs the ifstream object that will point to the input stream file
*/
void open_file(const string& fn, ifstream &ifs){
    const char* filename = fn.c_str();
    if(!ifs.is_open()){
        ifs.open(filename, ios::in);
        if(ifs.bad()){
            cerr << "Cannot open file\n";
            exit(1);
        }
    }
}

int main(){

    ifstream file1, file2, file3, file4;
    ofstream out;
    open_file("in1.txt", file1);
    open_file("in2.txt", file2);
    open_file("in3.txt", file3);
    open_file("in4.txt", file4);
    if(!out.is_open()){
        out.open("out.txt", ios::out);
        if(out.bad()){
            cerr << "Cannot open file\n";
            exit(1);
        }
    }

    Vector v1, v2;
    file1 >> v1;
    file2 >> v2;
    out << "First Vector\n";
    out << v1 << endl;
    out << "Second Vector\n";
    out << v2 << endl;
    out << "Their sum\n";
    out << v1+v2 << endl;
    out << "Their difference\n";
    out << v1-v2 << endl;

    Matrix m1, m2;
    file3 >> m1;
    file4 >> m2;
    out << "First Matrix\n";
    out << m1 << endl;
    out << "Second Matrix\n";
    out << m2 << endl;
    out << "Their Sum\n";
    out << m1+m2 << endl;
    out << "Their Difference\n";
    out << m1-m2 << endl;
    out << "Their product\n";
    out << m1*m2 << endl;

    out << "v1*m1 and m1*v1" << endl;
    out << v1*m1 << endl;
    out << m1*v1 << endl;

    out << "v2*m1 and m1*v2" << endl;
    out << v2*m1 << endl;
    out << m1*v2 << endl;

    out << "v1*m2 and m2*v1" << endl;
    out << v1*m2 << endl;
    out << m2*v1 << endl;

    out << "v2*m2 and m2*v2" << endl;
    out << v2*m2 << endl;
    out << m2*v2 << endl;

    return 0;
}