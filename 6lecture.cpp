#include <iostream>
using namespace std;

int main() {
    int sum = 0;         
    int n = 1000;
    for(int i = 1; i <= n; i++) {
        sum = sum + i;
    }

    cout << "Sum of first " << n << " integers = " << sum << endl;

    long long sum_formula = n * (n + 1) / 2;

    cout << "\nUsing formula (n*(n+1) / 2)   = " << sum_formula << endl;

    if (sum == sum_formula) {
        cout << "Both methods give the same correct result \n";
    }

    return 0;
}