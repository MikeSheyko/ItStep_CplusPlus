#include <iostream>
using namespace std;

class Point
{
	int x;
	int y;
public:
	Point() :x(0), y(0) {}
	Point(int value) :x(value), y(value) {}
	Point(int x, int y) :x(x), y(y) {}
	void Print()
	{
		cout << "X : " << x << ". Y : " << y << endl;
	}
	Point Plus(const Point& other)const
	{
		Point res(this->x + other.x, this->y + other.y);
		return res;
	}
	Point Minus(const Point& other)const
	{
		Point res(this->x - other.x, this->y - other.y);
		return res;
	}
	//void operator [type]() const {}
	Point operator +(const Point& other) const
	{
		Point res(this->x + other.x, this->y + other.y);
		return res;
	}
	Point operator -(const Point& other) const
	{
		Point res(this->x - other.x, this->y - other.y);
		return res;
	}
	Point operator *(const Point& other) const
	{
		Point res(this->x * other.x, this->y * other.y);
		return res;
	}
	Point operator /(const Point& other) const
	{
		Point res(this->x / other.x, this->y / other.y);
		return res;
	}
	Point operator +(int value) const
	{
		Point res(this->x + value, this->y + value);
		return res;
	}

	Point operator += (const Point& other)
	{
		// int a  = 5;
		//a += 4;
		//a = a + 4;
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	Point operator -()const
	{
		return Point(-this->x, -this->y);
	}
	Point operator =(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		return *this;
	}
	bool operator < (const Point& other)
	{
		/*	if ((this->x + this->y) < (other.x + other.y))
				return true;
			else
				return false;*/
		return ((this->x + this->y) < (other.x + other.y));
	}
	bool operator > (const Point& other)
	{
		return ((this->x + this->y) > (other.x + other.y));
	}
	bool operator <= (const Point& other)
	{

		return ((this->x + this->y) <= (other.x + other.y));
	}
	bool operator >= (const Point& other)
	{
		return ((this->x + this->y) >= (other.x + other.y));
	}
	bool operator == (const Point& other)
	{
		return ((this->x == other.x) && (this->y == other.y));
	}
	bool operator != (const Point& other)
	{
		//return ((this->x != other.x)|| (this->y != other.y));
		return !(*this == other);
	}

};

int main()
{
	// ++ -- - + ! uno operators
	//binary operators = + - *  / % > < >= <=
	Point p1(2, 7);
	Point p2(1, 4);
	cout << "Point p1 : "; p1.Print();
	cout << "Point p2 : "; p2.Print();
	Point res;
	res = p1.Plus(p2);
	res.Print();
	res = p1.Minus(p2);
	res.Print();

	res = p1 + p2;//res = p1.operator+(p2);
	res.Print();

	res = p1 - p2;//res = p1.operator-(p2);
	res.Print();

	res = p1 * p2;//res = p1.operator*(p2);
	res.Print();

	res = p1 / p2;//res = p1.operator/(p2);
	res.Print();

	res = p1 + 100;
	res.Print();

	p1 += p2;
	cout << "Point p1 : "; p1.Print();
	cout << "Point p2 : "; p2.Print();
	cout << "--------------- operator -  -----------------" << endl;
	res = -p1;
	res.Print();
	cout << "Point p1 : "; p1.Print();
	cout << "Point p2 : "; p2.Print();

	cout << "--------------- operator =  -----------------" << endl;
	p1 = p2;
	cout << "Point p1 : "; p1.Print();
	cout << "Point p2 : "; p2.Print();
	cout << "--------------- operator <  -----------------" << endl;
	if (p1 < p2)
	{
		cout << "p1 < p2" << endl;
	}
	else
	{
		cout << "p1> p2" << endl;

	}

	if (p1 == p2)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;

	}
	//int a = 5, b = 7;
	//cout << a + b << endl;
	//cout << a - b << endl;
	//cout << a * b << endl;
	//cout << p1 + p2 << endl;
	//cout << p1 - p2<< endl;
	//cout << p1 * p2<< endl;

}