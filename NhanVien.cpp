#include "NhanVien.h"

/********************************************
* @Description Hàm khởi tạo đối tượng Nhân Viên mới
********************************************/

NhanVien::NhanVien() {
    _strUsername = "";
    _strPassword = "";
}

/********************************************
* @Description Hàm khởi tạo đối tượng Nhân Viên mới
* @parameter Chuỗi username và password
********************************************/

NhanVien::NhanVien(string username, string password) {
    _strUsername = username;
    _strPassword = password;
}

/********************************************
* @Description Hàm hiển thị thông tin Nhân Viên
********************************************/

void NhanVien::display() {
    cout << _strUsername << "|" << _strPassword;
}

/********************************************
* @Description Hàm lấy username Nhân Viên
* @return Chuỗi username của nhân viên
********************************************/

string NhanVien::getUsername() {
    return _strUsername;
}

/********************************************
* @Description Hàm lấy password Nhân Viên
* @return Chuỗi password của nhân viên
********************************************/

string NhanVien::getPassword() {
    return _strPassword;
}