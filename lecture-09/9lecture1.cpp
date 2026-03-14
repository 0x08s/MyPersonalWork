#include <iostream>
using namespace std;

// Function prototype / definition
int square(int num) {
    return num * num; // Number ka square return karta hai
}

int main() {
    int number, result;

    // User se number input lena
    cout << "Ek number enter karein: ";
    cin >> number;

    // Function call karke square calculate karna
    result = square(number);

    // Result display karna
    cout << "Square of " << number << " is " << result << endl;

    return 0;
}