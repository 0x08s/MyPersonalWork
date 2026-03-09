#include <iostream>
using namespace std;

// Function to calculate square using call by value
double square(double num) {
    return num * num; // Square calculate karke return karta hai
}

int main() {
    double number, result;

    // User se number input lena
    cout << "Enter a number: ";
    cin >> number;

    // Function call (call by value)
    result = square(number);

    // Result display karna
    cout << "Square of " << number << " is " << result << endl;

    return 0;
}