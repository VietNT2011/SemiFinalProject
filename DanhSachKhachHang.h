#pragma once
#include "Header.h"
#include "LinkedList.h"

template <class KhachHang>
class DanhSachKhachHang :public LinkedList<KhachHang> {
public:
    void xuLyDocFile();
    void xuLyGhiFile(KhachHang data);
    KhachHang* timKiemKhachHang(string CMND);
};
