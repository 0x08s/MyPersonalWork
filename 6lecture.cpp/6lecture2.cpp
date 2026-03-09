#include <iostream>
using namespace std;

int main() {
    int limit;
    int sum = 0;

    cout << "Enter upper limit: ";
    cin >> limit;

    if (limit < 1) {
        cout << "Invalid input!\n";
        return 1;
    }

    for (int i = 2; i <= limit; i += 2) {
        sum += i;
    }

    cout << "Sum of even numbers from 1 to " << limit << " = " << sum << endl;

    return 0;
}