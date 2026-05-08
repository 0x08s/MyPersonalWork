#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream file;
    string line;

    file.open("myfile.txt");

    if (!file)
    {
        cout << "File not found";
        return 0;
    }

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();

    return 0;
}