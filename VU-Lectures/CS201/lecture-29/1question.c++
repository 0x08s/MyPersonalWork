#include <iostream>
using namespace std;

class Student {
private:
    int marks;

public:
    // Constructor
    Student() {
        marks = 90;
    }

    // Friend function declaration

    friend void showMarks(Student s);
};

// Friend function definition

void showMarks(Student s) {
    cout << "Marks = " << s.marks << endl;
}

int main() {
    Student s1;
    showMarks(s1);

    return 0;
}