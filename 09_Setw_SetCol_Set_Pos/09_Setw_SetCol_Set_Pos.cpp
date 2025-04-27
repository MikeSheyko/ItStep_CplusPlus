
#include <iostream>
using namespace std;
#include <windows.h>

void setColor(int color) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void setPosition(int x, int y) {
    COORD coord;
    coord.X = x; // колонка
    coord.Y = y; // рядок
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{

    for (int i = 0; i < 15; i++)
    {
		setColor(i);
        cout << "Hello world" << endl;
    }
    setColor(7);
    cout << "Hello world" << endl;


    /*setColor(10);
    cout << "Hello World!\n";
    setPosition(10, 5);
    setColor(3);
    cout << "Hello World!\n";

    cout << "\033[31mHi World\033[0m";*/
}

