#include <iostream>
using namespace std;
//struct Element
//{
//    string value;
//    int priority;
//};
//ostream& operator << (ostream& out, const Element& other)
//{
//    out << "Value : " << other.value << ". Priority : " << other.priority << endl;
//    return out;
//}
void Print()
{
    int a;
}
class QueueWithPriority
{
private:
    struct Element
    {
        string value;
        int priority;
        void Print()
        {
            cout << "Value : " << value << ". Priority : " << priority << endl;
        }
    };
    Element* arr;
    int size;
public:
    QueueWithPriority() :arr(nullptr), size(0) {}
    ~QueueWithPriority()
    {
        if (arr != nullptr)delete[]arr;
    }
    void Enqueue(string value, int priority)
    {
        int index = 0;//size = 2
        while (index < size && arr[index].priority < priority) { index++; }
        size++;//1
        Element* temp = new Element[size];
        for (int i = 0; i < index; i++)
        {
            temp[i] = arr[i];
        }
        temp[index] = Element{ value,priority };
        for (int i = index; i < size - 1; i++)
        {
            temp[i + 1] = arr[i];
        }
        if (arr != nullptr)delete[]arr;
        arr = temp;
    }
    bool IsEmpty()
    {
        /* if (size == 0)
             return true;
         else
             return false;*/
        return size == 0;
    }
    Element Dequeue()
    {
        if (!IsEmpty())
        {
            Element first = arr[0];
            for (int i = 0; i < size - 1; i++)
            {
                //size = 6
                arr[i] = arr[i + 1];
            }
            size--;
            return first;
        }
        return Element();
    }
    void Print()
    {
        cout << "------------------ Queueu -----------------" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i].value << " : " << arr[i].priority << "  ";
        }
        cout << "\n______________________________________" << endl;
    }

};

int main()
{
    QueueWithPriority q;
    /* Element el1 = { "A",1 };
     q.Enqueue(el1);*/
     /* q.Enqueue(QueueWithPriority::Element{ "A",1 });
      q.Enqueue(QueueWithPriority::Element{"G",5});
      q.Enqueue(QueueWithPriority::Element{"C",3});
      q.Enqueue(QueueWithPriority::Element{"B",2});
      q.Enqueue(QueueWithPriority::Element{"K",8});*/
    q.Enqueue("A", 1);
    q.Enqueue("G", 5);
    q.Enqueue("C", 3);
    q.Enqueue("B", 2);
    q.Enqueue("K", 8);

    q.Print();
    q.Enqueue("D", 4);
    q.Print();

    while (!q.IsEmpty())
    {
        q.Dequeue().Print();
    }





}