#include <iostream>
using namespace std;
int main(){
    int num;
    cout<<"enter a number";
    cin>> num;
    try 
    {
        if (num < 0)
        throw "negative number entered:";
    cout << "you entered:"<< num<< endl;

    }
    catch(const char *msg)
    {
        cout << "expection:" << msg << endl;
    }
    return 0;
}
