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
	Array() : arr(nullptr), size(0) {} // Пряма ініціалізація конструктора

	// Parametrized constructor
    Array(int n) : size(n) 
    {
        arr = new long[size];
        for (int i = 0; i < size; i++) 
        {
            arr[i] = 0;
        }
    }

    // Конструктор копіювання
    Array(const Array& other) : size(other.size) 
    {
        arr = new long[size];
        for (int i = 0; i < size; i++) 
        {
            arr[i] = other.arr[i];
        }
    }

    // Деструктор
    ~Array() {
        delete[] arr;  // Звільняємо пам'ять, виділену для масиву
    }

    // Функція для заповнення масиву випадковими числами
    void fillRandom() {
        if (size == 0) {
            cout << "Масив порожній, не можна заповнити випадковими значеннями.\n";
            return;
        }
        srand(time(0));  // Ініціалізація генератора випадкових чисел
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100 + 1;  // Випадкові числа від 1 до 100
        }
    }

    // Функція для заповнення масиву вручну (через клавіатуру)
    void fillFromInput() {
        if (size == 0) {
            cout << "Масив порожній, не можна заповнити значеннями.\n";
            return;
        }
        cout << "Введіть " << size << " елементів масиву:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // Функція для відображення вмісту масиву
    void display() const {
        if (size == 0) {
            cout << "Масив порожній.\n";
            return;
        }
        cout << "Масив: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Функція для додавання елемента в кінець масиву
    void addElement(long value) {
        long* temp = new long[size + 1];  // Створюємо новий масив на 1 елемент більший
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];  // Копіюємо старі елементи в новий масив
        }
        temp[size] = value;  // Додаємо новий елемент
        delete[] arr;  // Звільняємо стару пам'ять
        arr = temp;  // Вказуємо на новий масив
        size++;  // Збільшуємо розмір
    }

    // Функція для видалення елемента з масиву за індексом
    void removeElementByIndex(int index) {
        if (index < 0 || index >= size) {
            cout << "Невірний індекс.\n";
            return;
        }
        long* temp = new long[size - 1];  // Створюємо новий масив на 1 елемент менший
        for (int i = 0, j = 0; i < size; i++) {
            if (i != index) {
                temp[j++] = arr[i];  // Копіюємо елементи, пропускаючи видалений
            }
        }
        delete[] arr;  // Звільняємо стару пам'ять
        arr = temp;  // Вказуємо на новий масив
        size--;  // Зменшуємо розмір
    }

    // Функція для видалення елемента за значенням
    void removeElementByValue(long value) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Елемент не знайдений.\n";
            return;
        }
        removeElementByIndex(index);  // Викликаємо функцію для видалення за індексом
    }

    // Функція для сортування масиву по зростанню або спаданні (реалізація без <algorithm>)
    void sortArray(bool ascending = true) {
        if (size == 0) {
            cout << "Масив порожній, не можна сортувати.\n";
            return;
        }
        // Реалізуємо сортування методом бульбочки
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1 - i; j++) {
                if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                    // Обмін елементів
                    long temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // Функція для знаходження мінімального значення
    long min() const {
        if (size == 0) {
            cout << "Масив порожній.\n";
            return -1;  // Повертаємо значення, яке сигналізує про помилку
        }
        long minValue = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] < minValue) {
                minValue = arr[i];
            }
        }
        return minValue;
    }

    // Функція для знаходження максимального значення
    long max() const {
        if (size == 0) {
            cout << "Масив порожній.\n";
            return -1;  // Повертаємо значення, яке сигналізує про помилку
        }
        long maxValue = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > maxValue) {
                maxValue = arr[i];
            }
        }
        return maxValue;
    }

    // Функція для знаходження середнього арифметичного
    double average() const {
        if (size == 0) {
            cout << "Масив порожній.\n";
            return -1;  // Повертаємо значення, яке сигналізує про помилку
        }
        long sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return static_cast<double>(sum) / size;
    }

    // Геттер для розміру масиву
    int getSize() const {
        return size;
    }
};

int main() {
    Array arr(5);  // Створення масиву з 5 елементів

    arr.fillRandom();  // Заповнення масиву випадковими числами
    arr.display();  // Виведення вмісту масиву

    arr.addElement(100);  // Додавання елемента в масив
    arr.display();

    arr.removeElementByIndex(2);  // Видалення елемента за індексом
    arr.display();

    arr.removeElementByValue(100);  // Видалення елемента за значенням
    arr.display();

    arr.sortArray();  // Сортування по зростанню
    arr.display();

    cout << "Мінімальне значення: " << arr.min() << endl;
    cout << "Максимальне значення: " << arr.max() << endl;
    cout << "Середнє арифметичне: " << arr.average() << endl;

    return 0;
}
