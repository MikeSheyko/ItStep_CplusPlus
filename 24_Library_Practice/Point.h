#pragma once

#include <iostream>

using namespace std;





class Point
{
private:
	int _x, _y;
public:
    Point(int x = 0, int y = 0) : _x(x), _y(y) {}

    	
    void Print() const;

    
    Point operator +(const Point& other) const;

    
    Point operator -(const Point& other) const;

    
    bool operator <(const Point& other) const;


    bool operator >(const Point& other) const;


    
    Point operator!() const;


};

