#include "DanhSachNhanVien.h"

/********************************************
* @Description Hàm x? lý ??c file cho Danh Sách Nhân Viên
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
        //Kh?i t?o m?t ??i t??ng Nhân Viên m?i 
        NhanVien* newItem = new NhanVien(dataTemp[0], dataTemp[1]);
        //Thêm vào Danh Sách Nhân Viên
        LinkedList<NhanVien>::addTail(*newItem);
    }
    ifile.close();
}

/********************************************
* @Description Hàm tìm ki?m Nhân Viên cho Danh Sách Nhân Viên
* @parameter Chu?i username và chu?i password c?n tìm
* @return Tr? v? giá tr? ??a ch? c?a Nhân Viên tìm th?y, n?u không tìm th?y thì tr? v? NULL
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