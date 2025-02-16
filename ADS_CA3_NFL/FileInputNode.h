#pragma once

#include <fstream>
#include "Node.h"
#include "SalesRecords.h"
#include <list>
#include <string>

using namespace std;

class FileInputNode : public Node<list<SalesRecords>>
{
	//create salesRecords list 
	list<SalesRecords> salesRecords;


public:

	FileInputNode(string path);
	list<SalesRecords> getSales();

	SalesRecords parseSales(string s);

};
