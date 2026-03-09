#include <iostream>
using namespace std;

// Function definition
int f(int x) {
    x = x * 2;  // Number ko double karna
    return x;   // Result return karna
}

int main() {
    int num, result;

    // User se number input lena
    cout << "Enter an integer: ";
    cin >> num;

    // Function call (call by value)
    result = f(num);

    // Result display karna
    cout << "Original number: " << num << endl;   // Original number safe rehta hai
    cout << "Doubled number: " << result << endl; // Function se return hua number

    return 0;
}