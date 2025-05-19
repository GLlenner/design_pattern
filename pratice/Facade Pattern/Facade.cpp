//实现外观模式

#include <iostream>
using namespace std;


class AirConditioner
{
public:
    void turn_off(){
        cout << "Air Conditioner is turned off." << endl;
    }
};
class DeskLamp
{
public:
    void turn_off(){
        cout << "Desk Lamp is turned off." << endl;
    }
};
class Television
{
public:
    void turn_off(){
        cout << "Television is turned off." << endl;
    }
};
class Ifacade
{
public:
    void turn_off(int choice){
        switch (choice)
        {
        case 1:
            airConditioner.turn_off();
            break;
        case 2:
            deskLamp.turn_off();
            break;
        case 3:
            television.turn_off();
            break;
        case 4:
            airConditioner.turn_off();
            deskLamp.turn_off();
            television.turn_off();
            break;
        }
    }
private:
    AirConditioner airConditioner;
    DeskLamp deskLamp;
    Television television;
};

int main()
{   
    Ifacade facade;
    facade.turn_off(1);
    facade.turn_off(2);
    facade.turn_off(3);
    facade.turn_off(4);
    return 0;
}