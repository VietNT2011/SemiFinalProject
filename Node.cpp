#include "Node.h"
#include "Header.h"

/********************************************
* @Description Hàm khởi tạo một Node có giá trị là data
* @parameter Giá trị data
********************************************/

template <class DataType>
Node<DataType>::Node(DataType data) {
    _pNext = NULL;
    _data = data;
}

/********************************************
* @Description Hàm hiển thị thông tin một Node
********************************************/

template <class DataType>
void Node<DataType>::display() {
    _data.display();
}

/********************************************
* @Description Hàm hiển thị thông tin chi tiết một Node
********************************************/

template <class DataType>
void Node<DataType>::displayDetail() {
    _data.displayDetail();
}

template <class DataType>
Node<DataType>* Node<DataType>::getNext() {
    return _pNext;
}

template <class DataType>
DataType& Node<DataType>::getData() {
    return _data;
}