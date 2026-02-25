#include <iostream>
using namespace std;

int main() {
    int choice;
    char again = 'y';

    while(again == 'y' || again == 'Y') {
        cout << "\n=== Chhota Student Calculator ===\n";
        cout << "1. Average Marks\n";
        cout << "2. Percentage\n";
        cout << "3. Attendance %\n";
        cout << "4. CGPA\n";
        cout << "5. Exit\n";
        cout << "Choice (1-5): ";
        cin >> choice;

        if(choice == 1) {  // Average
            int n;
            float sum = 0, m;
            cout << "Subjects count: ";
            cin >> n;
            for(int i = 1; i <= n; i++) {
                cout << "Marks " << i << ": ";
                cin >> m;
                sum += m;
            }
            cout << "\nAverage = " << (sum / n) << endl;
        }

        else if(choice == 2) {  // Percentage
            float got, total;
            cout << "Obtained: ";
            cin >> got;
            cout << "Total: ";
            cin >> total;
            if(total > 0)
                cout << "Percentage = " << (got * 100 / total) << "%\n";
            else
                cout << "Total zero nahi ho sakta\n";
        }

        else if(choice == 3) {  // Attendance
            int total, present;
            cout << "Total classes: ";
            cin >> total;
            cout << "Present: ";
            cin >> present;
            if(total > 0)
                cout << "Attendance = " << (present * 100.0 / total) << "%\n";
            else
                cout << "Total zero nahi ho sakta\n";
        }

        else if(choice == 4) {  // CGPA
            int n;
            float gp, sum = 0;
            cout << "Subjects count: ";
            cin >> n;
            for(int i = 1; i <= n; i++) {
                cout << "GP " << i << " (4.0 scale): ";
                cin >> gp;
                sum += gp;
            }
            cout << "\nCGPA = " << (sum / n) << " / 4.0\n";
        }

        else if(choice == 5) {
            cout << "Bye! Padhai jari rakho :)\n";
            break;
        }

        else {
            cout << "Galat choice! 1-5 tak try karo\n";
        }

        cout << "\nPhir se? (y/n): ";
        cin >> again;
    }

    return 0;
}