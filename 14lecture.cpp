#include<iostream>
using namespace std;

// Swap function using pointers

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort function

void bubbleSort(int arr[], int size){
for(int i=0; i<size-1; i++){

for(int j=0; j<size-i-1; j++){

if(arr[j] > arr[j+1]){

swap(&arr[j], &arr[j+1]);

}

}

}
}

int main(){
    int arr[5];
    
    // Input array

    cout<<"Enter 5 elements:\n";

    for(int i=0; i<5; i++){
        cout<<"Element ["<<i<<"]: ";
        cin>>arr[i];
    }
    
    // Display original array

    cout<<"\nOriginal Array:\n";

    for(int i=0; i<5; i++)
        cout<<arr[i]<<" ";
    
    // Sort the array

    bubbleSort(arr, 5);
    
    // Display sorted array

    cout<<"\n\nSorted Array (Ascending Order):\n";

    for(int i=0; i<5; i++)
        cout<<arr[i]<<" ";
    
    cout<<"\n";
    return 0;
}