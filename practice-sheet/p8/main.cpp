#include <bits/stdc++.h>
using namespace std;

class MyException : public logic_error{
public:

    char msg[100];

    MyException(const char* msg = NULL) : logic_error::logic_error(msg){
        if(msg){
            strcpy(this->msg, msg);
        } else {
            strcpy(this->msg, "This is MyException.");
        }
    }

    virtual const char* what() const throw () {
        return "This is MyException";
    }
};

int main(){

    try{
        throw MyException();
    } catch(MyException& e){
        cout << e.what() << endl;
    }

    return 0;
}