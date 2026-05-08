#include<iostream>
using namespace std;

int main(){
    int matrix[2][3];
    
    cout<<"Enter 6 values for 2x3 matrix:\n";
    for(int i=0; i<2; i++)
        for(int j=0; j<3; j++){
            cout<<"Enter element ["<<i<<"]["<<j<<"]: ";
            cin>>matrix[i][j];
        }
    
    cout<<"\nMatrix (2 rows x 3 columns):\n";
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++)
            cout<<matrix[i][j]<<"\t";
        cout<<"\n";
    }
    
    return 0;
}
