#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*

void PrintPlayer(Player & pl)
{	
	cout << "Name : " << pl.name << endl;
	cout << "Age : " << pl.age << endl;
	cout << "Games : " << pl.games << endl;
	cout << "Goals : " << pl.goals << endl << endl;
	cout << endl;
}

void InitPlayer(Player& pl)
{
	cout << "Enter name : "; cin >> pl.name;
	cout << "Enter age : "; cin >> pl.age;
	pl.games = 0;
	pl.goals = 0;
}

void AddGameToPlayer(Player& pl, int goals = 0)
{
	pl.games++;
	pl.goals += goals;
}
*/

//struct Player
//{
//	//public
//	string name;
//	short age;
//	int games;
//	int goals;
//};


class Player
{
private:
	string name;
	short age;
	int games;
	int goals;
public:
	void PrintPlayer()
	{
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Games : " << games << endl;
		cout << "Goals : " << goals << endl << endl;
		cout << endl;
	}

	void InitPlayer()
	{
		cout << "Enter name : "; cin >> name;
		cout << "Enter age : "; cin >> age;
		games = 0;
		goals = 0;
	}

	void AddGameToPlayer(int goals = 0)
	{
		games++;
		this->goals += goals;
		//goals += Goals;
	}
};



class Student
{
private:
	// data members. змінні-члени класу.
	string name;
	int marks[3];
public:
	//member function. функції-члени класу, методи
	float getAverage()
	{
		float sum = 0;
		for (int i = 0; i < 3; i++)
		{
			sum += marks[i];
		}
		return sum / 3.0;
	}
	//set(мутатори)
	void setName(string name) //Name)
	{
		this->name = name; //Name;
	}
	void setMark(int mark, int index)
	{
		if (mark < 1 || mark > 12)
			mark = 0;
		marks[index] = mark;
	}
	//get (аксесори)
	string getName()
	{
		return name;
	}
	int getMark(int index)
	{
		return marks[index];
	}
};

//Practice 
class Point 
{
private:
	int x, y, z;

public:
	const char* FILENAME = "E:\\ItStep\\Practice.txt";
	void InputFromKeyBoard()
	{
		cout << "Enter coordinates 'x', 'y', 'z' : " << endl; cin >> x >> y >> z;
	}

	void print()
	{
		cout << "X = " << x << ", Y = " << y << ", Z = " << z << endl;
	}

	void setX(int x) 
	{ 
		this->x = x; 
	}
	void setY(int y) 
	{ 
		this->y = y; 
	}
	void setZ(int z) 
	{ 
		this->z = z; 
	}

	int getX() 
	{ 
		return x; 
	}
	int getY() 
	{ 
		return y; 
	}
	int getZ() 
	{ 
		return z; 
	}

	void SaveToFile() {
		ofstream fileOut(FILENAME);
		if (fileOut.is_open()) 
		{
			fileOut << x << " " << y << " " << z << endl;
			fileOut.close();
		}
	}
	void LoadFromFile() 
	{
		ifstream fileIn(FILENAME);
		if (fileIn.is_open()) 
		{
			fileIn >> x >> y >> z;
			fileIn.close();
		}
	}
};





int main()
{
	int a;

	//Student st1; //object 
	//st1.name = "Mukola";
	//st1.marks[0] = 12;
	//st1.marks[1] = 10;
	//st1.marks[2] = 11;

	//cout << "Student name: " << st1.name << endl;
	
	Student st; //object 
	st.setName("Mukola");
	st.setMark(12, 0);
	st.setMark(10, 1);
	st.setMark(11, 2);

	cout << "Name : " << st.getName() << ". Marks : "
		<< st.getMark(0) << ", " << st.getMark(1) << ", " << st.getMark(2) << endl;
	cout << "Average mark : " << st.getAverage() << endl;

	
	Student st2;
	st2.setName("Olga");
	st2.setMark(7, 0);
	st2.setMark(8, 1);
	st2.setMark(6, 2);

	cout << "Name : " << st2.getName() << ". Marks : "
		<< st2.getMark(0) << ", " << st2.getMark(1) << ", " << st2.getMark(2) << endl;
	cout << "Average mark : " << st2.getAverage() << endl;
	

	//Practice with Point class
	Point p;

	p.InputFromKeyBoard();
	p.print();
	p.SaveToFile();
	p.LoadFromFile();
	p.print();


	/*Player pl;
	pl.InitPlayer();
	pl.PrintPlayer();
	
	pl.AddGameToPlayer(0);
	pl.PrintPlayer();
	pl.AddGameToPlayer(2);
	pl.PrintPlayer();
	pl.AddGameToPlayer(3);
	pl.PrintPlayer();


	Player2 pl2;
	pl2.InitPlayer();
	pl2.PrintPlayer();

	pl2.AddGameToPlayer(1);
	pl2.PrintPlayer();
	pl2.AddGameToPlayer(8);
	pl2.PrintPlayer();*/

	


	//old variant
	//string name;
	//name = "John Doe";
	//cout << name << endl;
	//cout << sizeof(name) << endl;
	//cout << "Enter name" << endl;
	//getline(cin, name); //cin >> name;
	//cout << "Name: " << name << endl;
	

	/*Player player;
	InitPlayer(player);
	PrintPlayer(player);

	AddGameToPlayer(player);
	PrintPlayer(player);

	AddGameToPlayer(player, 2);
	PrintPlayer(player);

	AddGameToPlayer(player, 5);
	PrintPlayer(player);*/

	

}

