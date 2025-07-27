#include <iostream>
using namespace std;

template<typename T_value>
class List
{
	struct Node
	{
		Node* prev;
		T_value value;
		Node* next;
		Node(Node* prev, T_value value, Node* next) :prev(prev), value(value), next(next) {}
	};

	Node* head;
	Node* tail;

public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}
	bool IsEmpty()
	{
		return head == nullptr;
	}
	void AddToHead(T_value value)
	{
		Node* newNode = new Node(nullptr, value, head);

		if (IsEmpty())
		{
			head = tail = newNode;
		}
		head->prev = newNode;
		head = newNode;
	}
	void PrintList()
	{
		//Node* current = head;//int i = 0;
		//while (current != nullptr)//i < 10;
		//{
		//	cout << current->value << " ";//algorithm
		//	current = current->next;//i++
		//}
		for (Node* i = head; i != nullptr; i = i->next)
		{
			cout << i->value << " ";
		}
		cout << endl;
	}
	~List()
	{
		Node* current = nullptr;
		while (head != nullptr)
		{
			current = head;
			head = head->next;
			delete current;
		}
	}
	void AddToTail(T_value value)
	{
		Node* newNode = new Node(tail, value, nullptr);
		if (IsEmpty())
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}
	T_value GetElement(int pos)
	{
		Node* current = head;
		int i = 1;
		while (current != nullptr)
		{
			if (i == pos) return current->value;
			current = current->next;
			i++;
		}
	}
	T_value operator[](int pos)
	{
		Node* current = head;
		int i = 1;
		while (current != nullptr)
		{
			if (i == pos) return current->value;
			current = current->next;
			i++;
		}
	}
	void DeleteFromTail()
	{

		if (IsEmpty())return;
		if (head->next == nullptr)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}

	}
};

int main()
{
	List<int> l;
	l.AddToHead(100);
	l.AddToHead(200);
	l.AddToHead(300);
	l.PrintList();
	l.AddToTail(1);
	l.AddToTail(2);
	l.AddToTail(3);
	l.AddToTail(4);
	l.PrintList();
	l.DeleteFromTail();
	l.DeleteFromTail();
	l.DeleteFromTail();
	l.PrintList();





}