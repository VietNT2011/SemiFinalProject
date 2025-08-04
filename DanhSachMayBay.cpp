#include "DanhSachMayBay.h"
#include "LinkedList.h"

/********************************************
* @Description H�m x? l� ??c file cho Danh S�ch M�y Bay
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
        //Kh?i t?o m?t ??i t??ng M�y Bay m?i
        MayBay* newItem = new MayBay();
        //Set c�c thu?c t�nh cho ??i t??ng
        newItem->setSoHieuMayBay(dataTemp[0]);
        newItem->setSoCho(dataTemp[1]);

        //Th�m v�o danh s�ch m�y bay
        LinkedList<MayBay>::addTail(*newItem);
    }
    ifile.close();
}

/********************************************
* @Description H�m t�m ki?m M�y bay cho Danh S�ch M�y Bay
* @parameter Chu?i S? hi?u m�y bay c?n t�m
* @return Tr? v? ??a ch? c?a M�y Bay t�m th?y, n?u kh�ng t�m th?y th� tr? v? NULL
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