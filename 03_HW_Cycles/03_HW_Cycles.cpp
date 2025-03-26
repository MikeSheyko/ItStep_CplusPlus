#include <iostream>
using namespace std;



int main()
{
    cout << "Task 1" << endl;
    int number;
    int summa = 0;
    cout << "Enter some number: ";
    cin >> number;
    if (number > 500) {
        cout << "Number must not be more than 500!" << endl;
    }
    else {
        for (int i = number; i <= 500; i++) {
            summa += i;}
    }
    cout << "Sum of numbers from number " << number << " to 500: " << summa << endl;
    cout << "" << endl;

    cout << "Task 2" << endl;
    int x, y;
    long long result = 1;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    for (int i = 1; i <= y; i++) {
        result *= x;}
    cout << "Result: " << result << endl;
    cout << "" << endl;

    cout << "Task 3" << endl;
    double sum = 0;
    int count = 0;
    for (int i = 1; i <= 1000; i++) {
        sum += i;
        count++;
    }
    double res = sum / count;
    cout << "Average of numbers from 1 to 1000: " << res << endl;
    cout << "" << endl;


    cout << "Task 4" << endl;
    int number;
    int number_2 = 20;
    long long result = 1;
    cout << "Enter some number: ";
    cin >> number;
    if (number < 0 || number > number_2) {
        cout << "The entered number is greater than 20 and smaller than 0." << endl;
    }
    else {
        for (int i = number; i <= number_2; i++) {
            result *= i;
        }
        cout << "Result: " << result << endl;
    }
    cout << "" << endl;

    cout << "Task 5" << endl;
    int k;  
    cout << "Enter the value of k (variant number): ";
    cin >> k;
    for (int i = 2; i <= 10; i++) {
        cout << k << " x " << i << " = " << k * i << endl;
    }
    cout << "" << endl;

    cout << "Task 6" << endl;
    int count = 0;
    for (int num = 100; num <= 999; num++) {
        int a = num / 100;
        int b = (num / 10) % 10;
        int c = num % 10;
        if (a == b || a == c || b == c) {
            count++;
        }
    }
    cout << "Number of integers from 100 to 999 with two equal digits: " << count << endl;
    cout << "" << endl; 


    cout << "Task 7" << endl;
    int count = 0;
    for (int num = 100; num <= 999; num++) {
        int a = num / 100;
        int b = (num / 10) % 10;
        int c = num % 10;
        if (a != b && a != c && b != c) {
            count++;
        }
    }
    cout << "Number of integers from 100 to 999 with all different digits: " << count << endl;
    cout << "" << endl;

    cout << "Task 8" << endl;
    cout << "Don't find the decision" << endl;

    cout << "Task 9" << endl;
    int A;
    cout << "Enter A: ";
    cin >> A;
    for (int B = 1; B * B <= A; B++) {
        if (A % (B * B) == 0 && A % (B * B * B) != 0) {
            cout << "B = " << B << endl;
        }
    }
    cout << "" << endl;

    cout << "Task 10" << endl;
    cout << "Don't find the decision" << endl;

    cout << "Task 11" << endl;
	int NUMBER;
	cout << "Enter number: ";
	cin >> NUMBER;
	for (int i = 1; i <= NUMBER; i++) {
		if (NUMBER % i == 0) {
			cout << i << " ";
		}
	}
    cout << "" << endl;
    
    cout << "Task 12" << endl;
    int NUMBER_1, NUMBER_2;
    cout << "Enter number 1: ";
	cin >> NUMBER_1;
	cout << "Enter number 2: ";
	cin >> NUMBER_2;
	for (int i = 1; i < NUMBER_1; i++)
    {
        if (NUMBER_1 % i == 0 && NUMBER_2 % i == 0) {
            cout << i << " ";
        }
    }



}