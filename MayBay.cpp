#include "MayBay.h"

/********************************************
* @Description Hàm khởi tạo Máy Bay mới
********************************************/

MayBay::MayBay() {
    _strSoHieuMayBay = "";
    _iSoCho = 0;
}

/********************************************
* @Description Hàm khởi tạo Máy Bay mới
* @parameter Chuỗi số hiệu máy bay, số chỗ
********************************************/

MayBay::MayBay(string soHieuMayBay, int soCho) {
    _strSoHieuMayBay = soHieuMayBay;
    _iSoCho = soCho;
}

/********************************************
* @Description Hàm lấy số hiệu máy bay của Máy Bay
* @return Chuỗi số hiệu máy bay
********************************************/

string MayBay::getSoHieuMayBay() {
    return _strSoHieuMayBay;
}

/********************************************
* @Description Hàm lấy số chỗ của Máy Bay
* @return Số chỗ máy bay
********************************************/

int MayBay::getSoCho() {
    return _iSoCho;
}

/********************************************
* @Description Hàm set số hiệu máy bay của Máy Bay
* @parameter Chuỗi số hiệu máy bay muốn set
********************************************/

void MayBay::setSoHieuMayBay(string soHieuMayBay) {
    _strSoHieuMayBay = soHieuMayBay;
}

/********************************************
* @Description Hàm set số chỗ của Máy Bay
* @parameter Chuỗi số chỗ máy bay muốn set
* @attention Chuyển từ chuỗi thành số, sau đó set số chỗ cho máy bay
********************************************/

void MayBay::setSoCho(string temp) {
    stringstream ss(temp);
    int soCho;
    ss >> soCho;
    _iSoCho = soCho;
}

/********************************************
* @Description Hàm hiển thị thông tin của Máy bay
********************************************/

void MayBay::display() {
    cout << _strSoHieuMayBay << "|" << _iSoCho;
}
