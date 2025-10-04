#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <windows.h>
using namespace std;


void setColor(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}

void setPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hConsole, pos);
}


class Drink 
{
protected:
    string name;
    double price;
    int waterRequired;
    int coffeeRequired;
    int teaRequired;
    int sugarRequired;
    int milkRequired;

public:
    explicit Drink(string n, double p, int w, int c, int t, int s, int m = 0)
        : name(n), price(p), waterRequired(w),
        coffeeRequired(c), teaRequired(t), sugarRequired(s), milkRequired(m) {
    }

    string getName() const 
    { 
        return name; 
    }
    double getPrice() const 
    { 
        return price; 
    }

    void setPrice(double p) 
    {
        if (p < 0) throw invalid_argument("Error! Price cannot be negative!");
        price = p;
    }

    virtual bool canBeMade(int water, int coffee, int tea, int sugar, int milk) 
    {
        return water >= waterRequired && coffee >= coffeeRequired && tea >= teaRequired && sugar >= sugarRequired && milk >= milkRequired;
    }

    virtual void consumeIngredients(int& water, int& coffee, int& tea, int& sugar, int& milk) 
    {
        water -= waterRequired;
        coffee -= coffeeRequired;
        tea -= teaRequired;
        sugar -= sugarRequired;
        milk -= milkRequired;
    }
    
    friend ostream& operator <<(ostream& os, const Drink& drink);
                
};

ostream& operator <<(ostream& os, const Drink& drink) 
{
    os << drink.name << " - " << fixed << setprecision(2) << drink.price << " UAH";
    return os;
}


class Coffee : public Drink {
public:
    Coffee() : Drink("Coffee", 15.0, 100, 10, 0, 5, 0) {}
};

class Tea : public Drink {
public:
    Tea() : Drink("Tea", 40.0, 100, 0, 10, 5, 0) {}
};

class Cappuccino : public Drink {
public:
    Cappuccino() : Drink("Cappuccino", 30.0, 120, 15, 0, 5, 50) {}
};


class VendingMachine {
private:
    int water = 1000;
    int coffee = 50;
    int tea = 50;
    int sugar = 50;
    int milk = 200;
    double cash = 0.0;

    vector<Drink*> drinks;

public:
    VendingMachine() 
    {
        drinks.push_back(new Coffee());
        drinks.push_back(new Tea());
        drinks.push_back(new Cappuccino());
    }

    void userMenu() {
        int choice;
        do {
            system("cls");
            setColor(11);
            setPosition(10, 2);
            cout << "------------- User Menu -------------" << endl;
            setColor(7);

            setPosition(10, 4);
            cout << "Order a drink" << setw(30) << "[1]" << endl;
            setPosition(10, 5);
            cout << "Exit" << setw(39) << "[0]" << endl;
            setPosition(10, 7);
            cout << "Enter your choice : ";
            cin >> choice;

            if (choice == 1) {
                try {
                    orderDrink();
                }
                catch (const exception& e) 
                {
                    setColor(12);
                    cout << "Error : " << e.what() << endl;
                    setColor(7);
                    system("pause");
                }
            }

        } while (choice != 0);
    }

    void adminMenu() 
    {
        string pass;
        system("cls");
        cout << "Enter administrator password : ";
        cin >> pass;

        if (pass != "admin") 
        {
            setColor(12);
            cout << "Incorrect password!" << endl;
            setColor(7);
            system("pause");
            return;
        }

        int choice;
        do {
            system("cls");
            setColor(14);
            setPosition(10, 2);
            cout << "------------- Administrator Menu -------------" << endl;
            setColor(7);
            setPosition(10, 4);
            cout << "[1] Load ingredients" << endl;
            setPosition(10, 5);
            cout << "[2] Show ingredients status" << endl;
            setPosition(10, 6);
            cout << "[3] Change drink prices" << endl;
            setPosition(10, 7);
            cout << "[4] Withdraw cash" << endl;
            setPosition(10, 8);
            cout << "[5] Sort drinks by price" << endl;
            setPosition(10, 9);
            cout << "[0] Exit" << endl;
            setPosition(10, 10);
            cout << "Your choice : ";
            cin >> choice;

            try {
                switch (choice) {
                case 1: loadIngredients(); break;
                case 2: showStatus(); system("pause"); break;
                case 3: changePrices(); break;
                case 4: collectCash(); break;
                case 5: sortDrinksByPrice(); break;
                case 0: break;
                default: throw invalid_argument("Unknown menu option!");
                }
            }
            catch (const exception& e) 
            {
                setColor(12);
                cout << "Error: " << e.what() << endl;
                setColor(7);
                system("pause");
            }

        } while (choice != 0);


    }

    void showDrinks() 
    {
        cout << endl << "------------- Available drinks -------------" << endl;
        for (size_t i = 0; i < drinks.size(); ++i) {
            cout << i + 1 << ") " << *drinks[i] << endl;
        }
    }

    void orderDrink() 
    {
        showDrinks();
        int choice;
        cout << "Select a drink : ";
        cin >> choice;

        if (choice < 1 || choice >(int)drinks.size())
            throw out_of_range("Invalid drink selection.");

        Drink* selected = drinks[choice - 1];

        if (!selected->canBeMade(water, coffee, tea, sugar, milk))
            throw runtime_error("Not enough ingredients to prepare " + selected->getName());

        double amount;
        cout << "Insert " << fixed << setprecision(2) << selected->getPrice() << " UAH: ";
        cin >> amount;

        if (amount < selected->getPrice())
            throw runtime_error("Insufficient funds! Money returned!");

        double change = amount - selected->getPrice();
        if (change > 0)
            cout << "Your change : " << fixed << setprecision(2) << change << " UAH" << endl;

        selected->consumeIngredients(water, coffee, tea, sugar, milk);
        cash += selected->getPrice();

        cout << "Your " << selected->getName() << " is ready! Enjoy!" << endl;
        system("pause");
    }

    void loadIngredients() 
    {
        int w, c, t, s, m;
        cout << "How many ml of water to add? "; cin >> w;
        cout << "How many grams of coffee to add? "; cin >> c;
        cout << "How many grams of tea to add? "; cin >> t;
        cout << "How many grams of sugar to add? "; cin >> s;
        cout << "How many ml of milk to add? "; cin >> m;

        if (w < 0 || c < 0 || t < 0 || s < 0 || m < 0)
            throw invalid_argument("Cannot add a negative amount of ingredients!");

        water += w;
        coffee += c;
        tea += t;
        sugar += s;
        milk += m;

        cout << "Ingredients successfully added!" << endl;
        system("pause");
    }

    void showStatus() 
    {
        cout << endl << "------------- Ingredients status -------------" << endl;
        cout << "Water : " << water << " ml" << endl;
        cout << "Coffee : " << coffee << " g" << endl;
        cout << "Tea : " << tea << " g" << endl;
        cout << "Sugar : " << sugar << " g" << endl;
        cout << "Milk : " << milk << " ml" << endl;
        cout << "Cash in machine : " << fixed << setprecision(2) << cash << " UAH" << endl;
    }

    void changePrices() 
    {
        showDrinks();
        int idx;
        cout << "Select a drink to change price : ";
        cin >> idx;

        if (idx < 1 || idx >(int)drinks.size())
            throw out_of_range("Invalid drink selection for price change!");

        double newPrice;
        cout << "New price for " << drinks[idx - 1]->getName() << ": ";
        cin >> newPrice;

        drinks[idx - 1]->setPrice(newPrice);
        cout << "New price set successful!" << endl;
        system("pause");
    }

    void sortDrinksByPrice() 
    {
        for (int i = 0; i < drinks.size(); ++i) 
        {
            for (int j = 0; j < drinks.size() - 1 - i; ++j) 
            {
                if (drinks[j]->getPrice() > drinks[j + 1]->getPrice()) 
                {
                    Drink* temp = drinks[j];
                    drinks[j] = drinks[j + 1];
                    drinks[j + 1] = temp;
                }
            }
        }
        cout << "Drinks have been sorted by price (from low to high)" << endl;
        showDrinks();
        system("pause");
    }


    void collectCash() 
    {
        cout << "Withdrawn " << fixed << setprecision(2) << cash << " UAH from the machine" << endl;
        cash = 0.0;
        system("pause");
    }

       
    ~VendingMachine() {
        for (Drink* drink : drinks) 
        {
            delete drink;
        }
	}
};


int main()
{
    VendingMachine vm;
    int choice;

    do 
    {
        system("cls");
        setColor(10);
        cout << "------------- Hot Drinks Vending Machine -------------" << endl;
        setColor(7);    
        cout << "[1] - User" << endl;
        cout << "[2] - Admin" << endl;
        cout << "[0] - Exit" << endl;
        cout << "Your choice : "; cin >> choice;
        
        switch (choice) {
        case 1: vm.userMenu(); break;
        case 2: vm.adminMenu(); break;
        }
    } while (choice != 0);
	
	
	
}

