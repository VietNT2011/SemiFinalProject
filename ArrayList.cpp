#include "Header.h"
#include "ArrayList.h"
/********************************************
* @Description Hàm khởi tạo List rỗng có số phần tử tối đa là MAX_SIZE
********************************************/

template <class DataType>
ArrayList<DataType>::ArrayList() {
    _iCapacity = MAX_SIZE;
    _items = new DataType[_iCapacity];
    _iSize = 0;
}

/********************************************
* @Description Hàm khởi tạo List rỗng có số phần tử tối đa là maxSize
* @parameter Số phần tử tối đa của List
* @attention Nếu maxSize <= 0 thì lấy giá trị mặc định là MAX_SIZE
********************************************/

template <class DataType>
ArrayList<DataType>::ArrayList(int maxSize) {
    _iCapacity = maxSize > 0 ? maxSize : MAX_SIZE;
    _items = new DataType[_iCapacity];
    _iSize = 0;
}

/********************************************
* @Description Hàm hủy hủy cấp phát bộ nhớ cho items
********************************************/

template <class DataType>
ArrayList<DataType>::~ArrayList() {
    delete[] _items;
}

/********************************************
* @Description Hàm lấy giá trị của phần tử thứ i
* @parameter Vị trí i(index) của phần tử muốn lấy ra
* @return Giá trị phần tử thứ i
********************************************/

template <class DataType>
DataType ArrayList<DataType>::getItem(int i) {
    return _items[i];
}

/********************************************
* @Description Hàm lấy địa chỉ của phần tử thứ i
* @parameter Vị trí i(index) của phần tử muốn lấy ra
* @return Địa chỉ phần tử thứ i
********************************************/

template <class DataType>
DataType* ArrayList<DataType>::getPointerItem(int i) {
    return &(_items[i]);
}

/********************************************
* @Description Hàm lấy số phần tử hiện tại của List
* @return Số lượng phần tử của List
********************************************/

template <class DataType>
int ArrayList<DataType>::getSize() {
    return _iSize;
}

/********************************************
* @Description Hàm set giá trị item cho phần tử thứ i của List
* @parameter Vị trí i(index) của phần tử muốn set và giá trị item muốn set.
********************************************/

template <class DataType>
void ArrayList<DataType>::setItem(int i, DataType item) {
    _items[i] = item;
}

/********************************************
* @Description Hàm set List có số phần tử tối đa là maxSize
* @parameter Số phần tử tối đa của List
* @attention Nếu maxSize <= 0 thì lấy giá trị mặc định là MAX_SIZE
********************************************/

template <class DataType>
void ArrayList<DataType>::setMaxSize(int maxSize) {
    _iCapacity = maxSize > 0 ? maxSize : MAX_SIZE;
    _items = new DataType[_iCapacity];
    _iSize = 0;
}

/********************************************
* @Description Hàm hiển thị List
********************************************/

template <class DataType>
void ArrayList<DataType>::display() {
    for (int i = 0; i < _iSize; i++) {
        _items[i].display();
        cout << endl;
    }
}

/********************************************
* @Description Hàm hiển thị thông tin chi tiết của List
********************************************/

template <class DataType>
void ArrayList<DataType>::displayDetail() {
    for (int i = 0; i < _iSize; i++) {
        _items[i].displayDetail();
        cout << endl;
    }
}

/********************************************
* @Description Hàm thêm vào cuối danh sách phần tử có giá trị data
* @parameter Giá trị data muốn thêm
* @attention Nếu số lượng phần tử đầy (bằng số lượng phần tử tối đa) thì không thêm
********************************************/

template <class DataType>
void ArrayList<DataType>::add(DataType data) {
    if (_iSize == _iCapacity) {
        cout << "Khong the them, vui long thu lai." << endl;
        return;
    }
    _items[_iSize] = data;
    _iSize++;
}