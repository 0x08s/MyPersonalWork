#include<iostream>
using namespace std;

int main(){
    int arr[5] = {10, 20, 30, 40, 50};
    
    int *ptr;
    
    // Pointer points to first element of array
    ptr = arr;  
    
    cout<<"Accessing Array Elements \n";
    
    // Method 1: Using array index

    cout<<"\nMethod 1 - Using Array Index (arr[i]):\n";

    for(int i=0; i<5; i++){
        cout<<"arr["<<i<<"] = "<<arr[i]<<"\n";
    }
    // Method 2: Using pointer with index

    cout<<"\nMethod 2 - Using Pointer with Index (ptr[i]):\n";

    for(int i=0; i<5; i++){

        cout<<"ptr["<<i<<"] = "<<ptr[i]<<"\n";
    }
    // Method 3: Using pointer arithmetic with dereference

    cout<<"\nMethod 3 - Using Pointer Arithmetic (*(ptr+i)):\n";

    for(int i=0; i<5; i++){

        cout<<"*(ptr+"<<i<<") = "<<*(ptr+i)<<"\n";
    }
    // Method 4: Using pointer increment

    cout<<"\nMethod 4 - Using Pointer Increment (ptr++):\n";

    ptr = arr;  // reset pointer to start

    for(int i=0; i<5; i++){

        cout<<"*ptr = "<<*ptr<<"\n";
    
        ptr++;
    }
    
    // Display addresses

    cout<<"\n Memory Addresses\n";

    ptr = arr;  // reset pointer to start

    for(int i=0; i<5; i++)

        cout<<"Address of arr["<<i<<"] = "<<&arr[i]<<"\n";
    
    return 0;
}
