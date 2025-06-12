#include <iostream>
#include <vector>
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
    int color = 7;

    void initDefaults()
    {
        symbol = '*';
        position.x = 0;
        position.y = 0;
    }

public:
    NewRectangle()
    {
        width = 10;
        height = 5;
        initDefaults();
    }

    NewRectangle(int w, int h)
    {
        if (w <= 0 || h <= 0)
        {
            cout << "Error! Width and height must be positive! Defaulting to 8x4.\n";
            width = 8;
            height = 4;
        }
        else
        {
            width = w;
            height = h;
        }
        initDefaults();
    }

    void print()
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        for (int i = 0; i < height; ++i)
        {
            setPosition(position.x, position.y + i);
            for (int j = 0; j < width; ++j)
            {
                cout << symbol;
            }
            cout << endl;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }

    void drawBorder()
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        for (int i = 0; i < height; ++i)
        {
            setPosition(position.x, position.y + i);
            for (int j = 0; j < width; ++j)
            {
                if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                    cout << symbol;
                else
                    cout << ' ';
            }
            cout << endl;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }

    void NewSize(int newHeight, int newWidth)
    {
        if (newHeight > 0 && newWidth > 0)
        {
            height = newHeight;
            width = newWidth;
        }
    }

    void move(int deltaX, int deltaY)
    {
        position.x += deltaX;
        position.y += deltaY;
    }

    void setPosition(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void setSymbol(char c)
    {
        symbol = c;
    }

    void setColor(int c)
    {
        color = c;
    }
};

// Головне меню
void showMenu()
{
    cout << "\n=== Rectangle Manager ===\n";
    cout << "1. Create new rectangle\n";
    cout << "2. Edit rectangle\n";
    cout << "3. Show all (filled)\n";
    cout << "4. Show all (borders)\n";
    cout << "5. Delete rectangle\n";
    cout << "6. Exit\n";
    cout << "Choice: ";
}

void editMenu()
{
    cout << "\n--- Edit Menu ---\n";
    cout << "1. Resize\n";
    cout << "2. Move\n";
    cout << "3. Change symbol\n";
    cout << "4. Change color\n";
    cout << "5. Back\n";
    cout << "Choice: ";
}

int main()
{
    vector<NewRectangle> rects;
    bool running = true;

    while (running)
    {
        showMenu();
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int w, h;
            cout << "Width: "; cin >> w;
            cout << "Height: "; cin >> h;
            rects.push_back(NewRectangle(w, h));
            cout << "Created rectangle #" << rects.size() - 1 << endl;
            break;
        }
        case 2:
        {
            if (rects.empty()) {
                cout << "No rectangles to edit.\n";
                break;
            }

            int id;
            cout << "Enter rectangle index (0.." << rects.size() - 1 << "): ";
            cin >> id;
            if (id < 0 || id >= rects.size()) {
                cout << "Invalid index.\n";
                break;
            }

            bool editing = true;
            while (editing) {
                editMenu();
                int e;
                cin >> e;
                switch (e)
                {
                case 1:
                {
                    int w, h;
                    cout << "New width: "; cin >> w;
                    cout << "New height: "; cin >> h;
                    rects[id].NewSize(h, w);
                    break;
                }
                case 2:
                {
                    int dx, dy;
                    cout << "Move X: "; cin >> dx;
                    cout << "Move Y: "; cin >> dy;
                    rects[id].move(dx, dy);
                    break;
                }
                case 3:
                {
                    char s;
                    cout << "New symbol: "; cin >> s;
                    rects[id].setSymbol(s);
                    break;
                }
                case 4:
                {
                    int c;
                    cout << "Color (0–15): "; cin >> c;
                    rects[id].setColor(c);
                    break;
                }
                case 5:
                    editing = false;
                    break;
                default:
                    cout << "Invalid option.\n";
                }
            }
            break;
        }
        case 3:
            system("cls");
            for (auto& r : rects) r.print();
            break;
        case 4:
            system("cls");
            for (auto& r : rects) r.drawBorder();
            break;
        case 5:
        {
            int id;
            cout << "Enter rectangle index to delete: ";
            cin >> id;
            if (id >= 0 && id < rects.size()) {
                rects.erase(rects.begin() + id);
                cout << "Deleted.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
            break;
        }
        case 6:
            running = false;
            break;
        default:
            cout << "Invalid option.\n";
        }
    }

    return 0;
}
