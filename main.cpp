#include <iostream>
#include "Header.h"
#include "NhanVien.h"
#include "KhachHang.h"
#include "MayBay.h"
#include "Ve.h"
#include "Node.cpp"
#include "Queue.cpp"
#include "DanhSachVePending.cpp"
#include "LinkedList.cpp"
#include "ArrayList.cpp"
#include "DanhSachVeSuccess.cpp"
#include "DanhSachMayBay.cpp"
#include "ChuyenBay.cpp"
#include "DanhSachChuyenBay.cpp"
#include "DanhSachNhanVien.cpp"
#include "DanhSachKhachHang.cpp"
using namespace std;

int main() {
    //Danh sách Vé đang chờ
    DanhSachVePending<Ve> listTicketsPending;

    //Danh sách Vé hoàn tất
    DanhSachVeSuccess<Ve> listTicketsSuccess;

    DanhSachMayBay<MayBay> listPlanes;

    DanhSachChuyenBay<ChuyenBay<Ve>, MayBay, Ve> listFlights(100);

    DanhSachNhanVien<NhanVien> listEmployees;

    DanhSachKhachHang<KhachHang> listCustomers;

    //BAT DAU DOC FILE;
    listTicketsPending.xuLyDocFile();
    listTicketsSuccess.xuLyDocFile();
    listPlanes.xuLyDocFile();
    listFlights.xuLyDocFile(listPlanes, listTicketsSuccess);
    listEmployees.xuLyDocFile();
    listCustomers.xuLyDocFile();
    //KET THUC DOC FILE

    //update lai trang thai cac chuyen bay
    listFlights.updateTrangThai();

    //cap nhat lai file danh sach cac chuyen bay
    listFlights.updateFile();

    int iOption = 0;
    NhanVien* nhanVienHienTai = NULL;
    do {
        system("cls");

        menuChucNang();
        // Kiểm tra đầu vào
        while (true) {
            setColor(10);
            cin >> iOption;

            // Nếu nhập sai kiểu dữ liệu hoặc giá trị không hợp lệ
            if (cin.fail() || iOption < 0 || iOption > 3) {
                setColor(7);
                cout << "\t\t\t\tLua chon khong hop le!\n";
                cin.clear();              // Xóa trạng thái lỗi của cin
                cin.ignore(1000, '\n');   // Loại bỏ các ký tự không hợp lệ trong bộ đệm
                setColor(12);
                cout << "\t\t\t\tChon chuc nang: ";
            }
            else {
                setColor(7);
                break; // Đầu vào hợp lệ, thoát vòng lặp 
            }
        }

        switch (iOption)
        {
        case 0: {
            //THOAT CHUONG TRINH
            exit(0);
            break;
        }
        case 1:
        {
            //HIEN THI DANH SACH CAC CHUYEN BAY
            system("cls");
      
            system("cls");

            //update lai trang thai cac chuyen bay
            listFlights.updateTrangThai();
            //hien thi cac chuyen bay
            listFlights.hienThiChuyenBay();
            //cap nhat lai file danh sach cac chuyen bay
            listFlights.updateFile();
            system("pause");
            break;
        }
        case 2:
        {
            // DAT VE
            //update lai trang thai cac chuyen bay
            listFlights.updateTrangThai();

            //cap nhat lai file danh sach cac chuyen bay
            listFlights.updateFile();

            system("cls");
            string strHoTen, strCMND, strMaChuyenBay;
            int iMaSoGhe;

            setColor(10);
            cout << "\t\t\t\t\t";
            cout << "DAT VE:" << endl;

            setColor(7);
            cout << "\t\t\t";
            cout << "Vui Long Dien Thong Tin Ca Nhan" << endl;

            setColor(12);
            cout << "\t\t\t";
            cout << "Luu y: Chi duoc dat ve truoc gio khoi hanh 15 phut!" << endl;

            setColor(7);
            cout << "\t\t\t";
            cout << "Nhap CMND hoac CCCD: ";
            cin.ignore();

            while (getline(cin, strCMND)) {
                //Kiem tra khoang trang
                if (checkContainsSpacing(strCMND)) {
                    setColor(12);
                    cout << "\t\t\t";
                    cout << "Vui long nhap CMND hoac CCCD khong chua khoang trang!" << endl;
                    setColor(7);
                    cout << "\t\t\t";
                    cout << "Nhap CMND hoac CCCD: ";
                    continue;
                }
                //Kiem tra co phai la chuoi so hay khong
                if (!checkIsNumberString(strCMND)) {
                    setColor(12);
                    cout << "\t\t\t";
                    cout << "CMND hoac CCCD khong hop le, vui long nhap lai! " << endl;
                    setColor(7);
                    cout << "\t\t\t";
                    cout << "Nhap CMND hoac CCCD: ";
                    continue;
                }
                //Kiem tra CMND du 9 so, CCCD du 12 so
                if (strCMND.length() == 9 || strCMND.length() == 12) {
                    break;
                }

                setColor(12);
                cout << "\t\t\t";
                cout << "CMND hoac CCCD khong hop le, vui long dien du 9 so (CMND) va 12 so (CCCD)!" << endl;
                setColor(7);
                cout << "\t\t\t";
                cout << "Nhap CMND hoac CCCD: ";
            }
            //Kiem tra xem khach hang da dat ve truoc do chua
            KhachHang* searchKhachHang = listCustomers.timKiemKhachHang(strCMND);
            if (searchKhachHang == NULL) {
                //Neu khach hang chua dat ve truoc do, thi tao moi khach hang
                cout << "\t\t\t";
                cout << "Nhap Ho Ten: ";
                while (getline(cin, strHoTen)) {
                    //Kiem tra Ho ten co chua khoang trang hay khong
                    if (checkContainsSpacing(strHoTen)) {
                        setColor(12);
                        cout << "\t\t\t";
                        cout << "Ho Ten khong duoc chua khoang trang, vui long nhap lai!" << endl;
                        setColor(7);
                        cout << "\t\t\t";
                        cout << "Nhap Ho Ten: ";
                        continue;
                    }

                    if (checkIsNumberString(strHoTen)) {
                        setColor(12);
                        cout << "\t\t\t";
                        cout << "Ho Ten khong phai la so, vui long nhap lai!" << endl;
                        setColor(7);
                        cout << "\t\t\t";
                        cout << "Nhap Ho Ten: ";
                        continue;
                    }

                    if (checkKyTuDacBiet(strHoTen)) {
                        setColor(12);
                        cout << "\t\t\t";
                        cout << "Ho ten khong hop le, vui long nhap lai! " << endl;
                        setColor(7);
                        cout << "\t\t\t";
                        cout << "Nhap Ho Ten: ";
                        continue;
                    }

                    //Kiem tra Ho ten du 2 ki tu
                    if (strHoTen.length() >= 2) {
                        break;
                    }
                    setColor(12);
                    cout << "\t\t\t";
                    cout << "Ho Ten khong hop le, vui long nhap lai!" << endl;
                    setColor(7);
                    cout << "\t\t\t";
                    cout << "Nhap Ho Ten: ";
                }
                //Chuyen thanh UpperCase
                strHoTen = convertUpperCase(strHoTen);

            }
            else {
                //Neu khach hang da dat ve truoc do, thi lay thong tin lai
                cout << "\t\t\t";
                cout << "Chao mung tro lai! Khach hang: ";
                strHoTen = searchKhachHang->getHoTen();
                setColor(14);
                cout << searchKhachHang->getHoTen();
                setColor(7);
                cout << endl;
            }
            cout << "\t\t\t";
            cout << "Nhap Ma Chuyen Bay: ";
            while (getline(cin, strMaChuyenBay)) {
                //Kiem tra Ma chuyen bay co chua khoang trang hay khong
                if (checkContainsSpacing(strMaChuyenBay)) {
                    setColor(12);
                    cout << "\t\t\t";
                    cout << "Ma chuyen bay chua khoang trang, vui long nhap lai!" << endl;
                    setColor(7);
                    cout << "\t\t\t";
                    cout << "Nhap Ma Chuyen Bay: ";
                    continue;
                }
                
                if (strMaChuyenBay.length() == 0) {
                    setColor(12);
                    cout << "\t\t\t";
                    cout << "Ma chuyen bay khong hop le, vui long nhap lai!" << endl;
                    setColor(7);
                    cout << "\t\t\t";
                    cout << "Nhap Ma Chuyen Bay: ";
                    continue;
                }
                break;
            }
            //chuyen chu thuong thanh chu hoa
            strMaChuyenBay = convertUpperCase(strMaChuyenBay);

            //Tim kiem chuyen bay theo ma chuyen bay
            int iSearchChuyenBay = listFlights.timKiemChuyenBay(strMaChuyenBay);
            system("cls");
            cout << endl;

            if (iSearchChuyenBay == -1) {
                setColor(4);
                cout << "\t\t\t";
                cout << "Khong tim thay Chuyen Bay!" << endl;
                setColor(7);
                cout << "\t\t\t";
                system("pause");
                break;
            }
            //Lay thong tin chuyen bay sau khi tim kiem thanh cong
            ChuyenBay<Ve> cbTemp = listFlights.getItem(iSearchChuyenBay);

            //Hien thi chi tiet chuyen bay
            setColor(2);
            cout << "\t\t\t\t\t";
            cout << "THONG TIN CHUYEN BAY " << strMaChuyenBay << ": " << endl;

            setColor(7);
            cout << setfill('-');
            setColor(14);
            cout << setw(135) << "-" << endl;
            cout << endl;

            setColor(7);
            cout << setfill(' ');
            cout << setw(10) << left << "MAY BAY";
            cout << setw(15) << left << "MA CHUYEN BAY";
            cout << setw(20) << left << "NGAY KHOI HANH";
            cout << setw(15) << left << "SAN BAY DEN";
            cout << setw(15) << left << "TRANG THAI";
            cout << setw(15) << left << "SO CHO NGOI";
            cout << setw(20) << left << "SO CHO NGOI TRONG";
            cout << setw(100) << left << "DANH SACH VE DUOC DAT" << endl;
            cout << endl;

            cout << setfill('-');
            setColor(14);
            cout << setw(135) << "-" << endl;
            cout << endl;

            setColor(7);
            cout << setfill(' ');
            cbTemp.displayDetail();
            cout << setfill('-');
            setColor(14);
            cout << setw(135) << "-" << endl;
            cbTemp.hienThiSoDoGhe();

            setColor(7);
            cout << setfill(' ');
            cout << endl;
            //KIEM TRA TRANG THAI CUA CHUYEN BAY		
            //Kiem tra chuyen bay chua bi huy
            if (cbTemp.getTrangThai() == 0) {
                setColor(12);
                cout << "\t\t\t";
                cout << "Chuyen bay da bi huy!" << endl;
                setColor(7);
                system("pause");
                break;
            }
            //Kiem tra chuyen bay chua hoan tat
            if (cbTemp.getTrangThai() == 3) {
                setColor(12);
                cout << "\t\t\t";
                cout << "Chuyen bay da hoan tat!" << endl;
                setColor(7);
                system("pause");
                break;
            }
            //Kiem tra chuyen bay van con cho trong 
            if (cbTemp.isFullSeat()) {
                setColor(12);
                cout << "\t\t\t";
                cout << "Chuyen bay khong con ghe trong!" << endl;
                setColor(7);
                system("pause");
                break;
            }
            //Chi cho phep khach hang dat ve truoc gio khoi hanh cua chuyen bay 15 phut.
            if (cbTemp.getTimestamp() - 60 * 15 <= getCurrentTimestamp()) {
                setColor(4);
                cout << "\t\t\t";
                cout << "Vui long dat ve truoc gio khoi hanh 15 phut!" << endl;
                setColor(7);
                system("pause");
                break;
            }
            cout << "\t";
            cout << "Nhap ma so ghe muon dat: ";

            //Xu ly ngoai le nhap stt ghe = string
            string str;
            cin >> str;
            bool check = false;
            for (int i = 0;i < str.size();i++) {
                if (isalpha(str[i])) check = true;
            }
            if (!check) iMaSoGhe = stoi(str);
            else iMaSoGhe = -1;
            
            //cin >> iMaSoGhe;
            int kiemTraGhe = cbTemp.kiemTraMaSoGhe(iMaSoGhe);
            while (kiemTraGhe != 3) {
                //Kiem tra cac trang thai ghe cua chuyen bay dua vao so ghe khach nhap.
                setColor(12);
                if (kiemTraGhe == 1) {
                    cout << "\t\t\t";
                    cout << "Ma so ghe khong hop le, vui long chon ghe khac!" << endl;
                }
                else if (kiemTraGhe == 2) {
                    cout << "\t\t\t";
                    cout << "Ma so ghe da duoc dat, vui long chon ghe khac!" << endl;
                }
                setColor(7);
                cout << "\t\t\t";
                cout << "Nhap ma so ghe muon dat: ";
                cin >> str;
                bool check = false;
                for (int i = 0;i < str.size();i++) {
                    if (isalpha(str[i])) check = true;
                }
                if (!check) iMaSoGhe = stoi(str);
                else iMaSoGhe = -1;
                //cin >> iMaSoGhe;
                kiemTraGhe = cbTemp.kiemTraMaSoGhe(iMaSoGhe);
            }
            //Xac nhan lai thong tin dat ve
            system("cls");
            setColor(2);
            cout << "\t\t\t\t";
            cout << "VUI LONG KIEM TRA LAI THONG TIN DAT VE:" << endl;
            setColor(7);
            cout << setfill('-');
            setColor(14);
            cout << setw(130) << "-" << endl;
            setColor(7);
            cout << setfill(' ');
            cout << setw(30) << left << "HO TEN";
            cout << setw(20) << left << "CMND";
            cout << setw(25) << left << "MA CHUYEN BAY";
            cout << setw(20) << left << "SO GHE" << endl;
            cout << setfill('-');
            setColor(14);
            cout << setw(130) << "-" << endl;
            setColor(7);
            cout << setfill(' ');
            cout << setw(30) << left << strHoTen;
            cout << setw(20) << left << strCMND;
            cout << setw(25) << left << strMaChuyenBay;
            cout << setw(20) << left << iMaSoGhe << endl;
            cout << setfill('-');
            setColor(14);
            cout << setw(130) << "-" << endl;
            setColor(7);
            cout << setfill(' ');
            cout << endl;

            string strConfirmBook;
            cout << "\t\t\t";
            cout << "Xac nhan dat ve: Nhap ";
            setColor(10);
            cout << "YES";
            setColor(7);
            cout << " neu dong y, ";
            setColor(12);
            cout << "NO";
            setColor(7);
            cout << " neu tu choi: ";
            setColor(7);
            cin.ignore();
            getline(cin, strConfirmBook);
            //chuyen chu thuong thanh chu hoa
            strConfirmBook = convertUpperCase(strConfirmBook);
            //kiem tra nguoi dung co nhap yes hay no hay khong
            if (strConfirmBook != "YES" && strConfirmBook != "NO") {
                setColor(4);
                cout << "\t\t\t";
                cout << "Vui long nhap YES hoac NO!" << endl;
                setColor(7);
                system("pause");
                break;
            }
            if (strConfirmBook == "YES") {
                system("cls");
               
                system("cls");
                //Chi cho phep khach hang dat ve truoc gio khoi hanh cua chuyen bay 15 phut.
                if (cbTemp.getTimestamp() - 60 * 15 <= getCurrentTimestamp()) {
                    setColor(4);
                    cout << "\t\t\t";
                    cout << "Vui long dat ve truoc gio khoi hanh 15 phut!" << endl;
                    setColor(7);
                    system("pause");
                    break;
                }
                //DONG Y DAT VE
                //Neu chua co khach hang thi them vao danh sach khach hang 
                if (searchKhachHang == NULL) {
                    //Tao mot doi tuong KhachHang moi
                    KhachHang* khachHangMoi = new KhachHang(strCMND, strHoTen, listCustomers.getSize() + 1);
                    //Them doi tuong vao danh sach Khach Hang
                    listCustomers.addTail(*khachHangMoi);
                    //Update lai file KhachHang
                    listCustomers.xuLyGhiFile(*khachHangMoi);
                }
                //Them vao danh sach ve pending

                stringstream ss;
                ss << iMaSoGhe;
                string maSoGheString;
                ss >> maSoGheString;
                string maVe = strMaChuyenBay + maSoGheString;
                //Tao mot doi tuong Ve moi
                Ve* veMoi = new Ve(maVe, strMaChuyenBay, strCMND, strHoTen, iMaSoGhe, getCurrentDate());
                veMoi->setTimestamp();
                //Them vao danh sach Ve Pending
                listTicketsPending.enQueue(*veMoi);
                //Update lai file VeDangCho
                listTicketsPending.xuLyGhiFile(*veMoi);
                setColor(3);
                cout << "\t\t\t";
                cout << "DAT VE THANH CONG! VUI LONG CHO NHAN VIEN XU LY!" << endl;
                setColor(7);
            }
            else {
                //HUY DAT VE
                setColor(4);
                cout << "\t\t\t";
                cout << "HUY DAT VE THANH CONG! HEN GAP LAI QUY KHACH!" << endl;
                setColor(7);
            }
            system("pause");

            break;
        }
        case 3:
        {
            //NHAN VIEN QUAN LY
            system("cls");
            string strUsername, strPassword;
            int iDem = 0;
            setColor(4);
            cout << "-> ";
            setColor(7);
            cout << "3. Quan ly." << endl;
            setColor(14);
            char c;
            do {
                system("cls");
                //Menu chuc nang dang nhap nhan vien
                dangNhapNhanVien(strUsername, strPassword);
                //Tim kiem nhan vien theo username va password
                NhanVien* timKiemNhanVien = listEmployees.timKiemNhanVien(strUsername, strPassword);
                if (strUsername.length() == 0) {
                    system("cls");
                    setColor(4);
                    cout << endl << "\t\t\tUsername khong duoc bo trong. \n \t\t\tNhan phim ESC de thoat hoac phim Enter 2 lan de tiep tuc dang nhap!" << endl;
                    setColor(7);
                    //Lay du lieu khi nguoi dung nhan phim bat ki
                    c = getch();
                }
                else if (strPassword.length() == 0) {
                    system("cls");
                    setColor(4);
                    cout << endl << "\t\t\tPassword khong duoc bo trong. \n \t\t\tNhan phim ESC de thoat hoac phim Enter 2 lan de tiep tuc dang nhap!" << endl;
                    setColor(7);
                    //Lay du lieu khi nguoi dung nhan phim bat ki
                    c = getch();
                }
                else if (checkContainsSpacing(strUsername)) {
                    system("cls");
                    setColor(4);
                    cout << endl << "\t\t\tUsername khong duoc chua khoang trang. \n \t\t\tNhan phim ESC de thoat hoac phim Enter 2 lan de tiep tuc dang nhap!" << endl;
                    setColor(7);
                    //Lay du lieu khi nguoi dung nhan phim bat ki
                    c = getch();
                }
                else if (timKiemNhanVien == NULL) {
                    //Dang nhap that bai
                    iDem++;
                    system("cls");
                    setColor(4);
                    cout << endl << "\t\t\tSai tai khoan hoac mat khau! Ban con " << 3 - iDem << " lan nhap. \n \t\t\tNhan phim ESC de thoat hoac phim Enter 2 lan de tiep tuc dang nhap!" << endl;
                    setColor(7);
                    //Lay du lieu khi nguoi dung nhan phim bat ki
                    c = getch();
                }
                else {
                    //Luu thong tin dang nhap cua nhan vien hien tai
                    nhanVienHienTai = timKiemNhanVien;
                    break;
                }
                if (c == 27) {
                    //Neu nguoi dung nhap phim ESC thi thoat chuong trinh
                    exit(1);
                    break;
                }
                if (iDem == 3) {
                    //Neu nguoi dung nhap sai 3 lan thi thoat chuong trinh
                    exit(1);
                    break;
                }
                cout << endl;
            } while (iDem < 3 && c != 27);

            cout << "DANG NHAP THANH CONG." << endl;
            system("cls");
            int iOptionAdmin = 0;
            do {
                system("cls");
                cout << "Xin chao, " << nhanVienHienTai->getUsername() << endl;
                //Menu chuc nang nhan vien
                menuAdmin();
                cin >> iOptionAdmin;
                cout << endl;
                switch (iOptionAdmin) {
                case 0: {
                    //DANG XUAT NHAN VIEN
                    nhanVienHienTai = NULL;
                    break;
                }
                case 1:
                {
                    //XU LY DAT VE
                    system("cls");
                    setColor(4);
                    cout << "-> ";
                    setColor(7);
                    cout << "1. Xu ly dat ve." << endl;
                    setColor(2);
                    cout << "\t\t\t\t\t";
                    cout << "DANH SACH VE PENDING:" << endl;
                    setColor(7);
                    //Kiem tra danh sach ve pending trong
                    if (listTicketsPending.getSize() == 0) {
                        cout << "\t\t\t";
                        setColor(4);
                        cout << "Khong co danh sach ve dang cho." << endl;
                        setColor(7);
                        system("pause");
                        break;
                    }
                    //Hien thi danh sach ve pending
                    cout << setfill('-');
                    setColor(4);
                    cout << setw(150) << "-" << endl;
                    setColor(7);
                    cout << setfill(' ');
                    cout << setw(20) << left << "MA VE";
                    cout << setw(20) << left << "MA CHUYEN BAY";
                    cout << setw(20) << left << "CMND";
                    cout << setw(20) << left << "HO TEN";
                    cout << setw(20) << left << "SO GHE";
                    cout << setw(50) << left << "DATE" << endl;
                    cout << setfill('-');
                    setColor(4);
                    cout << setw(150) << "-" << endl;
                    setColor(7);
                    cout << setfill(' ');
                    listTicketsPending.displayDetail();
                    cout << setfill('-');
                    setColor(4);
                    cout << setw(150) << "-" << endl;
                    setColor(7);
                    cout << setfill(' ');
                    setColor(7);
                    //Ket thuc hien thi
                    string strConfirmHandle;
                    cout << "\t\t\t";
                    cout << "Ban co muon xu ly cac ve dang cho khong?" << endl;
                    cout << "\t\t\t";
                    cout << " Nhap ";
                    setColor(10);
                    cout << "\"YES\"";
                    setColor(7);
                    cout << " de xu ly ";
                    setColor(10);
                    cout << "tat ca";
                    setColor(7);
                    cout << " cac ve pending." << endl;
                    cout << "\t\t\t";
                    cout << " Hoac nhap ";
                    setColor(14);
                    cout << "ma ve";
                    setColor(7);
                    cout << " (VD: VE123) de chi xu ly ";
                    setColor(14);
                    cout << "mot ve cu the." << endl;
                    cout << "\t\t\t";
                    cout << " Nhap ";
                    setColor(12);
                    cout << "\"NO\"";
                    setColor(7);
                    cout << " de huy bo tat ca." << endl;
                    cout << "\n\t\t\tNhap lua chon cua ban: ";
                    setColor(7);
                    cin.ignore();
                    getline(cin, strConfirmHandle);
                    //Chuyen chu thuong thanh chu hoa
                    strConfirmHandle = convertUpperCase(strConfirmHandle);
                    //kiem tra nguoi dung co nhap yes hay no hay khong
                    /*if (strConfirmHandle != "YES" && strConfirmHandle != "NO") {
                        setColor(4);
                        cout << "\t\t\t";
                        cout << "Vui long nhap YES hoac NO!" << endl;
                        setColor(7);
                        system("pause");
                        break;
                    }*/
                    if (strConfirmHandle == "YES") {
                        system("cls");
                       
                        system("cls");
                        //Bat dau xu ly ve pending
                        system("cls");
                        setColor(2);
                        cout << "\t\t\t\t\t";
                        cout << "TIEN TRINH XU LY VE PENDING:" << endl << endl;
                        setColor(7);
                        cout << setfill('*');
                        cout << "\t\t\t\t";
                        cout << setw(50) << "*" << endl;
                        cout << setfill(' ');
                        //Trong khi danh sach ve pending van con ve de xu ly
                        while (listTicketsPending.getSize() != 0) {
                            // lay ve dang cho khoi hang doi
                            Ve veTemp = listTicketsPending.deQueue();
                            //Hien thi thong tin Ve
                            cout << "\t\t\t\t\t";
                            cout << "Ma ve: " << veTemp.getMaVe() << endl;
                            cout << "\t\t\t\t\t";
                            cout << "Khach hang: " << veTemp.getHoTen() << endl;
                            cout << "\t\t\t\t\t";
                            cout << "Chuyen Bay: " << veTemp.getMaChuyenBay() << endl;
                            cout << "\t\t\t\t\t";
                            cout << "Ma So Ghe: " << veTemp.getSoGhe() << endl;
                            cout << "\t\t\t\t\t";
                            cout << "Date: " << veTemp.getDate() << endl;
                            //Tim kiem chuyen bay dua tren ma chuyen bay cua ve
                            int iSearchChuyenBay = listFlights.timKiemChuyenBay(veTemp.getMaChuyenBay());
                            ChuyenBay<Ve>* cbTemp = listFlights.getPointerItem(iSearchChuyenBay);
                            //Cap nhat lai trang thai cua chuyen bay truoc khi thuc thi tiep tuc.
                            cbTemp->updateTrangThai();
                            if (cbTemp->getTrangThai() == 3) {
                                cout << "\t\t\t\t\t";
                                cout << "Trang thai: ";
                                setColor(12);
                                cout << "That bai." << endl;
                                setColor(7);
                                cout << "\t\t\t\t\t";
                                cout << "Ly do: Chuyen bay nay da hoan tat." << endl;
                            }
                            else if (cbTemp->getTrangThai() == 0) {
                                cout << "\t\t\t\t\t";
                                cout << "Trang thai: ";
                                setColor(12);
                                cout << "That bai." << endl;
                                setColor(7);
                                cout << "\t\t\t\t\t";
                                cout << "Ly do: Chuyen bay nay da bi huy." << endl;
                            }
                            else {
                                //Kiem tra so ghe cua ve co hop le hay khong
                                int iStatusGhe = cbTemp->kiemTraMaSoGhe(veTemp.getSoGhe());
                                //thanh cong
                                if (iStatusGhe == 3) {
                                    // tao file ve moi
                                    veTemp.createFile();
                                    //them ve vao danh sach ve cua chuyenbay
                                    cbTemp->themVeMoi(veTemp);
                                    //Sau khi them thi sap xep ve
                                    cbTemp->sapXepDanhSachVe(1);
                                    // remove ghe trong khoi danh sach ghe trong
                                    cbTemp->removeGheTrong(veTemp.getSoGhe());
                                    //sau khi xoa thi sap xep danh sach ghe trong
                                    cbTemp->sapXepDanhSachGheTrong(1);
                                    //update lai trang thai: hoan tat, con ve, het ve.
                                    cbTemp->updateTrangThai();
                                    //them ve moi vao file danh sach ve thanh cong
                                    listTicketsSuccess.xuLyGhiFile(veTemp);
                                    //them ve moi vao danh sach ve thanh cong
                                    listTicketsSuccess.addTail(veTemp);
                                    cout << "\t\t\t\t\t";
                                    cout << "Trang thai: ";
                                    setColor(10);
                                    cout << "Thanh cong.";
                                    setColor(7);
                                    cout << endl;
                                }
                                else {
                                    if (iStatusGhe == 2) {
                                        cout << "\t\t\t\t\t";
                                        cout << "Trang thai: ";
                                        setColor(12);
                                        cout << "That bai." << endl;
                                        setColor(7);
                                        cout << "\t\t\t\t\t";
                                        cout << "Ly do: Ma ghe da duoc nguoi khac dat!" << endl;
                                    }
                                    else if (iStatusGhe == 1) {
                                        cout << "\t\t\t\t\t";
                                        cout << "Trang thai: ";
                                        setColor(12);
                                        cout << "That bai." << endl;
                                        setColor(7);
                                        cout << "\t\t\t\t\t";
                                        cout << "Ly do: Ma ghe khong hop le!" << endl;
                                    }
                                    cout << endl;
                                }
                            }
                            cout << setfill('*');
                            cout << "\t\t\t\t";
                            cout << setw(50) << "*" << endl;
                            cout << setfill(' ');
                            //cap nhat lai file danh sach ve dang cho (VeDangCho) sau khi xu ly 1 ve
                            listTicketsPending.updateFile();
                        }
                        //cap nhat lai file danh sach chuyen bay sau khi xu ly xong tat ca ve pending
                        listFlights.updateFile();
                    }
                    else if(strConfirmHandle == "NO") {
                        cout << "\t\t\t";
                        setColor(4);
                        cout << "Tu choi " << endl;
                        setColor(7);
                    }
                    else {
                        // Người dùng nhập mã vé thay vì YES
                        string maVeCanXuLy = strConfirmHandle;
                        Ve veTemp;

                        if (listTicketsPending.xuLyVeTheoMa(maVeCanXuLy, veTemp)) {
                            system("cls");
                            cout << "\t\t\t\t\t";
                            setColor(2);
                            cout << "DANG XU LY VE CO MA: " << maVeCanXuLy << endl;
                            setColor(7);
                            cout << setfill('*');
                            cout << "\t\t\t\t";
                            cout << setw(50) << "*" << endl;
                            cout << setfill(' ');

                            cout << "\t\t\t\t\t";
                            cout << "Ma ve: " << veTemp.getMaVe() << endl;
                            cout << "\t\t\t\t\t";
                            cout << "Khach hang: " << veTemp.getHoTen() << endl;
                            cout << "\t\t\t\t\t";
                            cout << "Chuyen Bay: " << veTemp.getMaChuyenBay() << endl;
                            cout << "\t\t\t\t\t";
                            cout << "Ma So Ghe: " << veTemp.getSoGhe() << endl;
                            cout << "\t\t\t\t\t";
                            cout << "Date: " << veTemp.getDate() << endl;

                            // Tìm chuyến bay
                            int iSearchChuyenBay = listFlights.timKiemChuyenBay(veTemp.getMaChuyenBay());
                            ChuyenBay<Ve>* cbTemp = listFlights.getPointerItem(iSearchChuyenBay);
                            cbTemp->updateTrangThai();

                            if (cbTemp->getTrangThai() == 3) {
                                setColor(12);
                                cout << "\t\t\t\t\tTrang thai: That bai - Chuyen bay hoan tat." << endl;
                                setColor(7);
                            }
                            else if (cbTemp->getTrangThai() == 0) {
                                setColor(12);
                                cout << "\t\t\t\t\tTrang thai: That bai - Chuyen bay bi huy." << endl;
                                setColor(7);
                            }
                            else {
                                int iStatusGhe = cbTemp->kiemTraMaSoGhe(veTemp.getSoGhe());
                                if (iStatusGhe == 3) {
                                    veTemp.createFile();
                                    cbTemp->themVeMoi(veTemp);
                                    cbTemp->sapXepDanhSachVe(1);
                                    cbTemp->removeGheTrong(veTemp.getSoGhe());
                                    cbTemp->sapXepDanhSachGheTrong(1);
                                    cbTemp->updateTrangThai();
                                    listTicketsSuccess.xuLyGhiFile(veTemp);
                                    listTicketsSuccess.addTail(veTemp);
                                    setColor(10);
                                    cout << "\t\t\t\t\tTrang thai: Thanh cong!" << endl;
                                    setColor(7);
                                }
                                else {
                                    setColor(12);
                                    cout << "\t\t\t\t\tTrang thai: That bai." << endl;
                                    if (iStatusGhe == 2)
                                        cout << "\t\t\t\t\tLy do: Ghe da duoc dat." << endl;
                                    else if (iStatusGhe == 1)
                                        cout << "\t\t\t\t\tLy do: Ma ghe khong hop le." << endl;
                                    setColor(7);
                                }
                            }

                            listFlights.updateFile();
                        }
                        else {
                            setColor(4);
                            cout << "\t\t\t\t\tKhong tim thay ma ve: " << maVeCanXuLy << endl;
                            setColor(7);
                        }
                    }
                    cout << endl;
                    system("pause");
                    break;
                }
                case 2:
                {
                    //XU LY TRA VE

                    //update lai trang thai cac chuyen bay
                    listFlights.updateTrangThai();
                    //cap nhat lai file danh sach cac chuyen bay
                    listFlights.updateFile();

                    system("cls");
                    setColor(4);
                    cout << "-> ";
                    setColor(7);
                    cout << "2. Xu ly tra ve." << endl;
                    setColor(2);
                    cout << "\t\t\t\t\t";
                    cout << "DANH SACH VE DA DAT THANH CONG:" << endl;
                    setColor(7);

                    //Kiem tra danh sach ve pending trong
                    if (listTicketsSuccess.getSize() == 0) {
                        cout << "\t\t\t";
                        setColor(4);
                        cout << "Khong co danh sach ve thanh cong." << endl;
                        setColor(7);
                        system("pause");
                        break;
                    }

                    //Hien thi danh sach ve success
                    cout << setfill('-');
                    setColor(4);
                    cout << setw(150) << "-" << endl;
                    setColor(7);
                    cout << setfill(' ');
                    cout << setw(20) << left << "MA VE";
                    cout << setw(20) << left << "MA CHUYEN BAY";
                    cout << setw(20) << left << "CMND";
                    cout << setw(20) << left << "HO TEN";
                    cout << setw(20) << left << "SO GHE";
                    cout << setw(50) << left << "DATE" << endl;
                    cout << setfill('-');
                    setColor(4);
                    cout << setw(150) << "-" << endl;
                    setColor(7);
                    cout << setfill(' ');
                    listTicketsSuccess.displayDetail();
                    cout << setfill('-');
                    setColor(4);
                    cout << setw(150) << "-" << endl;
                    setColor(7);
                    cout << setfill(' ');
                    //Ket thuc hien thi danh sach
                    cin.ignore();
                    cout << "\t\t\t";
                    cout << "Nhap ma ve muon tra ve: ";
                    string strMaVe;
                    while (getline(cin, strMaVe)) {
                        //Kiem tra Ma chuyen bay co chua khoang trang hay khong
                        if (checkContainsSpacing(strMaVe)) {
                            setColor(4);
                            cout << "\t\t\t";
                            cout << "Ma Ve chua khoang trang, vui long nhap lai!" << endl;
                            setColor(7);
                            cout << "\t\t\t";
                            cout << "Nhap ma ve muon tra ve: ";
                            continue;
                        }
                        if (strMaVe.length() == 0) {
                            setColor(4);
                            cout << "\t\t\t";
                            cout << "Ma Ve khong hop le, vui long nhap lai!" << endl;
                            setColor(7);
                            cout << "\t\t\t";
                            cout << "Nhap ma ve muon tra ve: ";
                            continue;
                        }
                        break;
                    }
                    //Chuyen tu chu thuong sang hoa
                    strMaVe = convertUpperCase(strMaVe);
                    // tim ve 
                    Ve* timKiemVe = listTicketsSuccess.timKiemVe(strMaVe);
                    system("cls");
                   
                    system("cls");
                    setColor(2);
                    cout << "\t\t\t\t\t";
                    cout << "TIEN TRINH XU LY TRA VE:" << endl;
                    setColor(7);
                    if (timKiemVe != NULL) {
                        cout << setfill('*');
                        cout << "\t\t\t\t";
                        cout << setw(50) << "*" << endl;
                        cout << setfill(' ');
                        cout << "\t\t\t\t\t";
                        cout << "Ma ve: " << timKiemVe->getMaVe() << endl;
                        cout << "\t\t\t\t\t";
                        cout << "Khach hang: " << timKiemVe->getHoTen() << endl;
                        cout << "\t\t\t\t\t";
                        cout << "Chuyen Bay: " << timKiemVe->getMaChuyenBay() << endl;
                        cout << "\t\t\t\t\t";
                        cout << "Ma So Ghe: " << timKiemVe->getSoGhe() << endl;
                        cout << "\t\t\t\t\t";
                        cout << "Date: " << timKiemVe->getDate() << endl;
                        int iSearchChuyenBay = listFlights.timKiemChuyenBay(timKiemVe->getMaChuyenBay());
                        ChuyenBay<Ve>* cbTemp = listFlights.getPointerItem(iSearchChuyenBay);
                        //Kiem tra thoi gian hien tai voi thoi gian khoi hanh
                        if (getCurrentTimestamp() >= cbTemp->getTimestamp()) {
                            cout << "\t\t\t\t\t";
                            cout << "Trang thai: ";
                            setColor(12);
                            cout << "That bai." << endl;
                            setColor(7);
                            cout << "\t\t\t\t\t";
                            cout << "Ly do: Chuyen bay nay da hoan tat." << endl;
                        }
                        else if (cbTemp->getTrangThai() == 3) {
                            cout << "\t\t\t\t\t";
                            cout << "Trang thai: ";
                            setColor(12);
                            cout << "That bai." << endl;
                            setColor(7);
                            cout << "\t\t\t\t\t";
                            cout << "Ly do: Chuyen bay nay da hoan tat." << endl;
                        }
                        else {
                            cout << "\t\t\t\t\t";
                            cout << "Trang thai: ";
                            setColor(10);
                            cout << "Thanh cong." << endl;
                            setColor(7);
                            //xoa file ve
                            timKiemVe->deleteFile();
                            //them ghe trong vao chuyen bay
                            cbTemp->themGheTrongMoi(timKiemVe->getSoGhe());
                            //Sau khi them ghe trong thi sap xep lai
                            cbTemp->sapXepDanhSachGheTrong(1);
                            // xoa ve khoi chuyen bay
                            cbTemp->removeVe(timKiemVe->getSoGhe());
                            //Sau khi xpa ve thi sap xep lai danh sach ve
                            cbTemp->sapXepDanhSachVe(1);
                            //xoa khoi danh sach ve success
                            Node<Ve>* nodeVe = listTicketsSuccess.timKiemNode(strMaVe);
                            listTicketsSuccess.remove(nodeVe);
                            //Update lai file VeThanhCong
                            listTicketsSuccess.updateFile();
                            //Update lai trang thai cua chuyen bay
                            cbTemp->updateTrangThai();
                            //Update file danh sach chuyen bay
                            listFlights.updateFile();
                        }
                        cout << setfill('*');
                        cout << "\t\t\t\t";
                        cout << setw(50) << "*" << endl;
                        cout << setfill(' ');
                    }
                    else {
                        setColor(4);
                        cout << "\t\t\t";
                        cout << "Ma ve khong ton tai trong he thong!" << endl;
                        setColor(7);
                    }
                    cout << endl;
                    system("pause");
                    break;
                }
                case 3:
                {
                    int iOptionSubAdmin = 0;
                    do {
                        system("cls");
                        //Menu thong ke
                        menuAdminThongKe();
                        cin >> iOptionSubAdmin;
                        switch (iOptionSubAdmin)
                        {
                        case 0: {
                            break;
                        }
                        case 1: {
                            //THONG KE DANH SACH VE VA DANH SACH GHE TRONG
                            system("cls");
                            setColor(4);
                            cout << "-> ";
                            setColor(7);
                            cout << "3.1. Thong ke theo ma chuyen bay." << endl;
                            cin.ignore();
                            cout << "\t\t\t";
                            cout << "Nhap ma chuyen bay: ";
                            string maChuyenBay;
                            while (getline(cin, maChuyenBay)) {
                                //Kiem tra Ma chuyen bay co chua khoang trang hay khong
                                if (checkContainsSpacing(maChuyenBay)) {
                                    setColor(4);
                                    cout << "\t\t\t";
                                    cout << "Ma chuyen bay chua khoang trang, vui long nhap lai!" << endl;
                                    setColor(7);
                                    cout << "\t\t\t";
                                    cout << "Nhap ma chuyen bay: ";
                                    continue;
                                }
                                if (maChuyenBay.length() == 0) {
                                    setColor(4);
                                    cout << "\t\t\t";
                                    cout << "Ma chuyen bay khong hop le, vui long nhap lai!" << endl;
                                    setColor(7);
                                    cout << "\t\t\t";
                                    cout << "Nhap ma chuyen bay: ";
                                    continue;
                                }
                                break;
                            }
                            //Chuyen tu chu thuong thanh chu hoa
                            maChuyenBay = convertUpperCase(maChuyenBay);
                            system("cls");
                            
                            system("cls");
                            int iSearchChuyenBay = listFlights.timKiemChuyenBay(maChuyenBay);
                            if (iSearchChuyenBay == -1) {
                                setColor(4);
                                cout << "\t\t\t";
                                cout << "Ma chuyen bay khong ton tai trong he thong." << endl;
                                setColor(7);
                            }
                            else {
                                system("cls");
                                ChuyenBay<Ve>* cbTemp = listFlights.getPointerItem(iSearchChuyenBay);
                                setColor(2);
                                cout << "\t\t\t\t\t";
                                cout << "THONG TIN CHUYEN BAY: " << maChuyenBay << endl << endl;
                                setColor(7);

                                //update lai trang thai cac chuyen bay
                                listFlights.updateTrangThai();
                                //cap nhat lai file danh sach cac chuyen bay
                                listFlights.updateFile();

                                //Hien thi danh sach ve cua chuyen bay tim thay
                                cbTemp->hienThiDanhSachKhach();
                                cout << endl;
                                //Hien thi danh sach ghe trong cua chuyen bay tim thay
                                cbTemp->hienThiSoDoGhe();
                            }
                            cout << endl;
                            system("pause");
                            break;
                        }
                        case 2: {
                            //THONG KE SO LAN THUC HIEN CHUYEN BAY THEO MAY BAY
                            system("cls");
                            setColor(4);
                            cout << "-> ";
                            setColor(7);
                            cout << "3.2. Thong ke so lan thuc hien chuyen bay theo may bay." << endl;
                            cin.ignore();
                            cout << "\t\t\t";
                            cout << "Nhap so hieu may bay: ";
                            string soHieuMayBay;
                            while (getline(cin, soHieuMayBay)) {
                                //Kiem tra Ma chuyen bay co chua khoang trang hay khong
                                if (checkContainsSpacing(soHieuMayBay)) {
                                    setColor(4);
                                    cout << "\t\t\t";
                                    cout << "So hieu may bay chua khoang trang, vui long nhap lai!" << endl;
                                    setColor(7);
                                    cout << "\t\t\t";
                                    cout << "Nhap so hieu may bay: ";
                                    continue;
                                }
                                if (soHieuMayBay.length() == 0) {
                                    setColor(4);
                                    cout << "\t\t\t";
                                    cout << "So hieu may bay khong hop le, vui long nhap lai!" << endl;
                                    setColor(7);
                                    cout << "\t\t\t";
                                    cout << "Nhap so hieu may bay: ";
                                    continue;
                                }
                                break;
                            }
                            //Chuyen tu chu thuong thanh chu hoa
                            soHieuMayBay = convertUpperCase(soHieuMayBay);
                            system("cls");
                            
                            system("cls");
                            MayBay* timKiemMayBay = listPlanes.timKiemMayBay(soHieuMayBay);
                            if (timKiemMayBay == NULL) {
                                setColor(4);
                                cout << "\t\t\t";
                                cout << "So hieu may bay khong ton tai trong he thong." << endl;
                                setColor(7);
                            }
                            else {
                                system("cls");
                                //update lai trang thai cac chuyen bay
                                listFlights.updateTrangThai();
                                //cap nhat lai file danh sach cac chuyen bay
                                listFlights.updateFile();

                                listFlights.hienThiSoLanBay(soHieuMayBay);
                            }
                            cout << endl;
                            system("pause");
                            break;
                        }
                        default:
                            exit(1);
                            break;
                        }
                    } while (iOptionSubAdmin != 0);
                    cout << endl;
                    system("pause");
                    break;
                }
                default:
                    exit(1);
                    break;
                }
            } while (iOptionAdmin != 0);
            cout << endl;
            system("pause");
            break;
        }
        default:
            exit(1);
            break;
        }

    } while (iOption != 0);
    return 0;
}
