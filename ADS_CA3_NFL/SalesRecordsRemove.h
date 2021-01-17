#pragma once

#include "Node.h"
#include "SalesRecords.h"
#include <list>
#include <functional>

using namespace std;

//Removes the sales records from the list depending on the filter
class SalesRecordsRemove : public Node<list<SalesRecords>> {
private:
	function<bool(SalesRecords&)> filter;

public:

	SalesRecordsRemove(function<bool(SalesRecords&)> filter) {
		this->filter = filter;
	}

	//removes sales record from the list 
	void process(list<SalesRecords>& list) {
		list.erase(remove_if(list.begin(), list.end(), filter), list.end());
		this->getNext()->process(list);
	}
};