#include <iostream>
using namespace std;

int main() {
    int ageAmer, ageAmara;

    cout << "Enter Amer's age: ";
    cin >> ageAmer;

    cout << "Enter Amara's age: ";
    cin >> ageAmara;

    cout << "\nResults:";
    cout << "\n";

    // Check Amer
    if (ageAmer >= 0 && ageAmer <= 120) {
        if (ageAmer >= 18) {
            cout << "Amer is an adult." << endl;
        }
        if (ageAmer < 18) {
            cout << "Amer is a minor." << endl;
        }
    } else {
        cout << "Invalid age entered for Amer!\n";
    }

    // Check Amara
    if (ageAmara >= 0 && ageAmara <= 120) {
        if (ageAmara >= 18) {
            cout << "Amara is an adult." << endl;
        }
        if (ageAmara < 18) {
            cout << "Amara is a minor." << endl;
        }
    } else {
        cout << "Invalid age entered for Amara!\n";
    }

    cout << "\n";

    return 0;
}