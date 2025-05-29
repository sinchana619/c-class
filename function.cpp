#include <iostream>
using namespace std;
int add( int a, int b) {
    return a+b;

}

int main(){
    int num1, num2, sum;
    cout <<"enter first number:" << endl;
    cin >> num1;
    cout<< "enter secound number:" << endl;
    cin >> num2;
    sum =add(num1, num2);
    cout << "sum is " << sum << endl;
    
}