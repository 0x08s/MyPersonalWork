#include<iostream>
using namespace std;

int main(){
    int matrix[3][3];
    int transpose[3][3];
    
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
    
    // Transpose the matrix (swap rows and columns)
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            transpose[i][j] = matrix[j][i];
    
    // Display transposed matrix
    cout<<"\nTransposed Matrix:\n";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
            cout<<transpose[i][j]<<"\t";
        cout<<"\n";
    }
    
    return 0;
}