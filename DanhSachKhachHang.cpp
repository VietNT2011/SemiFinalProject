#include "DanhSachKhachHang.h"

/********************************************
* @Description H�m x? l� ??c file cho Danh S�ch Kh�ch H�ng
********************************************/

template <class KhachHang>
void DanhSachKhachHang<KhachHang>::xuLyDocFile() {
    ifstream ifile("KhachHang.txt");
    if (!ifile) {
        cout << "Khong mo duoc file KhachHang.txt!" << endl;
        exit(1);
        return;
    }
    string s;
    while (getline(ifile, s)) {
        stringstream ss(s);
        string temp;
        vector<string> dataTemp;
        while (getline(ss, temp, '|')) {
            dataTemp.push_back(temp);
        }
        if (dataTemp.size() != 3) {
            continue;
        }
        //Kh?i t?o ??i t??ng Kh�ch H�ng m?i v?i 2 tham s?
        KhachHang* newItem = new KhachHang(dataTemp[1], dataTemp[2]);
        //Set c�c thu?c t�nh cho Kh�ch H�ng v?a t?o
        newItem->setSoThuTu(dataTemp[0]);

        //Th�m v�o Danh S�ch Kh�ch H�ng
        LinkedList<KhachHang>::addTail(*newItem);
    }
    ifile.close();
}

/********************************************
* @Description H�m x? l� ghi file cho Danh S�ch Kh�ch H�ng
* @parameter Kh�ch H�ng mu?n ghi th�m v�o file
********************************************/

template <class KhachHang>
void DanhSachKhachHang<KhachHang>::xuLyGhiFile(KhachHang data) {
    ofstream ofile;
    ofile.open("KhachHang.txt", ios::in | ios::app);
    if (LinkedList<KhachHang>::getSize() != 1) {
        ofile << endl;
    }
    ofile << data.thongTinFile();
    ofile.close();
}

/********************************************
* @Description H�m t�m ki?m m?t Kh�ch H�ng d?a tr�n CMND ho?c CCCD trong Danh S�ch Kh�ch H�ng
* @parameter CMND/CCCD mu?n t�m
* @return Tr? v? ??a ch? c?a Kh�ch h�ng t�m th?y, n?u kh�ng t�m th?y tr? v? NULL
********************************************/

template <class KhachHang>
KhachHang* DanhSachKhachHang<KhachHang>::timKiemKhachHang(string CMND) {
    Node<KhachHang>* pWalker = LinkedList<KhachHang>::getHead();
    while (pWalker != NULL) {
        if (pWalker->_data.getCMND() == CMND) {
            return &(pWalker->_data);
        }
        pWalker = pWalker->_pNext;
    }
    return NULL;

}