

#include <iostream>
using namespace std;
class Date
{
    int day;
    int month;
    int year;
    const int baseYear;
public:
    Date() :day(0), month(0), year(0), baseYear(1991) {}

    Date(int day, int month, int year, int base) :
        baseYear(base), day(day), month(month),
        year(year) {
    }
    void setDay(int newDay)
    {
        day = newDay;
    }
    int getDay()
    {
        return day++;
    }
    int getDay()const
    {

        return day;
    }
    void Print()const
    {
        cout << day << " / " << month << " / " << year << endl;
        cout << "Base Year : " << baseYear << endl;
    }
};

class Account
{
private:
    double sum;
    const double rate;
public:
    Account(double Rate, double Sum) :rate(Rate)
    {
        //rate = Rate; //error
        sum = Sum;
    }
    double getRate() const
    {
        return rate;
    }
    double getIncome()
    {
        return sum * rate / 100;
    }
    double getIncome() const
    {
        return sum * rate / 100;
    }
    double getSum()const
    {
        return sum;
    }
    double setSum()
    {
        sum += getIncome();
        return sum;
    }
};
int main()
{
    Account account(5, 2000);
    const Account account2(8, 5000);

    cout << "Rate : " << account.getRate() << endl;
    cout << "Rate : " << account2.getRate() << endl;

    cout << "Rate : " << account.getSum() << endl;
    cout << "Rate : " << account2.getSum() << endl;

    cout << "Rate : " << account.getIncome() << endl;
    cout << "Rate : " << account2.getIncome() << endl;

    cout << "Rate : " << account.setSum() << endl;
    //cout<< "Rate : "<< account2.setSum() << endl;//error
    /*
    const int a = 10;

    Date d;//default
    const int size = 10;
    const string str{ "hello" };
    const int days[] = { 31,31,28 };
   // days[2] = 29;
    int independencyYear;
    cout << "Enter independency year : ";
    cin >> independencyYear;
    Date eventDate = { 21,7,2025,independencyYear };
    eventDate.Print();
    cout << "Day : " << eventDate.getDay() << endl;
    eventDate.setDay(20);
    cout << "Day : " << eventDate.getDay() << endl;

    const Date independenceDay = { 24,8,2025 ,1991};
    independenceDay.Print();
    cout << "Day : " << independenceDay.getDay() << endl;
    //independenceDay.setDay(12);
    cout << "Day : " << independenceDay.getDay() << endl;
    */
}
