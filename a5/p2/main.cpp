/*
CH08-320143
a5 p2.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/
#include <bits/stdc++.h>
using namespace std;

class OwnException : public exception{
public: 

    char msg[100];

    OwnException(const char* msg = NULL){
        if(msg)
            strcpy(this->msg, msg);
        else 
            strcpy(this->msg, "This is a default exception case.");
    }

    virtual const char* what() const throw(){
        return msg;
    }
};

void myfunc(const char& ch){

    if(ch == '1'){
        throw 'e';
    } else if(ch == '2'){
        throw 99;
    } else if(ch == '3'){
        throw false;
    } else {
        throw OwnException("This is an OwnException");
    }
}

int main(){

    char ch;
    cin >> ch;
    try{
        myfunc(ch);
    } catch(char& ch){
        cerr << "Exception caught in main: " << ch << endl;
        return 1;
    } catch(int& i){
        cerr << "Exception caught in main: " << i << endl;
        return 1;
    } catch(bool& b){
        cerr << "Exception caught in main: " << b << endl;
        return 1;
    } catch(OwnException& oe){
        cerr << "Exception caught in main: " << oe.what() << endl;
        return 1;
    }

    return 0;
}