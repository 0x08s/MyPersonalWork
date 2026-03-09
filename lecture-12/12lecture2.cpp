#include<iostream>
using namespace std;

void changeArray(int arr[], int size){
    for(int i=0; i<size; i++)
        arr[i] = arr[i] * 2; 
}
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    
    cout<<"Before function call:\n";
    for(int i=0; i<5; i++)
        cout<<arr[i]<<" ";
    
    changeArray(arr, 5); 
    cout<<"\n\nAfter function call:\n";
    for(int i=0; i<5; i++)
        cout<<arr[i]<<" ";
    
    cout<<"\n\n origional arry also changed";
    cout<<"\n(This proves it is Call by Reference)\n";
    
    return 0;
}