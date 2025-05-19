//实现模板设计模式

#include <iostream>
using namespace std;
class Coffee
{
public:
    virtual void add_seasonings() = 0;
    void grinding_beans()
    {
        cout << "Grinding coffee beans" << endl;
    }
    void brewing_coffee()
    {
        cout << "Brewing coffee" << endl;
    }
    void make_coffee()
    {
        grinding_beans();
        brewing_coffee();
        add_seasonings();
    }
};
class Black:public Coffee
{
public:
    void add_seasonings()
    {
        cout << "Adding condiments" << endl;
    }
};

class Latte:public Coffee
{
    public:
    void add_seasonings()
    {
        cout << "Adding condiments" << endl;
        cout << "Adding milk" << endl;
    }
};


int main()
{
    Coffee* coffee = new Latte;
    coffee->make_coffee();
    return 0;
}