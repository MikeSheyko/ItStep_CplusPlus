#include <iostream>
using namespace std;


int main()
{
	/*Task 1*/
	const int size = 10;
	int arr[size] = {};
	int average = 1;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter element in index [" << i << "]: ";
		cin >> arr[i];
	}
	for (int i = 0; i < size; i++)
	{
		average *= arr[i];
	}
	cout << "Average in list is :" << average << endl;
	cout << endl;

	/*Task 2*/
	const int SIZE = 7;
	int pos = 0;
	int neg = 0;
	int ARR[SIZE] = { -5,11,15,-8,-4,21,17 };
	for (int i = 0; i < SIZE; i++)
	{
		if (ARR[i] < 0)
		{
			neg += 1;
		}
		else {
			pos += 1;
		}
	}
	cout << "Negative element in list : " << neg << endl;
	cout << "Positive element in list : " << pos << endl;

	/*Task 3*/
	const long list = 7;
	int Arr[list] = {};
	int summa = 0;
	for (int i = 0; i < list; i++)
	{
		cout << "Enter element in index [" << i << "]: ";
		cin >> Arr[i];
	}
	for (int i = 0; i < list; i++)
	{
		if (Arr[i] % 2 == 0)
		{
			summa += Arr[i];
		}
	}
	cout << "Summa of even elements in list is :" << summa << endl;
	cout << endl;

	/*Task 4*/
	const int Size = 10;
	int ARr[Size];
	for (int i = 0; i < Size; i++)
	{
		ARr[i] = 1 << i;
	}
	cout << "Array in direct order: ";
	for (int i = 0; i < Size; i++)
	{
		cout << ARr[i] << " ";
	}
	cout << endl;
	cout << "Array in reverse order: ";
	for (int i = Size - 1; i >= 0; i--)
	{
		cout << ARr[i] << " ";
	}
	cout << endl;

	/*Task 5*/
	const int size_1 = 8;
	int arr_1[size_1] = { -5,11,15,-8,-4,21,17,-7 };
	for (int i = 0; i < size_1; i++)
	{
		if (arr_1[i] < 0)
		{
			arr_1[i] = arr_1[i] * -1;
		}
		cout << arr_1[i] << " ";
	}










}
