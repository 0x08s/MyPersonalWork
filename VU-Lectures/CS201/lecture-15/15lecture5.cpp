#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char source[100], dest[100];
    
    // Input source string

    cout<<"Enter a string: ";

    cin.getline(source, 100);
    
    // Copy source into dest

    strcpy(dest, source);
    
    // Display both arrays

    cout<<"\nSource Array: "<<source<<"\n";
    
    cout<<"Copied Array: "<<dest<<"\n";
    
    return 0;
}
