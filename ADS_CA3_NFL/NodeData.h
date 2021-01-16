#pragma once
#include "Node.h"

//node used to take the data from the graph network
template <class T>
class NodeData : public Node<T> {
private:
	T data;

public:

	void process(T& data) override {
		this->data = data;
	}

	T getOutput() {
		return this->data;
	}
};