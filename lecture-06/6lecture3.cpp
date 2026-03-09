#include <iostream>
using namespace std;

int main() {
    int n;
    int fact = 1;

    cout << "Enter number to calculate factorial: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial not defined for negative numbers.\n";
        return 1;
    }

    int i = n;
    while (i > 1) {
        fact *= i;
        i--;
    }

    cout << n << "! = " << fact << endl;

    return 0;
}