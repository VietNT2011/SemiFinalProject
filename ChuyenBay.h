#pragma once
#include "Ve.h"
#include "Header.h"
#include "DanhSachVeSuccess.h"
template <class DataType>
class ChuyenBay {
    string _strMaChuyenBay;
    string _strSoHieuMayBay;
    string _strNgayKhoiHanh;
    string _strSanBayDen;
    int _iTrangThai;
    Ve* _danhSachVe;
    int _danhSachGheTrong[100];
    int _iSoLuongVe;
    int _iSoLuongGheTrong;
    int _iSoCho;
    long _lTimestamp;
public:
    ChuyenBay();
    ChuyenBay(string maChuyenBay, string soHieuMayBay, string ngayKhoiHanh, string sanBayDen);
    void display();
    void hienThiSoDoGhe();
    void displayDetail();
    void hienThiDanhSachKhach();
    void hienThiDanhSachGheTrong();
    void setSoCho(int soCho);
    void setTrangThai(string temp);
    void removeGhe(int index);
    void setDanhSachGheTrong();
    void setDanhSachVe(string danhSachVe, string maChuyenBay, DanhSachVeSuccess<DataType> DSVS);
    void themVeMoi(Ve data);
    void removeVe(int soGhe);
    void themGheTrongMoi(int soGhe);
    void removeGheTrong(int soGhe);
    string getMaChuyenBay();
    string getSoHieuMayBay();
    int getTrangThai();
    bool isFullSeat();
    int isBooked(int maSoGhe);
    int kiemTraMaSoGhe(int maSoGhe);
    DataType* getDanhSachVe();
    int getSoLuongVe();
    void updateTrangThai();
    void setTimestamp();
    long getTimestamp();
    void sapXepDanhSachVe(int type);
    void sapXepDanhSachGheTrong(int type);
    string thongTinFile();

};

