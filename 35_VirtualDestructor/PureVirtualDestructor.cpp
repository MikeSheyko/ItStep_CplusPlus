#include <iostream>
using namespace std;

class Person//abstract class 
{
protected:
    string name;
public:
    Person() :name("no name") {}
    Person(string name) :name(name) {}
    virtual void Print()const
    {
        cout << "Name : " << name << endl;
    }
    virtual~Person() = 0 {};

};
class Asspirant : public Person
{
    string* subjects;
    int countSub;
public:
    Asspirant() : subjects(nullptr), countSub(0), Person() {}
    Asspirant(string name, initializer_list<string> list) : Person(name)
    {
        countSub = list.size();
        subjects = new string[countSub];
        int i = 0;
        for (string s : list)
        {
            subjects[i] = s;
            i++;
        }
    }
    void Print()const override
    {
        Person::Print();
        cout << "Subject : ";
        for (int i = 0; i < countSub; i++)
        {
            cout << subjects[i] << " , ";
        }
        cout << "\n---------------------------\n";
    }
    ~Asspirant()
    {
        if (subjects != nullptr)
            delete[]subjects;
    }
};

int main()
{
    srand(time(0));
    /*  Person st("Vasia");
      st.Print();*/

    Asspirant a("Inna", { "Main page", "UI/UX design","Trends in internet" });
    a.Print();
    cout << "-------------------------------------" << endl;
    Person* students[2]
    {
        //new Person("Vasia"),
        new Asspirant("Inna",{"Main page", "UI/UX design","Trends in internet"}),
        new Asspirant("Oleg",  {"C++", "C#"})
    };
    for (int i = 0; i < 2; i++)
    {
        students[i]->Print();
        delete students[i];
    }
}