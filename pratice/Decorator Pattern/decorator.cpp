#include<string>
#include <iostream>
using namespace std;

class Coffee{
public:
    virtual void add_condiments() = 0;
};

class Decoretor: public Coffee{
public:
    Coffee* coffee;//关键在于这个成员变量，这里起到装饰作用
    virtual void add_condiments() = 0;
};
class Mike:public Decoretor{
public:
    Mike(Coffee* coffee):coffee(coffee){};
    Coffee* coffee;
    void add_condiments(){
        coffee->add_condiments();
        cout << " + mike";
    }
};
class Suger:public Decoretor{
public:
    Suger(Coffee* coffee):coffee(coffee){};
    Coffee* coffee;
    void add_condiments(){
        coffee->add_condiments();
        cout << " + suger";
    }
};


class BlackCoffee :public Coffee{
public:
    void add_condiments(){
        cout << " blackCoffee";
    }
};
class Latte :public Coffee{
    void add_condiments(){
        cout << "Latte";
    }
};


int main(){
    Coffee* my_coffee = new Latte;
    my_coffee = new Suger(my_coffee);
    my_coffee = new Mike(my_coffee);
    my_coffee = new Suger(my_coffee);
    my_coffee->add_condiments();
    return 0;
}