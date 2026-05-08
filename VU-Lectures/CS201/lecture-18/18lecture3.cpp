#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file;
    string word;

    file.open("data.txt");

    if (!file)
    {
        cout << "File not found";
        return 0;
    }

    while (file >> word)
    {
        cout << word << endl;
    }

    file.close();

    return 0;
}