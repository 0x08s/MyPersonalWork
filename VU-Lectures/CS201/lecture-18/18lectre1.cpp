#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file;           
    file.open("myfileOut.txt");

    file << "Welcome to VU";  

    file.close();             

    cout << "Data written successfully";

    return 0;
}