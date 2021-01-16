#pragma once

#include "Node.h"
#include "SalesRecords.h"
#include <list>
#include <functional>
#include <algorithm>

using namespace std;

//Modifies the sales records in the list 
class SalesRecordsModify: public Node<list<SalesRecords>> {
private:
	std::function<void(SalesRecords&)> transform;

public:

	SalesRecordsModify(std::function<void(SalesRecords&)> transform) {
		this->transform = transform;
	}

	//copys the sales record and changes it in the list
	void process(list<SalesRecords>& list) {

		for (SalesRecords& salesRecords : list)
			transform(salesRecords);

		this->getNext()->process(list);
	}
};