#include <iostream>
#include <conio.h>
#include <windows.h>
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
		*(arr + i) = rand() % 100;
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
//int* AddNumber(int* arr, int* size, int number)
//{
//	(*size)++;
//	int* temp = new int[*size];
//	for (int i = 0; i < (*size) - 1; i++)
//	{
//		temp[i] = arr[i];
//	}
//	temp[(*size) - 1] = number;
//	delete[]arr;
//	arr = temp;
//	return arr;
//}
int* AddByPosition(int* arr, int* size, int number, int pos)
{
	pos = (pos > *size) ? *size : (pos < 0 ? 0 : pos);
	(*size)++;
	int* temp = new int[*size];
	for (int i = 0; i < pos; i++)
	{
		temp[i] = arr[i];
	}
	temp[pos] = number;
	for (int i = pos; i < *size; i++)
	{
		temp[i + 1] = arr[i];
	}	
	delete[]arr;
	arr = temp;
	return arr;
}

int* DeleteLastElement(int* arr, int* size)
{
	(*size)--;
	int* temp = new int[*size];

	for (int i = 0; i < *size; i++)
	{
		temp[i] = arr[i];
	}

	delete[] arr;
	return temp;
}

int* DeleteByPosition(int* arr, int* size, int pos)
{
	pos = (pos > *size) ? *size : (pos < 0 ? 0 : pos);
	(*size)--;
	int* temp = new int[*size];

	for (int i = 0; i < pos; i++)
	{
		temp[i] = arr[i];
	}
	for (int i = pos; i < *size; i++)
	{
		temp[i] = arr[i + 1];
	}
	delete[] arr;
	return temp;
}


int main()
{
	setColor(10);
	srand(time(0));
	int size = 5;
	/*cout << "Enter size : ";
	cin >> size;*/
	int* arr = CreateArr(size);
	FillArr(arr, size);
	ShowArr(arr, size);
	setColor(7);

	int number;
	char choice;
	while (true)
	{
		setColor(8);
		cout << "\nChoose an action:\n";
		cout << "a - Add number in array by position\n";
		cout << "d - Delete last element in array\n";
		cout << "r - Delete element in array by position\n";
		cout << "e - Exit\n";
		choice = _getch();
		cout << endl;
		setColor(7);

		if (choice == 'n') break;

		if (choice == 'a')
		{
			setColor(4);
			int number, pos;
			cout << "Enter number: "; cin >> number;
			cout << "Enter position: "; cin >> pos;
			arr = AddByPosition(arr, &size, number, pos);
			ShowArr(arr, size);
			setColor(7);
		}
		else if (choice == 'd')
		{
			setColor(8);
			arr = DeleteLastElement(arr, &size);
			cout << "New array: ";
			ShowArr(arr, size);
			setColor(7);
		}
		else if (choice == 'r')
		{
			setColor(3);
			int pos;
			cout << "Enter position to delete: ";
			cin >> pos;
			arr = DeleteByPosition(arr, &size, pos);
			ShowArr(arr, size);
			setColor(7);
		}
		else if (choice == 'e')break;
		
		else
		{
			setColor(14);
			cout << "Error! Invalid choice! Try again!";
			setColor(7);
		}

	}

	delete[]arr;
}
