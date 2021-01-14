#pragma once


template <typename T>
class Node {
public:

	T data;

	Node* pNext;

	Node* pPrevious;

	Node(T data) {

		this->data = data;
		this->pNext = this->pPrevious = nullptr;
	}

	~Node() {
		pNext = nullptr;
		pPrevious = nullptr;

		data = T();
	}

	void insertAfter(T data)
	{
		Node<T>* pNew = new Node<T>(data);
		pNew->pPrevious = this;
		pNew->pNext = this->pNext;
		if (this->pNext != nullptr)
		{
			this->pNext->pPrevious = pNew;
		}
		this->pNext = pNew;
	}

	void insertBefore(T data)
	{
		Node<T>* pNew = new Node<T>(data);
		pNew->pNext = this;
		pNew->pPrevious = this->pPrevious;
		if (this->pPrevious != nullptr)
		{
			this->pPrevious->pNext = pNew;
		}
		this->pPrevious = pNew;
	}

	void printAllFromHead() {

		Node<T> current = *this;

		while (current.pPrevious != nullptr) {
			current = *current.pPrevious;
		}

		std::cout << current.data << std::endl;
		do {
			current = *current.pNext;
			std::cout << current.data << std::endl;
		} while (current.pNext != nullptr);
	}
};