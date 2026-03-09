#include <iostream>
using namespace std;

int main() {
    char grade;

    // User se grade input lena
    cout << "Apna grade enter karein (A, B, C, D, F): ";
    cin >> grade;

    // Grade ke mutabiq description show karna
    switch (grade) {
        case 'A':
        case 'a':
            cout << "Excellent!" << endl;
            break;
        case 'B':
        case 'b':
            cout << "Good!" << endl;
            break;
        case 'C':
        case 'c':
            cout << "Average!" << endl;
            break;
        case 'D':
        case 'd':
            cout << "Below Average!" << endl;
            break;
        case 'F':
        case 'f':
            cout << "Fail!" << endl;
            break;
        default:
            cout << "Invalid grade!" << endl;
    }

    return 0;
}