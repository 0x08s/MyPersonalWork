#include <iostream>
using namespace std;

int main() {
    int numbers[100]; // Maximum 100 numbers
    int n;            // Array size
    int key;          // Number to search
    bool found = false;

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

    // User se number search karne ke liye
    cout << "Enter number to search: ";
    cin >> key;

    // Array mein number search karna
    for (int i = 0; i < n; i++) {
        if (numbers[i] == key) {
            found = true;
            cout << "Number found at position " << i + 1 << endl; // Position display karna
            break; // Stop searching once found
        }
    }

    if (!found) {
        cout << "Number not found in the array." << endl;
    }

    return 0;
}