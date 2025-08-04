#include "DanhSachKhachHang.h"

/********************************************
* @Description Hàm x? lý ??c file cho Danh Sách Khách Hàng
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
        //Kh?i t?o ??i t??ng Khách Hàng m?i v?i 2 tham s?
        KhachHang* newItem = new KhachHang(dataTemp[1], dataTemp[2]);
        //Set các thu?c tính cho Khách Hàng v?a t?o
        newItem->setSoThuTu(dataTemp[0]);

        //Thêm vào Danh Sách Khách Hàng
        LinkedList<KhachHang>::addTail(*newItem);
    }
    ifile.close();
}

/********************************************
* @Description Hàm x? lý ghi file cho Danh Sách Khách Hàng
* @parameter Khách Hàng mu?n ghi thêm vào file
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
* @Description Hàm tìm ki?m m?t Khách Hàng d?a trên CMND ho?c CCCD trong Danh Sách Khách Hàng
* @parameter CMND/CCCD mu?n tìm
* @return Tr? v? ??a ch? c?a Khách hàng tìm th?y, n?u không tìm th?y tr? v? NULL
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