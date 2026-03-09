#include <iostream>
using namespace std;

// Function to raise a number to a power
int raiseToPow(int base, int exponent) {
    int result = 1;
    for(int i = 1; i <= exponent; i++) {
        result = result * base;
    }
    return result;
}

int main() {
    int num, power, answer;

    // User se input lena
    cout << "Number enter karein: ";
    cin >> num;
    cout << "Power enter karein: ";
    cin >> power;

    // Function call
    answer = raiseToPow(num, power);

    // Result display karna
    cout << num << " raised to the power " << power << " is " << answer << endl;

    return 0;
}