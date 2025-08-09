#include "DanhSachChuyenBay.h"
#include "DanhSachMayBay.h"
#include "DanhSachVeSuccess.h"
#include "ArrayList.h"
#include "ChuyenBay.h"
#include "Ve.h"

/********************************************
* @Description Hàm kh?i t?o Danh Sách Chuy?n Bay v?i s? l??ng ph?n t? là maxSize
********************************************/

template <class ChuyenBay, class MayBay, class Ve>
DanhSachChuyenBay<ChuyenBay, MayBay, Ve>::DanhSachChuyenBay(int maxSize) {
    ArrayList<ChuyenBay>::setMaxSize(maxSize);
}

/********************************************
* @Description Hàm tìm ki?m chuy?n bay theo mã chuy?n bay c?a Danh Sách Chuy?n Bay
* @parameter Chu?i mã chuy?n bay c?n tìm
* @return Tr? v? v? trí c?a ph?n t? tìm th?y, n?u không tr? v? -1
********************************************/

template <class ChuyenBay, class MayBay, class Ve>
int DanhSachChuyenBay<ChuyenBay, MayBay, Ve>::timKiemChuyenBay(string maChuyenBay) {
    for (int i = 0; i < ArrayList<ChuyenBay>::getSize(); i++) {
        ChuyenBay temp = ArrayList<ChuyenBay>::getItem(i);
        if (temp.getMaChuyenBay() == maChuyenBay) {
            return i;
        }
    }
    return -1;
}

/********************************************
* @Description Hàm hi?n th? s? l?n bay theo s? hi?u máy bay c?a Danh Sách Chuy?n Bay
* @parameter Chu?i s? hi?u máy bay c?n tìm
********************************************/

template <class ChuyenBay, class MayBay, class Ve>
void DanhSachChuyenBay<ChuyenBay, MayBay, Ve>::hienThiSoLanBay(string soHieuMayBay) {
    int thongKeHoanTat = 0;
    int thongKeConVe = 0;
    int thongKeHetVe = 0;
    int thongKeDaHuy = 0;
    setColor(2);
    cout << "\t\t\t\t\t";
    cout << "DANH SACH CAC CHUYEN BAY CUA MAY BAY " << soHieuMayBay << ": " << endl;
    setColor(7);
    cout << setfill('-');
    setColor(4);
    cout << setw(145) << "-" << endl;
    setColor(7);
    cout << setfill(' ');
    cout << setw(15) << left << "MA CHUYEN BAY";
    cout << setw(25) << left << "NGAY KHOI HANH";
    cout << setw(25) << left << "SAN BAY DEN";
    cout << setw(15) << left << "TRANG THAI";
    cout << setw(100) << left << "DANH SACH VE DUOC DAT" << endl;
    cout << setfill('-');
    setColor(4);
    cout << setw(145) << "-" << endl;
    setColor(7);
    cout << setfill(' ');
    for (int i = 0; i < ArrayList<ChuyenBay>::getSize(); i++) {
        ChuyenBay temp = ArrayList<ChuyenBay>::getItem(i);
        if (temp.getSoHieuMayBay() == soHieuMayBay) {
            if (temp.getTrangThai() == 0) {
                thongKeDaHuy++;
                setColor(4);
            }
            else if (temp.getTrangThai() == 1) {
                thongKeConVe++;
                setColor(9);
            }
            else if (temp.getTrangThai() == 2) {
                thongKeHetVe++;
                setColor(4);
            }
            else if (temp.getTrangThai() == 3) {
                thongKeHoanTat++;
                setColor(10);
            }
            temp.display();
            setColor(7);
            cout << endl;
        }
    }
    cout << setfill('-');
    setColor(4);
    cout << setw(145) << "-" << endl;
    setColor(7);
    cout << setfill(' ');
    cout << endl;
    setColor(2);
    cout << "\t\t\t\t\t";
    cout << "THONG KE: " << endl;
    setColor(7);
    cout << "\t\t\t";
    cout << "So chuyen bay hoan tat: " << thongKeHoanTat << " chuyen." << endl;
    cout << "\t\t\t";
    cout << "So chuyen bay da huy: " << thongKeDaHuy << " chuyen." << endl;
    cout << "\t\t\t";
    cout << "So chuyen bay con ve: " << thongKeConVe << " chuyen." << endl;
    cout << "\t\t\t";
    cout << "So chuyen bay het ve: " << thongKeHetVe << " chuyen." << endl;
}


/********************************************
* @Description Hàm x? lý ??c file Danh Sách Chuy?n Bay
* @parameter Danh sách máy bay, danh sách vé thành công
********************************************/

template <class ChuyenBay, class MayBay, class Ve>
void DanhSachChuyenBay<ChuyenBay, MayBay, Ve>::xuLyDocFile(DanhSachMayBay<MayBay> DSMB, DanhSachVeSuccess<Ve> DSVS) {
    ifstream ifile("ChuyenBay.txt");
    if (!ifile) {
        cout << "Khong mo duoc file ChuyenBay.txt!" << endl;
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
        if (dataTemp.size() < 6 && dataTemp.size() > 7) {
            continue;
        }
        MayBay* timKiemMayBay = DSMB.timKiemMayBay(dataTemp[1]);
        if (timKiemMayBay != NULL) {
            ChuyenBay* newItem = new ChuyenBay(dataTemp[0], dataTemp[1], dataTemp[2], dataTemp[3]);
            newItem->setTimestamp();
            newItem->setTrangThai(dataTemp[4]);
            newItem->setSoCho(timKiemMayBay->getSoCho());
            newItem->setDanhSachVe(dataTemp[5], dataTemp[0], DSVS);
            newItem->setDanhSachGheTrong();
            ArrayList<ChuyenBay>::add(*newItem);
        }
    }
    ifile.close();
}

/********************************************
* @Description Hàm c?p nh?t file Danh Sách Chuy?n Bay
********************************************/

template <class ChuyenBay, class MayBay, class Ve>
void DanhSachChuyenBay<ChuyenBay, MayBay, Ve>::updateFile() {
    ofstream ofile;
    ofile.open("ChuyenBay.txt", ios::out);
    for (int i = 0; i < ArrayList<ChuyenBay>::getSize(); i++) {
        ChuyenBay data = ArrayList<ChuyenBay>::getItem(i);
        ofile << data.thongTinFile();
        if (i != ArrayList<ChuyenBay>::getSize() - 1) {
            ofile << endl;
        }
    }
    ofile.close();
}

/********************************************
* @Description Hàm hi?n th? t?t c? các chuy?n bay c?a Danh Sách Chuy?n Bay
********************************************/

template <class ChuyenBay, class MayBay, class Ve>
void DanhSachChuyenBay<ChuyenBay, MayBay, Ve>::hienThiChuyenBay() {
    setColor(10);
    cout << "\t\t\t\t\t";
    cout << "DANH SACH CAC CHUYEN BAY:" << endl;
    setColor(7);
    cout << setfill('-');
    setColor(14);
    cout << setw(120) << "-" << endl;
    cout << endl;

    setColor(7);
    cout << setfill(' ');
    cout << setw(18) << left << "MA CHUYEN BAY";
    cout << setw(22) << left << "NGAY KHOI HANH";
    cout << setw(22) << left << "SAN BAY DEN";
    cout << setw(22) << left << "TRANG THAI";
    cout << setw(100) << left << "DANH SACH VE DUOC DAT" << endl;

    cout << setfill('-');
    setColor(14);
    cout << setw(120) << "-" << endl;

    setColor(7);
    cout << setfill(' ');
    for (int i = 0; i < ArrayList<ChuyenBay>::getSize(); i++) {
        ChuyenBay item = ArrayList<ChuyenBay>::getItem(i);
        if (item.getTrangThai() == 0) {
            setColor(4);
        }
        else if (item.getTrangThai() == 1) {
            setColor(9);
        }
        else if (item.getTrangThai() == 2) {
            setColor(4);
        }
        else if (item.getTrangThai() == 3) {
            setColor(10);
        }

        item.display();
        setColor(7);
    }
    cout << setfill('-');
    setColor(14);
    cout << setw(120) << "-" << endl;
    setColor(7);
    cout << setfill(' ');
    cout << endl;

    cout << setw(100) << left << "Nhap [B] de quay lai menu chinh, [S] de tim kiem thong tin chi tiet: ";
    string option;
    getline(cin >> ws, option);
    // normalize input  
    string optionNormalized = toUpperCase(option);

    if (optionNormalized == "S")
    {
        // Search
        string maCanTim;
        do {
            cout << "\nNhap MA CHUYEN BAY can tim ";
            cout << "(Nhap 'Q' de thoat tim kiem): ";
            getline(cin >> ws, maCanTim);

            // normalize input  
            string maTimUpper = toUpperCase(maCanTim);

            if (maTimUpper.empty() || maTimUpper == "Q") {
                system("cls");
                hienThiChuyenBay();
                return;
            }


            system("cls");


            setColor(14);
            cout << setfill(' ');
            cout << setw(10) << left << "MAY BAY";
            cout << setw(15) << left << "MA CHUYEN BAY";
            cout << setw(20) << left << "NGAY KHOI HANH";
            cout << setw(15) << left << "SAN BAY DEN";
            cout << setw(15) << left << "TRANG THAI";
            cout << setw(15) << left << "SO CHO NGOI";
            cout << setw(20) << left << "SO CHO TRONG";
            cout << setw(100) << left << "DS VE DUOC DAT" << endl;
            setColor(7);

            bool found = false;
            for (int i = 0; i < ArrayList<ChuyenBay>::getSize(); i++) {
                ChuyenBay item = ArrayList<ChuyenBay>::getItem(i);
                if (toUpperCase(item.getMaChuyenBay()) == maTimUpper) {
                    /*setColor(11);
                    cout << "\n\t\t\tThong tin chuyen bay tim thay:\n";*/
                    setColor(7);
                    item.displayDetail();
                    item.hienThiSoDoGhe();
                    found = true;
                    break;
                }
            }

            if (!found) {
                setColor(4);
                cout << "\n\t\t\tKhong tim thay chuyen bay co ma: " << maCanTim << endl;
                setColor(7);
            }

        } while (true);
    }
    else if (optionNormalized == "B")
    {
        // Back to main menu
        return;
    }
    else
    {
        setColor(4);
        cout << "\n\t\t\tLua chon khong hop le. Vui long chon lai!" << endl;
        setColor(7);
	}
    
}

template <class ChuyenBay, class MayBay, class Ve>
void DanhSachChuyenBay<ChuyenBay, MayBay, Ve>::ShowListNoSearch() {
    setColor(10);
    cout << "\t\t\t\t\t";
    cout << "DANH SACH CAC CHUYEN BAY:" << endl;
    setColor(7);
    cout << setfill('-');
    setColor(14);
    cout << setw(120) << "-" << endl;
    cout << endl;

    setColor(7);
    cout << setfill(' ');
    cout << setw(18) << left << "MA CHUYEN BAY";
    cout << setw(22) << left << "NGAY KHOI HANH";
    cout << setw(22) << left << "SAN BAY DEN";
    cout << setw(22) << left << "TRANG THAI";
    cout << setw(100) << left << "DANH SACH VE DUOC DAT" << endl;

    cout << setfill('-');
    setColor(14);
    cout << setw(120) << "-" << endl;

    setColor(7);
    cout << setfill(' ');
    for (int i = 0; i < ArrayList<ChuyenBay>::getSize(); i++) {
        ChuyenBay item = ArrayList<ChuyenBay>::getItem(i);
        if (item.getTrangThai() == 0) {
            setColor(4);
        }
        else if (item.getTrangThai() == 1) {
            setColor(9);
        }
        else if (item.getTrangThai() == 2) {
            setColor(4);
        }
        else if (item.getTrangThai() == 3) {
            setColor(10);
        }

        item.display();
        setColor(7);
    }
    cout << setfill('-');
    setColor(14);
    cout << setw(120) << "-" << endl;
    setColor(7);
    cout << setfill(' ');
    cout << endl;
}

/********************************************
* @Description Hàm update tr?ng thái c?a t?t c? các chuy?n bay trong Danh Sách Chuy?n Bay
********************************************/

template <class ChuyenBay, class MayBay, class Ve>
void DanhSachChuyenBay<ChuyenBay, MayBay, Ve>::updateTrangThai() {
    for (int i = 0; i < ArrayList<ChuyenBay>::getSize(); i++) {
        ChuyenBay* data = ArrayList<ChuyenBay>::getPointerItem(i);
        data->updateTrangThai();
    }
}
