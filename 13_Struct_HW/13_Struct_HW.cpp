#include <iostream>
#include <windows.h>
#include <string>
#include <cstring>
using namespace std;

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//Task 1
struct WashingMachine 
{
    string brand;
    string color;
    double width;
    double length;
    double height;
    int power;
    int spinSpeed;
    int heatingTemp;
};
void printWashingMachine(WashingMachine &wm)
{
    cout << "\tWashing Machine\t" << endl;
	cout << "Brand : \t\t" << wm.brand << endl;
	cout << "Color : \t\t" << wm.color << endl;
	cout << "Width : \t\t" << wm.width << " cm" << endl;
	cout << "Length : \t\t" << wm.length << " cm" << endl;
	cout << "Height : \t\t" << wm.height << " cm" << endl;
	cout << "Power : \t\t" << wm.power << " W" << endl;
	cout << "Spin Speed : \t\t" << wm.spinSpeed << " rpm" << endl;
	cout << "Heating Temperature : \t" << wm.heatingTemp << " °C" << endl;
    cout << "---------------------------------" << endl;
}


//Task 2
struct Iron 
{
    string brand;
    string model;
    string color;
    int MinTemp;
    int MaxTemp;
    bool steam;
    int power;
};
void printIron(Iron &i) 
{
    cout << "\tIron\t" << endl;
    cout << "Brand : \t\t" << i.brand << endl;
	cout << "Model : \t\t" << i.model << endl;
	cout << "Color : \t\t" << i.color << endl;
	cout << "Min Temperature : \t" << i.MinTemp << " °C" << endl;
	cout << "Max Temperature : \t" << i.MaxTemp << " °C" << endl;
	cout << "Steam Function : \t" << (i.steam ? "Yes" : "No") << endl;
	cout << "Power : \t\t" << i.power << " W" << endl;
    cout << "---------------------------------" << endl;
}
//Task 3
struct Boiler 
{
    string brand;
    string color;
    int power;
    double volume;
    int heatingTemp;
};
void printBoiler(Boiler &b) 
{
    cout << "\tBoiler\t" << endl;
    cout << "Brand : \t\t" << b.brand << endl;
	cout << "Color : \t\t" << b.color << endl;
	cout << "Power : \t\t" << b.power << " W" << endl;
	cout << "Volume : \t\t" << b.volume << " L" << endl;
	cout << "Heating Temperature : \t" << b.heatingTemp << " °C" << endl;
	cout << "---------------------------------" << endl;  
}

//Task 4
union CarNumber 
{
    int number;
    char word[9];
};
struct Car 
{
    string color;
    string model;
    bool isNumber;
    CarNumber number;
};
void fillCar(Car& car, const string& color, const string& model, bool isNumber, const string& numberInput)
{
    car.color = color;
    car.model = model;
    car.isNumber = isNumber;
    if (isNumber) 
    {
        car.number.number = stoi(numberInput);
    }
    else 
    {
        strncpy_s(car.number.word, sizeof(car.number.word), numberInput.c_str(), _TRUNCATE);
    }
}

void printCar(Car &car, int carIndex)
{
    cout << "\t----//CAR " << carIndex + 1 << "//----\t" << endl;
	cout << "Color: \t" << car.color << endl;
	cout << "Model: \t" << car.model << endl;
	cout << "Number: ";
    if (car.isNumber) 
    {
        cout << car.number.number << endl;
    }
    else 
    {
        cout << car.number.word << endl;
    }
    cout << endl;
}

void editCar(Car& car, const string &newColor,const string &newModel, bool isNumber, const string &newNumber)
{
    fillCar(car, newColor, newModel, isNumber, newNumber);
}

void printCars(Car cars[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printCar(cars[i], i);
    }
}

bool findCarByNumber(Car cars[], int size, const string& searchNumber) 
{
    for (int i = 0; i < size; ++i) 
    {
        string currentNumber = cars[i].isNumber ? to_string(cars[i].number.number) : string(cars[i].number.word);
        if (currentNumber == searchNumber) 
        {
            cout << "Car found : " << endl;
            printCar(cars[i], i);
            return true;
        }
    }
	cout << "Car with number " << searchNumber << " not found." << endl;
	return false;
}


int main()
{
    //Task 1
    setColor(4);
    WashingMachine Samsung = {"Samsung", "Black", 60.0, 55.0, 85.0, 2000, 1200, 90};
    printWashingMachine(Samsung);
    setColor(7);

    //Task 2
    setColor(6);
    Iron iron = {"Philips", "DST8050/20", "Black", 100, 220, true, 2800 };
    printIron(iron);
    setColor(7);

    //Task 3
	setColor(11);
	Boiler boiler = {"Bosch", "White", 1500, 50.0, 75};
	printBoiler(boiler);
	setColor(7);
	
	//Task 4
    Car cars[10];
   
    fillCar(cars[0], "Red", "Toyota", true, "12345");
	fillCar(cars[1], "Blue", "Honda", false, "55458");
    fillCar(cars[2], "Green", "Ford", true, "67890");
	fillCar(cars[3], "Black", "BMW", false, "AB123CD");
	fillCar(cars[4], "White", "Audi", true, "54321");
	fillCar(cars[5], "Yellow", "Mercedes", false, "CD123ÀÂ");
	fillCar(cars[6], "Gray", "Nissan", true, "11223");
	fillCar(cars[7], "Pink", "Volkswagen", false, "ÕÌ475KA");
	fillCar(cars[8], "Orange", "Kia", true, "33445");
	fillCar(cars[9], "Purple", "Hyundai", false, "KS7855LS");

    setColor(12);
    printCars(cars, 10);
    setColor(7);

    setColor(13);
    findCarByNumber(cars, 10, "12345");
    setColor(14);
    findCarByNumber(cars, 10, "AB123CD");
    setColor(15);
    findCarByNumber(cars, 10, "99999");
    setColor(7);
	cout << endl;

    setColor(2);
    editCar(cars[1], "Black", "Nissan", true, "55458");
	cout << "After editing car 2:" << endl;
	printCar(cars[1], 1);
    setColor(7);




}

