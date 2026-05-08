#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file;

    int num = 10;
    float value = 5.5;
    char ch = 'A';

    file.open("test.txt");

    file << num << endl;
    file << value << endl;
    file << ch << endl;

    file.close();

    cout << "Data written to file successfully";

    return 0;
}