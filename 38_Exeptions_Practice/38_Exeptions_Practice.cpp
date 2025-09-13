#include <iostream>
#include <exception>
#include <fstream>
using namespace std;

class Stack
{
    enum {EMPTY = -1};

    int* arr;
    int maxSize;
    int topIndex;
public:
    Stack() = delete;

    Stack(int size) : maxSize(size)
    {
        if (size <= 0)
            throw invalid_argument("Eror! Size must be > 0!");

        arr = new int[size];
        topIndex = EMPTY;
    }

    ~Stack()
    {
        delete[] arr;
    }


    bool IsFull() const
    {
        return topIndex == maxSize - 1;
    }

    bool IsEmpty() const
    {
        return topIndex == EMPTY;
    }


    void Push(int value)
    {
        if (IsFull())
            throw overflow_error("Error! Stack is full!");

        arr[++topIndex] = value;
    }

    int Pop()
    {
        if (IsEmpty())
            throw underflow_error("Error! Stack is empty!");

        return arr[topIndex--];
    }


    void Clear()
    {
        topIndex = EMPTY;
    }


    int Peek() const
    {
        if (IsEmpty())
            throw runtime_error("Error! Stack is empty!");

        return arr[topIndex];
    }

    int GetSize() const
    {
        return topIndex + 1;
    }


    void Print() const
    {
        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    void SaveToFile(const string& filename)
    {
        ofstream out(filename);
        if (!out)
            throw runtime_error("Cannot open file for writing.");

        out << maxSize << endl;
        out << topIndex << endl;
        for (int i = 0; i <= topIndex; i++)
        {
            out << arr[i] << endl;
        }

        out.close();
        cout << "Save to file : " << filename << endl;
    }

    
    void LoadFromFile(const string& filename)
    {
        ifstream in(filename);
        if (!in)
            throw runtime_error("Error! Can't open file!");
        in >> maxSize; in >> topIndex;
        for (int i = 0; i <= topIndex; i++)
        {
            in >> arr[i];
        }
        in.close();
        cout << "Load from file : " << filename << endl;
    }



};


int main()
{
    try
    {
        Stack st(5);

        st.Push(10);
        st.Push(20);
        st.Push(30);
        st.Push(40);
        st.Push(50);

        cout << "Size : " << st.GetSize() << endl;
        st.Print();

        cout << "Last element : " << st.Peek() << endl;


		//st.Push(60); // Stack overflow

        st.SaveToFile("Test.txt");
        st.Clear();


        st.LoadFromFile("Test.txt");

        

        while (!st.IsEmpty())
        {
            cout << "Deleted element : " << st.Pop() << endl;
        }

        cout << "Size after clear : " << st.GetSize() << endl;

        
		//st.Pop(); // Stack underflow

    }
    catch (const exception& ex)
    {
        cout << "Exception : " << ex.what() << endl;
    }



}