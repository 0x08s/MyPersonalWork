#include <iostream>
#include <iomanip>
#include <cmath>     
using namespace std;

int main() {
    const double PI = 3.141;
    double radius;

    cout << "Enter radius of circle: ";
    cin >> radius;

    if (radius <= 0) {
        cout << "Please enter a positive radius.\n";
        return 1;
    }

    double diameter = 2 * radius;
    double circumference = 2 * PI * radius;
    double area = PI * radius * radius;

    cout << "Results:\n";
    cout << "\n";
    cout << fixed << setprecision(4);

    cout << "Radius :" ;
    cout << "Diameter :" ;
    cout << "Circumference :" ;
    cout << "Area : " ;
    cout << "\n";
    cout << "Radius         = " << radius << " units\n";
    cout << "Diameter       = " << diameter << " units\n";
    cout << "Circumference  = " << circumference << " units\n";
    cout << "Area           = " << area << " square units\n";
    cout << "\n";
    return 0;
}