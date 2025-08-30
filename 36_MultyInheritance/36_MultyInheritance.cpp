#include <iostream>
using namespace std;

class Car
{
public:
    void Drive() {
        cout << "I can drive " << endl;
    }
    void Use() {
        cout << "I can drive " << endl;
    }
};
class Airplane
{
public:
    void Fly() {
        cout << "I can fly " << endl;
    }
    void Use() {
        cout << "I can fly " << endl;
    }
};

class FlyCar : public Car, public Airplane
{

};
class A
{
public:
    int value;
};
class B :public A {};
class C :public A {};
class D : public B, public C
{
public:
    int getValue()
    {
        //return value;//error
        return B::value;
        return B::A::value;
        return C::value;
        return C::A::value;
    }
};
int main()
{
    /*  Car car;
      car.Drive();
      car.Use();

      Airplane air;
      air.Fly();
      air.Use();
      cout << "-----------------------------" << endl;
      FlyCar fc;
      fc.Drive();
      fc.Fly();
      ((Car)fc).Use();
      ((Airplane)fc).Use();*/

}