#include <iostream>
#include <cstring>
#include <fstream>
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

const int maxBooks = 100;
Book books[maxBooks];
int Size = 10;
const char* FILENAME = "E:\\ItStep\\books.txt";


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

void AddNewBook()
{
	if (Size >= maxBooks)
	{
		cout << "Cannot add more books, maximum limit reached!" << endl;
		return;
	}
    cout << "Enter ID: ";
    cin >> books[Size].id;
    cin.ignore();

    cout << "Enter title: ";
    cin.getline(books[Size].title, 50);

    cout << "Enter author: ";
    cin.getline(books[Size].author, 50);

    cout << "Enter publisher: ";
    cin.getline(books[Size].publisher, 50);

    cout << "Enter genre: ";
    cin.getline(books[Size].genre, 50);

    cout << "Enter year: ";
    cin >> books[Size].year;

    cout << "Enter price: ";
    cin >> books[Size].price;
    cin.ignore();

    Size++;
    cout << "Book added successfully!" << endl;
}

void SaveToFile()
{
    ofstream fileOut(FILENAME);
    if (fileOut.is_open())
    {
        fileOut << Size << endl;
        for (int i = 0; i < Size; ++i)
        {
            fileOut << books[i].id << endl;
            fileOut << books[i].title << endl;
            fileOut << books[i].author << endl;
            fileOut << books[i].publisher << endl;
            fileOut << books[i].genre << endl;
            fileOut << books[i].year << endl;
            fileOut << books[i].price << endl;
        }
        fileOut.close();
        cout << "Book have been saved!" << endl;
    }
}

void LoadFromFile()
{
    ifstream fileIn(FILENAME);
    if (fileIn.is_open())
    {
        fileIn >> Size;
        fileIn.ignore();
        for (int i = 0; i < Size; ++i)
        {
            fileIn >> books[i].id;
            fileIn.ignore();
            fileIn.getline(books[i].title, 50);
            fileIn.getline(books[i].author, 50);
            fileIn.getline(books[i].publisher, 50);
            fileIn.getline(books[i].genre, 50);
            fileIn >> books[i].year;
            fileIn >> books[i].price;
            fileIn.ignore();
        }
        fileIn.close();
    }
}

int main()
{
   

    Book Books[] = 
    {
        {1, "Harry Potter", "J.K. Rowling", "Scholastic", "Fantasy", 1997, 300},
        {2, "The Little Prince", "Antoine de Saint-Exupery", "Ranok", "Philosophy", 1943, 190},
        {3, "Fahrenheit 451", "Ray Bradbury", "Ranok", "Dystopia", 1953, 220},
        {4, "The Hobbit", "J.R.R. Tolkien", "HarperCollins", "Fantasy", 1937, 280},
        {5, "1984", "George Orwell", "Secker & Warburg", "Dystopia", 1949, 250},
        {6, "To Kill a Mockingbird", "Harper Lee", "J.B. Lippincott & Co.", "Classic", 1960, 200},
        {7, "Pride and Prejudice", "Jane Austen", "T. Egerton", "Romance", 1813, 150},
        {8, "The Catcher in the Rye", "J.D. Salinger", "Little, Brown", "Fiction", 1951, 230},
        {9, "The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons", "Classic", 1925, 210},
        {10, "Brave New World", "Aldous Huxley", "Chatto & Windus", "Dystopia", 1932, 240}
    };

    for (int i = 0; i < 10; ++i)
    {
        books[i] = Books[i];
    }

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
		cout << "Add new book                     [7]" << endl;
		cout << "Save to file                     [8]" << endl;
		cout << "Load from file                   [9]" << endl;
        cout << "Exit                             [0]" << endl;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            for (int i = 0; i < Size; i++)
            {
                Show(books[i]);
                cout << endl;
            }
            break;
        case 2:
            cout << "Enter author name : ";
            cin.getline(name, 50);
            SearchByAuthor(books, Size, name);
            break;
        case 3:
            cout << "Enter title name : ";
            cin.getline(name, 50);
            SearchByTitle(books, Size, name);
            break;
        case 4:
            cout << "Enter publisher name : ";
            cin.getline(name, 50);
            SearchByPublisher(books, Size, name);
            break;
        case 5:
            cout << "Enter genre name : ";
            cin.getline(name, 50);
            SearchByGenre(books, Size, name);
            break;
        case 6:
            int id;
            cout << "Enter book ID to edit : "; cin >> id;
            cin.ignore();
            EditBookById(books, Size, id);
            break;
        case 7:
            AddNewBook();
            break;
        case 8:
            SaveToFile();
            break;
        case 9:
            LoadFromFile();
            break;
        case 0:
            cout << "Goodbye!" << endl;
            exit(0);
        default:
            break;
        }
    } while (choice != 0);




}