#pragma once
#include "Node.h"
#include "Header.h"
template <class DataType>
class Queue {
    Node<DataType>* _pHear;
    Node<DataType>* _pFront;
    int _iSize;
public:
    Queue();
    ~Queue();
    bool isEmpty();
    void enQueue(DataType data);
    DataType deQueue();
    DataType peek();
    int getSize();
    void display();
    void displayDetail();
};
