#include <iostream>
using namespace std;

class Date {
    int day, month, year;

public:
    // Default constructor

    Date() {
        day = 1;       // Default day
        month = 1;     // Default month
        year = 2000;   // Default year
        cout << "Default constructor called!" << endl;
    }

    // Function to display date
    void display() {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }
};

int main() {
    Date d;        
    d.display();  

    return 0;
}