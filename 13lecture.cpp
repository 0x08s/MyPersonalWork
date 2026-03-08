#include<iostream>
using namespace std;

int main(){
    int matrix[3][3];
    int flipped[3][3];
    
    // Input matrix from user
    
    cout<<"Enter elements of 3x3 matrix:\n";
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++){
            cout<<"Enter element ["<<i<<"]["<<j<<"]: ";
            cin>>matrix[i][j];
        }
    
    // Display original matrix

    cout<<"\nOriginal Matrix:\n";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
            cout<<matrix[i][j]<<"\t";
        cout<<"\n";
    }
    
    // Flip the matrix (reverse row order)

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            flipped[i][j] = matrix[2-i][j];
    
    // Display flipped matrix

    cout<<"\nFlipped Matrix (Reversed Row Order):\n";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
            cout<<flipped[i][j]<<"\t";
        cout<<"\n";
    }
    
    return 0;
}