#pragma once
#include "Header.h"
class KhachHang {
    int _iSoThuTu;
    string _strCMND;
    string _strHoTen;
public:
    KhachHang();
    KhachHang(string CMND, string hoTen);
    KhachHang(string CMND, string hoTen, int soThuTu);
    void setSoThuTu(string temp);
    void display();
    string thongTinFile();
    string getCMND();
    string getHoTen();
};
