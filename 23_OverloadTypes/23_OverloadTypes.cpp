#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

class Airplane
{
private:
    string _model;
    string _type;
    int _passengers;
    int _maxPassengers;
public:
    Airplane(const string& m = "", const string& t = "", int p = 0, int maxP = 0)
        : _model(m), _type(t), _passengers(p), _maxPassengers(maxP) {}

    /*Airplane(const string& m, const string& t, int p, int maxP): _model(m), _type(t), _passengers(p), _maxPassengers(maxP) {}*/

    Airplane& operator ++ ()
    {
        if (_passengers < _maxPassengers) 
        {
            ++_passengers;
        }
        else 
        {
            cerr << "Error! Maximum passengers in airplane!" << endl;
        }
        return *this;
    }

    Airplane& operator -- ()
    {
        if (_passengers > 0) 
        {
            --_passengers;
        }
        else 
        {
            cerr <<"Error! No passengers in airplane!" << endl;
        }
        return *this;
    }
      
    void operator() (int number)
    {
        if (number <= 0)
        {
            cerr << "Error! Can't add negative number or zero!" << endl;
        }

        if (_passengers + number <= _maxPassengers)
        {
            _passengers += number;
        }
        else 
        {
            cerr << "Error! Can't add " << number << " passengers! Limit is out!" << endl;
        }
    }

    void display() const
    {
        cout << "Model:\t\t" << _model << endl;
		cout << "Type:\t\t" << _type << endl;
		cout << "Passengers:\t" << _passengers << endl;
		cout << "Max Passengers:\t" << _maxPassengers << endl;
    }

    operator string() const 
    {
        return _model;
    }

    friend bool operator == (const Airplane& a1, const Airplane& a2);
    friend bool operator > (const Airplane& a1, const Airplane& a2);
    friend ostream& operator << (ostream& out, const Airplane& plane);
    friend istream& operator >> (istream& in, Airplane& plane);
    
};

bool operator == (const Airplane& a1, const Airplane& a2)
{
    return a1._type == a2._type;
}

bool operator > (const Airplane& a1, const Airplane& a2)
{
    return a1._maxPassengers > a2._maxPassengers;
}

ostream& operator << (ostream& out, const Airplane& plane)
{
    out << "Model:\t\t" << plane._model << endl;
    out << "Type:\t\t" << plane._type << endl;
    out << "Passengers:\t" << plane._passengers << endl;
    out << "Max Passengers:\t" << plane._maxPassengers << endl;
    return out;
}

istream& operator >> (istream& in, Airplane& plane) 
{
    cout << "Enter model: ";
    in >> ws;
    getline(in, plane._model);

    cout << "Enter type: ";
    getline(in, plane._type);

    cout << "Enter current number of passengers : ";
    in >> plane._passengers;

    cout << "Enter maximum number of passengers: ";
    in >> plane._maxPassengers;

    if (plane._passengers > plane._maxPassengers) 
    {
        cerr << "Error! Current passengers exceed max! Adjusting to max!!" << endl;
        plane._passengers = plane._maxPassengers;
    }

    return in;
}


int main() 
{
    Airplane a1("Boeing", "Commercial", 125, 150);
    Airplane a2("F-16", "Military", 1, 2);
    Airplane a3("Mriya", "Cargo", 80, 160);
    Airplane a4("Airbus", "Commercial", 200, 260);
	
    setColor(11);
    cout << "\t----------Airplanes details (Ver 1)----------\t" << endl;
    a1.display();
	cout << endl;
    a2.display();
	cout << endl;
    a3.display();
	cout << endl;
	a4.display();
	cout << endl;
    setColor(7);

    setColor(4);
    cout << "\t----------Airplanes details (Ver 2)----------\t" << endl;
	cout << a1 << endl;
	cout << a2 << endl;
	cout << a3 << endl;
	cout << a4 << endl;
    setColor(7);

    setColor(6);
    cout << "\t----------Compare type----------\t" << endl;
    cout << (a1 == a2 ? "Yes" : "No") << endl;
	cout << (a1 == a3 ? "Yes" : "No") << endl;
	cout << (a2 == a3 ? "Yes" : "No") << endl;
    cout << (a1 == a4 ? "Yes" : "No") << endl;
    setColor(7);

    setColor(2);
    cout << "\t----------Increment----------\t" << endl; 
    ++a1;
    a1.display();
    setColor(7);

    setColor(2);
    cout << "\t----------Decrement----------\t" << endl;
    --a1;
    a1.display();
    setColor(7);

    setColor(5);
    cout << "\t----------Compare max passengers----------\t" << endl;
    cout << (a1 > a3 ? "Yes" : "No") << endl;
	cout << (a2 > a3 ? "Yes" : "No") << endl;
    setColor(7);

    setColor(9);
    cout << "\t----------Adding (number) passengers----------\t" << endl;

    a1(20);
    a1.display();
    setColor(7);

	a1(30);

    setColor(3);
    cout << "\t----------Input airplane from keyboard----------\t" << endl;
    Airplane a5;
    cin >> a5;
    cout << endl << "You've entered:" << endl << a5;

    setColor(7);

    setColor(14);
    cout << "Airplane model as string: " << string(a5) << endl;
    setColor(7);

    
}
