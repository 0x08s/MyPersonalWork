#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char str1[100], str2[100], str3[100];
    
    // Input strings
    
    cout<<"Enter first string : ";

    cin.getline(str1, 100);
    
    cout<<"Enter second string: ";

    cin.getline(str2, 100);
    
    // strcpy to preserve original strings

    strcpy(str3, str1);
    
    // strcat - full concatenation

    cout<<"\nstrcat\n";

    cout<<"str1 before strcat : "<<str1<<"\n";

    cout<<"str2 : "<<str2<<"\n";

    strcat(str1, str2);

    cout<<"str1 after strcat  : "<<str1<<"\n";
    
    // strncat - partial concatenation

    cout<<"\nstrncat \n";
    cout<<"str3 : "<<str3<<"\n";

    cout<<"str2 : "<<str2<<"\n";

    strncat(str3, str2, 3);  // append only first 3 chars of str2

    cout<<"str3 after strncat : "<<str3<<"\n";

    cout<<"(Only first 3 characters of str2 appended)\n";
    
    return 0;
}
