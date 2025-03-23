#include <iostream>
using namespace std;

int main()
{
	cout << "Task 1" << endl;
	int side_1, side_2, side_3;
	cout << "Enter tringle's side 1: ";
	cin >> side_1;
	cout << "Enter tringle's side 2: ";
	cin >> side_2;
	cout << "Enter tringle's side 3: ";
	cin >> side_3;
	if (side_1 == side_2 && side_1 == side_3)
	{
		cout << "Triangle is equilateral" << endl;
	}
	else if (side_1 == side_2 || side_2 == side_3 || side_1 == side_3)
	{
		cout << "Triangle is isosceles " << endl;
	}
	else
	{
		cout << "Triangle is scalene" << endl;
	}
	cout << endl;


	cout << "Task 2" << endl;
	int Brick_Width, Brick_Height, Hole_Width, Hole_Height;
	cout << "Enter Brick Width : ";
	cin >> Brick_Width;
	cout << "Enter Brick Height : ";
	cin >> Brick_Height;
	cout << "Enter Hole Width : ";
	cin >> Hole_Width;
	cout << "Enter Hole Height : ";
	cin >> Hole_Height;
	if ((Brick_Width <= Hole_Width && Brick_Height <= Hole_Height)||(Brick_Width <= Hole_Height && Brick_Height <= Hole_Width))
	{
		cout << "Brick WILL fit through the opening" << endl;
	}
	else 
	{
		cout << "Brick WILL NOT fit through the opening" << endl;
	}
	cout << endl;


	cout << "Task 3" << endl;
	int a, b, c;
	cout << "Enter number 1 : ";
	cin >> a;
	cout << "Enter number 2 : ";
	cin >> b;
	cout << "Enter number 3 : ";
	cin >> c;
	if (a > 0 || b > 0 || c > 0)
	{
		cout << "Among these numbers, there are positive ones" << endl;
	}
	else
	{
		cout << "There are no positive numbers among these" << endl;
	}
	cout << endl;*/


	cout << "Task 4" << endl;
	int some_number;
	cout << "Enter some number : ";
	cin >> some_number;
	if ((some_number < 2 || some_number > 5) && (some_number < -1 || some_number > 1))
	{
		cout << "The number is outside the intervals [2, 5] and [-1, 1]" << endl;
	}
	else
	{
		cout << "The number is inside the intervals [2, 5] or [-1, 1]" << endl;
	}
	cout << endl;

	
	cout << "Task 5" << endl;
	int number1, number2, number3;
	cout << "Enter number 1 : ";
	cin >> number1;
	cout << "Enter number 2 : ";
	cin >> number2;
	cout << "Enter number 3 : ";
	cin >> number3;
	if (number1 == number2 && number2 == number3)
	{
		cout << "Numbers are EVEN" << endl;
	}
	else
	{
		cout << "Numbers are NOT EVEN" << endl;
	}
	cout << endl;


	cout << "Task 6" << endl;
	int side_1, side_2, side_3, side_4;
	cout << "Enter side 1 length : ";
	cin >> side_1;
	cout << "Enter side 2 length : ";
	cin >> side_2;
	cout << "Enter side 3 length : ";
	cin >> side_3;
	cout << "Enter side 4 length : ";
	cin >> side_4;
	if (side_1 == side_2 && side_2 == side_3 && side_3 == side_4)
	{
		cout << "This is a SQUARE" << endl;
	}
	else if (side_1 == side_3 && side_2 == side_4)
	{
		cout << "This is a RECTANGLE" << endl;
	}
	else 
	{
		cout << "This is not a SQUARE or a RECTANGLE" << endl;
	}
	cout << endl;

	

}

