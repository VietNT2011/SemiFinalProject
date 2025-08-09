#pragma once
#include "Header.h"
#include "ArrayList.h"
#include "DanhSachMayBay.h"
#include "DanhSachVeSuccess.h"

template <class ChuyenBay, class MayBay, class Ve>
class DanhSachChuyenBay :public ArrayList<ChuyenBay> {
public:
    DanhSachChuyenBay(int maxSize);
    int timKiemChuyenBay(string maChuyenBay);
    void hienThiSoLanBay(string soHieuMayBay);
    void xuLyDocFile(DanhSachMayBay<MayBay> DSMB, DanhSachVeSuccess<Ve> DSVS);
    void updateFile();
    void hienThiChuyenBay();
    void ShowListNoSearch();
    void updateTrangThai();

};  