#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node 
{
    T data;
    int priority;
    Node* next;

    Node(const T& data, int priority) : data(data), priority(priority), next(nullptr) {}
};


template <typename T>
class PriorityQueue 
{
private:
    Node<T>* front;
public:
    PriorityQueue() : front(nullptr) {}

    ~PriorityQueue() 
    {
        while (front != nullptr) 
        {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
        }
    }
        
    void Enqueue(const T& data, int priority) 
    {
        Node<T>* newNode = new Node<T>(data, priority);

        if (!front || priority > front->priority) 
        {
            newNode->next = front;
            front = newNode;
        }
        else 
        {
            Node<T>* current = front;
            while (current->next && current->next->priority >= priority) 
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    T Dequeue() 
    {
        if (!front) throw std::out_of_range("Queue is empty");

        Node<T>* temp = front;
        T data = front->data;
        front = front->next;
        delete temp;
        return data;
    }

    bool IsEmpty() const 
    {
        return front == nullptr;
    }

    void Display() const 
    {
        if (!front) 
        {
            std::cout << "Queue is empty!" << endl;
            return;
        }
        Node<T>* current = front;
        std::cout << "Current queue: " << endl;
        while (current) 
        {
            std::cout << "Document: " << current->data << " | Priority: " << current->priority << endl;
            current = current->next;
        }
    }
};

int main() 
{
    PriorityQueue<std::string> printQueue;

    while (true) {
        cout << "---------Printer Queue Menu---------" << endl;
        cout << "Add document to queue              [1]" << endl;;
        cout << "Print next document                [2]" << endl;
        cout << "Show queue                         [3]" << endl;
        cout << "Exit                               [4]" << endl;
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string filename;
            int position;

            cout << "Enter file name : ";
            cin >> filename;

            cout << "Select position : " << endl;
            cout << "1 - Guest" << endl << "2 - Administrator" << endl << "3 - Manager" << endl << "4 - Director" << endl;
            cout << "Enter position number : ";
            cin >> position;

            int priority = 0;
            switch (position) 
            {
            case 1: priority = 1; break;
            case 2: priority = 2; break;
            case 3: priority = 3; break;
            case 4: priority = 4; break;
            default:
                cout << "Invalid position, default priority set to 1 (Guest)!" << endl;
                priority = 1;
                break;
            }

            printQueue.Enqueue(filename, priority);
            cout << "Document added to queue!" << endl;

        }
        else if (choice == 2) 
        {
            if (printQueue.IsEmpty()) 
            {
                cout << "No documents to print!" << endl;
            }
            else 
            {
                string doc = printQueue.Dequeue();
                cout << "Printing document : " << doc << endl;
            }
        }
        else if (choice == 3) 
        {
            printQueue.Display();
        }
        else if (choice == 4) 
        {
           cout << "Exiting program! Goodbye!" << endl;
           break;
        }
        else
        {
            cout << "Invalid option! Try again!" << endl;
        }
    }



}
