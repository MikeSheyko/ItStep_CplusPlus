#include <iostream>
using namespace std;


int& MaxElement(int &a, int &b)
{
	if (a > b) return a;
	else return b;
	
}

int main()
{
    
    int a = 15;
    int* pa = &a;
	cout << "Value: " << a << endl;//value
	cout << "Address of pa: " << pa << endl;//address
	cout << *pa << endl;//value


	//int* pa; //empty pointer
	//int* pa = 0;
	//int* pa = NULL;
	/*int* pa = nullptr;
	pa = &a;*/

	//Links
	int& la = a; //reference
	int b = 5;
	int& lb = b; //reference

	cout << a + b << endl;
	cout << la + lb << endl;

	int & lmax = MaxElement(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "lmax = " << lmax << endl;
	MaxElement(a, b) = 1;//lmax = 1;
	cout << "lmax = " << lmax << endl;

	for (int i = 0; i < 256; i++)
	{
		cout <<"code = " << i << " " << (char)i << endl;

	}

}
