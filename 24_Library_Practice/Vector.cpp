#include "Vector.h"


Vector::Vector() : points(nullptr), countPoint(0) {}

Vector::Vector(const Vector& other) : countPoint(other.countPoint)
{
    points = new Point[countPoint];
    for (int i = 0; i < countPoint; ++i)
    {
        points[i] = other.points[i];
    } 
}

Vector::Vector(Vector&& other) noexcept : points(other.points), countPoint(other.countPoint)
{
    other.points = nullptr;
    other.countPoint = 0;
}

Vector& Vector::operator= (const Vector& other) 
{
    if (this != &other) 
    {
        delete[] points;
        countPoint = other.countPoint;
        points = new Point[countPoint];
        for (int i = 0; i < countPoint; ++i)
        {
            points[i] = other.points[i];
        }
            
    }
    return *this;
}

Vector& Vector::operator= (Vector&& other) noexcept 
{
    if (this != &other) 
    {
        delete[] points;
        points = other.points;
        countPoint = other.countPoint;
        other.points = nullptr;
        other.countPoint = 0;
    }
    return *this;
}

Vector::~Vector() 
{
    delete[] points;
}

void Vector::Add(const Point& p) 
{
    Point* newPoints = new Point[countPoint + 1];
    for (int i = 0; i < countPoint; ++i)
    {
        newPoints[i] = points[i];
    }
    newPoints[countPoint] = p;
    delete[] points;
    points = newPoints;
    ++countPoint;
}

void Vector::Print() const 
{
    for (int i = 0; i < countPoint; ++i) 
    {
        cout << "Point " << i + 1 << ": ";
        points[i].Print();
        cout << endl;
    }
}
