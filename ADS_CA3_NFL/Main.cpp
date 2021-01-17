//https://en.cppreference.com/w/cpp/chrono
//used to help me return functions speed in nanoseconds
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>

#include "NodeData.h"
#include "SalesRecords.h"
//#include "FileInputNode.h"
#include "SalesRecordsModify.h"
#include "SalesRecordsRemove.h"
#include <chrono>

using namespace std; 
using namespace std::chrono;

void reportByRegion();
void reportByPopularity();


int main()
{
    
    //string filename;
    //ofstream salesRecordFile;

    //cout << "Enter text file name : ";
    //cin >> filename;

    //if (salesRecordFile.fail())
    //{
    //    cout << "File failed to open.\n";
    //    exit(1);
    //}

    //salesRecordFile.open(filename.c_str());
    //salesRecordFile >> filename;
    //cout << filename << endl;

    //salesRecordFile.close();
    //return 0;
    
    cout << endl << "************ Report By Region ************\n" << endl;

    auto start = high_resolution_clock::now();

    reportByRegion();

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Time taken by function: "
        << duration.count() << " nanoseconds" << endl;
    
}

void reportByRegion() {

    list<SalesRecords> salesList;

    ifstream filename("C:\\Users\\Nate Dawg\\source\\repos\\ADS_CA3_NFL\\ADS_CA3_NFL\\sales_100.txt");
    string salesRecords;
    int salesVolume;

    salesVolume = 0;

    while (filename.good()) {
        
        getline(filename, salesRecords);
        cout << salesRecords << endl;
        salesVolume++;

    }

    cout << "Total Volume of sales : " << salesVolume << "\n" << endl;
}

void reportByPopularity() {

    list<SalesRecords> salesList;

    ifstream filename("C:\\Users\\Nate Dawg\\source\\repos\\ADS_CA3_NFL\\ADS_CA3_NFL\\sales_100.txt");
    string salesRecords;

    while (filename.good()) {

        getline(filename, salesRecords);
        cout << salesRecords << endl;
    }


}
