#include <iostream>
using namespace std;

int main() {
    double salary, netSalary;
    double tax = 0.0;

    // User se salary input lena
    cout << "Apni salary enter karein: ";
    cin >> salary;

    // Deduction ke conditions
    if (salary <= 20000) {
        tax = salary * 0.05; // 5% tax
    } else if (salary <= 50000) {
        tax = salary * 0.10; // 10% tax
    } else {
        tax = salary * 0.20; // 20% tax
    }

    // Net salary calculate karna
    netSalary = salary - tax;

    // Net salary display karna
    cout << "Net payable amount after deduction: " << netSalary << endl;

    return 0;
}