#include <iostream>
using namespace std;

struct PIB 
{
	string name;
	string lastname;
	string surname;
};
struct Date 
{
	int day;
	int month;
	int year;
};

class Student 
{
private:
	PIB fullname;
	Date birthday;
	string phone;
	string city;
	string country;
	string studentUniversity;
	string city_university;
	string country_university;
	string group;
	int* marks;
	int CountMark;
	float averageMark;
public:
	//ctor + tab
	//default constructor - Побудувати пустий об'єкт з пустими змінними
	Student() 
	{
		cout << "Constructor called!" << endl;
		fullname.name = "no name";
		fullname.lastname = "no lastname";
		fullname.surname = "no surname";
		birthday.day = 0;
		birthday.month = 0;
		birthday.year = 0;
		phone = "no phone";
		city = "no city";
		country = "no country";
		studentUniversity = "no university";
		city_university = "no city_university";
		country_university = "no country_university";
		group = "no group";
		marks = nullptr;
		CountMark = 0;
		averageMark = 0.0;
	}
	Student(string n, string l, string s)
	{
		cout << "Parametrilaxed constructor" << endl;
		fullname.name = n;
		fullname.lastname = l;
		fullname.surname = s;
		birthday.day = 0;
		birthday.month = 0;
		birthday.year = 0;
		phone = "no phone";
		city = "no city";
		country = "no country";
		studentUniversity = "no university";
		city_university = "no city_university";
		country_university = "no country_university";
		group = "no group";
		marks = nullptr;
		CountMark = 0;
		averageMark = 0.0;
	}
	Student(string n, string l, string s, Date date)
	{
		cout << "Parametrilaxed constructor" << endl;
		fullname.name = n;
		fullname.lastname = l;
		fullname.surname = s;
		birthday.day = date.day;
		birthday.month = date.month;
		birthday.year = date.year;
		phone = "no phone";
		city = "no city";
		country = "no country";
		studentUniversity = "no university";
		city_university = "no city_university";
		country_university = "no country_university";
		group = "no group";
		marks = nullptr;
		CountMark = 0;
		averageMark = 0;
	}
	Student(string n, string l, string s, Date date, string p, string city, string country, string u,
		string ci_u, string country_u, string g)
	{
		cout << "Parametrilaxed constructor" << endl;
		this->fullname.name = n;
		this->fullname.lastname = l;
		this->fullname.surname = s;
		this->birthday.day = date.day;
		this->birthday.month = date.month;
		this->birthday.year = date.year;
		this->phone = p;
		this->city = city;
		this->country = country;
		this->studentUniversity = u;
		this->city_university = ci_u;
		this->country_university = country_u;
		this->group = g;
		this->marks = nullptr;
		this->CountMark = 0;
		this->averageMark = 0;

	}


	void setName(string namename)
	{
		fullname.name = namename;
	};
	void setLastname(string lastname)
	{
		fullname.lastname = lastname;
	};
	void setSurname(string surname)
	{
		fullname.surname = surname;
	};
	void setDate(Date date)
	{
		birthday.day = date.day;
		birthday.month = date.month;
		birthday.year = date.year;
		/*birthdate = date;*/

	};
	void SetAverageMark()
	{
		float summa = 0;
		for (int i = 0; i < CountMark; i++)
		{
			summa += marks[i];
		}
		averageMark = (float) summa / CountMark;
	};
	void AddMark(int mark)
	{
		CountMark++;
		int* temp = new int[CountMark];
		for (int i = 0; i < CountMark - 1; i++)
		{
			temp[i] = marks[i];
		}
		temp[CountMark - 1] = mark;
		delete[] marks;
		marks = temp;
		SetAverageMark();
	}
	void Delete()
	{
		if (marks != nullptr)
		{
			delete[]marks;
		}
	}
	void Initialize()
	{
		fullname.name = "no name";
		fullname.lastname = "no lastname";
		fullname.surname = "no surname";
		birthday.day = 0;
		birthday.month = 0;
		birthday.year = 0;
		phone = "no phone";
		city = "no city";
		country = "no country";
		studentUniversity = "no university";
		city_university = "no city_university";
		country_university = "no country_university";
		group = "no group";
		marks = nullptr;
		CountMark = 0;
		averageMark = 0.0;
	}
	void Print()
	{
		cout << "Full name : " << fullname.name << " "
			<< fullname.lastname << " " << fullname.surname << endl;
		cout << "Birthday : " << birthday.day << "." 
			<< birthday.month << "." << birthday.year << endl;
				cout << "Phone : " << phone << endl;
		cout << "City : " << city << endl;
		cout << "Country : " << country << endl;
		cout << "University : " << studentUniversity << endl;
		cout << "City University : " << city_university << endl;
		cout << "Country University : " << country_university << endl;
		cout << "Group : " << group << endl;
		cout << "Marks : ";
		for (int i = 0; i < CountMark; i++)
		{
			cout << marks[i] << " ";
		};
		cout << endl;
		cout << "Average Mark : " << averageMark << endl;

	}

	~Student()
	{
		cout << "Destructor " << fullname.name << endl;
		if (marks != nullptr)
		{
			delete[]marks;
		}
	}

};



int main()
{
	Student student; //default constructor
	/*student.Initialize();*/
	student.setName("Olga");
	student.setLastname("Mukolaivna");
	student.setSurname("Ivanchuk");
	student.setDate({ 15, 12, 2000 });
	student.AddMark(12);
	student.AddMark(7);
	student.AddMark(8);
	student.AddMark(10);
	student.Print();


	cout << "----------------------------" << endl;
	Student st1("Mukola", "Olegovich", "Popchuk");
	st1.AddMark(11);
	st1.AddMark(10);
	st1.AddMark(10);
	st1.Print();
	

	cout << "----------------------------" << endl;
	Student  st2("Ira", "Mukoluk", "Petrovich", { 1,1,1995 });//parametrized constructor
	st2.Print();

	cout << "----------------------------" << endl;
	Student  st3("Oleg", "Petrovich", "Ilchuk", { 1,1,2001 },
		"+380961478965", "Rivne", "Ukraine", "NYVGP", "Rivne", "Ukraine", "PD111");
	st3.Print();


	cout << "------------ Copy student----------------" << endl;
	Student copy(st2); //copy constructor
	copy.Print();



	
	student.Delete();
	st1.Delete();
	st2.Delete();
	st3.Delete();

	 

}
