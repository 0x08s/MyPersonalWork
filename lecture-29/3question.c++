#include <iostream>
using namespace std;

class Number {
private:
    int num;

public:
    Number(int n) {
        num = n;
    }

    // friend function declaration
    friend void add(Number n1, Number n2);
};

// friend function definition
void add(Number n1, Number n2) {
    cout << "Sum = " << n1.num + n2.num << endl;
}

int main() {
    Number a(10);
    Number b(20);

    add(a, b);

    return 0;
}