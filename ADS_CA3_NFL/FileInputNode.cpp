#include "FileInputNode.h"
#include "SalesRecords.h"
#include "Node.h"

#include <iostream>


FileInputNode : FileInputNode(string path)
{
	string s;
	ifstream salesRecordFiles(path);

}

list<SalesRecords> FileInputNode : getSalesRecords()
{
	return list<SalesRecords>();
}


SalesRecords FileInputNode : parseSalesRecords(string s)
{

}