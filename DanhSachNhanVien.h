#pragma once
#include "Header.h"
#include "LinkedList.h"

template <class NhanVien>
class DanhSachNhanVien :public LinkedList<NhanVien> {
public:
    void xuLyDocFile();
    NhanVien* timKiemNhanVien(string username, string password);

};

