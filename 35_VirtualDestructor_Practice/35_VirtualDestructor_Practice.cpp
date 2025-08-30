#include <iostream>
using namespace std;


class Pizza
{
public:
    virtual void CreatePizza() const = 0;
    virtual ~Pizza() {}
};

class MilanPizza : public Pizza
{
public:
    void CreatePizza() const override
    {
        cout << "Cooking Milanese pizza..." << endl;
    }
};

class GreekPizza : public Pizza
{
public:
    void CreatePizza() const override
    {
        cout << "Cooking Greek pizza..." << endl;
    }
};


class Souse
{
public:
    virtual void CreateSouse() const = 0;
    virtual ~Souse() {}
};

class MilanSouse : public Souse
{
public:
    void CreateSouse() const override
    {
        cout << "Cooking Milan sauce..." << endl;
    }
};

class GreekSouse : public Souse
{
public:
    void CreateSouse() const override
    {
        cout << "Cooking Greek sauce..." << endl;
    }
};


class Factory
{
public:
    virtual Pizza* CreatePizza() = 0;
    virtual Souse* CreateSouse() = 0;
    virtual ~Factory() {}
};

class MilanFactory : public Factory
{
public:
    Pizza* CreatePizza() override
    {
        return new MilanPizza();
    }

    Souse* CreateSouse() override
    {
        return new MilanSouse();
    }
};

class GreekFactory : public Factory
{
public:
    Pizza* CreatePizza() override
    {
        return new GreekPizza();
    }

    Souse* CreateSouse() override
    {
        return new GreekSouse();
    }
};


void Menu()
{
    cout << "-----------------------MENU-----------------------" << endl;
    cout << "Prepare Milanese pizza and sauce               [1]" << endl;
    cout << "Prepare Greek pizza and sauce                  [2]" << endl;
    cout << "Exit                                           [0]" << endl;
    cout << "Your choice: ";
}

int main()
{
    int choice;

    do {
        Menu();
        cin >> choice;

        Factory* factory = nullptr;

        switch (choice) 
        {
        case 1:
            factory = new MilanFactory();
            break;
        case 2:
            factory = new GreekFactory();
            break;
        case 0:
            cout << "Goodbye!!!" << endl;
            return 0;
        default:
            cout << "Invalid choice!! Try again!!" << endl;
            continue;
        }

        
        Pizza* pizza = factory->CreatePizza();
        Souse* souse = factory->CreateSouse();

        cout << "--------------------Your Order--------------------" << endl;
        pizza->CreatePizza();
        souse->CreateSouse();

        delete pizza;
        delete souse;
        delete factory;

    } while (true);

    
}
