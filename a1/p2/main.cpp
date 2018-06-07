/*
CH08-320143
a1 p2.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * This function is used to open a file for a file stream
 * for a specific filename.
 * @param filename the name of the file to be opened
 * @param in an ifstream instance, object for the filestream 
*/
void open_file(string filename, ifstream& in){
    const char* fn = filename.c_str();
    if(!in.is_open()){
        in.open(fn, ios::in | ios::binary);
    }
}

/**
 * This method returns the length of a file (the number of characters
 * it contains).
 * @param in the file whose length is returned
*/
int get_file_length(ifstream& in){
    in.seekg(0, ios::end);
    int len = in.tellg();
    in.seekg(0, ios::beg);
    return len;
}

int main(){

    /* Input */
    int n;
    cin >> n;
    string filenames[n];
    for(int i = 0; i < n; i++){
        cin >> filenames[i];
    }

    /* Open output file */
    ofstream out;
    if(!out.is_open()){
        out.open("countn.txt", ios::out | ios::binary);
        if(out.bad()){
            cerr << "Cannot open file\n";
            exit(1);
        }
    }

    /* Go through the input files and concatenate them */
    for(int i = 0; i < n; i++){

        /* Open and check the current input file */
        ifstream in;
        open_file(filenames[i], in);
        if(in.bad()){
            cerr << "Cannot open file\n";
            continue;
        }

        /* Read from the input file and insert into output file */
        int len = get_file_length(in);
        char *buffer = new char[len+1];
        in.read(buffer, len);
        buffer[len] = '\n';
        out.write(buffer, len+1);
        delete [] buffer;
    }

    return 0;
}