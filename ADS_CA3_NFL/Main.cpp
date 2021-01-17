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
    
    cout << endl << "************ Report By Region ************" << endl;

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

    while (filename.good()) {
        
        getline(filename, salesRecords);
        cout << salesRecords << endl;
    }

    double PriceLimit = 50;
    auto removeIfPriceFilter = [PriceLimit](SalesRecords salesRecord) { return salesRecord.price < PriceLimit; };
    SalesRecordsRemove* pFilterPriceNode = new SalesRecordsRemove(removeIfPriceFilter);
    NodeData<list<SalesRecords>>* pNodeData = new NodeData<list<SalesRecords>>();

    pFilterPriceNode->setNext(pNodeData);

    //prints the final results
    pFilterPriceNode->process(salesList);

    for (SalesRecords salesRecords : pNodeData->getOutput()) {
        cout << salesRecords << endl;
    }

}
