#include<iostream>
using namespace std;

int main(){
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr;
    
    // Point to first element of array

    ptr = arr;
    
    cout<<"Stepping through array using pointer:\n\n";

    cout<<"Index\nAddress\nValue\n";
    cout<<"\n";
    
    for(int i=0; i<5; i++){

        cout<<i<<"\t"<<ptr<<"\t"<<*ptr<<"\n";

        ptr++;  // move pointer to next element
    }
    
    // Stepping backwards
    ptr--;
    
    cout<<"\nStepping backwards through array:\n\n";

    cout<<"Index\nAddress\n\tValue\n";

    cout<<"\n";
    
    for(int i=4; i>=0; i--){
        cout<<i<<"\n"<<ptr<<"\n"<<*ptr<<"\n";
        ptr--;  // move pointer to previous element
    }
    
    return 0;
}