#include<iostream>
using namespace std;

int main(){
    int a[5], b[5];
    
    cout<<"Enter 5 elements for Array 1: ";
    for(int i=0; i<5; i++) cin>>a[i];
    
    cout<<"Enter 5 elements for Array 2: ";
    for(int i=0; i<5; i++) cin>>b[i];
    
    cout<<"\nArray 1: ";
    for(int i=0; i<5; i++){ 
    cout<<a[i]<<" ";
    }
    cout<<"\nArray 2: ";
    for(int i=0; i<5; i++){ 
    cout<<b[i]<<" ";
    }
    cout<<"\n\nComparison Results:\n";

    for(int i=0; i<5; i++){
        cout<<"a["<<i<<"]="<<a[i]<<i<<b[i]<<"";
        if(a[i]>b[i]){
        cout<<"A is greater\n";
        }

        else if(a[i]<b[i]) {
        cout<<"B is greater\n";
        }

        else{                
        cout<<"Equal\n";
        }
    }
    
    return 0;
}
