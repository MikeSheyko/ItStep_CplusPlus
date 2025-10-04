#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Animal
{
    string name;
    string place;
    float weight;
public:
    Animal() :name("no name"), place("no place"), weight(0) {}
    Animal(string n, string p, float w) :name(n), place(p)
    {
        this->weight = w > 0 ? w : 0;
    }
    void Print()const
    {
        cout << "Name : " << name << endl;
        cout << "Place : " << place << endl;
        cout << "Weight : " << weight << endl;
    }

    friend ofstream& operator <<(ofstream& out, const Animal& animal);
    friend ifstream& operator >> (ifstream& out, Animal& animal);
};
ofstream& operator <<(ofstream& out, const Animal& animal)
{
    out << animal.name << " " << animal.place << " " << animal.weight;
    return out;
}
ifstream& operator >> (ifstream& in, Animal& animal)
{
    in >> animal.name >> animal.place >> animal.weight;
    return in;
}
class Zoo
{
    string name;
    Animal* animals;
    int countAnimal;
public:
    Zoo(string name) :name(name), animals(nullptr), countAnimal(0) {}
    void AddAnimal(Animal a)
    {
        Animal* temp = new Animal[countAnimal + 1];
        for (int i = 0; i < countAnimal; i++)
        {
            temp[i] = animals[i];
        }
        temp[countAnimal] = a;
        countAnimal++;
        if (animals != nullptr)
            delete[]animals;
        animals = temp;

    }
    void ShowInfo()
    {
        cout << "\n\nName Zoo " << name << endl;
        for (int i = 0; i < countAnimal; i++)
        {
            animals[i].Print();
            cout << endl;
        }
    }
    ~Zoo()
    {
        if (animals != nullptr)
            delete[]animals;
    }
    void SaveToFile()
    {
        ofstream out("zoo.txt", ios_base::out);
        out << name << endl;
        out << countAnimal << endl;
        for (int i = 0; i < countAnimal; i++)
        {
            out << animals[i] << endl;

        }
        out.close();
        cout << "Save to File" << endl;
    }
    void ReadFromFile()
    {
        ifstream in("zoo.txt", ios_base::in);
        getline(in, name);
        //in >> name; //cin>>name
        in >> countAnimal;
        animals = new Animal[countAnimal];//4
        for (int i = 0; i < countAnimal; i++)
        {
            in >> animals[i];
        }
        in.close();
    }
    void SaveToFileBinary()
    {
        ofstream out("zoo.bin", ios_base::out | ios_base::binary);
        out.write((char*)&name, sizeof(name));
        out.write((char*)&countAnimal, sizeof(countAnimal));

        for (int i = 0; i < countAnimal; i++)
        {
            out.write((char*)&animals[i], sizeof(animals[i]));
        }
        out.close();
        cout << "Save to File" << endl;
    }
    void ReadFromFileBinary()
    {
        ifstream in("zoo.bin", ios_base::in | ios_base::binary);
        in.read((char*)&name, sizeof(name));
        in.read((char*)&countAnimal, sizeof(countAnimal));
        animals = new Animal[countAnimal];//4
        for (int i = 0; i < countAnimal; i++)
        {
            in.read((char*)&animals[i], sizeof(animals[i]));
        }
        in.close();
    }
};
int main()
{
    Animal an("Tom", "flat", 5);
    an.Print();

    Zoo zoo("Rivne Zoo");
    zoo.AddAnimal(an);
    zoo.AddAnimal(Animal("Lion","Africa",150));
    zoo.AddAnimal(Animal("Turtle","Africa",50));
    zoo.AddAnimal(Animal("Elephant","Africa",1500));
    zoo.ShowInfo();
    ////zoo.SaveToFile();
    zoo.SaveToFileBinary();
    zoo.ReadFromFileBinary();
    //zoo.ReadFromFile();
    zoo.ShowInfo();









}