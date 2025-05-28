#include <iostream>
using namespace std;
class book {
    public:
    void showTitle(){
        cout <<"C++ Programming" << endl;
 }
};
int main() {
    book b;
    book* ptr = &b;
    ptr->showTitle();
    return 0;
}
    