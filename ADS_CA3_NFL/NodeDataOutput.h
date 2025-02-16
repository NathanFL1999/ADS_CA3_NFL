#pragma once
#include "Node.h"

//node used to take the data from the graph network
template <class T>
class NodeDataOutput : public Node<T> {
private:
	T data;

public:

	void process(T& data) override {
		this->data = data;
	}

	//data can be used with getOutput()
	T getOutput() {
		return this->data;
	}
};