#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inFile("thisFile.txt");
    ofstream outFile("thatFile.txt");
    char ch;

    while (inFile.get(ch))
    {
        outFile.put(ch);
    }

    inFile.close();
    outFile.close();

    cout << "File copied successfully";

    return 0;
}