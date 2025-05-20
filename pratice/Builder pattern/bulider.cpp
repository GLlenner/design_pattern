#include<string>
#include <iostream>
#include <vector>
using namespace std;

class Bike {
public:
    void add_part(const string& part)
    {
        parts.push_back(part);
    }
    void show_parts()
    {
        cout << "Bike parts: ";
        for (const auto& part : parts) {
            cout << part << ", ";
        }
        cout << endl;
    }

private:
    vector<string> parts;
};

class BikeBuilder {
public:
    virtual void build_frame() = 0;
    virtual void build_tires() = 0;
    virtual ~BikeBuilder() = default;
};

class Mountain:public BikeBuilder
{
    void build_frame()
    {
        cout << "add Aluminum Frame" << endl;
    }
    void build_tires()
    {
        cout << "add Knobby Tires" << endl;
    }
};
class Road:public BikeBuilder
{
    void build_frame()
    {
        cout << "add Carbon Frame" << endl;
    }
    void build_tires()
    {
        cout << "add Slim Tries" << endl;
    }
};
class Director
{
public:
    Director(string name)
    {
        if(name == "mountain")
        {
            bike = new Mountain;
        }
        else if(name == "road")
        {   
            bike = new Road;
        }
    }
    void product()
    {
        bike->build_frame();
        bike->build_tires();
    }
    BikeBuilder* bike; 
};
int main()
{
    Director a("mountain");
    a.product();
    return 0;
}