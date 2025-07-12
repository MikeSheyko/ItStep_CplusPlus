#include <iostream>
using namespace std;

class MyClass 
{
	// Default constructor
	// copy constructor
    // Destructor
    // =
public:
    //MyClass(){}
	MyClass() = default; // Default constructor
    
   /* MyClass(const MyClass & other)
    {

    }*/
    //MyClass(const MyClass& other) {}
	MyClass(const MyClass& other) = delete; // Copy constructor deleted

	~MyClass() = default; // Default destructor
    
        
};

class Stack
{
	enum { EMTPY = -1, FULL = 9};

	int arr[FULL + 1]; // Stack size 10

	int topIndex;

public:
	//delete default


	Stack() 
	{
		topIndex = EMTPY; // Initialize stack as empty
	}

	~Stack() = default; // Default destructor



    bool IsFull()const
    {
        return topIndex == FULL;
    }

    bool Push(int value)
    {
        if (!IsFull())
        {
            ++topIndex;
            arr[topIndex] = value;
            //vs
            //arr[++topIndex] = value;
            return true;
        }
        return false;
    }


    bool IsEmpty()const
    {
        return topIndex == EMTPY;
    }

    int Pop()
    {
        if (!IsEmpty())
        {
            //int value = arr[topIndex];
            // topIndex--;
            //return value;
            return arr[topIndex--];//
        }
        return 0;
    }

    void Clear()
    {
        topIndex = EMTPY;
    }
   
    int Peek() const
    {
       if (!IsEmpty())
       {
            cout << "Top element: " << arr[topIndex] << endl;
       }
        else
        {
            cout << "Stack is empty!" << endl;
        }
       return 0;
	}
 
    int GetSize()const
    {
        return topIndex + 1;
    }


    void Print()const
    {
        for (int i = 0; i < GetSize(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


};









int main()
{
    /*const int size = 100;
	int arr[size] = {};

	int* arr = new int[10000];

	delete[] arr;*/



    Stack st;

	st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(40);
    st.Push(50);

	cout << "Stack size: " << st.GetSize() << endl;

	st.Print();

	cout << "Last element: " << st.Peek() << endl;

    while (!st.IsEmpty())
    {
        cout << "Delete element: " << st.Pop() << endl;
	}

	cout << "Stack size after pop: " << st.GetSize() << endl;










}

