
#include <iostream>
using namespace std;

void doSomething(long number) {

}
float SomeFucn()
{
	return 1.35; // double(16) ---> float(8)
}
class Array
{
	int* arr;
	int size;
public:
	explicit Array(int size = 10)
	{
		this->size = size;
		arr = new int[size];
	}
	~Array()
	{
		delete[]arr;
	}
	int getSize()const
	{
		return size;
	}
	int getValue(int index)
	{
		return arr[index];
	}
	void setValue(int value, int index)
	{
		arr[index] = value;
	}
	void display(int index)const
	{
		cout << arr[index] << " ";
	}
};

void Display(const Array& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		arr.display(i);
	}
	cout << endl;
}
int main()
{
	const int a = 7;
	int b = 7;
	//implicit - неявне 
	//double a(10);// int ----> double  10.000000000000000000
	//int a = 3.33;//double  ---> int   3

	doSomething(9);//int -----> long

	double res = 5.0 / 4;
	//explicit - явне
	int number = (int)3.33;
	int size = 5;
	Array arr(size);//parametrized c-tor
	for (int i = 0; i < arr.getSize(); i++)
	{
		arr.setValue(size - i, i);
	}
	Display(arr);
	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	//Display(15);//int ----> Array
	//Array test = 14;//int ----> Array
	//Display(test);


}
