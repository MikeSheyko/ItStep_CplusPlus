// 02_HW_LogicOperators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int main()
{
	cout << "Task 1" << endl;
	int diagonal;
	cout << "Enter diagonal: ";
	cin >> diagonal;
	const float inch_centimeters = 2.54;
	cout << "Diagonal = " << diagonal * inch_centimeters << " cen " << endl;

	cout << "" << endl;
	cout << "Task 2" << endl;
	int weight = 20;
	const int days = 30;
	float weight_kg;
	weight_kg = weight * days / 1000.0;
	cout << "Feed food for 30 days: " << weight_kg << "kg" << endl;

	cout << "" << endl;
	cout << "Task 3" << endl;
	int number_1, number_2, number_3;
	cout << "Enter number 1: ";
	cin >> number_1;
	cout << "Enter number 2: ";
	cin >> number_2;
	cout << "Enter number 3: ";
	cin >> number_3;
	cout << "Number 1: " << number_1 << "; " << "Number 2: " << number_2 << "; " << "Number 3: " << number_3 << "; " << "Summa = " << number_1 + number_2 + number_3 << endl;

	cout << "" << endl;
	cout << "Task 4" << endl;
	float number1, number2;
	cout << "Enter number 1: ";
	cin >> number1;
	cout << "Enter number 2: ";
	cin >> number2;
	cout << "Average number = " << (number1+number2)/2 << endl;

	cout << "" << endl;
	cout << "Task 5" << endl;
	float kilometers;
	cout << "Enter distance in kilometers: ";
	cin >> kilometers;
	const float meters = 1000;
	cout << "Distance = " << kilometers * meters << " meters " << endl;

	cout << "" << endl;
	cout << "Task 6" << endl;
	int Count_Of_First_Product, Count_Of_Second_Product, Count_Of_Third_Product;
	cout << "Enter count of first product: ";
	cin >> Count_Of_First_Product;
	cout << "Enter count of second product: ";
	cin >> Count_Of_Second_Product;
	cout << "Enter count of third product: ";
	cin >> Count_Of_Third_Product;
	float cost_1 = 10.54;
	float cost_2 = 154.78;
	float cost_3 = 8.74;
	cout << "Total cost: " << Count_Of_First_Product * cost_1 + Count_Of_Second_Product * cost_2 + Count_Of_Third_Product * cost_3 << endl;

	cout << "" << endl;
	cout << "Task 7" << endl;
	float some_number;
	cout << "Enter some number: ";
	cin >> some_number;
	cout << "Square of number \"" << some_number << "\"" << ": " << some_number * some_number << endl;


	cout << "" << endl;
	cout << "Task 8" << endl;
	int day;
	cout << "Enter days: ";
	cin >> day;
	const int hours = 24;
	const int minutes = 3600;
	cout << "In \"" << day << "\" days " << day * hours * minutes << " minutes" << endl;










}


