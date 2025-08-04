#include "DanhSachVePending.h"
#include "Queue.h"
#include "Ve.h"
#include "Header.h"

/********************************************
* @Description H�m x? l� ??c file cho Danh S�ch V� ?ang Ch?
********************************************/

template <class Ve>
void DanhSachVePending<Ve>::xuLyDocFile() {
    ifstream ifile("VeDangCho.txt");
    if (!ifile) {
        cout << "Khong mo duoc file VeDangCho.txt!" << endl;
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

        //Them v�o danh s�ch v� C?n ch? x? l�
        Queue<Ve>::enQueue(*newItem);
    }
    ifile.close();
}

/********************************************
* @Description H�m x? l� ghi file cho Danh S�ch V� ?ang Ch?
* @parameter V� mu?n ghi v�o file
********************************************/

template <class Ve>
void DanhSachVePending<Ve>::xuLyGhiFile(Ve data) {
    ofstream ofile;
    ofile.open("VeDangCho.txt", ios::in | ios::app);
    if (Queue<Ve>::getSize() != 1) {
        ofile << endl;
    }
    ofile << data.thongTinFile();
    ofile.close();
}

/********************************************
* @Description H�m x? l� c?p nh?t l?i file cho Danh S�ch V� ?ang Ch?
********************************************/

template <class Ve>
void DanhSachVePending<Ve>::updateFile() {
    ofstream ofile;
    ofile.open("VeDangCho.txt", ios::out);
    for (int i = 0; i < Queue<Ve>::getSize(); i++) {
        Ve data = Queue<Ve>::peek();
        ofile << data.thongTinFile();
        if (i != Queue<Ve>::getSize() - 1) {
            ofile << endl;
        }
    }
    ofile.close();
}
