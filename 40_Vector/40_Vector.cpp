#include <iostream>
#include <vector>
using namespace std;

void PrintVector(const vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}






int main()
{
   
	vector<int> v; // v is an empty vector size 0
	vector<int> v1({ 1,2,3,4,5,6,7,8,9,10 }); // size 10
	vector<int> v2(20); // size 20, all elements are 0
	vector<int> v3({ 22, 33, 44, 55, 66 }); // size 5
		

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";

	}
	cout << endl;

	v1[1] = 22;
	for (int item : v1)
	{
		cout << item << " - ";
	}
	cout << endl;


	cout << "Size : " << v1.size() << endl;
	cout << "Capacity : " << v1.capacity() << endl;

	//delete element
	v1.erase(v1.begin()); // delete 1st element
	PrintVector(v1);

	v1.erase(v1.begin() + 3); // delete 4th element
	PrintVector(v1);


	v1.erase(v1.begin() + 2, v1.end() - 2); // delete from 3rd to 8th element
	PrintVector(v1);

	v1.erase(v1.end() - 1);
	PrintVector(v1);
	


	
	//insert element

	v1.insert(v1.end(), 77); // insert 77 at the end
	PrintVector(v1);

	cout << "Size : " << v1.size() << endl;
	cout << "Capacity : " << v1.capacity() << endl; // capacity >= size

	v1.insert(v1.begin(), {11,12,14,15}); // insert 11 at the beginning
	PrintVector(v1);
	cout << "Size : " << v1.size() << endl;
	cout << "Capacity : " << v1.capacity() << endl;


	v1.insert(v1.begin() + 4, 5, 88); // insert five 88 at index 4
	PrintVector(v1);
	cout << "Size : " << v1.size() << endl;
	cout << "Capacity : " << v1.capacity() << endl;


	v1.insert(v1.end(), v3.begin(), v3.end()); // insert v3 at the end
	PrintVector(v1);
	cout << "Size : " << v1.size() << endl;
	cout << "Capacity : " << v1.capacity() << endl;


	//Add element at the end
	v1.push_back(444); // insert 444 at the end
	v1.push_back(444);
	v1.push_back(444);
	v1.push_back(444);
	PrintVector(v1);

	//delete the last element
	v1.pop_back();
	v1.pop_back();
	PrintVector(v1);



	//swap two vectors
	//v1.swap(v3);
	PrintVector(v1);
	PrintVector(v3);


	cout << "Front [first element] : " << v1.front() << endl;
	cout << "Back [last element] : " << v1.back() << endl;

	//resize
	v1.resize(50, 5); 
	PrintVector(v1);


	v1.resize(10);
	PrintVector(v1);
	v1.shrink_to_fit(); //capacity = size
	cout << "Size : " << v1.size() << endl;
	cout << "Capacity : " << v1.capacity() << endl;



	

}

