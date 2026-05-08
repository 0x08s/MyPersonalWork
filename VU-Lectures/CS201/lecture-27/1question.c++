#include <iostream>
using namespace std;

class Date {
    int day, month, year;

public:
    // Default constructor
    Date() {
        day = 1;
        month = 1;
        year = 2000;
        cout << "Default constructor called!" << endl;
    }

    // Parameterized constructor
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
        cout << "Parameterized constructor called!" << endl;
    }

    // Destructor
    ~Date() {
        cout << "Destructor called for date: " 
             << day << "/" << month << "/" << year << endl;
    }

    // Function to display date
    void display() {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }
};

int main() {
    cout << "Creating first date object..." << endl;
    Date d1;              // Default constructor will be called
    d1.display();

    cout << "\nCreating second date object..." << endl;
    Date d2(15, 4, 2026); // Parameterized constructor will be called
    d2.display();

    cout << "\nEnd of main function." << endl;
    return 0;
}