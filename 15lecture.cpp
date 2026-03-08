#include<iostream>
using namespace std;

int main(){
    int num = 10;
    
    int *ptr;
    
    // Assign address of num to pointer

    ptr = &num;
    
    // Display value and address

    cout<<"Value of num  : "<<num<<"\n";

    cout<<"Address of num : "<<&num<<"\n";

    cout<<"Pointer ptr holds : "<<ptr<<"\n";

    cout<<"Value at ptr (*ptr) : "<<*ptr<<"\n";
    
    // Display incremented address

    cout<<"\nAfter ptr++:\n";

    ptr++;

    cout<<"Incremented Address : "<<ptr<<"\n";
    
    cout<<"\nNote: Address incremented by 4 bytes\n";
    
    return 0;
}
