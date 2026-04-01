#include <iostream>
using namespace std;

int main() {
    // Dynamic memory allocation using 'new' operator
    int* ptr = new int;  // Allocate memory for an integer
    *ptr = 100;          // Store value in allocated memory

    cout << "Value stored in dynamically allocated memory: " << *ptr << endl;

    // Problem: Memory leak
    // 'delete ptr;' is not called, so allocated memory is not freed

    return 0;
}