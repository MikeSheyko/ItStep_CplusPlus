#include "Point.h"


void Point::Print() const
{
    cout << "(" << _x << ", " << _y << ")";
}


Point Point::operator +(const Point& other) const 
{
    return Point(_x + other._x, _y + other._y);
}

Point Point::operator -(const Point& other) const 
{
    return Point(_x - other._x, _y - other._y);
}

bool Point::operator <(const Point& other) const
{
    return (_x * _x + _y * _y) < (other._x * other._x + other._y * other._y);
}

bool Point::operator >(const Point& other) const 
{
    return (_x * _x + _y * _y) > (other._x * other._x + other._y * other._y);
}



Point Point::operator !() const
{
    return Point(-_x, -_y);
}
