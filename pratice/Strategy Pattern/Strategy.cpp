//策略设计模式
#include <iostream>
using namespace std;

class Strategy{    
public:
    virtual double charge(double) = 0;
};
class Discount:public Strategy{
public:
    virtual double charge(double val){
        return 0.9 * val;
    }
};
class Reduction:public Strategy{
public:
    virtual double charge(double val){
        int full[4] = {100,150,200,300};
        int reduction[4] = {5,15,25,40};
        int i = 0;
        for(;i<4;i++){
            if(val <= full[i]){
                break;
            }
        }
        if(i == 4){
            i = 3;
        }
        return val - reduction[i];
    }

};

class Context{
public:
    Context(int chioce){
        switch(chioce){
            case 1:
                strategy = new Discount;
                break;
            case 2:
                strategy = new Reduction;
                break;
            default:
                throw "can't recognition the number";
        }
    }

    Strategy* strategy;
};

int main(){
    int n;
    cin >> n;
    int val;
    int choice;
    for(int i = 0;i<n;i++){
        cin >> val >> choice;
        Context context = Context(choice);
        cout << context.strategy->charge(val) << endl;
    }
}