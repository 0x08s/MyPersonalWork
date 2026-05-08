#include <iostream>
using namespace std;

int main() {
    // Dynamically allocate memory for a single integer

    int* ptr = new int;
    *ptr = 100;  // Store value
    cout << "Value in dynamically allocated memory: " << *ptr << endl;

    // Properly deallocate memory using delete

    delete ptr;   // Free the memory
    ptr = nullptr; // Optional: avoid dangling pointer

    // Dynamically allocate memory for an array of integers

    int* arr = new int[5];
    for(int i = 0; i < 5; i++) {
        arr[i] = i * 10; // Assign values
    }

    cout << "Array values: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Properly deallocate memory for array
    
    delete[] arr;  // Free the array memory
    arr = nullptr; // Optional: avoid dangling pointer

    return 0;
}