#include<iostream>
using namespace std;

int main(){

    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr1, *ptr2;
    
    ptr1 = &arr[0];  // points to first element
    ptr2 = &arr[4];  // points to last element
    
    cout<<"ptr1 address : "<<ptr1<<"\n";
    cout<<"ptr2 address : "<<ptr2<<"\n";
    
    cout<<"\nptr1 value: "<<*ptr1<<"\n";
    cout<<"ptr2 value: "<<*ptr2<<"\n";
    
    cout<<"\nptr2 - ptr1 = "<<ptr2 - ptr1<<" elements apart\n";
    
    return 0;
}
