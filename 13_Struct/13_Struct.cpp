#include <iostream>
#include <windows.h>
using namespace std;
void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// int float double char short
//User id login password email

struct User
{
	int id;
	char login[50];
	char password[50];
	char email[50];
};

struct Date
{
	int day;
	int month;
	int year;
	char day_name[15];
	char day_month[15];
};

struct Worker {
	char name[50];
	char surname[50];
	int age;
	int salary;
	Date birthday;
	Date hiredate;
};

void Input(Worker & w)
{
	cout << "Enter name : "; cin >> w.name;
	cout << "Enter surname : "; cin >> w.surname;
	cout << "Enter Age : "; cin >> w.age;
	cout << "Enter salary : "; cin >> w.salary;
	cout << "Enter Birthday day : "; cin >> w.birthday.day;
	cout << "Enter Birthday month : "; cin >> w.birthday.month;
	cout << "Enter Birthday year : "; cin >> w.birthday.year;
	cout << "Enter Hiredate day : "; cin >> w.hiredate.day;
	cout << "Enter Hiredate month : "; cin >> w.hiredate.month;
	cout << "Enter Hiredate year : "; cin >> w.hiredate.year;
}

void Show(Worker w)
{
	cout << "Name : " << w.name << endl;
	cout << "Surname : " << w.surname << endl;
	cout << "Age : " << w.age << endl;
	cout << "Salary : " << w.salary << endl;
	cout << "Birthday : " << w.birthday.day << "/" << w.birthday.month << "/" << w.birthday.year << endl;;
	cout << "Hiredate : " << w.hiredate.day << "/" << w.hiredate.month << "/" << w.hiredate.year << endl;;
}




int main()
{
	Date date = {11, 05, 2025, "Sunday", "May"};

	cout << "------------- Day today : ------------------" << endl;
	cout << "Day : " << date.day << endl;
	cout << "Month : " << date.month << endl;
	cout << "Year : " << date.year << endl;
	cout << "Day name : " << date.day_name << endl;
	cout << "Month name : " << date.day_month << endl;
	


	Date birthday;
	cout << "Enter your birthday day : ";
	cout << "Enter day : "; cin >> birthday.day;
	cout << "Enter month : "; cin >> birthday.month;
	cout << "Enter year : "; cin >> birthday.year;
	cout << "Enter name of day : "; cin >> birthday.day_name;
	cout << "Enter name of month : "; cin >> birthday.day_month;
	cout << "------------- Birthday Day  : ------------------" << endl;
	cout << "Day : " << birthday.day << endl;
	cout << "Month : " << birthday.month << endl;
	cout << "Year : " << birthday.year << endl;
	cout << "Day name : " << birthday.day_name << endl;
	cout << "Month name : " << birthday.day_month << endl;


	Worker Nick = { "Nick","Tomson",22,30000,{25,12,2000},{11,5,2020} };
	Show(Nick);
	Input(Nick);
	Show(Nick);






}

