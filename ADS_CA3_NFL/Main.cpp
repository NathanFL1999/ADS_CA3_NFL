#include <iostream>
#include <fstream>
#include <vector>
#include <list>

#include "NodeData.h"
#include "SalesRecords.h"
#include "SalesRecordsModify.h"
#include "SalesRecordsRemove.h"

using namespace std; 

void fileProcessing();

int main()
{

    //ifstream infile;
    //infile.open("sales_100.txt");

    //if (infile.fail())
    //{
    //    cout << "File failed to open.\n";
    //    exit(1);
    //}

    //while (infile.good())
    //    cout << (char)infile.get();

    ////Closes file
    //infile.close();
    //return 0;

    fileProcessing();
}

void fileProcessing() {

    list<SalesRecords> salesList;
    salesList.push_back(SalesRecords("Pokemon Shield for Nintendo Switch", 25, 4, "Sweden", "EMEA", "SEK", 24 / 06 / 2020, 02 / 07 / 2020));
    salesList.push_back(SalesRecords("Train the Body", 62, 11, "Bolivia", "LATAM", "BOB", 04 / 10 / 2020 , 15 / 10 / 2020));

    //ifstream infile;
    //infile.open("sales_100.txt");

    double upperPriceLimit = 500;
    auto removeIfPriceFilter = [upperPriceLimit](SalesRecords salesRecord) { return salesRecord.price < upperPriceLimit; };
    SalesRecordsRemove* pFilterPriceNode = new SalesRecordsRemove(removeIfPriceFilter);

    double percentageReduction = 0.95;
    auto setPriceTransform = [percentageReduction](SalesRecords& salesRecord) {salesRecord.price = salesRecord.price * percentageReduction; };
    SalesRecordsModify* pTransformPriceNode = new SalesRecordsModify(setPriceTransform);

    NodeData<list<SalesRecords>>* pNodeData = new NodeData<list<SalesRecords>>();

    pFilterPriceNode->setNext(pTransformPriceNode)->setNext(pNodeData);

    //prints the final results
    pFilterPriceNode->process(salesList);

    for (SalesRecords salesRecords : pNodeData->getOutput()) {
        cout << salesRecords << endl;
    }

}