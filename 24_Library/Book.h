#pragma once
#include <iostream>

using namespace std;



enum Genre {
	None,
	History,
	Fantasy, 
	Detective, 
	Mistery, 
	Horror, 
	Comedy, 
	Fictions, 
	ComputerScience,
	Science, 
	Adventure
};


class Book
{
private:
	string title;
	string author;
	int year;
	int pages;
	Genre genre;
public:
	//prototype constructor
	Book();

	Book(string t, string a, int p, int y, Genre g) :
		title(t), author(a), pages(p), year(y), genre(g) {}

	void ShowInfo() const;


};

