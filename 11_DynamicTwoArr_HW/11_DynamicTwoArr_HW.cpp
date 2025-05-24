#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <iomanip>
using namespace std;

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void FillArr(int** arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 100 - 10;
		}
	}
}

void ShowArr(int** arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(4) << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl; cout << endl;
}

void Fill(int* arr, int col)
{
	for (int i = 0; i < col; i++)
	{
		arr[i] = rand() % 10;
	}
}

int** AddRow(int** arr, int& row, int col)
{
	int** temp = new int* [row + 1];
	for (int i = 0; i < row; i++)
	{
		temp[i] = arr[i];
	}
	temp[row] = new int[col];
	Fill(temp[row], col);
	delete[]arr;
	row++;
	arr = temp;
	return arr;
}

int** AddRowInPos(int** arr, int& row, int col, int pos)
{
	int** temp = new int* [row + 1];
	for (int i = 0; i < pos; i++)
	{
		temp[i] = arr[i];
	}
	temp[pos] = new int[col];
	Fill(temp[pos], col);
	for (int i = pos; i < row + 1; i++)
	{
		temp[i + 1] = arr[i];
	}
	delete[]arr;
	row++;
	arr = temp;
	return arr;

}

int** AddColInTheEnd(int** arr, int row, int& col)
{
	int** temp = new int* [row];
	for (int i = 0; i < row; i++)
	{
		temp[i] = new int[col + 1];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < row; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
	arr = temp;
	for (int i = 0; i < row; i++)
	{
		arr[i][col] = 7;
	}
	col++;
	return arr;
}

void DeleteRow(int**& arr, int& row)
{
	int** temp = new int* [row - 1];
	for (int i = 0; i < row - 1; i++)
	{
		temp[i] = arr[i];
	}
	delete[]arr[row - 1];
	delete[]arr;
	arr = temp;
	row--;
	//return arr;
}

//Task 1
int** AddRowStart(int** arr, int& row, int col) 
{
	int** temp = new int* [row + 1];

	temp[0] = new int[col];
	Fill(temp[0], col); 

	for (int i = 0; i < row; i++) 
	{
		temp[i + 1] = arr[i];
	}

	delete[] arr;
	arr = temp;
	row++;

	return arr;
}

//Task 2
int** DeleteRowStart(int** arr, int& row) 
{
	int** temp = new int* [row - 1];

	for (int i = 1; i < row; i++) 
	{
		temp[i - 1] = arr[i];
	}

	delete[] arr;
	arr = temp;
	row--;

	return arr;
}

//Task 3
int** DeleteRowPos(int** arr, int& row, int pos) 
{
	if (pos < 0 || pos >= row) return arr;
	delete[] arr[pos];

	int** temp = new int* [row - 1];

	for (int i = 0, k = 0; i < row; i++) 
	{
		if (i == pos) continue;
		temp[k++] = arr[i];
	}

	delete[] arr;
	arr = temp;
	row--;

	return arr;
}

//Task 4
int** AddColPos(int** arr, int row, int& col, int pos) 
{
	int** temp = new int* [row];
	for (int i = 0; i < row; i++) 
	{
		temp[i] = new int[col + 1];
	}

	for (int i = 0; i < row; i++) 
	{
		for (int j = 0, k = 0; j < col + 1; j++) 
		{
			if (j == pos) 
			{
				temp[i][j] = rand() % 100 - 10; 
			}
			else 
			{
				temp[i][j] = arr[i][k++];
			}
		}
	}

	for (int i = 0; i < row; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	arr = temp;
	col++;

	return arr;
}

//Task 5
int** AddColStart(int** arr, int row, int& col) 
{
	return AddColPos(arr, row, col, 0);
}




int main()
{
	int row = 5;
	int col = 6;

	/*int** arr = new int* [row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}
	FillArr(arr, row, col);
	ShowArr(arr, row, col);
	arr = AddRow(arr, row, col);
	ShowArr(arr, row, col);

	arr = AddRowInPos(arr, row, col, 2);
	ShowArr(arr, row, col);

	arr = AddColInTheEnd(arr, row, col);
	ShowArr(arr, row, col);

	DeleteRow(arr, row);
	ShowArr(arr, row, col);*/
	
	srand(time(0));
	
	int** arr = new int* [row];
	for (int i = 0; i < row; i++)
		arr[i] = new int[col];

	FillArr(arr, row, col);
	ShowArr(arr, row, col);

	char choice;
	while (true) 
	{
		setColor(6);
		cout << "\tChoose an action:\t" << endl;
		cout << "1 - Add row at start" << endl;
		cout << "2 - Delete row at start" << endl;
		cout << "3 - Delete row by position" << endl;
		cout << "4 - Add column by position" << endl;
		cout << "5 - Add column at start" << endl;
		cout << "e - Exit\n";
		cout << "Enter your choice: ";
		choice = _getch();
		cout << endl;

		if (choice == '1') 
		{
			setColor(4);
			arr = AddRowStart(arr, row, col);
			ShowArr(arr, row, col);
			setColor(7);
		}
		else if (choice == '2') 
		{
			setColor(8);
			arr = DeleteRowStart(arr, row);
			ShowArr(arr, row, col);
			setColor(7);
		}
		else if (choice == '3') 
		{
			setColor(9);
			int pos;
			cout << "Enter row position to delete: "; cin >> pos;
			arr = DeleteRowPos(arr, row, pos);
			ShowArr(arr, row, col);
			setColor(7);
		}
		else if (choice == '4') 
		{
			setColor(10);
			int pos;
			cout << "Enter column position to insert: "; cin >> pos;
			arr = AddColPos(arr, row, col, pos);
			ShowArr(arr, row, col);
			setColor(7);
		}
		else if (choice == '5') 
		{
			setColor(11);
			arr = AddColStart(arr, row, col);
			ShowArr(arr, row, col);
			setColor(7);
		}
		else if (choice == 'e') 
		{
			break;
		}
		else 
		{
			cout << "Invalid choice!!! Try again!!!" << endl;
		}
	}









    for (int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

