
#include <iostream>
#include <Windows.h>
using namespace std;
//virtual override
class Car
{
private:
    string mark;
    float volume;
    string type_fuel;
    int year;
protected:
    int speed;
public:
    Car() :mark("none"), volume(0), type_fuel("none"), year(0), speed(0) {}
    Car(string m, float v, string tf, int y) :mark(m), volume(v), type_fuel(tf),
        year(y), speed(0) {
    }
    void setSpeed(int speed)
    {
        /* if (speed > 0)
         {
             this->speed = speed;
         }
         else
         {
             this->speed = 0;
         }*/

        this->speed = (speed > 0) ? speed : 0;

    }
    void Print()const
    {
        cout << "-----------Car------------------" << endl;
        cout << "Mark : " << mark << endl;
        cout << "Volume : " << volume << endl;
        cout << "Type_fuel : " << type_fuel << endl;
        cout << "Year : " << year << endl;
        cout << "Speed : " << speed << endl;
    }
    virtual void Drive()const
    {
        cout << "I am a Car! I can drive with speed : " << speed << " km/h" << endl;
    }
};
class PoliceCar : public Car//public private protected
{
    int volumeSound;
public:
    PoliceCar() :volumeSound(0), Car() {}
    PoliceCar(string m, float v, string tf, int y, int vol) :volumeSound(vol),
        Car(m, v, tf, y) {
    }
    void Print()const
    {
        cout << "----------- Police Car------------------" << endl;
        Car::Print();
        cout << "Sound volume " << volumeSound << endl;
    }
    void Drive()const
    {
        cout << "I am a Police Car! I can drive with speed : " << speed << " km/h" << endl;
    }
    void BeepBeep()
    {
        Beep(330, 100); Sleep(100);
        Beep(330, 100); Sleep(300);
        Beep(330, 100); Sleep(300);
        Beep(262, 100); Sleep(100);
        Beep(330, 100); Sleep(300);
        Beep(392, 100); Sleep(700);
        Beep(196, 100); Sleep(700);
        Beep(262, 300); Sleep(300);
        Beep(196, 300); Sleep(300);
        Beep(164, 300); Sleep(300);
        Beep(220, 300); Sleep(100);
        Beep(246, 100); Sleep(300);
        Beep(233, 200);
        Beep(220, 100); Sleep(300);
        Beep(196, 100); Sleep(150);
        Beep(330, 100); Sleep(150);
        Beep(392, 100); Sleep(150);
        Beep(440, 100); Sleep(300);
        Beep(349, 100); Sleep(100);
        Beep(392, 100); Sleep(300);
        Beep(330, 100); Sleep(300);
        Beep(262, 100); Sleep(100);
        Beep(294, 100); Sleep(100);
        Beep(247, 100); Sleep(500);
        Beep(262, 300); Sleep(300);
        Beep(196, 300); Sleep(300);
        Beep(164, 300); Sleep(300);
        Beep(220, 300); Sleep(100);
        Beep(246, 100); Sleep(300);
        Beep(233, 200);
        Beep(220, 100); Sleep(300);
        Beep(196, 100); Sleep(150);
        Beep(330, 100); Sleep(150);
        Beep(392, 100); Sleep(150);
        Beep(440, 100); Sleep(300);
        Beep(349, 100); Sleep(100);
        Beep(392, 100); Sleep(300);
        Beep(330, 100); Sleep(300);
        Beep(262, 100); Sleep(100);
        Beep(294, 100); Sleep(100);
        Beep(247, 100); Sleep(900);
        Beep(392, 100); Sleep(100);
        Beep(370, 100); Sleep(100);
        Beep(349, 100); Sleep(100);
        Beep(311, 100); Sleep(300);
        Beep(330, 100); Sleep(300);
        Beep(207, 100); Sleep(100);
        Beep(220, 100); Sleep(100);
        Beep(262, 100); Sleep(300);
        Beep(220, 100); Sleep(100);
        Beep(262, 100); Sleep(100);
        Beep(294, 100); Sleep(500);
        Beep(392, 100); Sleep(100);
        Beep(370, 100); Sleep(100);
        Beep(349, 100); Sleep(100);
        Beep(311, 100); Sleep(300);
        Beep(330, 100); Sleep(300);
        Beep(523, 100); Sleep(300);
        Beep(523, 100); Sleep(100);
        Beep(523, 100); Sleep(1100);
        Beep(392, 100); Sleep(100);
        Beep(370, 100); Sleep(100);
        Beep(349, 100); Sleep(100);
        Beep(311, 100); Sleep(300);
        Beep(330, 100); Sleep(300);
        Beep(207, 100); Sleep(100);
        Beep(220, 100); Sleep(100);
        Beep(262, 100); Sleep(300);
        Beep(220, 100); Sleep(100);
        Beep(262, 100); Sleep(100);
        Beep(294, 100); Sleep(500);
        Beep(311, 300); Sleep(300);
        Beep(296, 300); Sleep(300);
        Beep(262, 300); Sleep(1300);
        Beep(262, 100); Sleep(100);
        Beep(262, 100); Sleep(300);
        Beep(262, 100); Sleep(300);
        Beep(262, 100); Sleep(100);
        Beep(294, 100); Sleep(300);
        Beep(330, 200); Sleep(50);
        Beep(262, 200); Sleep(50);
        Beep(220, 200); Sleep(50);
        Beep(196, 100); Sleep(700);
        Beep(262, 100); Sleep(100);
        Beep(262, 100); Sleep(300);
        Beep(262, 100); Sleep(300);
        Beep(262, 100); Sleep(100);
        Beep(294, 100); Sleep(100);
        Beep(330, 100); Sleep(700);
        Beep(440, 100); Sleep(300);
        Beep(392, 100); Sleep(500);
        Beep(262, 100); Sleep(100);
        Beep(262, 100); Sleep(300);
        Beep(262, 100); Sleep(300);
        Beep(262, 100); Sleep(100);
        Beep(294, 100); Sleep(300);
        Beep(330, 200); Sleep(50);
        Beep(262, 200); Sleep(50);
        Beep(220, 200); Sleep(50);
        Beep(196, 100); Sleep(700);
        /*Intro*/
        Beep(330, 100); Sleep(100);
        Beep(330, 100); Sleep(300);
        Beep(330, 100); Sleep(300);
        Beep(262, 100); Sleep(100);
        Beep(330, 100); Sleep(300);
        Beep(392, 100); Sleep(700);
        Beep(196, 100); Sleep(700);
        Beep(196, 100); Sleep(125);
        Beep(262, 100); Sleep(125);
        Beep(330, 100); Sleep(125);
        Beep(392, 100); Sleep(125);
        Beep(523, 100); Sleep(125);
        Beep(660, 100); Sleep(125);
        Beep(784, 100); Sleep(575);
        Beep(660, 100); Sleep(575);
        Beep(207, 100); Sleep(125);
        Beep(262, 100); Sleep(125);
        Beep(311, 100); Sleep(125);
        Beep(415, 100); Sleep(125);
        Beep(523, 100); Sleep(125);
        Beep(622, 100); Sleep(125);
        Beep(830, 100); Sleep(575);
        Beep(622, 100); Sleep(575);
        Beep(233, 100); Sleep(125);
        Beep(294, 100); Sleep(125);
        Beep(349, 100); Sleep(125);
        Beep(466, 100); Sleep(125);
        Beep(587, 100); Sleep(125);
        Beep(698, 100); Sleep(125);
        Beep(932, 100); Sleep(575);
        Beep(932, 100); Sleep(125);
        Beep(932, 100); Sleep(125);
        Beep(932, 100); Sleep(125);
        Beep(1046, 675);


    }

};
class SportCar : public Car//public private protected
{
    int turbo;
public:
    SportCar() :turbo(0), Car() {}
    SportCar(string m, float v, string tf, int y, int t) :turbo(t),
        Car(m, v, tf, y) {
    }
    void Print()const
    {
        cout << "----------- Police Car------------------" << endl;
        Car::Print();
        cout << "Turbo speed " << turbo << endl;
    }
    void Drive() const override
    {
        cout << "I am a Sport Car! I can drive with speed : " << speed << " km/h" << endl;
    }
    void NitroSpeed()
    {
        cout << "Nitro speed : " << speed + turbo << "km / h" << endl;
    }

};

void TestCar(Car& car)
{
    car.setSpeed(70);
    car.Drive();
}
int main()
{
    Car car("Nissan", 1.5, "gazoline", 2007);
    car.setSpeed(100);
    car.Drive();
    car.Print();
    cout << endl;
    PoliceCar p("Prius", 2.0, "hybrid", 2020, 500);
    //p.BeepBeep();
    p.setSpeed(250);
    p.Drive();
    p.Print();

    SportCar sport("Formula1", 2.5, "gazoline", 2025, 50);
    sport.setSpeed(200);
    sport.Drive();
    cout << "------------------------------------" << endl;
    TestCar(car);
    TestCar(p);
    TestCar(sport);




}
