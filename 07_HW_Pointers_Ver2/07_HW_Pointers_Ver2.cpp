#include <iostream>
#include <windows.h>
using namespace std;

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


int main()
{
	//Task 1
    /*setColor(10);
	cout << "Task 1" << endl;
    int a;
    int b;
    cout << "Enter first number : "; cin >> a;
    cout << "Enter second number : "; cin >> b;
    int* ptrA = &a;
    int* ptrB = &b;
    if (*ptrA > *ptrB)
    {
        cout << "The larger number is : " << *ptrA << endl;
    }
    else if (*ptrB > *ptrA)
    {
        cout << "The larger number is : " << *ptrB << endl;
    }
    else
    {
        cout << "Both numbers are equal" << endl;
    }
    cout << endl;
    setColor(7);*/


	//Task 2
   /* setColor(2);
    cout << "Task 2" << endl;
    int SomeNumber;
    cout << "Enter number: ";
    cin >> SomeNumber;
    int* ptr = &SomeNumber;
    if (*ptr > 0)
    {
        cout << "The number is positive." << endl;
    }
    else if (*ptr < 0)
    {
        cout << "The number is negative." << endl;
    }
    else 
    {
        cout << "The number is zero." << endl;
    }
    cout << endl;
    setColor(7);*/

	//Task 3
	setColor(3);
	cout << "Task 3" << endl;
	
    int a;
    int b;
    cout << "Enter first number : "; cin >> a;
    cout << "Enter second number : "; cin >> b;

    int* ptrA = &a;
    int* ptrB = &b;

    cout << "Before swapping:" << endl;
    cout << "A = " << *ptrA << endl;
    cout << "B = " << *ptrB << endl;
       
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;

    cout << "After swapping:" << endl;
    cout << "A = " << *ptrA << endl;
    cout << "B = " << *ptrB << endl;
    
    cout << endl;
    setColor(7);


	//Task 4
    setColor(4);

    double number_1;
    double number_2;
    char operation;
    double res = 0;
    //double res;

    double* ptrnum1 = &number_1;
    double* ptrnum2 = &number_2;
    double* ptrResult = &res;

    cout << "Enter first number: ";
    cin >> *ptrnum1;

    cout << "Enter operator (+, -, *, /): ";
    cin >> operation;

    cout << "Enter second number: ";
    cin >> *ptrnum2;

    if (operation == '+')
    {
        *ptrResult = *ptrnum1 + *ptrnum2;
    }
    else if (operation == '-')
    {
        *ptrResult = *ptrnum1 - *ptrnum2;
    }
    else if (operation == '*')
    {
        *ptrResult = *ptrnum1 * *ptrnum2;
    }
    else if (operation == '/') 
    {
        if (*ptrnum2 != 0)
        {
            *ptrResult = *ptrnum1 / *ptrnum2;
        }
        else
        {
            cout << "Error: Division by zero!" << endl;
            return 1;
        }
    }
    else
    {
        cout << "Invalid operator!" << endl;
        return 1;
    }
    cout << *ptrnum1 << " " << operation << " " << *ptrnum2 << " = " << *ptrResult << endl;

    cout << endl;
    setColor(7);

	//Task 5
    setColor(6);
    cout << "Task 5" << endl;
    const int size = 5;
    int arr[size];

    cout << "Enter " << size << " numbers:" << endl;
    for (int i = 0; i < size; ++i) 
    {
        cin >> *(arr + i);
    }

    int* ptr = arr;
    int sum = 0;

    for (int i = 0; i < size; ++i) 
    {
        sum += *(ptr + i);
    }

    cout << "Summa = " << sum << endl;
    setColor(7);
}
