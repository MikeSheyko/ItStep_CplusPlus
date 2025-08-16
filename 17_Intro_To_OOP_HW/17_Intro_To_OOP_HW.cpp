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
    Date birthdate;
    string phone;
    string city;
    string country;
    string studentUniversity;
    string city_university;
    string country_university;
    string group;
    int* marks;
    int countMark;
    float averageMark;

    void setAverageMark() 
    {
        float sum = 0;
        for (int i = 0; i < countMark; i++) 
        {
            sum += marks[i];
        }
        averageMark = sum / countMark;
    }

public:
    Student() 
    {
        fullname = { "no name", "no lastname", "no surname" };
        birthdate = { 0, 0, 0 };
        phone = "no phone";
        city = "no city";
        country = "no country";
        studentUniversity = "no university";
        city_university = "no city university";
        country_university = "no country university";
        group = "no group";
        marks = nullptr;
        countMark = 0;
        averageMark = 0.0;
    }

    Student(const Student& other) 
    {
        fullname = other.fullname;
        birthdate = other.birthdate;
        phone = other.phone;
        city = other.city;
        country = other.country;
        studentUniversity = other.studentUniversity;
        city_university = other.city_university;
        country_university = other.country_university;
        group = other.group;
        countMark = other.countMark;
        averageMark = other.averageMark;
        marks = new int[countMark];
        for (int i = 0; i < countMark; i++) 
        {
            marks[i] = other.marks[i];
        }
    }

    ~Student() 
    {
        delete[] marks;
    }

    void Input() 
    {
        cout << "Enter name: "; cin >> fullname.name;
        cout << "Enter lastname: "; cin >> fullname.lastname;
        cout << "Enter surname: "; cin >> fullname.surname;
        cout << "Enter birth date (dd mm yyyy): "; cin >> birthdate.day >> birthdate.month >> birthdate.year;
        cout << "Enter phone: "; cin >> phone;
        cout << "Enter city: "; cin >> city;
        cout << "Enter country: "; cin >> country;
        cout << "Enter university: "; cin >> studentUniversity;
        cout << "Enter university city: "; cin >> city_university;
        cout << "Enter university country: "; cin >> country_university;
        cout << "Enter group: "; cin >> group;
    }

    
    void Print() 
    {
        cout << "Student information: " << endl;
        cout << "Name: " << fullname.name << " " << fullname.lastname << " " << fullname.surname << endl;
        cout << "Date of Birth: " << birthdate.day << "/" << birthdate.month << "/" << birthdate.year << endl;
        cout << "Phone: " << phone << endl;
        cout << "City: " << city << endl;
        cout << "University: " << studentUniversity << endl;
		cout << "University city: " << city_university << endl;
		cout << "University country: " << country_university << endl;
        cout << "Group: " << group << endl;
        cout << "Marks: ";
        for (int i = 0; i < countMark; i++) 
        {
            cout << marks[i] << " ";
        }
		cout << endl;
        cout << "Average Mark: " << averageMark << endl;
    }

    void setName(string name)
    {
        this->fullname.name = name;
    }
    void setLastName(string lastname)
    {
        this->fullname.lastname = lastname;
    } 
    void setSurname(string surname)
    {
        this->fullname.surname = surname;
    }  
    void setBirthdate(Date date)
    {
        this->birthdate = date;
    }
    void setPhone(string phone)
    {
        this->phone = phone;
    }
    void setCity(string city)
    {
        this->city = city;
    }
    void setCountry(string country)
    {
        this->country = country;
    }  
    void setUniversity(string university)
    {
        this->studentUniversity = university;
    }
    void setCityUniversity(string cityUniversity)
    {
        this->city_university = cityUniversity;
    }
    void setCountryUniversity(string countryUniversity)
    {
        this->country_university = countryUniversity;
    }  
    void setGroup(string group)
    {
        this->group = group;
    }

        
    string getName() const
    {
        return this->fullname.name;
    }
    string getLastName() const
    {
        return this->fullname.lastname;
    }
    string getSurname() const
    {
        return this->fullname.surname;
    }
    Date getBirthdate() const
    {
        return this->birthdate;
    }
    string getPhone() const
    {
        return this->phone;
    }
    string getCity() const
    {
        return this->city;
    }
    string getCountry() const
    {
        return this->country;
    }
    string getUniversity() const
    {
        return this->studentUniversity;
    }
    string getCityUniversity() const
    {
        return this->city_university;
    }
    string getCountryUniversity() const
    {
        return this->country_university;
    }
    string getGroup() const
    {
        return this->group;
    }

    
    float getAverageMark() const
    {
        return this->averageMark;
    }
   

    void AddMark(int mark) 
    {
        int* temp = new int[countMark + 1];
        for (int i = 0; i < countMark; i++) 
        {
            temp[i] = marks[i];
        }
        temp[countMark++] = mark;
        delete[] marks;
        marks = temp;
        setAverageMark();
    }

  
};

int main() 
{
	Student student;
	student.Print(); 

    Student s;
    s.Input();
    s.AddMark(10);
    s.AddMark(12);
    s.AddMark(9);
    s.Print();




    
    
}
