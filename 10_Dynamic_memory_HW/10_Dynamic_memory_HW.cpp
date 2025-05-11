#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;


void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


int* CreateArr(int size)
{
    int* arr = new int[size];
    return arr;
}

void FillArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = rand() % 100 - 40;
    }
}
void ShowArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}


int main()
{
    //Task 1
	setColor(1);
    int* a = new int(5);
    float* b = new float(2.5);
    double* c = new double(3.0);
        
    double product = (*a) * (*b) * (*c);
        
    cout << "a = " << *a << endl;
    cout << "b = " << *b << endl;
    cout << "c = " << *c << endl;
    cout << "Product = " << product << endl;
    cout << endl;
    setColor(7);

	//Task 2
    setColor(14);
    srand(time(0));
    int size;
    cout << "Enter size : "; cin >> size;
    int* arr = CreateArr(size);
    FillArr(arr, size);
    ShowArr(arr, size);
    setColor(7);
    






    delete a;
    delete b;
    delete c;
    delete[]arr;

}

