#include <iostream>
using namespace std;
int add_recursion(int num)
{
    if (num <= 0)
    {
        return 0;
    }
    if (num i*i>n)
    {
        return add_recursion(num - 1);
    }
    return num + add_recursion(num - 1);
}
int main()
{
    cout << add_recursion(10) << endl;
}