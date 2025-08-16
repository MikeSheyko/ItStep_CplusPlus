#include <iostream>
using namespace std;


class Enemy
{
protected:
	string name;
	int health;
	float strength;
	int speed;
	const static int maxHealth = 100;
public:
	Enemy() : name("no name"), health(maxHealth), strength(0), speed(0) {}
	Enemy(string n, float s, int sp) :name(n), health(maxHealth), strength(s), speed(sp) {}
	void Print()const
	{
		cout << "Name : " << name << endl;
		cout << "Health : " << health << endl;
		cout << "Strength : " << strength << endl;
		cout << "Speed : " << speed << endl;
	}
	void DecreaseHealth(int value)
	{
		if (health - value < 0)
			health = 0;
		else
			health -= value;
	}
	bool IsAlive()const
	{
		return health > 0;
	}
};
//Inheritance 
//class Child : [spetificator] Parent
//[spetificator] - private, public , protected
class Dragon : public Enemy
{
	float armor;
public:
	Dragon() :armor(0), Enemy() {}
	Dragon(string n, float s, float sp, float a) :armor(a), Enemy(n, s, sp) {}
	float Attack()
	{
		cout << "Attacking with strength " << strength << endl;
		return strength;
	}
	void Kick(int damage)
	{
		cout << "Getting damage " << damage << endl;
		DecreaseHealth(damage - armor);
		cout << "Health after kick : " << health << "%" << endl;
	}
	void Print()
	{
		cout << "------------------ Dragon----------------" << endl;
		Enemy::Print();
		cout << "Armor : " << armor << endl;
	}
};

class Monster : Enemy
{
private:
	float turboSpeed;
public:
	Monster() :turboSpeed(0), Enemy() {}
	Monster(string n, float s, int sp, float r) :turboSpeed(r), Enemy(n, s, sp) {}
	void Print()
	{
		cout << "------------------ Monster----------------" << endl;
		Enemy::Print();
		cout << "Run speed : " << turboSpeed << endl;
	}
	void Run()
	{
		cout << "I am running with speed : " << turboSpeed << "km/h" << endl;
	}
};


//Practice
//Task 1
class Student 
{
protected:
	string studentName;
	string studentUniversity;
	int course;
	float averageMark;

public:
	Student() : studentName("No name"), studentUniversity("No university"), course(0), averageMark(0.0) {}

	Student(string n, string u, int c, float m): studentName(n), studentUniversity(u), course(c), averageMark(m) {}

	void Print() const 
	{
		cout << "Student : " << studentName << endl;
		cout << "University : " << studentUniversity << endl;
		cout << "Course : " << course << endl;
		cout << "Average Mark : " << averageMark << endl;
	}
};

class Aspirant : public Student 
{
private:
	string workTitle;
	string aspirantSupervisor;

public:
	Aspirant() : workTitle("No title"), aspirantSupervisor("No supervisor") {}

	Aspirant(string n, string u, int c, float m, string t, string sup): Student(n, u, c, m), workTitle(t), aspirantSupervisor(sup) {}

	void Print() const 
	{
		cout << "--------------- Aspirant Info ---------------" << endl;
		Student::Print();
		cout << "Thesis Title: " << workTitle << endl;
		cout << "Supervisor: " << aspirantSupervisor << endl;
	}
};


// Task 2
class Passport 
{
protected:
	string fullName;
	string dateOfBirth;
	string passportNumber;
	string placeOfBirth;
	
public:
	Passport() : fullName("No name"), dateOfBirth("No date"), passportNumber("No number"), placeOfBirth("No place") {}

	Passport(string n, string d, string num, string p) : fullName(n), dateOfBirth(d), passportNumber(num), placeOfBirth(p) {}

	void Print() const 
	{
		cout << "Full Name : " << fullName << endl;
		cout << "Date of Birth : " << dateOfBirth << endl;
		cout << "Passport Number : " << passportNumber << endl;
		cout << "Place of Birth : " << placeOfBirth << endl;
	}
};

class ForeignPassport : public Passport 
{
private:
	string foreignPassportNumber;
	string* visas;
	int visaCount;
	int visaCapacity;

public:
	ForeignPassport() : foreignPassportNumber("No number"), visas(nullptr), visaCount(0), visaCapacity(0) {}

	ForeignPassport(string name, string dob, string number, string place, string foreignNumber) : Passport(name, dob, number, place), foreignPassportNumber(foreignNumber), visaCount(0), visaCapacity(2)
	{
		visas = new string[visaCapacity];
	}

	~ForeignPassport() 
	{
		delete[] visas;
	}

	void AddVisa(const string& visa) 
	{
		if (visaCount >= visaCapacity) 
		{
			int newCapacity = visaCapacity * 2;
			if (newCapacity == 0) newCapacity = 2;

			string* newVisas = new string[newCapacity];

			for (int i = 0; i < visaCount; ++i) 
			{
				newVisas[i] = visas[i];
			}

			delete[] visas;
			visas = newVisas;
			visaCapacity = newCapacity;
		}

		visas[visaCount++] = visa;
	}

	void Print() const 
	{
		cout << "--------------- Foreign Passport Info ---------------" << endl;
		Passport::Print();
		cout << "Foreign Passport Number : " << foreignPassportNumber << endl;
		cout << "Visas : ";
		if (visaCount == 0) 
		{
			cout << "No visas" << endl;
		}
		else 
		{
			cout << endl;
			for (int i = 0; i < visaCount; ++i) 
			{
				cout << " - " << visas[i] << endl;
			}
		}
	}
};




int main()
{

	Enemy e;
	Dragon bob("Bob", 10, 35, 3); bob.Print();
	Dragon boss("Boss", 14, 50, 5); boss.Print();

	int i = 1;
	do
	{
		cout << "------------------ Round [ " << i << " ] ----------------------" << endl;
		boss.Kick(bob.Attack());
		bob.Kick(boss.Attack());

		boss.Print();
		bob.Print();
		i++;
	} while (bob.IsAlive() && boss.IsAlive());

	Monster m("Tom", 1, 15, 150);
	m.Print();
	m.Run();


	//Task 1
	cout << endl;
	Aspirant a("Mykhaylo Shevchenko", "Harvard", 2, 4.5, "AI", "Dr. William Smith");
	a.Print();

	cout << endl;

	//Task 2
	ForeignPassport fp("Mykhaylo Shevchenko", "01.01.1990", "AB134596", "Rivne", "FL159874");
	fp.Print();

	
	fp.AddVisa("Canada");
	fp.AddVisa("USA");
	fp.AddVisa("Schengen");
	
	cout << endl;

	fp.Print();

}

