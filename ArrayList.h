#pragma once
#include "Header.h"
template <class DataType>
class ArrayList {
    int _iCapacity;
    int _iSize;
    DataType* _items;
public:
    ArrayList();
    ArrayList(int maxSize);
    ~ArrayList();
    DataType getItem(int i);
    DataType* getPointerItem(int i);
    int getSize();
    void setItem(int i, DataType item);
    void setMaxSize(int maxSize);
    void display();
    void displayDetail();
    void add(DataType data);

};
