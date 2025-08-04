#include "DanhSachVeSuccess.h"
#include "Header.h"
#include "LinkedList.h"
#include "Node.h"

/********************************************
* @Description Hàm x? lý ??c file cho Danh Sách Vé Thành Công
********************************************/

template <class Ve>
void DanhSachVeSuccess<Ve>::xuLyDocFile() {
    ifstream ifile("VeThanhCong.txt");
    if (!ifile) {
        cout << "Khong mo duoc file VeThanhCong.txt!" << endl;
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
        if (dataTemp.size() != 6) {
            continue;
        }
        //Kh?i t?o m?t ??i t??ng Vé m?i
        Ve* newItem = new Ve(dataTemp[0], dataTemp[1], dataTemp[2], dataTemp[3]);
        //Set các thu?c tính cho Vé ?ó
        newItem->setSoGhe(dataTemp[4]);
        newItem->setDate(dataTemp[5]);
        newItem->setTimestamp();

        //Thêm vào danh sách Vé Thành Công
        LinkedList<Ve>::addTail(*newItem);
    }
    ifile.close();
}

/********************************************
* @Description Hàm x? lý ghi file cho Danh Sách Vé Thành Công
* @parameter Vé mu?n ghi file
********************************************/

template <class Ve>
void DanhSachVeSuccess<Ve>::xuLyGhiFile(Ve data) {
    ofstream ofile;
    ofile.open("VeThanhCong.txt", ios::in | ios::out | ios::app);
    if (LinkedList<Ve>::getSize() != 0) {
        ofile << endl;
    }
    ofile << data.thongTinFile();
    ofile.close();
}

/********************************************
* @Description Hàm x? lý c?p nh?t la? file cho Danh Sách Vé Thành Công
********************************************/

template <class Ve>
void DanhSachVeSuccess<Ve>::updateFile() {
    ofstream ofile;
    ofile.open("VeThanhCong.txt", ios::out);
    Node<Ve>* pWalker = LinkedList<Ve>::getHead();
    while (pWalker != NULL) {
        ofile << pWalker->_data.thongTinFile();
        if (pWalker != LinkedList<Ve>::getTail()) {
            ofile << endl;
        }
        pWalker = pWalker->_pNext;
    }
    ofile.close();
}

/********************************************
* @Description Hàm tìm ki?m Vé trong Danh Sách Vé Thành Công
* @parameter S? gh? và Chu?i Mã Chuy?n Bay mu?n tìm
* @return Tr? v? ??a ch? c?a Vé tìm th?y, n?u không tìm th?y thì tr? v? NULL
********************************************/

template <class Ve>
Ve* DanhSachVeSuccess<Ve>::timKiemVe(int maSoGhe, string maChuyenBay) {
    Node<Ve>* pWalker = LinkedList<Ve>::getHead();
    while (pWalker != NULL) {
        if (pWalker->_data.getSoGhe() == maSoGhe && pWalker->_data.getMaChuyenBay() == maChuyenBay) {

            return &(pWalker->_data);
        }
        pWalker = pWalker->_pNext;
    }
    return NULL;
}

/********************************************
* @Description Hàm tìm ki?m Vé trong Danh Sách Vé Thành Công
* @parameter Chu?i Mã Vé mu?n tìm
* @return Tr? v? ??a ch? c?a Vé tìm th?y, n?u không tìm th?y thì tr? v? NULL
********************************************/

template <class Ve>
Ve* DanhSachVeSuccess<Ve>::timKiemVe(string maVe) {
    Node<Ve>* pWalker = LinkedList<Ve>::getHead();
    while (pWalker != NULL) {
        if (pWalker->_data.getMaVe() == maVe) {
            return &(pWalker->_data);
        }
        pWalker = pWalker->_pNext;
    }
    return NULL;
}

/********************************************
* @Description Hàm tìm ki?m Vé (Node) trong Danh Sách Vé Thành Công
* @parameter Chu?i Mã Vé mu?n tìm
* @return Tr? v? Node ch?a Vé tìm th?y, n?u không tìm th?y thì tr? v? NULL
********************************************/

template <class Ve>
Node<Ve>* DanhSachVeSuccess<Ve>::timKiemNode(string maVe) {
    Node<Ve>* pWalker = LinkedList<Ve>::getHead();
    while (pWalker != NULL) {
        if (pWalker->_data.getMaVe() == maVe) {
            return pWalker;
        }
        pWalker = pWalker->_pNext;
    }
    return NULL;
}