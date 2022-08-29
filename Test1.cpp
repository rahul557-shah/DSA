// Representation of Graph
#include <bits/stdc++.h>
using namespace std;
class Car
{
private:
    int wheels, speed;

public:
    Car()
    {
        cout << "Car Default Constructor!!" << endl;
    }
    Car(int speed)
    {
        this->speed = speed;
    }
    virtual void display()
    {
        cout << "General Car" << endl;
    }
    void findSpeed()
    {
        cout << "The speed of car is: " << speed << endl;
    }
};
class Innova : public Car
{
public:
    Innova()
    {
        cout << "Innova Default Constructor!!" << endl;
    }
    // void display()
    // {
    //     cout << "Innova Car!!" << endl;
    // }
};
class Swift : public Car
{
public:
    Swift()
    {
        cout << "Swift Default Constructor!!" << endl;
    }
    void display()
    {
        cout << "Swift Car" << endl;
    }
};
int main()
{
    // Car *c = new Car(80);
    // c->display();
    // c->findSpeed();
    Car *c = new Innova();
    c->display();
    Swift *s = new Swift();
    s->display();
    s->findSpeed();
    return 0;
}