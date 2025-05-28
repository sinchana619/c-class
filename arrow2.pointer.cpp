#include <iostream>
using namespace std;
class Person {
    public:
    string name = "default name";
    int age = 0;
    Person (string name , int age)
    {
       
        this->name = name;
        this->age = age;
    }
    void Print()
    {
        cout << name << endl;
        cout << age << endl;
    }

};
int main()
{
    Person P1("sinchana", 18);
    P1.Print();
    cout << "size of variable:" << sizeof(P1) << " bytes" << endl;
}