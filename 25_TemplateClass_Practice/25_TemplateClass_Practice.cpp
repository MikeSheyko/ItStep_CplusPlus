#include <iostream>
#include <initializer_list>
using namespace std;

template <typename T>
class Array
{
private:
    T* arr;
    int size;
public:
    Array();
    Array(int size);
    Array(const initializer_list<T> list);
    ~Array();

    void Fill(const initializer_list<T> list);
    void Print() const;

    T* GetData() const;
    int GetSize() const;

    T FindMax() const;
    T FindMin() const;
    void Sort();
    int BinarySearch(T key) const;
    bool Replace(T oldVal, T newVal);
};


template <typename T>
Array<T>::Array() : arr(nullptr), size(0) {};

template <typename T>
Array<T>::Array(int size) : size(size)
{
    arr = new T[size]{};
};

template <typename T>
Array<T>::Array(const initializer_list<T> list)
{
    size = list.size();
    arr = new T[size];
    int i = 0;
    for (const T elem : list)
    {
        arr[i++] = elem;
    }
};

template <typename T>
Array<T>::~Array()
{
    delete[] arr;
};

template <typename T>
void Array<T>::Fill(const initializer_list<T> list)
{
    if (arr != nullptr)
        delete[] arr;
    size = list.size();
    arr = new T[size];
    int i = 0;
    for (const T elem : list)
    {
        arr[i++] = elem;
    }
};

template <typename T>
void Array<T>::Print() const
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
};

template <typename T>
T* Array<T>::GetData() const
{
    return arr;
}

template <typename T>
int Array<T>::GetSize() const
{
    return size;
};

template <typename T>
T Array<T>::FindMax() const
{
    T max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
};

template <typename T>
T Array<T>::FindMin() const
{
    T min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
};

template <typename T>
void Array<T>::Sort()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
};

template <typename T>
int Array<T>::BinarySearch(T key) const
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
};

template <typename T>
bool Array<T>::Replace(T oldVal, T newVal)
{
    bool replaced = false;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == oldVal)
        {
            arr[i] = newVal;
            replaced = true;
        }
    }

    return replaced;
};

int main()
{
    Array<int> arr = {10, -1, -8, 12, 0, 41, 18, 54, 5, 16, 74, 72, 12, 42};
    arr.Print();

    cout << "Max element : " << arr.FindMax() << endl;
    cout << "Min element: " << arr.FindMin() << endl;

    arr.Sort();
    cout << "Sorted array : ";
    arr.Print();

    int index = arr.BinarySearch(5);
    if (index != -1)
        cout << "Number '5' found at index: " << index << endl;
    else
        cout << "Number '5' not found" << endl;


    arr.Replace(10, 20);
    cout << "After replace : ";
    arr.Print();


};
