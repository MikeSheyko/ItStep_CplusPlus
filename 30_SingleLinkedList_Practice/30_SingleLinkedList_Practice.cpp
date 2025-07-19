#include <iostream>
#include <windows.h>
using namespace std;


template<typename T>
struct Node 
{
    T value;
    Node* next;
    Node(T value, Node* next = nullptr) : value(value), next(next) {}
};

template<typename T>
class List 
{
private:
    Node<T>* head;
public:
    List() : head(nullptr) {}

    void AddToHead(const T& value) 
    {
        Node<T>* newNode = new Node<T>(value, head);
        head = newNode;
    }

    void AddToTail(const T& value) 
    {
        Node<T>* newNode = new Node<T>(value, nullptr);
        if (!head) 
        {
            head = newNode;
            return;
        }
        Node<T>* current = head;
        while (current->next) 
        {
            current = current->next;
        }
        current->next = newNode;
    }

    void deleteFromHead() 
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromTail() 
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node<T>* current = head;
        while (current->next->next) 
        {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    T getElement(int pos) const 
    {
        Node<T>* current = head;
        int i = 1;
        while (current) 
        {
            if (i == pos) return current->value;
            current = current->next;
            i++;
        }
        return -1;
    }

    T operator[](int pos) const 
    {
        return getElement(pos);
    }

    void Print() const 
    {
        Node<T>* current = head;
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~List() 
    {
        Node<T>* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }

    Node<T>* getHead() const 
    {
        return head;
	}
};


class Point 
{
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    friend ostream& operator<< (ostream& os, const Point& p);
};

ostream& operator<< (ostream& os, const Point& p) 
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

void gotoxy(int x, int y)
{
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


class Vector 
{
private:
    int size;
    int PosX;
    int PosY;
    List<Point> points;
public:
    Vector() : size(0), PosX(40), PosY(42) {}


    void AddPointToHead(const Point& p) 
    {
        points.AddToHead(p);
        size++;
    }

    void AddPointToTail(const Point& p) 
    {
        points.AddToTail(p);
        size++;
    }

    void DeleteFromHead() 
    {
        points.deleteFromHead();
        if (size > 0) 
        {
            size--;
        } 
    }

    void DeleteFromTail() 
    {
        points.deleteFromTail();
        if (size > 0)
        {
            size--;
        } 
    }

    void Print() const 
    {
        cout << "Class vector has " << size << " point/points : ";
        points.Print();
    }

    //void PrintPoints() const
    //{
    //   /* system("cls");*/

    //    Node<Point>* current = points.getHead();
    //    while (current)
    //    {
    //        int consoleX = PosX + current->value.x;
    //        int consoleY = PosY - current->value.y;
    //        if (consoleX >= 0 && consoleX < 80 && consoleY >= 0 && consoleY < 25)
    //        {
    //            gotoxy(consoleX, consoleY);
    //            cout << "*";
    //            Sleep(300);
    //        }
    //        current = current->next;
    //    }
    //    gotoxy(40, 12);
    //}


};


int main() 
{
    Vector v;
    v.AddPointToHead(Point(18, 7));
    v.AddPointToTail(Point(14, 10));
    v.AddPointToHead(Point(140, 20));
    v.Print();
    /*v.PrintPoints();*/
    
    

    v.DeleteFromTail();
    v.Print();
    

    v.DeleteFromHead();
    v.Print();

    v.DeleteFromHead(); 
    v.Print();

	
    
    

	v.DeleteFromHead(); // "List is empty"
    

   
}
