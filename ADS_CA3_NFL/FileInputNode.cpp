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
		SalesRecords salesrecord = parseSales(s);
		this->salesRecords.push_back(salesrecord); //pushes to the back of the list 
	}
}

list<SalesRecords> FileInputNode::getSales() 
{
	return list<SalesRecords>();
}

SalesRecords FileInputNode::parseSales(string s)
{
	string productName = s.substr(s.find_first_of(","));
	s = s.substr(s.find_first_of(","));

	float price = stof(s.substr(s.find_first_of(",")));
	s = s.substr(s.find_first_of(","));

	int quantity = stoi(s.substr(s.find_first_of(",")));
	s = s.substr(s.find_first_of(","));

	string country = s.substr(s.find_first_of(","));
	s = s.substr(s.find_first_of(","));

	string region = s.substr(s.find_first_of(","));
	s = s.substr(s.find_first_of(","));

	string currency = s.substr(s.find_first_of(","));
	s = s.substr(s.find_first_of(","));

	int orderDateTime = stoi(s.substr(s.find_first_of(",")));
	s = s.substr(s.find_first_of(","));

	int deliveryDate = stoi(s.substr(s.find_first_of(",")));
	s = s.substr(s.find_first_of(","));
}
