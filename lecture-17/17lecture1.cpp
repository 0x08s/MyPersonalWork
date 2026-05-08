#include<iostream>
#include<cstring>
using namespace std;

int main(){

    char str1[100], str2[100], str3[100];
    
    cout<<"Enter first string : ";

    cin.getline(str1, 100);
    
    cout<<"Enter second string: ";

    cin.getline(str2, 100);
    
    // strlen - string length

    cout<<"\n String Manipulation\n";

    cout<<"\nLength of str1 : "<<strlen(str1);

    cout<<"\nLength of str2 : "<<strlen(str2);
    
    // strcpy - string copy

    strcpy(str3, str1);

    cout<<"\n\nCopied str1 to str3: "<<str3;
    
    // strcat - string concatenation

    strcat(str1, str2);

    cout<<"\n\nAfter strcat : "<<str1;
    
    // strcmp - string comparison

    cout<<"\n\nComparing str2 and str3:\n";

    int result = strcmp(str2, str3);

if(result == 0){

cout<<"Strings are Equal\n";

}    
else if(result < 0){

cout<<"str2 is Less than str3\n";

}

else{

cout<<"str2 is Greater than str3\n";

}
    // strupr - string to uppercase

    cout<<"\nstr2 in Uppercase  : "<<strupr(str2);

    
    // strlwr - string to lowercase

    cout<<"\nstr2 in Lowercase  : "<<strlwr(str2);
    
    // strrev - string reverse

    cout<<"\nstr3 Reversed      : "<<strrev(str3);
    
    cout<<"\n";

    return 0;
}