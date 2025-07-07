#include <iostream>
#include <windows.h>
using namespace std;

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

class Date 
{
private:
    int day, month, year;

    bool isLeapYear(int y) const 
    {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int daysInMonth(int m, int y) const 
    {
        static const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if (m == 2 && isLeapYear(y)) return 29;
        return days[m - 1];
    }

    void normalize() 
    {
        while (day > daysInMonth(month, year)) 
        {
            day -= daysInMonth(month, year);
            month++;
            if (month > 12) 
            {
                month = 1;
                year++;
            }
        }
        while (day <= 0) 
        {
            month--;
            if (month <= 0) 
            {
                month = 12;
                year--;
            }
            day += daysInMonth(month, year);
        }

        while (month > 12) 
        {
            month -= 12;
            year++;
        }

        while (month <= 0) 
        {
            month += 12;
            year--;
        }
    }

public:
    Date(int d = 1, int m = 1, int y = 2010) : day(d), month(m), year(y) 
    {
        normalize();
    }

    void display() const 
    {
        cout << (day < 10 ? "0" : "") << day << "."
            << (month < 10 ? "0" : "") << month << "."
            << year << endl;
    }

    Date& operator+=(int daysToAdd) 
    {
        day += daysToAdd;
        normalize();
        return *this;
    }

    Date& operator-=(int daysToSub) 
    {
        day -= daysToSub;
        normalize();
        return *this;
    }

    void operator() (int d) 
    {
        *this += d;
    }

    void operator() (int m, int d) 
    {
        month += m;
        day += d;
        normalize();
    }

    void operator() (int y, int m, int d) 
    {
        year += y;
        month += m;
        day += d;
        normalize();
    }

    friend ostream& operator<< (ostream& out, const Date& d);
    friend istream& operator>> (istream& in, Date& d);
    friend bool operator== (const Date& a, const Date& b);
    friend bool operator!= (const Date& a, const Date& b);
    friend bool operator< (const Date& a, const Date& b);
    friend bool operator> (const Date& a, const Date& b);
    friend Date& operator++ (Date& d);
    friend Date operator++ (Date& d, int);
    friend Date& operator-- (Date& d);
    friend Date operator-- (Date& d, int);
};


ostream& operator<<(ostream& out, const Date& d) 
{
    out << (d.day < 10 ? "0" : "") << d.day << "."
        << (d.month < 10 ? "0" : "") << d.month << "."
        << d.year;
    return out;
}


istream& operator>> (istream& in, Date& d) 
{
    int dd, mm, yy;
    cout << "Enter day, month and year (e.g. 01 01 2010) : ";
    in >> dd >> mm >> yy;

    if (dd < 1 || mm < 1 || mm > 12 || yy < 0) 
    {
        cerr << "Invalid date! Default date setted to 01.01.2010" << endl;
        d = Date(1, 1, 2010);
    }
    else 
    {
        d = Date(dd, mm, yy);
    }

    return in;
}


bool operator== (const Date& a, const Date& b) 
{
    return a.day == b.day && a.month == b.month && a.year == b.year;
}

bool operator!= (const Date& a, const Date& b) 
{
    return !(a == b);
}

bool operator< (const Date& a, const Date& b) 
{
    if (a.year != b.year) return a.year < b.year;
    if (a.month != b.month) return a.month < b.month;
    return a.day < b.day;
}

bool operator> (const Date& a, const Date& b) 
{
    return b < a;
}


Date& operator++ (Date& d) 
{
    d.day += 1;
    d.normalize();
    return d;
}

Date operator++ (Date& d, int) 
{
    Date temp = d;
    ++d;
    return temp;
}

Date& operator-- (Date& d) 
{
    d.day -= 1;
    d.normalize();
    return d;
}

Date operator-- (Date& d, int) 
{
    Date temp = d;
    --d;
    return temp;
}



int main() 
{
    setColor(11);
    cout << "======= Test Date Class =======" << endl;

    Date d1(07, 07, 2025);
    setColor(14);
    cout << "\nInitial date: " << d1 << endl;

    setColor(10);
    cout << "++d1: " << ++d1 << endl;
    cout << "d1++: " << d1++ << " → now: " << d1 << endl;

    setColor(12);
    cout << "--d1: " << --d1 << endl;
    cout << "d1--: " << d1-- << " → now: " << d1 << endl;

    setColor(13);
    d1 += 40;
    cout << "d1 += 40: " << d1 << endl;

    d1 -= 70;
    cout << "d1 -= 70: " << d1 << endl;

    setColor(9);
    d1(5);
    cout << "d1(5): " << d1 << endl;

    d1(2, 10);
    cout << "d1(2, 10): " << d1 << endl;

    d1(1, 2, 3);
    cout << "d1(1, 2, 3): " << d1 << endl;

    setColor(14);
    Date d2(1, 1, 2025);
    cout << "\nd2: " << d2 << endl;

    setColor(6);
    cout << "d1 == d2 ? " << (d1 == d2 ? "Yes" : "No") << endl;
    cout << "d1 != d2 ? " << (d1 != d2 ? "Yes" : "No") << endl;
    cout << "d1 > d2 ?  " << (d1 > d2 ? "Yes" : "No") << endl;
    cout << "d1 < d2 ?  " << (d1 < d2 ? "Yes" : "No") << endl;

    setColor(3);
    cout << "\n>>> Enter date from keyboard:\n";
    Date userDate;
    cin >> userDate;
    cout << "You entered: " << userDate << endl;

    setColor(7);
    
    cout << "\n======= End of Test =======" << endl;




}
