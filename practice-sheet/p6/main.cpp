#include <bits/stdc++.h>
using namespace std;

class worker{
private:
    int id;
    string name;
public: 
    worker(const int& id, const string& name){
        this->id = id;
        this->name = name;
    }
    friend ostream& operator<<(ostream& os, const worker& w);
};

ostream& operator<<(ostream& os, const worker& w){
    os << w.name << " " << w.id << endl;
    return os;
}

int main(){

    worker a(234, "John Mcenroe");
    worker b(324, "Jack Nicholson");

    cout << a << b;

    cout << "Dumping to file...: " << endl;
    fstream out;
    if(!out.is_open()){
        out.open("list.dat", ios::out | ios::binary);
    }
    if(!out.good()){
        exit(1);
    }
    out << a << b;
    out.close();

    cout << "Done.\n";

    return 0;
}