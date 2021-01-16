#include <iostream>
#include <fstream>

using namespace std; 

int main()
{
    ifstream infile;
    infile.open("sales_100.txt");

    if (infile.fail())
    {
        cout << "File failed to open.\n";
        exit(1);
    }

    while (infile.good())
        cout << (char)infile.get();

    //Closes file
    infile.close();
    return 0;
}
