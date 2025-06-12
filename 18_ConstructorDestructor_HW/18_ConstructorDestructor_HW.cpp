#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Array 
{
private:
    long* arr;
    int size;

public:
	// Default constructor
	Array() : arr(nullptr), size(0) {} // ����� ����������� ������������

	// Parametrized constructor
    Array(int n) : size(n) 
    {
        arr = new long[size];
        for (int i = 0; i < size; i++) 
        {
            arr[i] = 0;
        }
    }

    // ����������� ���������
    Array(const Array& other) : size(other.size) 
    {
        arr = new long[size];
        for (int i = 0; i < size; i++) 
        {
            arr[i] = other.arr[i];
        }
    }

    // ����������
    ~Array() {
        delete[] arr;  // ��������� ���'���, ������� ��� ������
    }

    // ������� ��� ���������� ������ ����������� �������
    void fillRandom() {
        if (size == 0) {
            cout << "����� �������, �� ����� ��������� ����������� ����������.\n";
            return;
        }
        srand(time(0));  // ����������� ���������� ���������� �����
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100 + 1;  // �������� ����� �� 1 �� 100
        }
    }

    // ������� ��� ���������� ������ ������ (����� ���������)
    void fillFromInput() {
        if (size == 0) {
            cout << "����� �������, �� ����� ��������� ����������.\n";
            return;
        }
        cout << "������ " << size << " �������� ������:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // ������� ��� ����������� ����� ������
    void display() const {
        if (size == 0) {
            cout << "����� �������.\n";
            return;
        }
        cout << "�����: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // ������� ��� ��������� �������� � ����� ������
    void addElement(long value) {
        long* temp = new long[size + 1];  // ��������� ����� ����� �� 1 ������� ������
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];  // ������� ���� �������� � ����� �����
        }
        temp[size] = value;  // ������ ����� �������
        delete[] arr;  // ��������� ����� ���'���
        arr = temp;  // ������� �� ����� �����
        size++;  // �������� �����
    }

    // ������� ��� ��������� �������� � ������ �� ��������
    void removeElementByIndex(int index) {
        if (index < 0 || index >= size) {
            cout << "������� ������.\n";
            return;
        }
        long* temp = new long[size - 1];  // ��������� ����� ����� �� 1 ������� ������
        for (int i = 0, j = 0; i < size; i++) {
            if (i != index) {
                temp[j++] = arr[i];  // ������� ��������, ����������� ���������
            }
        }
        delete[] arr;  // ��������� ����� ���'���
        arr = temp;  // ������� �� ����� �����
        size--;  // �������� �����
    }

    // ������� ��� ��������� �������� �� ���������
    void removeElementByValue(long value) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "������� �� ���������.\n";
            return;
        }
        removeElementByIndex(index);  // ��������� ������� ��� ��������� �� ��������
    }

    // ������� ��� ���������� ������ �� ��������� ��� ������� (��������� ��� <algorithm>)
    void sortArray(bool ascending = true) {
        if (size == 0) {
            cout << "����� �������, �� ����� ���������.\n";
            return;
        }
        // �������� ���������� ������� ���������
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1 - i; j++) {
                if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                    // ���� ��������
                    long temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // ������� ��� ����������� ���������� ��������
    long min() const {
        if (size == 0) {
            cout << "����� �������.\n";
            return -1;  // ��������� ��������, ��� �������� ��� �������
        }
        long minValue = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] < minValue) {
                minValue = arr[i];
            }
        }
        return minValue;
    }

    // ������� ��� ����������� ������������� ��������
    long max() const {
        if (size == 0) {
            cout << "����� �������.\n";
            return -1;  // ��������� ��������, ��� �������� ��� �������
        }
        long maxValue = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > maxValue) {
                maxValue = arr[i];
            }
        }
        return maxValue;
    }

    // ������� ��� ����������� ���������� �������������
    double average() const {
        if (size == 0) {
            cout << "����� �������.\n";
            return -1;  // ��������� ��������, ��� �������� ��� �������
        }
        long sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return static_cast<double>(sum) / size;
    }

    // ������ ��� ������ ������
    int getSize() const {
        return size;
    }
};

int main() {
    Array arr(5);  // ��������� ������ � 5 ��������

    arr.fillRandom();  // ���������� ������ ����������� �������
    arr.display();  // ��������� ����� ������

    arr.addElement(100);  // ��������� �������� � �����
    arr.display();

    arr.removeElementByIndex(2);  // ��������� �������� �� ��������
    arr.display();

    arr.removeElementByValue(100);  // ��������� �������� �� ���������
    arr.display();

    arr.sortArray();  // ���������� �� ���������
    arr.display();

    cout << "̳������� ��������: " << arr.min() << endl;
    cout << "����������� ��������: " << arr.max() << endl;
    cout << "������ �����������: " << arr.average() << endl;

    return 0;
}
