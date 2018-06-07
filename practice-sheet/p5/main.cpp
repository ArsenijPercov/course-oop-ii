#include <bits/stdc++.h>
using namespace std;

class Building {
public:
    double price(){
        return 100.0;
    }
};

class Neighborhood {
public:
    std::vector<Building*> coll;
public:
    Neighborhood(){
        for(int i = 0; i < 10; i++){
            coll.push_back(new Building());
        }
    }
    double overallprice(){
        double sum = 0;
        for(unsigned int i = 0; i < coll.size(); i++){
            sum += coll[i]->price();
        }
        return sum;
    }
};

int main(){
    
    Neighborhood n;
    cout << n.overallprice() << endl;

    return 0;
}