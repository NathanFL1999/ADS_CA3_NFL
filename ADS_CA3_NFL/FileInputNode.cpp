//#include "FileInputNode.h"
//#include <iostream>
//
//using namespace std;
//
//FileInputNode::FileInputNode(string path)
//{
//	string s;
//	ifstream salesRecordFile(path); //reads in the sales record
//
//	//takes a line from the sales record list and parses it
//	//when parsed pushes it to the back of the list
//	while (salesRecordFile.good())
//	{
//		getline(salesRecordFile, s);
//		SalesRecords salesrecord = parseSales(s);
//		this->salesRecords.push_back(salesrecord); //pushes to the back of the list 
//	}
//}
//
////gets sales records list 
//list<SalesRecords> FileInputNode::getSales() 
//{
//	return list<SalesRecords>();
//}
