#include <iostream>
using namespace std;

class Document
{
    string name;
    string format;
    int pages;
public:
    Document() :name("none"), format("none"), pages(0) {}
    Document(string n, string f, int p) :name(n), format(f) 
    {
        this->pages = p > 0 ? p : 0;
    }
    void ShowDocument()
    {
        cout << "Name : " << name << endl;
        cout << "Format : " << format << endl;
        cout << "Pages : " << pages << endl;
    }
};
class Cartridge
{
    string color;
    float volume;
public:
    Cartridge() :color("none"), volume(0) {}
    Cartridge(string c, float v) :color(c), volume(v) {}
    void ShowInfo()const
    {
        cout << "Color : " << color << endl;
        cout << "Volume : " << volume << endl;
    }

};
class Scanner
{
    float resolution;
    float height, width;
public:
    Scanner() :resolution(0), height(0), width(0) {}
    Scanner(float r, float h, float w) :resolution(r), height(h), width(w) {}
    void ShowInfo()const
    {
        cout << "Scan resolution : " << resolution << " dpi " << endl;
        cout << "Area Scan : " << height << " * " << width << endl;
    }
};
enum Type
{
    None, Color, Black
};
class Printer
{
private:
    string model;
    Type type;
    //composition
    Scanner scanner;//default ctor
    Cartridge* cartridges;
    int countCart;

    //agregation
    Document* currentDoc;
public:
    Printer() :model("none"), type(None), cartridges(nullptr),
        countCart(0), currentDoc(nullptr) {
    }
    Printer(string m, Type t, float r, float h, float w) : currentDoc(nullptr)
    {
        this->model = m;
        this->type = t;
        scanner = Scanner(r, h, w);

        countCart = 4;
        cartridges = new Cartridge[countCart];
        cartridges[0] = Cartridge("red", 300);
        cartridges[1] = Cartridge("green", 300);
        cartridges[2] = Cartridge("blue", 300);
        cartridges[3] = Cartridge("black", 500);
    }
    void PrintDodument()
    {
        cout << "Printing......." << endl;
        if (currentDoc != nullptr)
            currentDoc->ShowDocument();
        else
            cout << "No document to print!" << endl;
    }
    void Cancel()
    {
        currentDoc = nullptr;
    }
    void Scan()
    {
        cout << "Scanning......." << endl;
    }
    void AddDoc(Document& doc)
    {
        currentDoc = &doc;
    }
    void ShowProperties()
    {
        cout << "Model : " << model << endl;
        cout << "Type : ";
        switch (type)
        {
        case None:cout << "None" << endl; break;
        case Color:cout << "Color" << endl; break;
        case Black:cout << "Black" << endl;  break;
        }
        scanner.ShowInfo();
        for (int i = 0; i < countCart; i++)
        {
            cartridges[i].ShowInfo();
        }
    }
    ~Printer()
    {
        if (cartridges != nullptr)
            delete[]cartridges;
    }
};


int main()
{
    Printer p("Canon", Type::Color, 300, 50, 30);//default ctor
    p.PrintDodument();
    p.Scan();
    p.ShowProperties();

    Document myDoc("Passport", "A6", 7);
    myDoc.ShowDocument();

    p.AddDoc(myDoc);
    p.PrintDodument();

    Document myDoc2("C++ for begginers", "A5", 1523);
    myDoc2.ShowDocument();
    p.AddDoc(myDoc2);
    p.Cancel();
    p.PrintDodument();
}
