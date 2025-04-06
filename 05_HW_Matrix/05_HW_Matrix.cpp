#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
    /*Task 1*/
    int arr[10][9];  
    srand(time(0));   
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            arr[i][j] = rand() % 18 - 10;
        }
    }   
    cout << "Matrix:" << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }   
    int count = 0;
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            if (arr[i][j] != 0) {
                count++;
            }
        }
    }  
    cout << "Number of non-zero elements: " << count << endl;

    /*Task 2*/
    int countZero = 0;
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            if (arr[i][j] == 0) 
            {
                countZero++;
            }
        }
    }   
    cout << "Number of zero elements: " << countZero << endl;

    /*Task 3*/
    int count_1 = 0;
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            if (abs(arr[i][j]) < 12) 
            {
                count_1++;
            }
        }
    }
    cout << "Number of elements with absolute value less than 12: " << count_1 << endl;
    
    /*Task 4*/
    int positiveCount = 0;
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            if (arr[i][j] > 0) 
            {
                positiveCount++;
            }
        }
    }   
    cout << "Number of positive elements: " << positiveCount << endl;
    
    /*Task 5*/
    unsigned long long product = 1;
    bool isPositive = false;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] > 0)
            {
                product *= arr[i][j];
                isPositive = true;
            }
        }
    }
    if (isPositive)
    {
        cout << "Product of all positive elements: " << product << endl;
    }
    else
    {
        cout << "There are no positive elements in the array." << endl;
    }



    /*Task 6*/
    long long product_1 = 1;
    bool isNegative = false;  
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            if (arr[i][j] < 0) 
            {  
                product_1 *= arr[i][j];  
                isNegative = true;
            }
        }
    }
    if (isNegative) 
    {
        cout << "Product of all negative elements: " << product_1 << endl;
    }
    else 
    {
        cout << "There are no negative elements in the array." << endl;
    }

	/*Task 7*/
    int count_2 = 0;
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            if (arr[i][j] % 6 == 1) 
            {
                count_2++;
            }
        }
    }  
    cout << "Number of elements, that gives 12:6 = 1, is : " << count << endl;

	/*Task 8*/
    int minElement = arr[0][0];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[i][j] < minElement) 
            {
                minElement = arr[i][j];
            }
        }
    } 
    cout << "The minimum element in the array is: " << minElement << endl;

    /*Task 9*/
    int maxElement = arr[0][0];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[i][j] > maxElement)
            {
                maxElement = arr[i][j];
            }
        }
    }
    cout << "The maximum element in the array is: " << maxElement << endl;


	/*Task 10*/

    int sum = 0;
    bool is_Negative = false;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] < 0)
            {
                sum += arr[i][j];
                is_Negative = true;
            }
        }
    }
    if (is_Negative)
    {
        cout << "Summa of all negative elements: " << sum << endl;
    }
    else
    {
        cout << "There are no negative elements in the array." << endl;
    }


}


