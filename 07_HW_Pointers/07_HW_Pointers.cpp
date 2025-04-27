#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//Task 4
void FillArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = rand() % 40-20;
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

void SwapIndex(int* arr, int size)
{
    for (int i = 0; i < size - 1; i += 2)
    {
        int temp = *(arr + i);
        *(arr + i) = *(arr + i + 1);
        *(arr + i + 1) = temp;
    }
}


int main()
{
	srand(time(0));
    //Task 1
    cout << "Task 1" << endl;
    int a = 18;
    int b = 3;
    int c = 8;
    int* pa = &a;
    int* pb = &b;
    int* pc = &c;
    int product = (*pa) * (*pb) * (*pc);
    float average = (*pa + *pb + *pc) / 3.0;
    int min = *pa;
    if (*pb < min) min = *pb;
    if (*pc < min) min = *pc;

    cout << "Product = " << product << endl;
    cout << "Average = " << average << endl;
    cout << "Min number = " << min << endl;
    cout << endl;

    //Task 2
    cout << "Task 2" << endl;
    const int size = 5;
    int arr[size];
    cout << "Enter " << size << " numbers: " << endl;
    for (int* ptr = arr; ptr < arr + size; ptr++)
    {
        cin >> *ptr;
    }
    cout << endl;
    cout << "Array : ";
    for (int* ptr = arr; ptr < arr + size; ptr++)
    {
        cout << *ptr << " ";
    }
    cout << endl;
    cout << "New array : ";
    for (int* ptr = arr + size - 1; ptr >= arr; ptr--)
    {
        cout << *ptr << " ";
    }
    cout << endl;
    int sum = 0;
    for (int* ptr = arr; ptr < arr + size; ptr++)
    {
        sum += *ptr;
    }
    cout << "Summa = " << sum << endl;
    cout << endl;

    //Task 3
    cout << "Task 3" << endl;
    const int SIZE = 10;
    int Arr[SIZE] = { 7, 2, 15, 9, 3, 11, 24, 5, 6, 19 };

    cout << "Array: ";
    for (int* ptr = Arr; ptr < Arr + SIZE; ptr++)
    {
        cout << *ptr << " ";
    }
    cout << endl;

    int* minPtr = Arr;
    int* maxPtr = Arr;
    for (int* ptr = Arr; ptr < Arr + SIZE; ptr++)
    {
        if (*ptr < *minPtr)
        {
            minPtr = ptr;
        }
        if (*ptr > *maxPtr)
        {
            maxPtr = ptr;
        }
    }

    int temp = *minPtr;
    *minPtr = *maxPtr;
    *maxPtr = temp;
    cout << "New array: ";
    for (int* ptr = Arr; ptr < Arr + SIZE; ptr++)
    {
        cout << *ptr << " ";
    }
    cout << endl;
    cout << endl;

	//Task 4
	cout << "Task 4" << endl;
    const int Size = 10;
    int ARR[Size];

    FillArr(ARR, Size);
    cout << "Array : " << setw (6);
    ShowArr(ARR, Size);
    
    SwapIndex(ARR, Size);

    cout << "New array : ";
    ShowArr(ARR, Size);


}

