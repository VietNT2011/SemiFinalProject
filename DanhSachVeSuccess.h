#pragma once
#include "Header.h"
#include "LinkedList.h"

template <class Ve>
class DanhSachVeSuccess :public LinkedList<Ve> {
public:
    void xuLyDocFile();
    void xuLyGhiFile(Ve data);
    void updateFile();
    Ve* timKiemVe(int maSoGhe, string maChuyenBay);
    Ve* timKiemVe(string maVe);
    Node<Ve>* timKiemNode(string maVe);
    vector<Ve> layTatCaVeTheoCMND(string CMND);
};
