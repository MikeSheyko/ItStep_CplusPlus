#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class PIB 
{
public:
    string lastname;
    string name;
    string surname;

    PIB() {}

    PIB(string ln, string n, string sn) : lastname(ln), name(n), surname(sn) {}

    string getFullName() const 
    {
        return lastname + " " + name + " " + surname;
    }
};


class Abonent 
{
private:
    PIB pib;
    string homePhone;
    string workPhone;
    string mobilePhone;
    string extraInfo;

    static int abonentCount;

public:
    Abonent() {}

    Abonent(PIB p, string home, string work, string mobile, string extra) : 
        pib(p), homePhone(home), workPhone(work), mobilePhone(mobile), extraInfo(extra) {abonentCount++;}

    Abonent(PIB p, string home, string work, string mobile) : 
        Abonent(p, home, work, mobile, "") {}

    ~Abonent() 
    {
        abonentCount--;
    }

    PIB getPIB() const 
    {
        return pib;
    }

    string getHomePhone() const 
    {
        return homePhone; 
    }
    string getWorkPhone() const 
    { 
        return workPhone; 
    }
    string getMobilePhone() const 
    { 
        return mobilePhone; 
    }

    void print() const 
    {
        cout << "Full Name: " << pib.getFullName() << endl;
        cout << "Home Phone: " << homePhone << endl;
        cout << "Work Phone: " << workPhone << endl;
        cout << "Mobile Phone: " << mobilePhone << endl;
        cout << "Extra Info: " << extraInfo << endl;
        cout << "------------------------" << endl;
    }

    void saveToFile(const string& filename) const 
    {
        ofstream file(filename);
        if (file.is_open()) 
        {
            file << pib.lastname << endl << pib.name << endl << pib.surname << endl;
            file << homePhone << endl << workPhone << endl
                 << mobilePhone << endl << extraInfo << endl;
            file.close();
            cout << "Contact has been saved to file." << endl;
        }
        else 
        {
            cerr << "Error !!!" << endl;
        }
    }

    static Abonent loadFromFile(const string& filename) 
    {
        ifstream file(filename);
        PIB p;
        string home, work, mobile, extra;
        if (file.is_open()) 
        {
            getline(file, p.lastname);
            getline(file, p.name);
            getline(file, p.surname);
            getline(file, home);
            getline(file, work);
            getline(file, mobile);
            getline(file, extra);
            file.close();
            cout << "Contact has been loaded from file." << endl;
            return Abonent(p, home, work, mobile, extra);
        }
        else 
        {
            cerr << "Error !!!" << endl;
        }
    }

    static int getCount() 
    {
        return abonentCount;
    }

    bool hasPhone(const string& phone) const 
    {
        return homePhone == phone || workPhone == phone || mobilePhone == phone;
    }
};

int Abonent::abonentCount = 0;


class PhoneBook 
{
private:
    Abonent* abonents;
    int countAbonent;
    int capacity;

    void expandArr() 
    {
        capacity *= 2;
        Abonent* newArr = new Abonent[capacity];
        for (int i = 0; i < countAbonent; ++i) 
        {
            newArr[i] = abonents[i];
        }
        delete[] abonents;
        abonents = newArr;
    }

public:
    PhoneBook() 
    {
        countAbonent = 0;
        capacity = 20;
        abonents = new Abonent[capacity];
    }

    ~PhoneBook() 
    {
        delete[] abonents;
    }

    void Add(const Abonent& a) 
    {
        if (countAbonent >= capacity)
            expandArr();
        abonents[countAbonent++] = a;
    }

    void Delete(const string& phone) 
    {
        for (int i = 0; i < countAbonent; ++i) 
        {
            if (abonents[i].hasPhone(phone)) 
            {
                for (int j = i; j < countAbonent - 1; ++j) 
                {
                    abonents[j] = abonents[j + 1];
                }
                countAbonent--;
                cout << "Contact has been deleted!" << endl;
                return;
            }
        }
        cout << "Contact not found!" << endl;
    }

    void SearchByName(const string& fullname) const 
    {
        bool found = false;
        for (int i = 0; i < countAbonent; ++i) 
        {
            if (abonents[i].getPIB().getFullName() == fullname) 
            {
                abonents[i].print();
                found = true;
            }
        }
        if (!found) cout << "Contact not found!! Try again!" << endl;
    }

    void SearchByPhone(const string& phone) const 
    {
        bool found = false;
        for (int i = 0; i < countAbonent; ++i) 
        {
            if (abonents[i].hasPhone(phone)) 
            {
                abonents[i].print();
                found = true;
            }
        }
        if (!found) cout << "Contact not found!! Try again!" << endl;
    }

    void ShowAll() const 
    {
        if (countAbonent == 0) 
        {
            cout << "Phone book is empty!" << endl;
        }
        for (int i = 0; i < countAbonent; ++i) 
        {
            abonents[i].print();
        }
    }
};

int main() 
{
    PhoneBook book;

    while (true) 
    {
        cout << "============ Phone Book Menu ============" << endl;
        cout << "Add contact                           [1]" << endl;
		cout << "Delete contact                        [2]" << endl;
		cout << "Search by full name                   [3]" << endl;
		cout << "Search by phone                       [4]" << endl;
		cout << "Show all contacts                     [5]" << endl;
		cout << "Save one contact to file              [6]" << endl;
		cout << "Load one contact from file            [7]" << endl;
		cout << "Exit                                  [0]" << endl;
		cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) 
        {
            string lname, fname, sname, home, work, mobile, extra;
            cout << "Last name: "; getline(cin, lname);
            cout << "First name: "; getline(cin, fname);
            cout << "Middle name: "; getline(cin, sname);
            cout << "Home phone: "; getline(cin, home);
            cout << "Work phone: "; getline(cin, work);
            cout << "Mobile phone: "; getline(cin, mobile);
            cout << "Extra info: "; getline(cin, extra);

            PIB p(lname, fname, sname);
            Abonent a(p, home, work, mobile, extra);
            book.Add(a);
        }
        else if (choice == 2) 
        {
            string phone;
            cout << "Enter phone number: ";
            getline(cin, phone);
            book.Delete(phone);
        }
        else if (choice == 3) 
        {
            string lname, fname, sname;
            cout << "Last name: "; getline(cin, lname);
            cout << "First name: "; getline(cin, fname);
            cout << "Middle name: "; getline(cin, sname);
            string fullname = lname + " " + fname + " " + sname;
            book.SearchByName(fullname);
        }
        else if (choice == 4) 
        {
            string phone;
            cout << "Enter phone number: ";
            getline(cin, phone);
            book.SearchByPhone(phone);
        }
        else if (choice == 5) 
        {
            book.ShowAll();
        }
        else if (choice == 6) 
        {
            string filename;
            cout << "Enter file name: ";
            getline(cin, filename);

            string lname, fname, sname;
            cout << "Last name: "; getline(cin, lname);
            cout << "First name: "; getline(cin, fname);
            cout << "Middle name: "; getline(cin, sname);

            PIB p(lname, fname, sname);
            Abonent a(p, "+380991111111", "+380931111111", "+380671111111", "None");
            a.saveToFile(filename);
        }
        else if (choice == 7) 
        {
            string filename;
            cout << "Enter file name: ";
            getline(cin, filename);
            Abonent a = Abonent::loadFromFile(filename);
            book.Add(a);
        }
        else if (choice == 0) 
        {
            break;
        }
        else 
        {
            cout << "Invalid choice!" << endl;
        }
    }




	cout << "Total abonents: " << Abonent::getCount() << endl;
   
}
