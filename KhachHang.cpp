#include "KhachHang.h"

/********************************************
* @Description Hàm khởi tạo Khách Hàng mới
********************************************/

KhachHang::KhachHang() {
    _iSoThuTu = 0;
    _strCMND = "";
    _strHoTen = "";
}

/********************************************
* @Description Hàm khởi tạo Khách Hàng mới
* @parameter Chuỗi CMND/CCCD, Chuỗi Họ Tên
********************************************/

KhachHang::KhachHang(string CMND, string hoTen) {
    _strCMND = CMND;
    _strHoTen = hoTen;
}

/********************************************
* @Description Hàm khởi tạo Khách Hàng mới
* @parameter Chuỗi CMND/CCCD, Chuỗi họ tên, Số thứ tự
********************************************/

KhachHang::KhachHang(string CMND, string hoTen, int soThuTu) {
    _strCMND = CMND;
    _strHoTen = hoTen;
    _iSoThuTu = soThuTu;
}

/********************************************
* @Description Hàm set số thứ tự Khách Hàng
* @parameter Chuỗi số thứ tự
* @attention Chuyển từ chuỗi số thứ tự thành số thứ tự, sau đó cập nhật cho KhachHang
********************************************/

void KhachHang::setSoThuTu(string temp) {
    stringstream ss(temp);
    int soThuTu;
    ss >> soThuTu;
    _iSoThuTu = soThuTu;
}

/********************************************
* @Description Hàm hiển thị thông tin của Khách hàng
********************************************/

void KhachHang::display() {
    cout << _iSoThuTu << "|" << _strCMND << "|" << _strHoTen;
}

/********************************************
* @Description Hàm lấy thông tin của Khách Hàng để chuẩn bị ghi File
* @return Một chuỗi thông tin Khách
********************************************/

string KhachHang::thongTinFile() {
    string result = "";
    stringstream ss;
    ss << _iSoThuTu;
    string soThuTuString;
    ss >> soThuTuString;
    result = soThuTuString + "|" + _strCMND + "|" + _strHoTen;
    return result;
}

/********************************************
* @Description Hàm lấy CMND/CCCD của Khách hàng
* @return Một chuỗi thông tin CMND/CCCD Khách
********************************************/

string KhachHang::getCMND() {
    return _strCMND;
}

/********************************************
* @Description Hàm lấy Họ Tên của Khách hàng
* @return Một chuỗi thông tin Họ Tên Khách
********************************************/

string KhachHang::getHoTen() {
    return _strHoTen;
}