#include "DanhSachMayBay.h"
#include "LinkedList.h"

/********************************************
* @Description Hàm x? lý ??c file cho Danh Sách Máy Bay
********************************************/

template <class MayBay>
void DanhSachMayBay<MayBay>::xuLyDocFile() {
    ifstream ifile("MayBay.txt");
    if (!ifile) {
        cout << "Khong mo duoc file MayBay.txt!" << endl;
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
        //Kh?i t?o m?t ??i t??ng Máy Bay m?i
        MayBay* newItem = new MayBay();
        //Set các thu?c tính cho ??i t??ng
        newItem->setSoHieuMayBay(dataTemp[0]);
        newItem->setSoCho(dataTemp[1]);

        //Thêm vào danh sách máy bay
        LinkedList<MayBay>::addTail(*newItem);
    }
    ifile.close();
}

/********************************************
* @Description Hàm tìm ki?m Máy bay cho Danh Sách Máy Bay
* @parameter Chu?i S? hi?u máy bay c?n tìm
* @return Tr? v? ??a ch? c?a Máy Bay tìm th?y, n?u không tìm th?y thì tr? v? NULL
********************************************/

template <class MayBay>
MayBay* DanhSachMayBay<MayBay>::timKiemMayBay(string soHieuMayBay) {
    Node<MayBay>* pWalker = LinkedList<MayBay>::getHead();
    while (pWalker != NULL) {
        if (pWalker->_data.getSoHieuMayBay() == soHieuMayBay) {
            return &(pWalker->_data);
        }
        pWalker = pWalker->_pNext;
    }
    return NULL;
}