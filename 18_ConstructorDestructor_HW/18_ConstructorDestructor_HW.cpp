#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


class Array 
{
private:
    long* _arr;
    int _size;
public:
    Array() 
    {
        _size = 1;
        _arr = new long[_size];
        _arr[0] = 0;
    }

    explicit Array(int n) 
    {
        while (n <= 0) 
        {
            cout << "Error! Size could not be nagative or 0. Please enter size again: ";
            cin >> n;
        }
        _size = n;
        _arr = new long[_size];
        for (int i = 0; i < _size; ++i) 
        {
            _arr[i] = 0;
        }
    }

    Array(const Array& other) 
    {
        _size = other._size;
        _arr = new long[_size];
        for (int i = 0; i < _size; ++i) 
        {
            _arr[i] = other._arr[i];
        }
    }

    ~Array() 
    {
        delete[] _arr;
    }

    void fillFromInput() {
        for (int i = 0; i < _size; ++i) 
        {
            cout << "Enter values[" << i << "]: ";
            cin >> _arr[i];
        }
    }

    void fillRandom(int min = 0, int max = 100) 
    {
        srand(time(0));
        for (int i = 0; i < _size; ++i) 
        {
            _arr[i] = min + rand() % (max - min + 1);
        }
    }

    void print() const 
    {
        if (_size == 0) 
        {
            cout << "Array is empty!" << endl;
            return;
        }
        for (int i = 0; i < _size; ++i) 
        {
            cout << _arr[i] << " ";
        }
        cout << endl;
    }

    void addNewValue(long value) 
    {
        long* newArr = new long[_size + 1];
        for (int i = 0; i < _size; ++i) 
        {
            newArr[i] = _arr[i];
        }
        newArr[_size] = value;
        delete[] _arr;
        _arr = newArr;
        _size++;
    }

    void removeByIndex(int index) 
    {
        if (index < 0 || index >= _size) 
        {
            cout << "Error! Invalid index or index is out of range!" << endl;
            return;
        }
        if (_size == 1) 
        {
            delete[] _arr;
            _arr = nullptr;
            _size = 0;
            return;
        }
        long* newArr = new long[_size - 1];
        for (int i = 0, j = 0; i < _size; ++i) 
        {
            if (i != index) 
            {
                newArr[j++] = _arr[i];
            }
        }
        delete[] _arr;
        _arr = newArr;
        _size--;
    }

    void removeByValue(long value) 
    {
        int index = -1;
        for (int i = 0; i < _size; ++i) 
        {
            if (_arr[i] == value) 
            {
                index = i;
                break;
            }
        }
        if (index == -1) 
        {
            cout << "Value not found." << endl;
        }
        else 
        {
            removeByIndex(index);
        }
    }

    void sortAsc() 
    {
        for (int i = 0; i < _size - 1; ++i) 
        {
            for (int j = 0; j < _size - i - 1; ++j) 
            {
                if (_arr[j] > _arr[j + 1]) 
                {
                    long temp = _arr[j];
                    _arr[j] = _arr[j + 1];
                    _arr[j + 1] = temp;
                }
            }
        }
    }

    void sortDesc() 
    {
        for (int i = 0; i < _size - 1; ++i) 
        {
            for (int j = 0; j < _size - i - 1; ++j) 
            {
                if (_arr[j] < _arr[j + 1]) 
                {
                    long temp = _arr[j];
                    _arr[j] = _arr[j + 1];
                    _arr[j + 1] = temp;
                }
            }
        }
    }

    long getMinValue() const 
    {
        if (_size == 0) 
        {
            cout << "Array is empty." << endl;
            return 0;
        }
        long min = _arr[0];
        for (int i = 1; i < _size; ++i) 
        {
            if (_arr[i] < min) min = _arr[i];
        }
        return min;
    }

    long getMaxValue() const
    {
        if (_size == 0) 
        {
            cout << "Array is empty." << endl;
            return 0;
        }
        long max = _arr[0];
        for (int i = 1; i < _size; ++i) {
            if (_arr[i] > max) max = _arr[i];
        }
        return max;
    }

    double getAverage() const 
    {
        if (_size == 0) 
        {
            cout << "Array is empty." << endl;
            return 0;
        }
        long sum = 0;
        for (int i = 0; i < _size; ++i) 
        {
            sum += _arr[i];
        }
        return (double) sum / _size;
    }

    int getSize() const 
    {
        return _size;
    }
};


int main() 
{
    int choice;
    int initialSize;

    cout << "Enter array size: "; cin >> initialSize;

    Array arr(initialSize);

    do {
        setColor(2);
        cout << "================= Menu ===================" << endl;
        cout << "Fill array with random values          [1]" << endl;
        cout << "Fill array from keyboard               [2]" << endl;
        cout << "Print array                            [3]" << endl;
        cout << "Add new element in the end             [4]" << endl;
        cout << "Remove element by index                [5]" << endl;
        cout << "Remove element by value                [6]" << endl;
        cout << "Sort by ascending                      [7]" << endl;
        cout << "Sort by descending                     [8]" << endl;
        cout << "Get minimum value                      [9]" << endl;
        cout << "Get maximum value                      [10]" << endl;
        cout << "Get average value                      [11]" << endl;
        cout << "Exit                                   [0]" << endl;
		cout << "==========================================" << endl;
        setColor(11);
        cout << "Enter your choice: "; cin >> choice;
        setColor(7);

        switch (choice) 
        {
        case 1:
            arr.fillRandom();
            arr.print();
            break;
        case 2:
            arr.fillFromInput();
            arr.print();
            break;
        case 3:
            arr.print();
            break;
        case 4:
        {
            long val;
            cout << "Enter value to add: ";
            cin >> val;
            cout << "Array before adding new value:\t";
            arr.print();
            arr.addNewValue(val);
            cout << "Array after adding new value:\t";
            arr.print();
            break;
        }
        case 5:
        {
            int index;
            cout << "Enter index to remove: ";
            cin >> index;
            cout << "Array before removing by index:\t";
            arr.print();
            arr.removeByIndex(index);
            cout << "Array after removing by index:\t";
            arr.print();
            break;
        }
        case 6:
        {
            long value;
            cout << "Enter value to remove: ";
            cin >> value;
            cout << "Array before removing by value:\t";
            arr.print();
            arr.removeByValue(value);
            cout << "Array after removing by value:\t";
            arr.print();
            break;
        }
        case 7:
            cout << "Array before sorting by Asc:\t";
            arr.print();
            arr.sortAsc();
            cout << "Array after sorting by Asc:\t";
            arr.print();
            break;
        case 8:
            cout << "Array before sorting by Desc:\t";
            arr.print();
            arr.sortDesc();
            cout << "Array after sorting by Desc:\t";
            arr.print();
            break;
        case 9:
            cout << "Minimum value: " << arr.getMinValue() << endl;
            break;
        case 10:
            cout << "Maximum value: " << arr.getMaxValue() << endl;
            break;
        case 11:
            cout << "Average value: " << arr.getAverage() << endl;
            break;
        case 0:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again!" << endl;
        }

    } while (choice != 0);

 









}

