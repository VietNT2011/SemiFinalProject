#pragma once
#include "Queue.h"

template <class Ve>
class DanhSachVePending :public Queue<Ve> {
public:
    void xuLyDocFile();
    void xuLyGhiFile(Ve data);
    void updateFile();
    bool xuLyVeTheoMa(string maVeCanXuLy, Ve& veTimDuoc);
    vector<Ve> layTatCaVeTheoCMND(string CMND);
};
