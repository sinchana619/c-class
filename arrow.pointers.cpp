#include <iostream>
using namespace std;
class Person {
    public:
    string name = "default name";
    Person (string name)
    {
       
        this->name = name;
    }
    void Print()
    {
        cout << name << endl;
    }

};
int main()
{
    Person P1("sinchana");
    P1.Print();
}