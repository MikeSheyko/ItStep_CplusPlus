
#include <iostream>
#include <windows.h>
using namespace std;


struct Coord 
{
	int x;
	int y;
};

class NewRectangle
{
private:
    int width;
    int height;
    char symbol;
    Coord position;
public:
    NewRectangle()
    {
        cout << "Default constructor called!" << endl;
        width = 10;
        height = 5;
        symbol = '*';
        position.x = 0;
        position.y = 0;
    }

    NewRectangle(int size)
    {
        cout << "Parametrized constructor 1 called!" << endl;
        width = size;
        height = size;
        symbol = '*';
        position.x = 0;
        position.y = 0;
        if (width <= 0 || height <= 0)
        {
            cout << "Error! Size (Width and height) must be positive!" << endl;
            size = 5;
        }
    }

    NewRectangle(int w, int h)
    {
        cout << "Parametrized constructor 2 called!" << endl;
        width = w;
        height = h;
        symbol = '*';
        position.x = 0;
        position.y = 0;
        if (width <= 0 || height <= 0)
        {
            cout << "Error! Size (Width and height) must be positive!" << endl;
            width = 8;
            height = 4;
        }
    }

    void print()
    {
        Sleep(2000);
        system("cls");
        for (int i = 0; i < height; ++i)
        {
            setPosition(position.x, position.y + i);
            for (int j = 0; j < width; ++j)
            {
                cout << symbol;
            }
            cout << endl;
        }
        cout << endl;
    }

    void NewSize(int newHeight, int newWidth)
    {
        if (newHeight <= 0 || newWidth <= 0)
        {
			cout << "Error! Size (Width and height) must be positive!" << endl;
            return;
        }
        height = newHeight;
        width = newWidth;
        position.x = 0;
        position.y = 0;

    }
    void move(int deltaX, int deltaY) 
    {
        position.x += deltaX;
        position.y += deltaY;
    }


    void setPosition(int x, int y)
    {
        
        COORD coord;
        coord.X = x; // колонка
        coord.Y = y; // рядок
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
};




int main()
{
    NewRectangle rect1;
    rect1.print();
    cout << "----------------------------" << endl;


    NewRectangle rect2(7);
    rect2.print();
    cout << "----------------------------" << endl;


    NewRectangle rect3(5, 3);
    rect3.print();
    cout << "----------------------------" << endl;


    cout << "Changing size of rectangle 3 to 8x6" << endl;
    rect3.NewSize(8, 6);
    rect3.print();
    cout << "----------------------------" << endl;


    cout << "Changing position of rectangle" << endl;
    rect3.move(20, 20);
    rect3.print();
    cout << "----------------------------" << endl;


   


	







}
