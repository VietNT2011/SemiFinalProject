#include "DanhSachVePending.h"
#include "Queue.h"
#include "Ve.h"
#include "Header.h"

/********************************************
* @Description Hàm x? lý ??c file cho Danh Sách Vé ?ang Ch?
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
        //Kh?i t?o m?t ??i t??ng Vé m?i
        Ve* newItem = new Ve(dataTemp[0], dataTemp[1], dataTemp[2], dataTemp[3]);
        //Set các thu?c tính cho Vé ?ó
        newItem->setSoGhe(dataTemp[4]);
        newItem->setDate(dataTemp[5]);
        newItem->setTimestamp();

        //Them vào danh sách vé C?n ch? x? lý
        Queue<Ve>::enQueue(*newItem);
    }
    ifile.close();
}

/********************************************
* @Description Hàm x? lý ghi file cho Danh Sách Vé ?ang Ch?
* @parameter Vé mu?n ghi vào file
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
* @Description Hàm x? lý c?p nh?t l?i file cho Danh Sách Vé ?ang Ch?
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
template <class Ve>
bool DanhSachVePending<Ve>::xuLyVeTheoMa(string maVeCanXuLy, Ve& veTimDuoc) {
    Queue<Ve> tempQueue;
    bool found = false;

    while (!this->isEmpty()) {
        Ve current = this->deQueue();
        if (!found && toUpperCase(current.getMaVe()) == toUpperCase(maVeCanXuLy)) {
            veTimDuoc = current;
            found = true;
            continue; // không thêm vào tempQueue
        }
        tempQueue.enQueue(current);
    }
    while (!tempQueue.isEmpty()) {
        this->enQueue(tempQueue.deQueue());
    }

    if (found) {
        this->updateFile();
    }

    return found;
}

/********************************************
* @Description Trả về danh sách tất cả các vé đang chờ theo CMND
* @parameter CMND khách hàng cần tìm
* @return vector chứa các vé khớp
********************************************/
template <class Ve>
vector<Ve> DanhSachVePending<Ve>::layTatCaVeTheoCMND(string CMND) {
    vector<Ve> danhSachVe;
    Queue<Ve> tempQueue;

    while (!this->isEmpty()) {
        Ve current = this->deQueue();
        if (toUpperCase(current.getCMND()) == toUpperCase(CMND)) {
            danhSachVe.push_back(current);
        }
        tempQueue.enQueue(current);
    }

    // Đưa dữ liệu trở lại hàng đợi gốc
    while (!tempQueue.isEmpty()) {
        this->enQueue(tempQueue.deQueue());
    }

    return danhSachVe;
}