#include <iostream>
#include <windows.h>
using namespace std;


void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int text_len(char str[]) 
{
	int length = 0;
	for (length = 0; str[length] != '\0'; length++) 
	{
	}
	return length;
}

int main()
{
	//С-Style rows
	//string
	char word[] = { 'C', 'a', 't', '!' };
	for (int i = 0; i < 4; i++)
	{
		cout << word[i];
	}
	cout << endl;

	char mystring[] = "string"; //Нуль термінований рядок (\0) 6 letters + \0
	cout << mystring << " has " << sizeof(mystring) << " characters " << endl;
	cout << "Int : " << sizeof(int) << endl;
	cout << "Double : " << sizeof(double) << endl;
	cout << "Float : " << sizeof(float) << endl;
	cout << "Word : " << sizeof(word) << endl;

	for (int i = 0; i < sizeof(mystring); i++)
	{
		cout << static_cast<int>(mystring[i]) << " ";
	}

	cout << endl;

	//mystring = "Cat" ---- Error
	//mystring[0] = 'p'; //OK

	char name[15] = "Max"; //3 letters + \0
	cout << "My name is : " << name << endl;
	cout << "Max has sizeof() : " << sizeof(name) << endl; // sizeof() - count letters + \0
	cout << "Max has strlen() : " << strlen(name) << endl; // strlen() - count letters without \0


	//char myname[255];
	//cout << "Enter your name : ";
	//cin.getline(myname, 255); // cin >> myname;
	//cout << "You entered : " << myname << endl;

	//char text[] = "Some text";
	//char copy[50];
	//strcpy_s(copy, text); //copy text to copy
	//cout << "Copy : " << copy << endl;

	


	char arr[255] = "Return the head of a list";
	_strupr_s(arr); //Uppercase
	cout << arr << endl;
	_strlwr_s(arr); //Lowercase
	cout << arr << endl;

	_strrev(arr); //Reverse
	cout << arr << endl;

	cout << "Copy array : " << endl;
	char copyarr[255] = {};
	strcpy_s(copyarr, arr);
	cout << copyarr << endl;



	cout << "Add to array" << endl;
	strcat_s(arr, "............");
	cout << arr << endl;
	
	// Pratice
	//Task 1
	setColor(11);
	char text[255];
	cout << "Enter text : ";
	cin.getline(text, 255);
	int count_a = 0;
	int count_o = 0;
	for (int i = 0; i < strlen(text); i++)
	{
		if (text[i] == 'a' || text[i] == 'A') 
		{
			count_a++;
		}
		if (text[i] == 'o' || text[i] == 'O') 
		{
			count_o++;
		}
	}
	cout << "Number of 'a': " << count_a << endl;
	cout << "Number of 'o': " << count_o << endl;

	if (count_a > count_o) 
	{
		cout << "A > O" << endl;
	}
	else if (count_o > count_a)
	{
		cout << "O > A" << endl;
	}
	else 
	{
			cout << "A = O" << endl;
	}
	cout << endl;
	setColor(7);

	//Task 2
	setColor(9);
	char text_1[255];
	cout << "Enter text : ";
	cin.getline(text_1, 255);

	int letters = 0, digits = 0, spaces = 0;

	for (int i = 0; i < strlen(text_1); i++) 
	{
		if (isalpha(text_1[i]))
		{
			letters++;
		}
		else if (isdigit(text_1[i]))
		{
			digits++;
		}
		else if (isspace(text_1[i])) 
		{
			spaces++;
		}
	}
	cout << "Letters : " << letters << ", Digits : " << digits << ", Spaces : " << spaces << endl;
	cout << endl;
	setColor(7);

	//Task 3
	setColor(10);
	char text_2[255];
	cout << "Enter text : ";
	cin.getline(text_2, 255);
	for (int i = 0; i < strlen(text_2); i++) 
	{
		if (isupper(text_2[i]))
		{
			text_2[i] = tolower(text_2[i]);
		}
		else if (islower(text_2[i]))
		{
			text_2[i] = toupper(text_2[i]);
		}
			
	}
	cout << "New text : " << text_2 << endl;
	cout << endl;
	setColor(7);

	//Task 4
	setColor(4);
	char text_3[255];
	cout << "Enter text : ";
	cin.getline(text_3, 255);
	int len = text_len(text_3);
	cout << "Length of text is : " << len << " " << "characters." << endl;
	setColor(7);








	}





