#include <iostream>
using namespace std;
class city {
    char* name;
public:
    city(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
   }
 void display() {
    cout << "city:" << name <<endl;

 }
 ~city(){
    delete[] name;
 }
};
int main(){
    city c("banglore");
    c.display();
    return 0;
}
