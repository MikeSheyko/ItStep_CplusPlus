#include <iostream>
using namespace std;


class CharStack 
{
private:
    static const int size = 5;
    char symbol[size];
    int topIndex;

public:
    CharStack()
    {
        topIndex = -1;
    };
      

    bool IsEmpty() const 
    {
        return topIndex == -1;
    }

    bool IsFull() const 
    {
        return topIndex == size - 1;
    }


    bool Push(char c) 
    {
        if (IsFull()) 
        {
            cout << "Error! Stack is full!" << endl;
            return false;
        }
		symbol[++topIndex] = c; // symbol[topIndex++] = c ---> ERROR!!!! (Потрібно спочатку збільшити, потім записати)
        return true;
    }

    bool Pop() 
    {
        if (IsEmpty()) 
        {
            cout << "Error! Stack is empty!" << endl;
            return false;
        }
        topIndex--;
        return true;
    }

    int Size() const 
    {
        return topIndex + 1;
    }

    void Clear() 
    {
        topIndex = -1;
    }

    char Peek() const 
    {
        if (!IsEmpty())
            return symbol[topIndex];
        else
        {
            cout << "Stack is empty!" << endl;
            return 0;
        }     
    }

    void Print() const 
    {
        cout << "CharStack : ";
        for (int i = 0; i <= topIndex; ++i) 
        {
            cout << symbol[i] << ' ';
        }
        cout << endl;
    }
};


//Task 2

class DynamicCharStack
{
private:
    char* symbol;
    int capacity;
    int topIndex;

public:   
    DynamicCharStack(int size)
    {
    capacity = size;
    symbol = new char[capacity];
    topIndex = -1;
    }        

    ~DynamicCharStack()
    {
        delete[] symbol;
    }

    bool IsEmpty() const
    {
        return topIndex == -1;
    }

    bool IsFull() const
    {
        return topIndex == capacity - 1;
    }

    bool Push(char c)
    {
        if (IsFull())
        {
            cout << "Error! Stack is full!" << endl;
            return false;
        }
        symbol[++topIndex] = c;
        return true;
    }

    bool Pop()
    {
        if (IsEmpty())
        {
            cout << "Error! Stack is empty!" << endl;
            return false;
        }
        topIndex--;
        return true;
    }

    char Peek() const
    {
        if (!IsEmpty())
            return symbol[topIndex];
        else
            return 0;
    }

    void Clear()
    {
        topIndex = -1;
    }

    int Size() const
    {
        return topIndex + 1;
    }

    void Print() const
    {
        for (int i = 0; i <= topIndex; ++i)
        {
            cout << symbol[i] << ' ';
        }
        cout << endl;
    }



};


int main()
{
    cout << "------------------ Task 1 -----------------" << endl;
    CharStack s;

    s.Pop();

    s.Push('A');
    s.Push('B');
    s.Push('C');
    s.Push('D');
    s.Push('E');
    s.Print();

    s.Push('F');

    cout << "Top char : " << s.Peek() << endl;

    s.Pop();
    s.Print();

    cout << "CharStack Size : " << s.Size() << endl;
    cout << "Is CharStack empty : " << (s.IsEmpty() ? "Yes" : "No") << endl;
    s.Clear();
    cout << "Is CharStack empty : " << (s.IsEmpty() ? "Yes" : "No") << endl;


    cout << "------------------ Task 2 -----------------" << endl;

    int stackSize;
    cout << "Enter DynamicCharStack size: ";
    cin >> stackSize;

    DynamicCharStack s1(stackSize);
    cout << "Is DynamicCharStack empty: " << (s1.IsEmpty() ? "Yes" : "No") << endl;
	s1.Pop();

    s1.Push('A');
    s1.Push('B');
    s1.Push('C');
	s1.Push('D');
	s1.Push('E');
    s1.Print();

    cout << "Top symbol: " << s1.Peek() << endl;

    s1.Pop();
    s1.Print();

    cout << "DynamicCharStack Size: " << s1.Size() << endl;
    s1.Clear();
    cout << "Is DynamicCharStack empty: " << (s1.IsEmpty() ? "Yes" : "No") << endl;







};
