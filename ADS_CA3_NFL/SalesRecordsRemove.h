#pragma once

#include "Node.h"
#include "SalesRecords.h"
#include <list>
#include <functional>

using namespace std;

/// @brief Removes those Bike objects from the list that satisfy the filter
class SalesRecordsRemove : public Node<list<SalesRecords>> {
private:
	std::function<bool(SalesRecords&)> filter;

public:

	SalesRecordsRemove(std::function<bool(SalesRecords&)> filter) {
		this->filter = filter;
	}

	//removes sales record from the list 
	void process(list<SalesRecords>& list) {
		list.erase(std::remove_if(list.begin(), list.end(), filter), list.end());
		this->getNext()->process(list);
	}
};