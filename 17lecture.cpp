#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    
    cout<<"ASCII Code Table \n\n";
    cout<<setw(8)<<"ASCII"<<setw(10)<<"Character"<<"\n";
    cout<<"\n";
    
    // Display ASCII table from 32 to 127

    for(int i=32; i<=127; i++){

    if(i==32){

    cout<<setw(8)<<i<<setw(10)<<"(space)"<<"\n";
    }
    else

    cout<<setw(8)<<i<<setw(10)<<(char)i<<"\n";
    }
    
    return 0;
}