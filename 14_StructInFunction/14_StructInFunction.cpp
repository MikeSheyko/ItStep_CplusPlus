#include <iostream>
#include <cstring>
using namespace std;


struct Book 
{
    int id;
    char title[50];
    char author[50];
    char publisher[50];
    char genre[50];
    int year;
    float price;
};

void Show(Book b)
{
    cout << "Title    : " << b.title << endl;
    cout << "Author   : " << b.author << endl;
    cout << "Publisher: " << b.publisher << endl;
    cout << "Genre    : " << b.genre << endl;
    cout << "Year     : " << b.year << endl;
    cout << "Price    : " << b.price << endl;
    cout << "-------------------------------";
}


void SearchByAuthor(Book books[], int size, char author[])
{
    for (int i = 0; i < size; ++i)
    {
        if (strcmp(books[i].author, author) == 0)
        {
            Show(books[i]);
            cout << endl;
        }
    }
}

void SearchByTitle(Book books[], int size, char title[])
{
    for (int i = 0; i < size; ++i)
    {
        if (strcmp(books[i].title, title) == 0)
        {
            Show(books[i]);
            cout << endl;
        }
    }
}


void SearchByPublisher(Book books[], int size, char publisher[])
{
    for (int i = 0; i < size; ++i)
    {
        if (strcmp(books[i].publisher, publisher) == 0)
        {
            Show(books[i]);
            cout << endl;
        }
    }
}

void SearchByGenre(Book books[], int size, char genre[])
{
    for (int i = 0; i < size; ++i)
    {
        if (strcmp(books[i].genre, genre) == 0)
        {
            Show(books[i]);
            cout << endl;
        }
    }
}

void EditBookById(Book books[], int size, int id)
{
    for (int i = 0; i < size; ++i)
    {
        if (books[i].id == id)
        {
            cout << "Edit book ID: " << id << endl;

            cout << "Enter new title: ";
            cin.getline(books[i].title, 50);

            cout << "Enter new author: ";
            cin.getline(books[i].author, 50);

            cout << "Enter new publisher: ";
            cin.getline(books[i].publisher, 50);

            cout << "Enter new genre: ";
            cin.getline(books[i].genre, 50);

            cout << "Enter new year: ";
            cin >> books[i].year;

            cout << "Enter new price: ";
            cin >> books[i].price;
            cin.ignore();

            cout << "Book has been edited!!" << endl;
        }
    }
    cout << "Error!Book ID " << id << " not found!!Try again!" << endl;
}


int main()
{
    const int size = 4;

    Book books[size] =
    {
        {1, "Harry Potter", "J.K. Rowling", "Scholastic", "Fantasy", 1997, 300},
        {2, "The Little Prince", "Antoine de Saint-Exupery", "Ranok", "Philosophy", 1943, 190},
        {3, "Fahrenheit 451", "Ray Bradbury", "Ranok", "Dystopia", 1953, 220},
        {4, "The Hobbit", "J.R.R. Tolkien", "HarperCollins", "Fantasy", 1937, 280}
    };

    int choice;
    char name[50];
    do
    {
        cout << "=============== Menu ===============" << endl;
        cout << "Show all books                   [1]" << endl;
        cout << "Search by author                 [2]" << endl;
        cout << "Search by title                  [3]" << endl;
        cout << "Search by publisher              [4]" << endl;
        cout << "Search by genre                  [5]" << endl;
        cout << "Edit book by ID                  [6]" << endl;
        cout << "Exit                             [0]" << endl;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            for (int i = 0; i < size; i++)
            {
                Show(books[i]);
                cout << endl;
            }
            break;
        case 2:
            cout << "Enter author name : ";
            cin.getline(name, 50);
            SearchByAuthor(books, size, name);
            break;
        case 3:
            cout << "Enter title name : ";
            cin.getline(name, 50);
            SearchByTitle(books, size, name);
            break;
        case 4:
            cout << "Enter publisher name : ";
            cin.getline(name, 50);
            SearchByPublisher(books, size, name);
            break;
        case 5:
            cout << "Enter genre name : ";
            cin.getline(name, 50);
            SearchByGenre(books, size, name);
            break;
        case 6:
            int id;
            cout << "Enter book ID to edit : "; cin >> id;
            cin.ignore();
            EditBookById(books, size, id);
            break;
        case 0:
            cout << "Goodbye!" << endl;
            exit(0);
        default:
            break;
        }
    } while (choice != 0);




}