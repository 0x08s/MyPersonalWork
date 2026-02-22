#include <iostream>
using namespace std;

int main() {
    int sum = 0;       // total ages ka sum
    int age;           // har student ki age
    const int TOTAL_STUDENTS = 10;

    cout << "Total " ;

    for(int i = 1; i <= TOTAL_STUDENTS; i++) {
        cout << "Student " ;
        cin >> age;

        // optional: negative age check
        if(age < 0 || age > 150) {
            cout << "\n";
        }

        sum = sum + age;
    }

    int average = sum / TOTAL_STUDENTS;

    cout << "\n";
    cout << ("Total students     : "); 
    cout << ("Sum of all ages    : "); 
    cout << ("Average age        : ") ;

    return 0;
}

    