#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file;

    int num;
    float value;
    char ch;

    file.open("test.txt");

    if (!file)
    {
        cout << "File not found";
        return 0;
    }

    file >> num;
    file >> value;
    file >> ch;

    cout << "Integer: " << num << endl;
    cout << "Float: " << value << endl;
    cout << "Character: " << ch << endl;

    file.close();

    return 0;
}