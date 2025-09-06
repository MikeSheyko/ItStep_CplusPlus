#include <iostream>
using namespace std;


class Wheel 
{
private:
    string wheel_type;
public:
    Wheel() : wheel_type("No type") {}
    Wheel(string type) : wheel_type(type) {}
    void Show() const 
    {
        cout << "Wheel type : " << wheel_type << endl;
    }
};

class Engine 
{
private:
    string engine_type;
public:
    Engine() : engine_type("No type") {}
    Engine(string type) : engine_type(type) {}
    void Show() const 
    {
        cout << "Engine type : " << engine_type << endl;
    }
};

class Door 
{
private:
    string door_type;
public:
    Door() : door_type("No type") {}
    Door(string type) : door_type(type) {}
    void Show() const 
    {
        cout << "Door type: " << door_type << endl;
    }
};

class Body 
{
private:
    string body_type;
public:
    Body() : body_type("No type") {}
    Body(string type) : body_type(type) {}
    void Show() const 
    {
        cout << "Body type: " << body_type << endl;
    }
};

class Headlight 
{
private:
    string headlight_type;
public:
    Headlight() : headlight_type("No type") {}
    Headlight(string type) : headlight_type(type) {}
    void Show() const 
    {
        cout << "Headlight type: " << headlight_type << endl;
    }
};

class Car 
{
private:
    Headlight headlights[2];
    Door doors[4];
    Wheel* wheels;
    Engine engine;
    Body body;

public:
    Car() : engine("No type"), body("No type")
    {
        for (int i = 0; i < 2; ++i)
            headlights[i] = Headlight("No type");

        for (int i = 0; i < 4; ++i)
            doors[i] = Door("No type");

        wheels = new Wheel[4];
        for (int i = 0; i < 4; ++i)
            wheels[i] = Wheel("No type");
    }

    
    Car(string engineType, string bodyType, string wheelType, string doorType, string headlightType) : engine(engineType), body(bodyType)
    {
        wheels = new Wheel[4];
        for (int i = 0; i < 4; ++i)
            wheels[i] = Wheel(wheelType);

        for (int i = 0; i < 4; ++i)
            doors[i] = Door(doorType);
                
        for (int i = 0; i < 2; ++i)
            headlights[i] = Headlight(headlightType);
    }
        
      
    void Print() const 
    {
        cout << "----------------Car Info----------------" << endl;
        engine.Show();
        body.Show();

        cout << "----------------Wheels----------------" << endl;
        for (int i = 0; i < 4; ++i)
            wheels[i].Show();

        cout << "----------------Doors----------------" << endl;
        for (const Door& d : doors)
            d.Show();

        cout << "--------------Headlights--------------" << endl;
        for (const Headlight& h : headlights)
            h.Show();

    }

    ~Car()
    {
        delete[] wheels;
    }

};



int main()
{
	Car defaultCar;
	defaultCar.Print();

	cout << endl << "----------------------------------------" << endl << endl;
    
    Car car("PureTech", "Sedan", "Sport", "Standart", "LED");
    car.Print();



}

