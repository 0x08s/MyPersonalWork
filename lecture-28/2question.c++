#include <iostream>
using namespace std;

class Date {
    int day;
    int month;
    int year;

public:
    // Default constructor
    Date() {
        day = 1;
        month = 1;
        year = 2000;
    }

    // Setter function for month
    void setMonth(int m) {
        if (m >= 1 && m <= 12) {   // Valid month check
            month = m;
        } else {
            cout << "Invalid month! Setting default value 1." << endl;
            month = 1;
        }
    }

    // Function to display date
    void display() {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }
};

int main() {
    Date d;

    d.display();       
    d.setMonth(5);     // Set month to May
    d.display();       // Output: 1/5/2000

    d.setMonth(15);    // Invalid month
    d.display();       // Output: 1/1/2000

    return 0;
}