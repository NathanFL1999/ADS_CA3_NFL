#pragma once

#include <list>
#include "Node.h"

//node class that can connect to multiple nodes
//doesnt work as of yet
template <class T>
class MultiNode : public Node<T> {
private:
    list<Node<T>> listNext;

public:

    void setNext(list<Node<T>>& listNext) {
        this->pListNext = listNext;
    }

    list<Node<T>>& getNext() {
        return this->listNext;
    }
};