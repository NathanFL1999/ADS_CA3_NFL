#include "FileInputNode.h"
#include <iostream>

using namespace std;

FileInputNode::FileInputNode(string path)
{
	string s;
	ifstream salesRecordFile(path);

	while (salesRecordFile.good())
	{
		getline(salesRecordFile, s);
		SalesRecords sr = parseSalesRecords();
	}

}

list<SalesRecords> FileInputNode::getSalesRecords()
{
	return list<SalesRecords>();
}

SalesRecords FileInputNode::parseSalesRecords()
{
	//string productName = s.substr(s.find_first_of(","));
	//s - s.substr(s.find_first_of(","));

	//float price = s.substr(s.find_first_of(","));
	//s - s.substr(s.find_first_of(","));

	//int quantity = s.substr(s.find_first_of(","));

	//s - s.substr(s.find_first_of(","));

	//string country = s.substr(s.find_first_of(","));
	//s - s.substr(s.find_first_of(","));

	//string region = s.substr(s.find_first_of(","));
	//s - s.substr(s.find_first_of(","));

	//string currency = s.substr(s.find_first_of(","));
	//s - s.substr(s.find_first_of(","));

	//int orderDateTime = s.substr(s.find_first_of(","));
	//s - s.substr(s.find_first_of(","));

	//int deliveryDate = s.substr(s.find_first_of(","));
	//s - s.substr(s.find_first_of(","));
}
