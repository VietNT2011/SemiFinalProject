#include "DanhSachVeSuccess.h"
#include "Header.h"
#include "LinkedList.h"
#include "Node.h"

/********************************************
* @Description H�m x? l� ??c file cho Danh S�ch V� Th�nh C�ng
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
        //Kh?i t?o m?t ??i t??ng V� m?i
        Ve* newItem = new Ve(dataTemp[0], dataTemp[1], dataTemp[2], dataTemp[3]);
        //Set c�c thu?c t�nh cho V� ?�
        newItem->setSoGhe(dataTemp[4]);
        newItem->setDate(dataTemp[5]);
        newItem->setTimestamp();

        //Th�m v�o danh s�ch V� Th�nh C�ng
        LinkedList<Ve>::addTail(*newItem);
    }
    ifile.close();
}

/********************************************
* @Description H�m x? l� ghi file cho Danh S�ch V� Th�nh C�ng
* @parameter V� mu?n ghi file
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
* @Description H�m x? l� c?p nh?t la? file cho Danh S�ch V� Th�nh C�ng
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
* @Description H�m t�m ki?m V� trong Danh S�ch V� Th�nh C�ng
* @parameter S? gh? v� Chu?i M� Chuy?n Bay mu?n t�m
* @return Tr? v? ??a ch? c?a V� t�m th?y, n?u kh�ng t�m th?y th� tr? v? NULL
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
* @Description H�m t�m ki?m V� trong Danh S�ch V� Th�nh C�ng
* @parameter Chu?i M� V� mu?n t�m
* @return Tr? v? ??a ch? c?a V� t�m th?y, n?u kh�ng t�m th?y th� tr? v? NULL
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
* @Description H�m t�m ki?m V� (Node) trong Danh S�ch V� Th�nh C�ng
* @parameter Chu?i M� V� mu?n t�m
* @return Tr? v? Node ch?a V� t�m th?y, n?u kh�ng t�m th?y th� tr? v? NULL
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