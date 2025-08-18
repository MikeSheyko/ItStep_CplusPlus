#include <iostream>
using namespace std;


struct Vagon 
{
    int number;
    int seats;
    int passengers;

    Vagon(int n = 0, int s = 0, int p = 0) : number(n), seats(s), passengers(p) {}
};


template <typename T>
class List 
{
private:
    struct Node 
    {
        T data;
        Node* prev;
        Node* next;
        Node(const T& d) : data(d), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    
    List(const List& other) : head(nullptr), tail(nullptr), size(0) {Node* current = other.head;
        while (current) 
        {
            PushBack(current->data);
            current = current->next;
        }
    }

    ~List() {
        while (head)
            PopFront();
    }

    void PushFront(const T& value) 
    {
        Node* node = new Node(value);
        node->next = head;
        if (head) head->prev = node;
        head = node;
        if (!tail) tail = node;
        ++size;
    }

    void PushBack(const T& value) 
    {
        Node* node = new Node(value);
        node->prev = tail;
        if (tail) tail->next = node;
        tail = node;
        if (!head) head = node;
        ++size;
    }

    void PopFront() 
    {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        --size;
    }

    void PopBack() 
    {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        --size;
    }

    void DeleteAtPos(int pos) 
    {
        if (pos < 0 || pos >= size) return;
        Node* current = head;
        for (int i = 0; i < pos; ++i)
            current = current->next;

        if (current->prev)
            current->prev->next = current->next;
        else
            head = current->next;

        if (current->next)
            current->next->prev = current->prev;
        else
            tail = current->prev;

        delete current;
        --size;
    }

    void InsertAtPos(int pos, const T& value) 
    {
        if (pos <= 0) 
        {
            PushFront(value);
        }
        else if (pos >= size) 
        {
            PushBack(value);
        }
        else 
        {
            Node* current = head;
            for (int i = 0; i < pos; ++i)
                current = current->next;

            Node* node = new Node(value);
            node->next = current;
            node->prev = current->prev;
            current->prev->next = node;
            current->prev = node;
            ++size;
        }
    }

    void Print() const 
    {
        Node* current = head;
        while (current) 
        {
            cout << "Vagon " << current->data.number << " | Seats: " << current->data.seats << " | Passengers: " << current->data.passengers << endl;
            current = current->next;
        }
    }

    int GetSize() const 
    {
        return size;
    }
};


class Train 
{
private:
    string model;
    int countVagons;
    List<Vagon> vagons;

public:
    Train() : model("NoName"), countVagons(0) {}

    Train(string m) : model(m), countVagons(0) {}

    Train(const Train& other) 
    {
        model = other.model;
        countVagons = other.countVagons;
        vagons = other.vagons;
    }

    void Show() const 
    {
        cout << "Train model: " << model << endl;
        cout << "Number of vagons: " << countVagons << endl;
        vagons.Print();
    }

    void AddToHead(const Vagon& v) 
    {
        vagons.PushFront(v);
        countVagons++;
    }

    void AddToTail(const Vagon& v) 
    {
        vagons.PushBack(v);
        countVagons++;
    }

    void RemoveFromHead() 
    {
        if (countVagons > 0) 
        {
            vagons.PopFront();
            countVagons--;
        }
    }

    void RemoveFromTail() 
    {
        if (countVagons > 0) 
        {
            vagons.PopBack();
            countVagons--;
        }
    }

    void AddAtPos(int pos, const Vagon& v) 
    {
        vagons.InsertAtPos(pos, v);
        countVagons++;
    }

    void RemoveAtPos(int pos) 
    {
        if (pos >= 0 && pos < countVagons) 
        {
            vagons.DeleteAtPos(pos);
            countVagons--;
        }
    }
};





int main()
{
    Train t("L0 Series Maglev");

    t.AddToTail(Vagon(1, 50, 45));
    t.AddToTail(Vagon(2, 60, 50));
    t.AddToHead(Vagon(0, 40, 35));
    t.Show();

	cout << endl;
	cout << "Removing from head and adding at position 1: " << endl;
    t.RemoveFromHead();
    t.Show();

    cout << endl;
    cout << "Adding at position 3: " << endl;
    t.AddAtPos(3, Vagon(4, 55, 52));
    t.Show();

    cout << endl;
    cout << "Removing vagon at position 2 : " << endl;
    t.RemoveAtPos(1);
    t.Show();





}

