#include<iostream>
using namespace std;

int main(){
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    
    cout<<"Using Pointer Arithmetic:\n\n";
    
    for(int i=0; i<5; i++){

        cout<<"*(ptr+"<<i<<") = "<<*(ptr+i)<<"\n";
    }
    cout<<"\nAddresses:\n";

    for(int i=0; i<5; i++){
        cout<<"(ptr+"<<i<<") = "<<(ptr+i)<<"\n";
    }
    return 0;
}
