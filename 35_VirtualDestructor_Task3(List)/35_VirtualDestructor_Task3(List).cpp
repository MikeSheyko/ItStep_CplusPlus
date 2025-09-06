#include <iostream>
using namespace std;

class List 
{
protected:
    struct Node 
    {
        int data;
        Node* prev;
        Node* next;
        Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    virtual void insert(int value) = 0;
    virtual void remove() = 0;

    
    virtual void removeFromHead() 
    {
        if (!head) 
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    
    virtual void removeFromTail() 
    {
        if (!tail) 
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    virtual void display() const 
    {
        cout << "List : ";
        Node* curr = head;
        while (curr) 
        {
            cout << curr->data << ", ";
            curr = curr->next;
        }
        cout << "EMPTY!" << endl;
    }

    virtual ~List() 
    {
        while (head) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};


class Stack : public List 
{
public:
    void insert(int value) override 
    {
        Node* node = new Node(value);
        node->next = head;
        if (head) head->prev = node;
        else tail = node;
        head = node;
    }

    void remove() override 
    {
        removeFromHead();
    }
};


class Queue : public List 
{
public:
    void insert(int value) override 
    {
        Node* node = new Node(value);
        node->prev = tail;
        if (tail) tail->next = node;
        else head = node;
        tail = node;
    }

    void remove() override 
    {
        removeFromHead();
    }

    
    void priorityInsert(int value) 
    {
        Node* node = new Node(value);

        if (!head) 
        {
            head = tail = node;
            return;
        }

        if (value < head->data) 
        {
            node->next = head;
            head->prev = node;
            head = node;
            return;
        }

        Node* curr = head;
        while (curr->next && curr->next->data < value) 
        {
            curr = curr->next;
        }

        node->next = curr->next;
        node->prev = curr;

        if (curr->next)
            curr->next->prev = node;
        else
            tail = node;

        curr->next = node;
    }
};

void SubMenu(List* list) 
{
    int choice;
    do {
        cout << endl;
        cout << "[1] Insert" << endl;
        cout << "[2] Remove" << endl;
        cout << "[3] Remove from front" << endl;
        cout << "[4] Remove from back" << endl;
        cout << "[5] Display" << endl;
        cout << "[6] Priority insert (ONLY FOR QUEUE)" << endl;
        cout << "[0] Back" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) 
        {
        case 1: 
        {
            int val;
            cout << "Enter value : ";
            cin >> val;
            list->insert(val);
            break;
        }
        case 2:
            list->remove();
            break;
        case 3:
            list->removeFromHead();
            break;
        case 4:
            list->removeFromTail();
            break;
        case 5:
            list->display();
            break;
        case 6: 
        {
            Queue* q = dynamic_cast<Queue*>(list);
            if (q) 
            {
                int val;
                cout << "Enter value for priority insert : ";
                cin >> val;
                q->priorityInsert(val);
            }
            else 
            {
                cout << "Priority insert available ONLY FOR QUEUE!" << endl;
            }
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid option!" << endl;
        }

    } while (choice != 0);
}


int main() 
{
    List* list = nullptr;
    int choice;

    do {
        cout << "------------MAIN MENU------------" << endl;
        cout << "[1] Stack" << endl;
        cout << "[2] Queue" << endl;
        cout << "[0] Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        delete list;
        list = nullptr;

        switch (choice) {
        case 1:
            list = new Stack();
            SubMenu(list);
            break;
        case 2:
            list = new Queue();
            SubMenu(list);
            break;
        case 0:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!!" << endl;
        }

    } while (choice != 0);

    delete list;
    return 0;
}
