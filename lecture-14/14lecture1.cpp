#include<iostream>
#include<cstring>
using namespace std;

// Function to convert string to uppercase

void toUpperCase(char str[]){
for(int i=0; i<strlen(str); i++){

if(str[i]>='a' && str[i]<='z'){

str[i] = str[i] - 32;  // subtract 32 to convert to uppercase
}
}
}
int main(){

    char str[100];
    
    // Input string from user
    cout<<"Enter a string: ";
    cin.getline(str, 100);
    
    // Display original string

    cout<<"\nOriginal String : "<<str;
    
    // Convert to uppercase

    toUpperCase(str);
    
    // Display uppercase string

    cout<<"\nUppercase String: "<<str;
    
    cout<<"\n";

    return 0;
}
