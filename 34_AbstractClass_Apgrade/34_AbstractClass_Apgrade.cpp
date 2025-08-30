#include <iostream>
using namespace std;

class Shape 
{
protected:
    string name;
    string type;
public:
    Shape() : name("no name"), type("no type") {}
    Shape(string n, string t) : name(n), type(t) {}

    virtual void Show() const 
    {
        cout << "Name : " << name << endl;
        cout << "Type : " << type << endl;
    }

    virtual double GetArea() const = 0;
    virtual void Draw() const = 0;
};

class Rectangle : public Shape 
{
    double width;
    double height;
public:
    Rectangle() : width(0), height(0), Shape() {}
    Rectangle(string n, string t, double w, double h) : width(w), height(h), Shape(n, t) {}

    void Show() const override 
    {
        Shape::Show();
        cout << "Width : " << width << endl;
        cout << "Height : " << height << endl;
    }

    double GetArea() const override 
    {
        return width * height;
    }

    void Draw() const override 
    {
        int w = int(width);
        int h = int(height);
        for (int i = 0; i < h; i++) 
        {
            for (int j = 0; j < w; j++) 
            {
                cout << "*";
            }
            cout << endl;
        }
    }
};

class Circle : public Shape 
{
    double radius;
public:
    Circle() : radius(0), Shape() {}
    Circle(string n, string t, double r) : radius(r), Shape(n, t) {}

    void Show() const override 
    {
        Shape::Show();
        cout << "Radius : " << radius << endl;
    }

    double GetArea() const override 
    {
        return 3.1416 * radius * radius;
    }

    void Draw() const override 
    {
        int r = int(radius);
        for (int i = -r; i <= r; i++) 
        {
            for (int j = -2 * r; j <= 2 * r; j++) 
            {
                if (i * i + j * j / 4 <= r * r)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
};

class RightTriangle : public Shape 
{
protected:
    double base;
    double height;
public:
    RightTriangle() : base(0), height(0), Shape() {}
    RightTriangle(string n, string t, double b, double h) : base(b), height(h), Shape(n, t) {}

    void Show() const override 
    {
        Shape::Show();
        cout << "Base : " << base << endl;
        cout << "Height : " << height << endl;
    }

    double GetArea() const override 
    {
        return 0.5 * base * height;
    }

    void Draw() const override 
    {
        int h = int(height);
        for (int i = 1; i <= h; i++) 
        {
            for (int j = 1; j <= i; j++) 
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
};

class Triangle : public RightTriangle 
{
public:
    Triangle() : RightTriangle() {}
    Triangle(string n, string t, double b, double h) : RightTriangle(n, t, b, h) {}

    void Draw() const override 
    {
        int h = int(height);
        for (int i = 1; i <= h; i++) 
        {
            for (int s = 0; s < h - i; s++)
                cout << " ";
            for (int j = 1; j <= 2 * i - 1; j++)
                cout << "*";
            cout << endl;
        }
    }
};

class Trapezoid : public Shape
{
    double base1;
    double base2;
    double height;
public:
    Trapezoid() : base1(0), base2(0), height(0), Shape() {}
    Trapezoid(string n, string t, double b1, double b2, double h) : base1(b1), base2(b2), height(h), Shape(n, t) {}

    void Show() const override
    {
        Shape::Show();
        cout << "Base 1 (bottom) : " << base1 << endl;
        cout << "Base 2 (top)    : " << base2 << endl;
        cout << "Height          : " << height << endl;
    }

    double GetArea() const override
    {
        return 0.5 * (base1 + base2) * height;
    }

    void Draw() const
    {
        
        
    }
};


void Menu() {
    int choice;
    do {
        cout << "========== Menu ==========" << endl;
        cout << "[1] Rectangle" << endl;
        cout << "[2] Circle" << endl;
        cout << "[3] Right Triangle" << endl;
        cout << "[4] Triangle" << endl;
        cout << "[5] Trapezoid" << endl;
        cout << "[0] Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        system("cls");

        string name;
        if (choice >= 1 && choice <= 5) 
        {
            cout << "Enter shape name : ";
            cin >> name;
        }

        if (choice == 1) 
        {
            double w, h;
            cout << "Enter width : "; 
            cin >> w;
            cout << "Enter height : "; 
            cin >> h;
            Rectangle r(name, "Rectangle", w, h);
            r.Show();
            cout << "Area : " << r.GetArea() << endl;
            r.Draw();
        }
        else if (choice == 2) 
        {
            double r;
            cout << "Enter radius : "; 
            cin >> r;
            Circle c(name, "Circle", r);
            c.Show();
            cout << "Area: " << c.GetArea() << endl;
            c.Draw();
        }
        else if (choice == 3) 
        {
            double b, h;
            cout << "Enter base : "; 
            cin >> b;
            cout << "Enter height : "; 
            cin >> h;
            RightTriangle rt(name, "RightTriangle", b, h);
            rt.Show();
            cout << "Area : " << rt.GetArea() << endl;
            rt.Draw();
        }
        else if (choice == 4) 
        {
            double b, h;
            cout << "Enter base : "; cin >> b;
            cout << "Enter height : "; cin >> h;
            Triangle t(name, "Triangle", b, h);
            t.Show();
            cout << "Area : " << t.GetArea() << endl;
            t.Draw();
        }
        else if (choice == 5) 
        {
            double b1, b2, h;
            cout << "Enter bottom base : ";
            cin >> b1;
            cout << "Enter top base : ";
            cin >> b2;
            cout << "Enter height : ";
            cin >> h;            
            Trapezoid tz(name, "Trapezoid", b1, b2, h);
            tz.Show();
            cout << "Area: " << tz.GetArea() << endl;
            //tz.Draw();
        }
        else if (choice == 0) 
        {
            cout << "Goodbye!" << endl;
        }
        else 
        {
            cout << "Invalid choice! Please try again!" << endl;
        }

    } while (choice != 0);
}





int main() 
{
    
    Menu();
    
}
