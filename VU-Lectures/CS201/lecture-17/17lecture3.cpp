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
    
    // strcpy - full copy

    cout<<"\nstrcp \n";

    cout<<"str2 before strcpy : "<<str2<<"\n";

    strcpy(str3, str1);

    cout<<"str1 : "<<str1<<"\n";

    cout<<"str3 after strcpy  : "<<str3<<"\n";

    cout<<"(Full str1 copied into str3)\n";
    
    // strncpy - partial copy

    cout<<"\nstrncpy\n";

    strncpy(str3, str2, 3);  // copy only first 3 chars

    str3[3] = '\0';          // null terminate manually

    cout<<"str2  : "<<str2<<"\n";

    cout<<"str3 after strncpy : "<<str3<<"\n";

    cout<<"(Only first 3 characters of str2 copied)\n";
    
    return 0;
}

