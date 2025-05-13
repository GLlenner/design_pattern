#include <string>
#include <iostream>
using namespace std;

class Building_Blocks
{
public:
    virtual void product() = 0;
};

class Circle_BB:public Building_Blocks
{
    void product()
    {
        cout << "circle buliding_block" << endl;
        return;
    }
};

class Square_BB:public Building_Blocks
{
public:
    void product()
    {
        cout << "square buliding_block" << endl;
        return;
    }
};


class Building_Blocks_Factory
{
public:
    virtual Building_Blocks* creat_factory() = 0; 
};


class Circle_BB_Factory:public Building_Blocks_Factory
{
public:
    virtual Building_Blocks* creat_factory()
    {
        return new Circle_BB;
    }
};

class Square_BB_Factory:public Building_Blocks_Factory
{
public:
    virtual Building_Blocks* creat_factory()
    {
        return new Square_BB;
    }
};



int main()
{
    Building_Blocks_Factory* circle = new Circle_BB_Factory;
    Building_Blocks* a = circle->creat_factory();
    a->product();
}