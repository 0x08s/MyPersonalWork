#include <iostream>
using namespace std;

int main() {
    int numbers[100]; // Array to store maximum 100 numbers
    int num;
    int count = 0; // Counter for how many numbers are stored

    cout << "Enter positive integers (enter -1 to stop): " << endl;

    while (count < 100) {
        cin >> num;

        if (num == -1) {
            break; // Stop input if -1 is entered
        }

        if (num > 0) {
            numbers[count] = num; // Store in array
            count++;
        } else {
            cout << "Please enter a positive integer: ";
        }
    }

    // Display stored numbers
    cout << "Numbers stored in the array are: ";
    for (int i = 0; i < count; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}