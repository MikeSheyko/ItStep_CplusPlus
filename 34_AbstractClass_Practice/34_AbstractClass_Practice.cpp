#include <iostream>
using namespace std;


class Shape 
{
protected:
    string name;
    string type;
public:
    Shape() : name("no name"), type("no name") {}
    Shape(string n, string t) : name(n), type(t) {}

    virtual void Show() const 
    {
        cout << "Name : " << name << endl;
        cout << "Type : " << type << endl;
    }

    virtual double GetArea() const = 0;
};


class Rectangle : public Shape 
{
    double width;
    double height;
public:
    Rectangle() : width(0), height(0), Shape() {}
    Rectangle(string n, string t, double w, double h) : width(w), height(h), Shape(n,t) {}

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
};


class Triangle : public RightTriangle 
{

public:
    Triangle() : RightTriangle() {}
    Triangle(string n, string t, double b, double h) : RightTriangle(n,t,b,h) {}

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
        cout << "Base 1 : " << base1 << endl;
        cout << "Base 2 : " << base2 << endl;
        cout << "Height : " << height << endl;
    }

    double GetArea() const override 
    {
        return 0.5 * (base1 + base2) * height;
    }
};


void TestShape(const Shape& s)
{
    s.Show();
    cout << "Area : " << s.GetArea() << endl;
    cout << "----------------------------" << endl;
};




int main()
{
    Rectangle rectangle("MyRectangle", "Rectangle", 4, 5);
    Circle circle("MyCircle", "Circle", 3);
    RightTriangle rightTriangle("MyRightTriangle", "RightTriangle", 3, 4);
    Triangle triangle("MyTriangle", "Triangle", 5, 4);
    Trapezoid trapezoid("MyTrapezoid", "Trapezoid", 6, 10, 5);

	rectangle.Show();
    cout << "Area of Rectangle: " << rectangle.GetArea() << endl;
    cout << "-------------------------------" << endl;

    circle.Show();
    cout << "Area of Circle: " << circle.GetArea() << endl;
    cout << "-------------------------------" << endl;

    rightTriangle.Show();
    cout << "Area of Right Triangle: " << rightTriangle.GetArea() << endl;
    cout << "-------------------------------" << endl;

    triangle.Show();
    cout << "Area of Triangle: " << triangle.GetArea() << endl;
    cout << "-------------------------------" << endl;

    trapezoid.Show();
    cout << "Area of Trapezoid: " << trapezoid.GetArea() << endl;
    cout << "-------------------------------" << endl;

    cout << endl;
	cout << "Testing with TestShape function:" << endl;
    cout << endl;
    TestShape(rectangle);
    TestShape(circle);
    TestShape(rightTriangle);
    TestShape(triangle);
    TestShape(trapezoid);


};
