#include<iostream>
using namespace std;

int main(){
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    
    cout<<"Accessing matrix using pointer:\n\n";
    
    // Using array name as pointer

for(int i=0; i<2; i++){
    for(int j=0; j<3; j++){
            cout<<"*(*(matrix+"<<i<<")+"<<j<<") = "<<*(*(matrix+i)+j)<<"\n";
    }
}
    // Display addresses

    cout<<"\nRow Addresses:\n";

    for(int i=0; i<2; i++){

    cout<<"*(matrix+"<<i<<") = "<<*(matrix+i)<<"\n";
    }

    return 0;
}

