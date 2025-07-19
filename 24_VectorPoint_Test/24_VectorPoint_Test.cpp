#include <iostream>
#include <windows.h>
using namespace std;

// ========= Клас Point ==========
class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    void Print() const {
        cout << "(" << x << ", " << y << ")";
    }

    // Префіксний інкремент ++p
    Point& operator++() {
        ++x;
        ++y;
        return *this;
    }

    // Префіксний декремент --p
    Point& operator--() {
        --x;
        --y;
        return *this;
    }

    // Відстань до (0, 0)
    bool operator<(const Point& other) const {
        return (x * x + y * y) < (other.x * other.x + other.y * other.y);
    }

    bool operator>(const Point& other) const {
        return (x * x + y * y) > (other.x * other.x + other.y * other.y);
    }

    Point operator!() const {
        return Point(-x, -y);
    }

    int getX() const { return x; }
    int getY() const { return y; }
};

// ========= Функція gotoxy ==========
void gotoxy(int x, int y) {
    COORD coord{ (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// ========= Клас Vector ==========
class Vector {
private:
    Point* points;
    int countPoint;
public:
    Vector() : points(nullptr), countPoint(0) {}

    Vector(const Vector& other) : countPoint(other.countPoint) {
        points = new Point[countPoint];
        for (int i = 0; i < countPoint; ++i)
            points[i] = other.points[i];
    }

    Vector(Vector&& other) noexcept : points(other.points), countPoint(other.countPoint) {
        other.points = nullptr;
        other.countPoint = 0;
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] points;
            countPoint = other.countPoint;
            points = new Point[countPoint];
            for (int i = 0; i < countPoint; ++i)
                points[i] = other.points[i];
        }
        return *this;
    }

    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] points;
            points = other.points;
            countPoint = other.countPoint;
            other.points = nullptr;
            other.countPoint = 0;
        }
        return *this;
    }

    ~Vector() {
        delete[] points;
    }

    void Add(const Point& p) {
        Point* newPoints = new Point[countPoint + 1];
        for (int i = 0; i < countPoint; ++i)
            newPoints[i] = points[i];
        newPoints[countPoint] = p;
        delete[] points;
        points = newPoints;
        ++countPoint;
    }

    void Print() const {
        for (int i = 0; i < countPoint; ++i) {
            cout << "Point " << i + 1 << ": ";
            points[i].Print();
            cout << endl;
        }
    }

    void PrintWithCoordinates() const {
        system("cls");
        for (int i = 0; i < countPoint; ++i) {
            int x = points[i].getX();
            int y = points[i].getY();
            if (x >= 0 && y >= 0) {
                gotoxy(x, y);
                cout << "*";
            }
        }
        gotoxy(0, 25);
        cout << endl;
    }
};

// ========== main ============
int main() {
    Point p1(5, 4);
    Point p2(-1, 9);

    cout << "Original p1: "; p1.Print(); cout << endl;
    cout << "Original p2: "; p2.Print(); cout << endl;

    ++p1;
    --p2;
    cout << "After ++p1: "; p1.Print(); cout << endl;
    cout << "After --p2: "; p2.Print(); cout << endl;

    cout << "p1 < p2: " << ((p1 < p2) ? "True" : "False") << endl;
    cout << "p1 > p2: " << ((p1 > p2) ? "True" : "False") << endl;

    Point neg = !p1;
    cout << "!p1: "; neg.Print(); cout << endl;

    cout << "\n=== Vector ===" << endl;
    Vector vec;
    vec.Add(p1);
    vec.Add(p2);
    vec.Add(neg);
    vec.Print();

    cout << "\n=== Vector with Coordinates (gotoxy) ===" << endl;
    Sleep(2000);
    vec.PrintWithCoordinates();

    Sleep(3000);
    return 0;
}
