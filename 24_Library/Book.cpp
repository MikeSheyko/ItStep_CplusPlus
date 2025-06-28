#include "Book.h"

Book::Book()
{
	title = "no title";
	author = "no author";
	year = 0;
	pages = 0;
	genre = None;
}

void Book::ShowInfo() const
{
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Year: " << year << endl;
	cout << "Pages: " << pages << endl;
	cout << "Genre: ";
	switch (genre) 
	{
	case History: cout << "History"; break;
	case Fantasy: cout << "Fantasy"; break;
	case Detective: cout << "Detective"; break;
	case Mistery: cout << "Mistery"; break;
	case Horror: cout << "Horror"; break;
	case Comedy: cout << "Comedy"; break;
	case Fictions: cout << "Fictions"; break;
	case ComputerScience: cout << "Computer Science"; break;
	case Science: cout << "Science"; break;
	case Adventure: cout << "Adventure"; break;
	default: cout << "None"; break;
	}
	cout << "____________________________________________" << endl;
}
