#include <iostream>
using namespace std;

main()
{
    int tryNum = 0;
    char c;

    do
    {
        cout << "Please enter a character between a-z for guessing : ";
        cin >> c;

        if (c == 'z')
        {
            cout << "Congratulations, Your guess is correct\n";
            tryNum = 6;           // to exit loop
        }
        else
        {
            tryNum = tryNum + 1;
            cout << "Wrong guess!\n";
        }
    }
    while (tryNum <= 5);

    if (tryNum > 5)
    {
        cout << "\nSorry! You couldn't guess it";
        cout << "The correct character was 'z'\n";
    }

    return 0;
}