#include <iostream>
#include <iomanip>
using namespace std;


class Time 
{
private:
    int _hours;
    int _minutes;
    int _seconds;
        
    void editTime() 
    {
        int totalSeconds = _hours * 3600 + _minutes * 60 + _seconds;
        _hours = totalSeconds / 3600;
        _minutes = (totalSeconds % 3600) / 60;
        _seconds = totalSeconds % 60;
    }

    int toTotalSeconds() const 
    {
        return _hours * 3600 + _minutes * 60 + _seconds;
    }

public:
    Time() : _hours(0), _minutes(0), _seconds(0) {}
    Time(int h, int m, int s) : _hours(h), _minutes(m), _seconds(s) {editTime();}
    explicit Time(int totalSeconds) : Time(0, 0, totalSeconds) {}

    void print() const 
    {
        cout << setfill('0') << setw(2) << _hours << ":" << setfill('0') << setw(2) << _minutes << ":" << setfill('0') << setw(2) << _seconds << endl;
    }
    
    Time operator ++(int) 
    {
        Time temp = *this;  
        _seconds++;
        editTime();
        return temp;
    }

    Time operator +(const Time& other) const 
    {
        return Time(toTotalSeconds() + other.toTotalSeconds());
    }

    Time operator -(const Time& other) const 
    {
        return Time(toTotalSeconds() - other.toTotalSeconds());
    }

    Time operator *(int multiplier) const 
    {
        return Time(toTotalSeconds() * multiplier);
    }

    Time operator /(int divisor) const 
    {
        if (divisor == 0) 
        {
            cerr << "Error! Division by zero!" << endl;
            return Time(0);
        }
        return Time(toTotalSeconds() / divisor);
    }

    bool operator >(const Time& other) const 
    {
        return toTotalSeconds() > other.toTotalSeconds();
    }

    bool operator <(const Time& other) const 
    {
        return toTotalSeconds() < other.toTotalSeconds();
    }

    bool operator >=(const Time& other) const 
    {
        return toTotalSeconds() >= other.toTotalSeconds();
    }

    bool operator <=(const Time& other) const 
    {
        return toTotalSeconds() <= other.toTotalSeconds();
    }

    bool operator ==(const Time& other) const 
    {
        return toTotalSeconds() == other.toTotalSeconds();
    }

    bool operator!=(const Time& other) const 
    {
        return !(*this == other);
    }



};




int main()
{
    Time t1;
    Time t2(1, 59, 59);
    Time t3(5555);
    Time t4(-1, 41, 45);


    cout << "Time 1: ";
    t1.print();

    cout << "Time 2: ";
    t2.print();

    t2++;
    cout << "Time 2 + 1sec: ";
    t2.print();

    cout << "Time 3: ";
    t3.print();

    t3++;
    cout << "Time 3 + 1sec: ";
    t3.print();

    Time sum = t2 + t3;
    cout << "Sum t2 + t3: ";
    sum.print();

    Time diff = t2 - t3;
    cout << "Difference t2 - t3: ";
    diff.print();

    Time multiplied = t3 * 2;
    cout << "t3 * 2: ";
    multiplied.print();

    Time divided = t3 / 2;
    cout << "t3 / 2: ";
    divided.print();

    cout << "t2 > t3: " << ((t2 > t3) ? "True" : "False") << endl;
    cout << "t2 == t3: " << ((t2 == t3) ? "True" : "False") << endl;
    cout << "t2 != t3: " << ((t2 != t3) ? "True" : "False") << endl;

}

