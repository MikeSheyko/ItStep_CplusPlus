#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;


void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//Task 2
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
void ReplaceNegElement(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) < 0)
        {
            *(arr + i) = 0;
        }
    }
}

//Task 3
void Swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
	srand(time(0));

	//Task 1
	setColor(10);
    int a = 15;
    int b = 11;
    int c = 7;

    int& rA = a;
    int& rB = b;
    int& rC = c;

    int product = rA * rB * rC; 
    double average = (rA + rB + rC)/3.0;

    int MinElement = rA;
    if (rB < MinElement) MinElement = rB;
    if (rC < MinElement) MinElement = rC;

    cout << "Numbers: " << rA << ", " << rB << ", " << rC << endl;
    cout << "Product = " << product << endl;
    cout << "Average = " << average << endl;
    cout << "MinElement: " << MinElement << endl;
    cout << endl;
    setColor(7);

	//Task 2
    setColor(3);
    const int size = 10;
    int arr[size];
    FillArr(arr, size);
    cout << "Array: " << endl;
    ShowArr(arr, size);
    cout << "New Array: " << endl;
	ReplaceNegElement(arr, size);
    ShowArr(arr, size);
    cout << endl;
    setColor(7);

    //Task 3
    setColor(2);
    const int row = 5, col = 7;
    int Arr[row][col];
	cout << "Original matrix: " << endl;
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            Arr[i][j] = rand() % 50 - 20;
            cout << setw(5) << Arr[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++) 
    {
        Swap(&Arr[i][0], &Arr[i][1]); 
    }

    cout << endl;
    setColor(11);
    cout << "New matrix: " << endl;
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            cout << setw(5) << Arr[i][j];
        }
        cout << endl;
    }
    setColor(7);

}

