#pragma once
#include "Header.h"
#include "LinkedList.h"
template <class MayBay>
class DanhSachMayBay :public LinkedList<MayBay> {
public:
    void xuLyDocFile();
    MayBay* timKiemMayBay(string soHieuMayBay);
    void showAll();
};
