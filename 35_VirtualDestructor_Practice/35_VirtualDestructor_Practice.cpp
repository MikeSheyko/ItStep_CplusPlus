#include <iostream>
using namespace std;

class Pizza
{
protected:
    string* ingredients;
    int ingCount;

public:
    Pizza(initializer_list<string> list)
    {
        ingCount = list.size();
        ingredients = new string[ingCount];
        int i = 0;
        for (const string& ingr : list)
        {
            ingredients[i++] = ingr;
        }
    }

    virtual void CreatePizza() const = 0;

    virtual ~Pizza()
    {
        delete[] ingredients;
    }
};

class MilanPizza : public Pizza
{
public:
    MilanPizza() : Pizza({ "Parmesan", "Tomatoes" }) {}

    void CreatePizza() const override
    {
        cout << "Cooking Milanese pizza with : ";
        for (int i = 0; i < ingCount; ++i)
        {
            cout << ingredients[i];
            if (i < ingCount - 1)
                cout << ", ";
        }
        cout << endl;
    }
};

class GreekPizza : public Pizza
{
public:
    GreekPizza() : Pizza({ "Feta", "Tomatoes" }) {}

    void CreatePizza() const override
    {
        cout << "Cooking Greek pizza with : ";
        for (int i = 0; i < ingCount; ++i)
        {
            cout << ingredients[i];
            if (i < ingCount - 1)
                cout << ", ";
        }
        cout << endl;
    }
};

class Souse
{
protected:
    string* ingredients;
    int ingredientCount;

public:
    Souse(initializer_list<string> list)
    {
        ingredientCount = list.size();
        ingredients = new string[ingredientCount];
        int i = 0;
        for (const string& ingr : list)
        {
            ingredients[i++] = ingr;
        }
    }

    virtual void CreateSouse() const = 0;

    virtual ~Souse()
    {
        delete[] ingredients;
    }
};

class MilanSouse : public Souse
{
public:
    MilanSouse() : Souse({ "Tomatoes", "Basilic" }) {}

    void CreateSouse() const override
    {
        cout << "Cooking Milan sauce with: ";
        for (int i = 0; i < ingredientCount; ++i)
        {
            cout << ingredients[i];
            if (i < ingredientCount - 1)
                cout << ", ";
        }
        cout << endl;
    }
};

class GreekSouse : public Souse
{
public:
    GreekSouse() : Souse({ "Yogurt", "Cucumber" }) {}

    void CreateSouse() const override
    {
        cout << "Cooking Greek sauce with: ";
        for (int i = 0; i < ingredientCount; ++i)
        {
            cout << ingredients[i];
            if (i < ingredientCount - 1)
                cout << ", ";
        }
        cout << endl;
    }
};

class Factory
{
public:
    virtual Pizza* CreatePizza() = 0;
    virtual Souse* CreateSouse() = 0;
    virtual ~Factory() = default;
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

        if (choice == 0) {
            cout << "Goodbye!!!" << endl;
            break;
        }

        Factory* factory = nullptr;

        switch (choice)
        {
        case 1:
            factory = new MilanFactory();
            break;
        case 2:
            factory = new GreekFactory();
            break;
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

    return 0;
}
