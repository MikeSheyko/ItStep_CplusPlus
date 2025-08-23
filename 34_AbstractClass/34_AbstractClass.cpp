#include <iostream>
using namespace std;



class Animal //abstract class
{
protected:
	string name;
	string place;
	float weight;
	public:
	Animal() :  name("no name"), place("no place"), weight(0) {}
	Animal(string n, string p, float w) : name(n), place(p) 
	{
		//1
		/*if (w < 0)
			this->weight = 0;
		else
			this->weight = w;*/
			//2
			//w > 0 ? this->weight = w : this->weight = 0;
			//3
		this->weight = (w > 0) ? w : 0;
	}
	void Print()const
	{
		cout << "Name : " << name << endl;
		cout << "Place : " << place << endl;
		cout << "Weight : " << weight << "kg" << endl;
	}
	
	virtual void MakeSound() const = 0; //pure virtual method
	//if class has at least one pure virtual method - it is abstract class

	virtual void Move() const
	{
		cout << "I am moving......" << endl;
	}
};



class Lion : public Animal
{
	float runSpeed;
public:
	Lion() : runSpeed(0), Animal() {}
	Lion(string n, string p, float w, float rs) : runSpeed(rs), Animal(n,p,w) {}
	void Print()const
	{
		cout << "------------------ Lion ------------------" << endl;
		Animal::Print();
		cout << "Run speed : " << runSpeed << " km/h" << endl;
	}
	void MakeSound() const override
	{
		cout << "Roarrrrrrrr-rrrrrrrrrrrrrr!" << endl;
	}
	void Move() const override
	{
		cout << "I am running with speed : " << runSpeed << " km/h" << endl;
	}

};

class Duck : public Animal
{
	float flyHeight;
public:
	Duck() : flyHeight(0), Animal() {}
	Duck(string n, string p, float w, float fh) : flyHeight(fh), Animal(n, p, w) {}
	void Print()const
	{
		cout << "------------------ Duck ------------------" << endl;
		Animal::Print();
		cout << "Fly height : " << flyHeight << " m" << endl;
	}
	void MakeSound() const override
	{
		cout << "Quack-quack-quack-quack!" << endl;
	}
	void Move() const override
	{
		cout << "I am flying at height : " << flyHeight << " m" << endl;
	}
};

class Reptile : public Animal // abstract class
{
	float sweemDeep;
public:
	Reptile() :sweemDeep(0), Animal() {}
	Reptile(string n, string p, float w, float sd) : sweemDeep(sd), Animal(n, p, w) {}
	
	//virtual void MakeSound() const = 0; //pure virtual method
	

	void Move()const
	{
		cout << "I am a Reptile. A can crowling and swimming to deep " << sweemDeep << " m" << endl;
	}
};


class Snake : public Reptile
{
	int lenght;
public:
	Snake() : lenght(0), Reptile() {}
	Snake(string n, string p, float w, float sd, int l) : lenght(l), Reptile(n, p, w, sd) {}
	
	void MakeSound()const override
	{
		cout << "sssssssssssssssssssssssss-sssssssssssssss" << endl;
	}
};



void RollCall(Animal& a)
{
	a.MakeSound();
};









int main()
{
	//Animal a("some animal", "Flat", 5);


	Lion l("Simba", "Savannah", 190, 80);
	l.MakeSound();
	l.Move();
	l.Print();
	cout << endl;
	
	Duck d ("Donald", "Pond", 5, 10);
	d.MakeSound();
	d.Move();
	d.Print();
	cout << endl;

	Snake s("Kaa", "Jungle", 15, 5, 3);
	s.MakeSound();
	s.Move();
	s.Print();


	Animal* zoo[2]
	{
		&l,&d
	};


	




}

