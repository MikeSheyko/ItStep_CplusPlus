#include "Vector.h"


int main()
{
    Point p1(5, 4);
    Point p2(-1, 9);

    cout << " -------------- Print Point 1 --------------" << endl;
    cout << "p1: ";
    p1.Print();
	cout << endl;

    cout << " -------------- Print Point 2 --------------" << endl;
    cout << "p2: ";
    p2.Print();
    cout << endl;

    cout << " -------------- Summa P1 + P2 --------------" << endl;
    Point summa = p1 + p2;
    cout << "p1 + p2: ";
    summa.Print();
    cout << endl;

    cout << " -------------- Difference P1 - P2 --------------" << endl;
    Point difference = p1 - p2;
    cout << "p1 - p2: ";
    difference.Print();
    cout << endl;

    cout << " ------------- Comparison P1 and P2 ------------" << endl;
    cout << "p1 < p2: " << ((p1 < p2) ? "True" : "False") << endl;
    cout << "p1 > p2: " << ((p1 > p2) ? "True" : "False") << endl;
    

    cout << " -------------- Reverse P1 --------------" << endl;
    Point reverse = !p1;
    cout << "!p1: ";
    reverse.Print();
    cout << endl;

	cout << " -------------- Reverse P2 --------------" << endl;
    Point reverse2 = !p2;
    cout << "!p2: ";
    reverse2.Print();
    cout << endl;
    

    cout << "-------------- Vector --------------" << endl;
    Vector v;
    v.Add(p1);
    v.Add(p2);
    v.Add(Point(0, 0));

    v.Print();

}



