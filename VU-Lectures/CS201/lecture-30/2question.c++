#include <iostream>
using namespace std;

class Student {
private:
    int marks;

public:
    // Constructor
    Student(int m) {
        marks = m;
    }

    // Friend function using reference parameter
    friend void showMarks(Student &s);
};

// Friend function definition
void showMarks(Student &s) {
    cout << "Marks = " << s.marks << endl;
}

int main() {
    Student s1(95);

    showMarks(s1);

    return 0;
}