#pragma once
#include "Node.h"
#include "Header.h"
template <class DataType>
class LinkedList {
protected:
    Node<DataType>* _pHead;
    Node<DataType>* _pTail;
    int _iSize;
public:
    LinkedList();
    ~LinkedList();
    void addTail(DataType data);
    void remove(Node<DataType>* node);
    void removeHead();
    Node<DataType>* searchPre(Node<DataType>* node);
    int getSize();
    void display();
    void displayDetail();
    Node<DataType>* getHead();
    Node<DataType>* getTail();
};
