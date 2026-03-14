#include <iostream>
using namespace std;

int main()
{
    int n;
    int sum = 0;

    cout << "Enter value of n: ";
    cin >> n;

    if (n < 1)
    {
        cout << "Invalid input!\n";
        return 1;
    }

    for(int i = 1; i <= n; i++)
    {
        sum = sum + i * i;
    }

    cout << "Sum of squares from 1 to " << n << " = " << sum << endl;

    return 0;
}