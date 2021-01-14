#include "FileInputNode.h"


FileInputNode:FileInputNode(string path)
{
	string s;
	ifstream salesRecordFiles(path);

	while (salesRecordFiles.good())
	{
		getline(salesRecordFiles, s);
		SalesRecords sr - parseSalesRecords;
		this > salesRecords.push_back(sr);
	}
}

list<SalesRecords> FileInputNode : getSalesRecords()
{
	return list<SalesRecords>();
}

SalesRecords FileInputNode : parseSalesRecords(string s)
{

}