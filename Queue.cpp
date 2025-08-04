#include "Header.h"
#include "Queue.h"
#include "Node.h"

/********************************************
* @Description Hàm khởi tạo một Queue rỗng
********************************************/

template <class DataType>
Queue<DataType>::Queue() {
    _pHear = NULL;
    _pFront = NULL;
    _iSize = 0;
}

/********************************************
* @Description Hàm hủy một Queue
********************************************/

template <class DataType>
Queue<DataType>::~Queue() {
}

/********************************************
* @Description Hàm kiểm tra xem Queue có rỗng hay không
* @return True nếu Queue rỗng, ngược lại là False
********************************************/

template <class DataType>
bool Queue<DataType>::isEmpty() {
    return _pFront == NULL;
}

/********************************************
* @Description Hàm thêm một phần tử vào cuối hàng của Queue
********************************************/

template <class DataType>
void Queue<DataType>::enQueue(DataType data) {
    Node<DataType>* pAdd = new Node<DataType>(data);
    if (_pFront == NULL) {
        _pHear = pAdd;
        _pFront = pAdd;
    }
    else {
        _pHear->_pNext = pAdd;
        _pHear = _pHear->_pNext;
    }
    _iSize++;
}

/********************************************
* @Description Hàm lấy một phần tử đầu hàng của Queue
* @return Giá trị của phần tử đầu hàng
* @attention Nếu Queue đang rỗng thì thông báo ngoại lệ
********************************************/

template <class DataType>
DataType Queue<DataType>::deQueue() {
    if (isEmpty()) {
        cout << "Queue rong, khong the thuc hien" << endl;
        exit;
    }
    else {
        Node<DataType>* pTemp = _pFront;
        DataType dataTemp = pTemp->_data;
        _pFront = _pFront->_pNext;
        if (_pFront == NULL) {
            _pHear = NULL;
        }
        delete pTemp;
        _iSize--;
        return dataTemp;
    }
}

/********************************************
* @Description Hàm lấy giá trị của phần tử đầu hàng Queue
* @return Giá trị của phần tử đầu hàng
* @attention Nếu Queue đang rỗng thì thông báo ngoại lệ
********************************************/

template <class DataType>
DataType Queue<DataType>::peek() {
    if (isEmpty()) {
        cout << "Queue trong, khong the thuc hien" << endl;
        exit;
    }
    Node<DataType>* pTemp = _pFront;
    return pTemp->_data;
}

/********************************************
* @Description Hàm lấy số lượng phần tử của Queue
* @return Số lượng phần tử của Queue
********************************************/

template <class DataType>
int Queue<DataType>::getSize() {
    return _iSize;
}

/********************************************
* @Description Hàm hiển thị tất cả phần tử của Queue
********************************************/

template <class DataType>
void Queue<DataType>::display() {
    Node<DataType>* pWalker = _pFront;
    while (pWalker != NULL) {
        pWalker->display();
        cout << endl;
        pWalker = pWalker->_pNext;
    }
}

/********************************************
* @Description Hàm hiển thị chi tiết tất cả phần tử của Queue
********************************************/

template <class DataType>
void Queue<DataType>::displayDetail() {
    Node<DataType>* pWalker = _pFront;
    while (pWalker != NULL) {
        pWalker->displayDetail();
        cout << endl;
        pWalker = pWalker->_pNext;
    }
}
