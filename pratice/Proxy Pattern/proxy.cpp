#include <iostream>
using namespace std;

class HorseBuyer{
public:
    virtual bool buy_horse(int) = 0;
};

class Person:public HorseBuyer{
public:
    bool buy_horse(int area){
        if(area > 100){
            return true;
        }
        return false;
    }
};

class Proxy:public HorseBuyer{
public:
    HorseBuyer* horse_buyer;
    
    Proxy(HorseBuyer* horse_buyer = new Person):horse_buyer(horse_buyer){}

    bool buy_horse(int area){
        return horse_buyer->buy_horse(area);
    }
};


int main(){
    int n;
    HorseBuyer* horse_buyer = new Proxy;
    cin >> n;
    int area;
    for(int i = 0;i<n;i++){
        cin >> area;
        if(horse_buyer->buy_horse(area)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}