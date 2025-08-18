#include <iostream>
using namespace std;
#include <Windows.h>




class Car
{
private:
    string model;
	float volume;
	string typeFuel;
	int year;
protected:
	int speed;
public:
	Car() : model("none"), volume(0.0), typeFuel("none"), year(0), speed(0) {}
	Car(string m, float v, string tf, int y, int s) : model(m), volume(v), typeFuel(tf), year(y), speed(0) {}

    void setSpeed(int speed)
	{
		/*if (speed > 0) 
		{
			this->speed = speed;
		}
		else
		{
			this->speed = 0;
		}*/

		this->speed = (speed > 0) ? speed : 0; // Ternary operator for setting speed
	}

	void Print() const
	{
		cout << "-------------- Car --------------" << endl;
		cout << "Model : " << model << endl;
		cout << "Volume : " << volume << endl;
		cout << "Type of fuel : " << typeFuel << endl;
		cout << "Year : " << year << endl;
		cout << "Speed : " << speed << endl;
	}


	void Drive() const
	{
		cout << "I am a Car! I can drive with speed " << speed << " km/h" << endl;
	}
    

};


class PoliceCar : public Car // public, protected, private
{
	int soundVolume;
public:
	PoliceCar() :soundVolume(0), Car() {}
	PoliceCar(string m, float v, string tf, int y, int vol) : soundVolume(vol), Car(m, v, tf, y) {}
	void Drive() const
	{
		cout << "I am a Police Car! I can drive with speed " << speed << " km/h" << endl;
	}
	void Print()const
	{
		cout << "---------- Police  Car --------------" << endl;
		Car::Print();
		cout << "Sound Volume : " << soundVolume << endl;
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






int main()
{
   

	Car car("Nissan", 1.5, "Gasoline", 2007);
	car.setSpeed(100);
	car.Drive();
	car.Print();

	cout << endl;

	PoliceCar p("Toyota", 2.0, "Hybrid", 2020, 500);

	p.setSpeed(150);
	p.Drive();
	p.Print();



}

