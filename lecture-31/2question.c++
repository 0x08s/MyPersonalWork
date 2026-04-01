#include <iostream>
using namespace std;

// Function returning reference
int& getNumber(int &x) {
    return x;
}

int main() {
    int num = 10;

    cout << "Before: " << num << endl;

    // Using returned reference
    getNumber(num) = 50;

    cout << "After: " << num << endl;

    return 0;
}