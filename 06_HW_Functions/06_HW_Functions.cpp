#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


/*Task 1*/
void drawRectangle(int width, int height);
/*Task 2*/
void drawRectangle(int Width, int Height, char fillChar);
/*Task 3*/
bool isLeapYear(int year);
/*Task 4*/
long long factorial(int n);
/*Task 5*/
void fillArrayWithRandomNumbers(int arr[], int size, int min, int max);
/*Task 6*/
double calculateAverage(int arr[], int size);
/*Task 7*/
void reverseArray(int Array[], int size);

int main()
{
    /*Task 1*/
    cout << "Task 1" << endl;
    int width, height;
    cout << "Enter width: ";
    cin >> width;
    cout << "Enter height: ";
    cin >> height;
    drawRectangle(width, height);

    /*Task 2*/
    cout << "Task 2" << endl;
    int Width, Height;
    char fillChar;
    cout << "Enter width: ";
    cin >> Width;
    cout << "Enter height: ";
    cin >> Height;
    cout << "Enter character to fill the rectangle: ";
    cin >> fillChar;
    drawRectangle(Width, Height, fillChar);

    /*Task 3*/
    cout << "Task 3" << endl;
    int year;
    cout << "Enter a year: ";
    cin >> year;
    if (isLeapYear(year))
    {
        cout << year << " is a leap year." << endl;
    }
    else
    {
        cout << year << " is NOT a leap year." << endl;
    }

    /*Task 4*/
	cout << "Task 4" << endl;
    int num;
    cout << "Enter number: "; cin >> num;
    cout << "Factorial of " << num << " is: " << factorial(num) << endl;

    /*Task 5*/
    cout << "Task 5" << endl;
	const int size = 10;
    int min, max;
    cout << "Enter the minimum value: ";
    cin >> min;
    cout << "Enter the maximum value: ";
    cin >> max;
    int arr[size];
    fillArrayWithRandomNumbers(arr, size, min, max);
    cout << "The filled array with random numbers is: ";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

	/*Task 6*/
    cout << "Task 6" << endl;
    const int SIZE = 7;
    int ARR[SIZE];
	cout << "Enter " << SIZE << " elements of the array: ";
    for (int i = 0; i < SIZE; ++i) {
        cin >> ARR[i];
    }
    double average = calculateAverage(ARR, SIZE);
    cout << "The average of the array elements is: " << average << endl;

    /*Task 7*/
    cout << "Task 7" << endl;
    const int Size = 8;
    int Array[Size];
    cout << "Enter " << Size << " elements of the array: ";
    for (int i = 0; i < Size; ++i) 
    {
        cin >> Array[i];
    }
    cout << "Original array: ";
    for (int i = 0; i < Size; ++i) 
    {
        cout << Array[i] << " ";
    }
    cout << endl;  
    reverseArray(Array, Size);
    cout << "Reversed array: ";
    for (int i = 0; i < Size; ++i) 
    {
        cout << Array[i] << " ";
    }
    cout << endl;   

}

/*Task 1*/
void drawRectangle(int width, int height)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            cout << "#";
        }
        cout << endl;
    }
}

/*Task 2*/
void drawRectangle(int Width, int Height, char fillChar)
{
    for (int i = 0; i < Height; ++i)
    {
        for (int j = 0; j < Width; ++j)
        {
            cout << fillChar;
        }
        cout << endl;
    }
}

/*Task 3*/
bool isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    return false;
}

/*Task 4*/
long long factorial(int n)
{
    long long result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

/*Task 5*/
void fillArrayWithRandomNumbers(int arr[], int size, int min, int max)
{
    srand(time(0));
    for (int i = 0; i < size; ++i)
    {
        arr[i] = min + rand() % (max - min + 1);
    }
}

/*Task 6*/
double calculateAverage(int arr[], int size)
{
    int sum = 0;  
    for (int i = 0; i < size; ++i) 
    {
        sum += arr[i];
    }
    return (double)sum / size;
} 

/*Task 7*/
void reverseArray(int Array[], int size)
{
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        int temp = Array[start];
        Array[start] = Array[end];
        Array[end] = temp;
        start++;
        end--;
    }
}

