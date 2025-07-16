#pragma once
#include "Point.h"


class Vector 
{
private:
    Point* points;
    int countPoint;

public:
    Vector();
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;
    ~Vector();
    void Add(const Point& p);
    void Print() const;
};
