#pragma once
#include "Header.h"
class Ve {
    string _strMaVe;
    string _strMaChuyenBay;
    string _strHoTen;
    string _strCMND;
    int _iSoGhe;
    long _lTimestamp;
    string _strDate;
public:
    Ve();
    Ve(string maVe, string maChuyenBay, string CMND, string hoTen);
    Ve(string maVe, string maChuyenBay, string CMND, string hoTen, int soGhe);
    Ve(string maVe, string maChuyenBay, string CMND, string hoTen, int soGhe, string date);
    void setSoGhe(string temp);
    string thongTinFile();
    void display();
    void displayDetail();
    string getMaChuyenBay();
    string getMaVe();
    int getSoGhe();
    string getHoTen();
    string getDate();
    void createFile();
    void deleteFile();
    void setDate(string date);
    void setTimestamp();
};
