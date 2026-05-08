#include <iostream>
using namespace std;

int main() {
    int numbers[100];  // Maximum 100 numbers
    int n;             // Array mein kitne numbers hain
    int sum = 0;       // Sum of squares

    // User se array size lena
    cout << "Kitne numbers store karne hain (max 100): ";
    cin >> n;

    if (n > 100 || n <= 0) {
        cout << "Invalid input! Maximum 100 positive numbers allowed." << endl;
        return 1; // Program terminate
    }

    // User se numbers input lena
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // Sum of squares calculate karna
    for (int i = 0; i < n; i++) {
        sum += numbers[i] * numbers[i]; // Square karke add karna
    }

    // Result display karna
    cout << "Sum of squares = " << sum << endl;

    return 0;
}