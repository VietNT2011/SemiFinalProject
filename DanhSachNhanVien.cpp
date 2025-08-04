#include "DanhSachNhanVien.h"

/********************************************
* @Description H�m x? l� ??c file cho Danh S�ch Nh�n Vi�n
********************************************/

template <class NhanVien>
void DanhSachNhanVien<NhanVien>::xuLyDocFile() {
    ifstream ifile("Admin.txt");
    if (!ifile) {
        cout << "Khong mo duoc file Admin.txt!" << endl;
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
        if (dataTemp.size() != 2) {
            continue;
        }
        //Kh?i t?o m?t ??i t??ng Nh�n Vi�n m?i 
        NhanVien* newItem = new NhanVien(dataTemp[0], dataTemp[1]);
        //Th�m v�o Danh S�ch Nh�n Vi�n
        LinkedList<NhanVien>::addTail(*newItem);
    }
    ifile.close();
}

/********************************************
* @Description H�m t�m ki?m Nh�n Vi�n cho Danh S�ch Nh�n Vi�n
* @parameter Chu?i username v� chu?i password c?n t�m
* @return Tr? v? gi� tr? ??a ch? c?a Nh�n Vi�n t�m th?y, n?u kh�ng t�m th?y th� tr? v? NULL
********************************************/

template <class NhanVien>
NhanVien* DanhSachNhanVien<NhanVien>::timKiemNhanVien(string username, string password) {
    Node<NhanVien>* pWalker = LinkedList<NhanVien>::getHead();
    while (pWalker != NULL) {
        if (pWalker->_data.getUsername() == username && pWalker->_data.getPassword() == password) {
            return &(pWalker->_data);
        }
        pWalker = pWalker->_pNext;
    }
    return NULL;
}