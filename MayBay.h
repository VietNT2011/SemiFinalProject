#pragma once
#include "Header.h"
class MayBay {
    string _strSoHieuMayBay;
    int _iSoCho;
public:
    MayBay();
    MayBay(string soHieuMayBay, int soCho);
    string getSoHieuMayBay();
    int getSoCho();
    void setSoHieuMayBay(string soHieuMayBay);
    void setSoCho(string temp);
    void display();
};