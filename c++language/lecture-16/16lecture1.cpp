#include<iostream>
using namespace std;

int main(){
    int arr[5];
    
    // Input array elements
    cout<<"Enter 5 elements:\n";

    for(int i=0; i<5; i++){

        cout<<"arr["<<i<<"]: ";
        
        cin>>arr[i];
    }
    
    // Display original array

    cout<<"\nOriginal Array:\n";\

    for(int i=0; i<5; i++){

        cout<<"arr["<<i<<"] = "<<arr[i]<<"\n";
    }
    // Manipulate array using indexing

    cout<<"\nArray Manipulation:\n";

    for(int i=0; i<5; i++){

        arr[i] = arr[i] * 2;  // multiply each element by 2

        cout<<"arr["<<i<<"] = "<<arr[i]<<"\n";
    }
    
    // Display sum using indexing
    int sum = 0;

    for(int i=0; i<5; i++){\

    sum += arr[i];

    }

    cout<<"\nSum of all elements : "<<sum<<"\n";

    cout<<"Average of elements : "<<sum/5<<"\n";
    
    return 0;
}
