#include <iostream>
using namespace std;

// Function returning reference
int& getValue(int &x) {
    return x;
}

int main() {
    int a = 5;

    cout << "Before change: " << a << endl;

    // Using returned reference to change original value
    getValue(a) = 20;

    cout << "After change: " << a << endl;

    return 0;
}
