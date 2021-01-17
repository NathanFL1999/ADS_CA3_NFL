//https://en.cppreference.com/w/cpp/chrono
//used to help me return functions speed in nanoseconds
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>

#include "NodeDataOutput.h"
#include "SalesRecords.h"
//#include "FileInputNode.h"
#include "SalesRecordsModify.h"
#include "SalesRecordsRemove.h"
#include <chrono>

using namespace std; 
using namespace std::chrono;

void reportByRegion();
void reportByPopularity();
void reportByPrice();


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

    //starts the clock before the function
    auto start = high_resolution_clock::now();

    reportByRegion();

    //stops the clock when the function is finished
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Time taken by function: "
        << duration.count() << " nanoseconds" << endl;

    return 0;
}

void reportByRegion() {

    //creates a new list 
    list<SalesRecords> salesList;

    //reads in the file path
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

void reportByPrice() {

    //creating new list saleslist
    list<SalesRecords> salesList;

    //reads in the file path
    ifstream filename("C:\\Users\\Nate Dawg\\source\\repos\\ADS_CA3_NFL\\ADS_CA3_NFL\\sales_100.txt");
    string salesRecords;

    while (filename.good()) {

        getline(filename, salesRecords);
    }

    //removes the sales records that price is less than 50 using the filter in my remove class
    double PriceLimit = 50;
    auto removeIfPriceFilter = [PriceLimit](SalesRecords saleRecord) { return saleRecord.price < PriceLimit; };
    SalesRecordsRemove* pFilterPriceNode = new SalesRecordsRemove(removeIfPriceFilter);

    NodeDataOutput<list<SalesRecords>>* pNodeDataOutput = new NodeDataOutput<list<SalesRecords>>();

    //connects the price filter to the output node
    pFilterPriceNode->setNext(pNodeDataOutput);

    //passes the data through the graph network 
    pFilterPriceNode->process(salesList);

    //prints out the final results
    for (SalesRecords salesRecords : pNodeDataOutput->getOutput()) {
        cout << salesRecords << endl;
    }
}

