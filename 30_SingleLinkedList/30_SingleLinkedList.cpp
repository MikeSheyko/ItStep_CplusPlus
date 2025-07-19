#include <iostream>
using namespace std;


struct Node 
{
    int value;
    Node* next;
	Node(int value, Node* next) :value(value), next(next) {} // Constructor to initialize value and next pointer

};



class List
{
private:
	Node* head;
public:
    List() 
    {
		head = nullptr;
    }
    void AddToHead(int value) 
    {
		//Node* newNode = new Node; // Allocate memory for new node
		//newNode->value = value;   // Set the value of the new node
		//newNode->next = head;     // Point the new node's next to the current head
		//head = newNode;           // Update the head to point to the new node

		Node* newNode = new Node(value, head);
		head = newNode;
	}

	void AddToTail(int value) 
	{
		Node* newNode = new Node(value, nullptr);

		if (head == nullptr) 
		{
			head = newNode; // If the list is empty, set head to the new node
			return;
		}
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}

			current->next = newNode; // Set the next of the last node to the new node
		}
	}


	int getElement(int pos)
	{
		Node* current = head;
		int i = 1;
		while (current != nullptr)
		{
			if (pos == i) return current->value; 
			current = current->next;
			i++;
		}
		return -1; // Return -1 if position is out of bounds
	}

	int operator[](int pos)
	{
		Node* current = head;
		int i = 1;
		while (current != nullptr)
		{
			if (pos == i) return current->value;
			current = current->next;
			i++;
		}
		return -1; // Return -1 if position is out of bounds
	}

	void deleteFromHead()
	{
		if (head == nullptr) 
		{
			cout << "List is empty" << endl;
			return; // If the list is empty, do nothing
		}
		Node* current = head;
		head = head->next;	// Move head to the next node
		delete current;		// Delete the old head
	}

	void deleteFromTail()
	{
		if (head == nullptr) 
		{
			cout << "List is empty, nothing to delete." << endl;
			return; // If the list is empty, do nothing
		}
		if (head->next == nullptr) 
		{
			delete head; // If there's only one node, delete it
			head = nullptr; // Set head to nullptr
			return;
		}
		else
		{
			Node* current = head;
			while (current->next->next != nullptr)
			{
				current = current->next; // Traverse to the second last node

			}
			delete current->next;		// Delete the last node
			current->next = nullptr;	// Set the next of the second last node to nullptr	
		}
		

	}

	void Print() 
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->value << " ";
			current = current->next;
		}
		cout << endl;
		
	}

	~List()
	{
		Node* current = nullptr;
		while (head != nullptr) 
		{
			current = head;          // Store the current head
			head = head->next;      // Move head to the next node
			delete current;         // Delete the old head
		}

	}



};


int main()
{
    
	List l;
	/*for (int i = 0; i < 10; i++)
	{
		l.AddToHead(i);
	}

	l.Print();*/

	l.AddToTail(100);
	l.AddToTail(200);
	l.AddToTail(300);

	l.Print();

	cout << "Element at position 3: " << l.getElement(3) << endl; // Should print 300
	cout << "Element at position 3: " << l.getElement(300) << endl; // Should print -1 (out of bounds)

	cout << "Element at position 3 using operator[]: " << l[3] << endl; // Should print 300

	l.deleteFromTail(); // Delete the last element (300)
	l.Print(); // Should print 100 200

	l.deleteFromTail();
	l.Print();

	l.deleteFromTail();
	l.Print();
}

