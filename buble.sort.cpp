#include <iostream>
using namespace std;
void BubbleSort(int arr[],int length){
    for (int i=0;i<length-1; i++){
        for (int j=0; j<length-1; j++){
            int temp;
            if (arr[j]> arr[j + 1]){
                temp =arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
        }

    }
}
void print(int arr[],int length){
    for(int i=0; i < length; i++){
        cout<< arr[i]<<" ";
    }
    cout << endl;
}
int main(){
    int array[] ={5,4,6,3,7,2,0,9};
    int arraySize =sizeof(array)/sizeof(array[0]);
    print(array, arraySize);
    BubbleSort(array,arraySize);
    print(array,arraySize);
}