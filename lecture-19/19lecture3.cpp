#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
    ifstream file;
    file.open(argv[1]);

    if (!file)
    {
        cout << "File not found";
        return 0;
    }

    file.seekg(0, ios::end);
    int length = file.tellg();

    cout << "Length of file is: " << length << " bytes";

    file.close();

    return 0;
}