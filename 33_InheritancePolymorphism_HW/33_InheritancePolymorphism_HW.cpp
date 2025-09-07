#include <iostream>
#include <Windows.h>
using namespace std;


class Animal
{
protected:
    string species;
    double weight;
    string habitat;
    double speed;

public:
    Animal() : species("None"), weight(0), habitat("None"), speed(0) {}

    Animal(string sp, double w, string hab) : species(sp), weight(w), habitat(hab), speed(0) {}

    void setSpeed(double spd)
    {
        speed = (spd > 0) ? spd : 0;
    }

    virtual void print() const
    {
        cout << "------------------ Animal ------------------" << endl;
        cout << "Species: " << species << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Habitat: " << habitat << endl;
        cout << "Speed: " << speed << " km/h" << endl;
    }

    virtual void move() const
    {
        cout << species << " is moving at speed: " << speed << " km/h" << endl;
    }

    virtual void say() const = 0;
};

class Bird : public Animal
{
protected:
    double wingspan;

public:
    Bird() : wingspan(0), Animal() {}
    Bird(string sp, double w, string hab, double ws) : wingspan(ws), Animal(sp, w, hab) {}

    void print() const override
    {
        Animal::print();
        cout << "Wingspan: " << wingspan << " meters" << endl;
    }

    void move() const override
    {
        cout << "I am a Bird! I can fly at speed: " << speed << " km/h" << endl;
    }

    void say() const override
    {
        cout << "Chirp chirp!" << endl;
    }
};


class Reptile : public Animal
{
protected:
    bool venomous;

public:
    Reptile() : venomous(false), Animal() {}
    Reptile(string sp, double w, string hab, bool venom) : venomous(venom), Animal(sp, w, hab) {}

    void print() const override
    {
        Animal::print();
        cout << "Venomous: " << (venomous ? "Yes" : "No") << endl;
    }

    void move() const override
    {
        cout << "I am a Reptile! I crawl at speed: " << speed << " km/h" << endl;
    }

    void say() const override
    {
        cout << "Hissss!" << endl;
    }
};


class Fish : public Animal
{
protected:
    double finLength;

public:
    Fish() : finLength(0), Animal() {}
    Fish(string sp, double w, string hab, double fin) : finLength(fin), Animal(sp, w, hab) {}

    void print() const override
    {
        Animal::print();
        cout << "Fin length: " << finLength << " meters" << endl;
    }

    void move() const override 
    {
        cout << "I am a Fish! I swim at speed: " << speed << " km/h" << endl;
    }

    void say() const override 
    {
        cout << "Blub blub!" << endl;
    }
};



class Eagle : public Bird
{
public:
    Eagle() : Bird("Eagle", 6.5, "Mountains", 2.3) {}

    void move() const override 
    {
        cout << "Eagle is soaring in the sky at speed: " << speed << " km/h" << endl;
    }

    void say() const override 
    {
        cout << "Screeeemmmmm!" << endl;
        Beep(314, 1400);
        Beep(350, 1400);
        Beep(390, 1400);
		Beep(467, 1400);
        Beep(526, 1400);
        Beep(624, 1400);
        Beep(314, 1400);
    }
};

class Snake : public Reptile
{
public:
    Snake() : Reptile("Snake", 2.5, "Desert", true) {}

    void move() const override
    {
        cout << "Snake is slithering at speed: " << speed << " km/h" << endl;
    }

    void say() const override
    {
        cout << "Ssssssssssssss!" << endl;
        Sleep(200);
        Beep(523, 500);
        Sleep(50);
        Beep(659, 400);
        Sleep(50);
        Beep(440, 400);
        Sleep(50);
        Beep(494, 400);
        Sleep(50);
        Beep(523, 750);
        Sleep(400);
        Beep(600, 400);
        Sleep(100);
        Beep(600, 350);
        Sleep(200);
        Beep(600, 300);
        Sleep(150);
        Beep(600, 250);
        Sleep(150);
        Beep(600, 150);
        Sleep(150);
        Beep(550, 250);
        Sleep(150);
        Beep(555, 350);
        Sleep(50);
        Beep(555, 200);
        Sleep(150);
        Beep(555, 200);
        Sleep(150);
        Beep(690, 200);
        Sleep(150);
        Beep(690, 200);
        Sleep(150);
        Beep(610, 200);
        Sleep(150);
        Beep(535, 160);
        Sleep(100);
        Beep(500, 150);
        Beep(500, 50);
        Sleep(200);
        Beep(700, 200);
    }
};

class Salmon : public Fish
{
public:
    Salmon() : Fish("Salmon", 4.0, "River", 0.5) {}

    void move() const override
    {
        cout << "Salmon is swimming in the river at speed: " << speed << " km/h" << endl;
    }

    void say() const override
    {
        cout << "Glubglubglubglub!" << endl;
        Beep(600, 400);
        Beep(600, 800);
        Beep(600, 800);
        Beep(600, 800);
    }
};


int main()
{
    Eagle eagle;
    eagle.setSpeed(100);
    eagle.print();
    eagle.move();
    eagle.say();
    cout << endl;


    Snake snake;
    snake.setSpeed(5);
    snake.print();
    snake.move();
    snake.say();
    cout << endl;

    Salmon salmon;
    salmon.setSpeed(10);
    salmon.print();
    salmon.move();
    salmon.say();
    cout << endl;
    



};
