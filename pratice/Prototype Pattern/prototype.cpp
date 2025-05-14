#include<string>
#include <memory>
#include <iostream>

using namespace std;
class Prototype
{
public:
    virtual unique_ptr<Prototype> clone() = 0; 
    int width;
    int length;
    string color;
};

class Rectangle:public Prototype
{
public:
    Rectangle(int width, int length, const string& color)
    {
        this->width = width;
        this->length = length;
        this->color = color;
    }
    Rectangle(const Rectangle& rectangle)
    {
        this->width = rectangle.width;
        this->length = rectangle.length;
        this->color = rectangle.color;
    }
    unique_ptr<Prototype> clone()
    {
        return make_unique<Rectangle>(*this);
    }
};

int main()
{
    string color;
    int width;
    int length;
    cin >> color >> width >> length;
    unique_ptr<Prototype> rec1 = make_unique<Rectangle>(width, length, color);
    unique_ptr<Prototype> rec2 = rec1->clone();
    unique_ptr<Prototype> rec3 = rec2->clone();

    cout <<  rec3->width << endl;

}