#include <iostream>
using namespace std;

int main() {
    int arr[100];   // Maximum 100 numbers
    int n;          // Number of elements in the array
    int key;        // Number to search
    bool found = false;

    // User se array size lena
    cout << "Kitne numbers store karne hain (max 100): ";
    cin >> n;

    if (n > 100 || n <= 0) {
        cout << "Invalid input! Maximum 100 positive numbers allowed." << endl;
        return 1;
    }

    // Array ke elements input lena
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Number search karne ke liye input lena
    cout << "Enter number to search: ";
    cin >> key;

    // Array mein number search karna
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Number found at position " << i + 1 << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Number not found in the array." << endl;
    }

    return 0;
}