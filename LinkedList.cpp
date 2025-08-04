#include "Header.h"
#include "LinkedList.h"
#include "Node.h"

/********************************************
* @Description Hàm khởi tạo Linked List
********************************************/

template <class DataType>
LinkedList<DataType>::LinkedList() {
    _pHead = NULL;
    _pTail = NULL;
    _iSize = 0;
}

/********************************************
* @Description Hàm hủy Linked List
********************************************/

template <class DataType>
LinkedList<DataType>::~LinkedList() {
}

/********************************************
* @Description Hàm thêm vào đuôi phần tử có giá trị data
* @parameter Phần tử có giá trị data
* @attention: Nếu Linked List đang trống thì phần tử đầu bằng phần tử đuôi và bằng phần tử được thêm
********************************************/

template <class DataType>
void LinkedList<DataType>::addTail(DataType data) {
    Node<DataType>* pAdd = new Node<DataType>(data);
    if (_pHead == NULL) {
        _pHead = pAdd;
        _pTail = pAdd;
    }
    else {
        _pTail->_pNext = pAdd;
        _pTail = _pTail->_pNext;
    }
    _iSize++;
}

/********************************************
* @Description Hàm xóa phần tử node trong Linked List
* @parameter Node muốn xóa
* @attention Nếu node là phần tử đầu, thì gọi removeHead, nếu node có tồn tại trong danh sách thì mới thực hiện xóa
********************************************/

template <class DataType>
void LinkedList<DataType>::remove(Node<DataType>* node) {
    if (node == _pHead) {
        removeHead();
    }
    else {
        if (node != NULL) {
            Node<DataType>* pSearchPre = searchPre(node);
            if (pSearchPre != NULL) {
                pSearchPre->_pNext = node->_pNext;
                if (pSearchPre->_pNext == NULL) {
                    _pTail = pSearchPre;
                }
                delete node;
                _iSize--;
            }
        }

    }
}

/********************************************
* @Description Hàm xóa phần tử đầu trong Linked List
* @attention Nếu LinkedList có tồn tại phần tử đầu trong danh sách thì mới thực hiện xóa
********************************************/

template <class DataType>
void LinkedList<DataType>::removeHead() {
    if (_pHead != NULL) {
        Node<DataType>* pTemp = _pHead;
        _pHead = _pHead->_pNext;
        if (_pHead == NULL) {
            _pTail = NULL;
        }
        delete pTemp;
        _iSize--;
    }
}

/********************************************
* @Description Hàm tìm phần tử đứng trước một node trong Linked List
* @parameter Node muốn tìm
* @return Node đứng trước Node cần tìm
* @attention Nếu node là phần tử đầu hoặc node không tồn tại thì không thực hiện tìm kiếm
********************************************/

template <class DataType>
Node<DataType>* LinkedList<DataType>::searchPre(Node<DataType>* node) {
    if (node == NULL || node == _pHead) {
        return NULL;
    }
    Node<DataType>* pWalker = _pHead;
    while (pWalker != NULL) {
        if (pWalker->_pNext == node) {
            return pWalker;
        }
        pWalker = pWalker->_pNext;
    }
    return pWalker;
}

/********************************************
* @Description Hàm lấy số lượng phần tử đang có trong Linked List
* @return Số lượng phần tử của Linked List
********************************************/

template <class DataType>
int LinkedList<DataType>::getSize() {
    return _iSize;
}

/********************************************
* @Description Hàm hiển thị từng phần tử trong Linked List
********************************************/

template <class DataType>
void LinkedList<DataType>::display() {
    Node<DataType>* pWalker = _pHead;
    while (pWalker != NULL) {
        pWalker->display();
        cout << endl;
        pWalker = pWalker->_pNext;
    }
}

/********************************************
* @Description Hàm hiển thị chi tiết từng phần tử trong Linked List
********************************************/

template <class DataType>
void LinkedList<DataType>::displayDetail() {
    Node<DataType>* pWalker = _pHead;
    while (pWalker != NULL) {
        pWalker->displayDetail();
        cout << endl;
        pWalker = pWalker->_pNext;
    }
}

/********************************************
* @Description Hàm lấy phần tử đầu trong Linked List
* @return Phần tử đầu trong LinkedList
********************************************/

template <class DataType>
Node<DataType>* LinkedList<DataType>::getHead() {
    return _pHead;
}

/********************************************
* @Description Hàm lấy phần tử đuôi trong Linked List
* @return Phần tử đuôi trong LinkedList
********************************************/

template <class DataType>
Node<DataType>* LinkedList<DataType>::getTail() {
    return _pTail;
}

