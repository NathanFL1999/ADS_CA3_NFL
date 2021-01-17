#pragma once

enum class NodeType {
	Input,
	Filter,
	Sort,
	Transform,
	Copy,
	Output
};

// parent class for a node
template <class T>
class Node {
private:
	Node<T>* pNext = nullptr;

public:

	Node() {};
	~Node() {};

	Node<T>* setNext(Node<T>* pNext) {
		this->pNext = pNext;
		return this->pNext;
	}

	Node<T>* getNext() {
		return this->pNext;
	}

	virtual void process(T& data) = 0;

	////method should print each element of the list into a single line
	//void printAllFromHead() {

	//	Node<T> current = *this;

	//	while (current.pPrevious != nullptr) {
	//		current = *current.pPrevious;
	//	}

	//	cout << current.data << endl;
	//	do {
	//		current = *current.pNext;
	//		cout << current.data << endl;
	//	} while (current.pNext != nullptr);
	//}

};
