#include<iostream>
using namespace std;

int main(int argc, char *argv[]){
    
    // Display number of arguments

    cout<<"Total Arguments (argc): "<<argc<<"\n\n";
    
    // Display all arguments

    cout<<"Arguments passed:\n";

    for(int i=0; i<argc; i++){
        cout<<"argv["<<i<<"] = "<<argv[i]<<"\n";
    
    return 0;
}
}