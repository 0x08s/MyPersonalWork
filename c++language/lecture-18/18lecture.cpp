#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file;       
    string name;
    int age;
    float salary;

    file.open("myfile.txt");   // txt file open

    if (!file)
    {
        cout << "File not found!" << endl;
        return 0;
    }

    while (file >> name >> age >> salary)  
    {
        cout << "Employee Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
        cout << "" << endl;
    }

    file.close();   // file close

    return 0;
}