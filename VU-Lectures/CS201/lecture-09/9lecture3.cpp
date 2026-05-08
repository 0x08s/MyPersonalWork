#include <iostream>
using namespace std;

// Function to calculate the area of a circle
double circleArea(double radius) {
    const double PI = 3.14159;
    return PI * radius * radius;  // Area = π × r × r
}

int main() {
    double r, area;

    // User se radius input lena
    cout << "Circle ka radius enter karein: ";
    cin >> r;

    // Function call karke area calculate karna
    area = circleArea(r);

    // Result display karna
    cout << "Circle ka area: " << area << endl;

    return 0;
}