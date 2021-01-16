#include <iostream>
#include <fstream>
#include "NodeData.h"
#include "SalesRecords.h"
#include "SalesRecordsModify.h"
#include "SalesRecordsRemove.h"

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
