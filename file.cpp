#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ofstream file ("example.txt");
    file<<"hello,C++ file!";
    file.close();
    cout<< "file written succesfully."<< endl;
    return 0;

}
