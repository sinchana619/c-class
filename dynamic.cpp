#include <iostream>
using namespace std;
int main ()
{
    int *num = new int;
    *num = 50;
    cout << "allocated value:" <<*num << endl;
    cout << "size of variables:"<< sizeof(*num) << " bytes" << endl;
    delete num;
}