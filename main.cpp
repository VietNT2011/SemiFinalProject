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
        startApp();
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

            bool exitBooking = false;
            bool restartBooking = false;

            // Đặt lại firstTime khi bắt đầu case
            bool firstInputClear = true;

            do {
                restartBooking = false;
                system("cls");
                string strHoTen, strCMND, strMaChuyenBay;
                int iMaSoGhe;

                setColor(10);
                cout << "\t\t\t\t\t";
                cout << "DAT VE:" << endl;

                setColor(7);
                cout << "\t\t\t";
                cout << "Dien tat ca thong tin khach hang theo yeu cau" << endl;

                setColor(12);
                cout << "\t\t\t";
                cout << "Luu y: Chi duoc dat ve truoc gio khoi hanh 15 phut!" << endl;
                cout << "\t\t\t";
                cout << "Nhap 'Q' de thoat, 'B' de bat dau lai" << endl;

                setColor(7);

                // BƯỚC 1: NHẬP CMND/CCCD
                cout << "\t\t\t";
                cout << "Nhap CMND hoac CCCD: ";

                // Chỉ ignore buffer lần đầu tiên, không ignore khi restart
                static bool firstTime = true;
                if (firstTime) {
                    cin.ignore();
                    firstTime = false;
                }

                while (getline(cin, strCMND)) {
                    // Kiểm tra lệnh thoát hoặc quay lại
                    string upperCMND = convertUpperCase(strCMND);
                    if (upperCMND == "Q") {
                        exitBooking = true;
                        break;
                    }
                    if (upperCMND == "B") {
                        restartBooking = true;
                        break;
                    }

                    //Kiem tra khoang trang
                    if (checkContainsSpacing(strCMND)) {
                        setColor(12);
                        cout << "\t\t\t";
                        cout << "Vui long nhap CMND hoac CCCD khong chua khoang trang!" << endl;
                        cout << "\t\t\t";
                        cout << "Hoac nhap 'Q' de thoat, 'B' de bat dau lai" << endl;
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
                        cout << "\t\t\t";
                        cout << "Hoac nhap 'Q' de thoat, 'B' de bat dau lai" << endl;
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
                    cout << "\t\t\t";
                    cout << "Hoac nhap 'Q' de thoat, 'B' de bat dau lai" << endl;
                    setColor(7);
                    cout << "\t\t\t";
                    cout << "Nhap CMND hoac CCCD: ";
                }

                if (exitBooking || restartBooking) continue;

                //Kiem tra xem khach hang da dat ve truoc do chua
                KhachHang* searchKhachHang = listCustomers.timKiemKhachHang(strCMND);
                if (searchKhachHang == NULL) {
                    // BƯỚC 2: NHẬP HỌ TÊN (chỉ khi khách hàng chưa tồn tại)
                    cout << "\t\t\t";
                    cout << "Nhap Ho Ten cua khach hang: ";
                    while (getline(cin, strHoTen)) {
                        // Kiểm tra lệnh thoát hoặc quay lại
                        string upperHoTen = convertUpperCase(strHoTen);
                        if (upperHoTen == "Q") {
                            exitBooking = true;
                            break;
                        }
                        if (upperHoTen == "B") {
                            restartBooking = true;
                            break;
                        }

                        //Kiem tra Ho ten co chua khoang trang hay khong
                        if (checkContainsSpacing(strHoTen)) {
                            setColor(12);
                            cout << "\t\t\t";
                            cout << "Ho Ten khong duoc chua khoang trang, vui long nhap lai!" << endl;
                            cout << "\t\t\t";
                            cout << "Hoac nhap 'Q' de thoat, 'B' de bat dau lai" << endl;
                            setColor(7);
                            cout << "\t\t\t";
                            cout << "Nhap Ho Ten: ";
                            continue;
                        }

                        if (checkIsNumberString(strHoTen)) {
                            setColor(12);
                            cout << "\t\t\t";
                            cout << "Ho Ten khong phai la so, vui long nhap lai!" << endl;
                            cout << "\t\t\t";
                            cout << "Hoac nhap 'Q' de thoat, 'B' de bat dau lai" << endl;
                            setColor(7);
                            cout << "\t\t\t";
                            cout << "Nhap Ho Ten: ";
                            continue;
                        }

                        if (checkKyTuDacBiet(strHoTen)) {
                            setColor(12);
                            cout << "\t\t\t";
                            cout << "Ho ten khong hop le, vui long nhap lai! " << endl;
                            cout << "\t\t\t";
                            cout << "Hoac nhap 'Q' de thoat, 'B' de bat dau lai" << endl;
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
                        cout << "\t\t\t";
                        cout << "Hoac nhap 'Q' de thoat, 'B' de bat dau lai" << endl;
                        setColor(7);
                        cout << "\t\t\t";
                        cout << "Nhap Ho Ten: ";
                    }

                    if (exitBooking || restartBooking) continue;

                    //Chuyen thanh UpperCase
                    strHoTen = convertUpperCase(strHoTen);

                }
                else {
                    //Neu khach hang da dat ve truoc do, thi lay thong tin lai
                    cout << "\t\t\t";
                    cout << "Khach hang da ton tai trong he thong: ";
                    strHoTen = searchKhachHang->getHoTen();
                    setColor(14);
                    cout << searchKhachHang->getHoTen();
                    setColor(7);
                    cout << endl;
                }

                // BƯỚC 3: NHẬP MÃ CHUYẾN BAY
                cout << "\t\t\t";
                cout << "Nhap Ma Chuyen Bay: ";
                while (getline(cin, strMaChuyenBay)) {
                    // Kiểm tra lệnh thoát hoặc quay lại
                    string upperMaChuyenBay = convertUpperCase(strMaChuyenBay);
                    if (upperMaChuyenBay == "Q") {
                        exitBooking = true;
                        break;
                    }
                    if (upperMaChuyenBay == "B") {
                        restartBooking = true;
                        break;
                    }

                    //Kiem tra Ma chuyen bay co chua khoang trang hay khong
                    if (checkContainsSpacing(strMaChuyenBay)) {
                        setColor(12);
                        cout << "\t\t\t";
                        cout << "Ma chuyen bay chua khoang trang, vui long nhap lai!" << endl;
                        cout << "\t\t\t";
                        cout << "Hoac nhap 'Q' de thoat, 'B' de bat dau lai" << endl;
                        setColor(7);
                        cout << "\t\t\t";
                        cout << "Nhap Ma Chuyen Bay: ";
                        continue;
                    }

                    if (strMaChuyenBay.length() == 0) {
                        setColor(12);
                        cout << "\t\t\t";
                        cout << "Ma chuyen bay khong hop le, vui long nhap lai!" << endl;
                        cout << "\t\t\t";
                        cout << "Hoac nhap 'Q' de thoat, 'B' de bat dau lai" << endl;
                        setColor(7);
                        cout << "\t\t\t";
                        cout << "Nhap Ma Chuyen Bay: ";
                        continue;
                    }
                    break;
                }

                if (exitBooking || restartBooking) continue;

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
                    cout << "\t\t\t";
                    cout << "Nhap 'B' de nhap lai hoac 'Q' de thoat: ";
                    setColor(7);
                    string choice;
                    getline(cin, choice);
                    choice = convertUpperCase(choice);
                    if (choice == "Q") {
                        exitBooking = true;
                        continue;
                    }
                    else if (choice == "B") {
                        restartBooking = true;
                        continue;
                    }
                    else {
                        system("pause");
                        restartBooking = true;
                        continue;
                    }
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
                    cout << "\t\t\t";
                    cout << "Nhap 'B' de chon chuyen bay khac hoac 'Q' de thoat: ";
                    setColor(7);
                    string choice;
                    getline(cin, choice);
                    choice = convertUpperCase(choice);
                    if (choice == "Q") {
                        exitBooking = true;
                        continue;
                    }
                    else {
                        restartBooking = true;
                        continue;
                    }
                }
                //Kiem tra chuyen bay chua hoan tat
                if (cbTemp.getTrangThai() == 3) {
                    setColor(12);
                    cout << "\t\t\t";
                    cout << "Chuyen bay da hoan tat!" << endl;
                    cout << "\t\t\t";
                    cout << "Nhap 'B' de chon chuyen bay khac hoac 'Q' de thoat: ";
                    setColor(7);
                    string choice;
                    getline(cin, choice);
                    choice = convertUpperCase(choice);
                    if (choice == "Q") {
                        exitBooking = true;
                        continue;
                    }
                    else {
                        restartBooking = true;
                        continue;
                    }
                }
                //Kiem tra chuyen bay van con cho trong 
                if (cbTemp.isFullSeat()) {
                    setColor(12);
                    cout << "\t\t\t";
                    cout << "Chuyen bay khong con ghe trong!" << endl;
                    cout << "\t\t\t";
                    cout << "Nhap 'B' de chon chuyen bay khac hoac 'Q' de thoat: ";
                    setColor(7);
                    string choice;
                    getline(cin, choice);
                    choice = convertUpperCase(choice);
                    if (choice == "Q") {
                        exitBooking = true;
                        continue;
                    }
                    else {
                        restartBooking = true;
                        continue;
                    }
                }
                //Chi cho phep khach hang dat ve truoc gio khoi hanh cua chuyen bay 15 phut.
                if (cbTemp.getTimestamp() - 60 * 15 <= getCurrentTimestamp()) {
                    setColor(4);
                    cout << "\t\t\t";
                    cout << "Vui long dat ve truoc gio khoi hanh 15 phut!" << endl;
                    cout << "\t\t\t";
                    cout << "Nhap 'B' de chon chuyen bay khac hoac 'Q' de thoat: ";
                    setColor(7);
                    string choice;
                    getline(cin, choice);
                    choice = convertUpperCase(choice);
                    if (choice == "Q") {
                        exitBooking = true;
                        continue;
                    }
                    else {
                        restartBooking = true;
                        continue;
                    }
                }

                // BƯỚC 4: NHẬP SỐ GHẾ
                bool validSeat = false;
                while (!validSeat) {
                    cout << "\t";
                    cout << "Nhap ma so ghe muon dat (hoac 'Q' de thoat, 'B' de bat dau lai): ";

                    //Xu ly ngoai le nhap stt ghe = string
                    string str;
                    cin >> str;
                    cin.ignore(1000, '\n');

                    // Kiểm tra lệnh thoát hoặc quay lại
                    string upperStr = convertUpperCase(str);
                    if (upperStr == "Q") {
                        exitBooking = true;
                        break;
                    }
                    if (upperStr == "B") {
                        restartBooking = true;
                        break;
                    }

                    bool check = false;
                    for (int i = 0; i < str.size(); i++) {
                        if (isalpha(str[i])) check = true;
                    }
                    if (!check) iMaSoGhe = stoi(str);
                    else iMaSoGhe = -1;

                    int kiemTraGhe = cbTemp.kiemTraMaSoGhe(iMaSoGhe);
                    if (kiemTraGhe == 3) {
                        validSeat = true;
                    }
                    else {
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
                        cout << "\t\t\t";
                        cout << "Hoac nhap 'Q' de thoat, 'B' de bat dau lai" << endl;
                        setColor(7);
                    }
                }

                if (exitBooking || restartBooking) continue;

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

                // BƯỚC 5: XÁC NHẬN ĐẶT VÉ
                string strConfirmBook;
                bool validConfirm = false;

                while (!validConfirm) {
                    cout << "\t\t\t";
                    cout << "Xac nhan dat ve: Nhap ";
                    setColor(10);
                    cout << "YES";
                    setColor(7);
                    cout << " neu dong y, ";
                    setColor(12);
                    cout << "NO";
                    setColor(7);
                    cout << " neu tu choi";
                    cout << " (hoac 'Q' de thoat, 'B' de bat dau lai): ";
                    setColor(7);
                    //// Xóa buffer trước khi đọc input
                    //cin.clear();
                    //cin.sync();
                    getline(cin, strConfirmBook);

                    // Kiểm tra lệnh thoát hoặc quay lại
                    string upperConfirm = convertUpperCase(strConfirmBook);
                    if (upperConfirm == "Q") {
                        exitBooking = true;
                        break;
                    }
                    if (upperConfirm == "B") {
                        restartBooking = true;
                        break;
                    }

                    //chuyen chu thuong thanh chu hoa
                    strConfirmBook = convertUpperCase(strConfirmBook);

                    //kiem tra nguoi dung co nhap yes hay no hay khong
                    if (strConfirmBook == "YES" || strConfirmBook == "NO") {
                        validConfirm = true;
                    }
                    else {
                        setColor(4);
                        cout << "\t\t\t";
                        cout << "Vui long nhap YES hoac NO!" << endl;
                        cout << "\t\t\t";
                        /*cout << "Hoac nhap 'Q' de thoat, 'B' de bat dau lai" << endl;*/
                        setColor(7);
                    }
                }

                if (exitBooking || restartBooking) continue;

                if (strConfirmBook == "YES") {
                    system("cls");

                    system("cls");
                    //Chi cho phep khach hang dat ve truoc gio khoi hanh cua chuyen bay 15 phut.
                    if (cbTemp.getTimestamp() - 60 * 15 <= getCurrentTimestamp()) {
                        setColor(4);
                        cout << "\t\t\t";
                        cout << "Vui long dat ve truoc gio khoi hanh 15 phut!" << endl;
                        cout << "\t\t\t";
                        cout << "Nhap 'B' de bat dau lai hoac 'Q' de thoat: ";
                        setColor(7);
                        string choice;
                        getline(cin, choice);
                        choice = convertUpperCase(choice);
                        if (choice == "Q") {
                            exitBooking = true;
                            continue;
                        }
                        else {
                            restartBooking = true;
                            continue;
                        }
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
                    exitBooking = true; // Thoát sau khi đặt vé thành công
                }
                else {
                    //HUY DAT VE
                    setColor(4);
                    cout << "\t\t\t";
                    cout << "HUY DAT VE THANH CONG! HEN GAP LAI QUY KHACH!" << endl;
                    setColor(7);
                    exitBooking = true; // Thoát sau khi hủy đặt vé
                }

                if (!restartBooking) {
                    system("pause");
                }

            } while (restartBooking && !exitBooking);

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
                    bool continueProcessing = true;
                    bool firstTime = true; // Thêm biến để kiểm soát lần đầu
                    while (continueProcessing) {
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
                            cout << "\t\t\tNhap phim bat ky de quay lai menu chinh...";
                            system("pause");
                            continueProcessing = false;
                            continue;
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
                        setColor(14);
                        cout << "1. ";
                        setColor(7);
                        cout << "Nhap ";
                        setColor(14);
                        cout << "YES";
                        setColor(7);
                        cout << " de xu ly tat ca cac ve pending." << endl;
                        cout << "\t\t\t";
                        setColor(14);
                        cout << "2. ";
                        setColor(7);
                        cout << "Nhap ";
                        setColor(14);
                        cout << "ma ve";
                        setColor(7);
                        cout << " (VD: VE123) de chi xu ly mot ve cu the." << endl;
                        cout << "\t\t\t";
                        setColor(14);
                        cout << "3. ";
                        setColor(7);
                        cout << "Nhap ";
                        setColor(14);
                        cout << "DELETE ma_ve";
                        setColor(7);
                        cout << " (VD: DELETE VE123) de xoa mot ve cu the." << endl;
                        cout << "\t\t\t";
                        setColor(14);
                        cout << "4. ";
                        setColor(7);
                        cout << "Nhap ";
                        setColor(14);
                        cout << "NO";
                        setColor(7);
                        cout << " de huy bo tat ca." << endl;
                        cout << "\t\t\t";
                        setColor(14);
                        cout << "5. ";
                        setColor(7);
                        cout << "Nhap ";
                        setColor(14);
                        cout << "EXIT";
                        setColor(7);
                        cout << " de thoat ve menu chinh." << endl;
                        cout << "\n\t\t\tNhap lua chon cua ban: ";
                        setColor(7);


                        if (firstTime) {
                            cin.ignore(); // Chỉ ignore ở lần đầu tiên
                            firstTime = false;
                        }
                        getline(cin, strConfirmHandle);

                        //Chuyen chu thuong thanh chu hoa
                        strConfirmHandle = convertUpperCase(strConfirmHandle);

                        if (strConfirmHandle == "EXIT") {
                            continueProcessing = false;
                            continue;
                        }

                        // Kiểm tra lệnh DELETE
                        if (strConfirmHandle.substr(0, 6) == "DELETE" && strConfirmHandle.length() > 7) {
                            string maVeCanXoa = strConfirmHandle.substr(7); // Lấy mã vé sau "DELETE "
                            Ve veTemp;

                            if (listTicketsPending.xuLyVeTheoMa(maVeCanXoa, veTemp)) {
                                system("cls");
                                setColor(13);
                                cout << "\t\t\t\t\t";
                                cout << "XOA VE CO MA: " << maVeCanXoa << endl;
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

                                string confirm;
                                cout << "\n\t\t\t\t\t";
                                cout << "Ban co chac chan muon xoa ve nay? (Y/N): ";
                                getline(cin, confirm);
                                confirm = convertUpperCase(confirm);

                                if (confirm == "Y" || confirm == "YES") {
                                    // Ve đã được remove khỏi listTicketsPending trong xuLyVeTheoMa
                                    listTicketsPending.updateFile(); // Cập nhật file
                                    setColor(10);
                                    cout << "\t\t\t\t\tDa xoa ve thanh cong!" << endl;
                                    setColor(7);
                                }
                                else {
                                    // Thêm lại vé vào danh sách nếu không xác nhận xóa
                                    listTicketsPending.enQueue(veTemp);
                                    setColor(14);
                                    cout << "\t\t\t\t\tHuy bo xoa ve." << endl;
                                    setColor(7);
                                }

                                cout << setfill('*');
                                cout << "\t\t\t\t";
                                cout << setw(50) << "*" << endl;
                                cout << setfill(' ');
                            }
                            else {
                                setColor(4);
                                cout << "\t\t\t\t\tKhong tim thay ma ve: " << maVeCanXoa << endl;
                                setColor(7);
                            }
                        }
                        else if (strConfirmHandle == "YES") {
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

                            cout << "\n\t\t\t\t\t";
                            setColor(10);
                            cout << "Da xu ly xong tat ca ve pending!" << endl;
                            setColor(7);
                        }
                        else if (strConfirmHandle == "NO") {
                            // Hủy tất cả vé pending
                            system("cls");
                            setColor(12);
                            cout << "\t\t\t\t\t";
                            cout << "XAC NHAN HUY TAT CA VE PENDING" << endl;
                            setColor(7);
                            cout << setfill('*');
                            cout << "\t\t\t\t";
                            cout << setw(50) << "*" << endl;
                            cout << setfill(' ');

                            cout << "\t\t\t\t\t";
                            cout << "So luong ve se bi huy: " << listTicketsPending.getSize() << endl;

                            string confirmDelete;
                            cout << "\n\t\t\t\t\t";
                            cout << "Ban co chac chan muon huy tat ca ve pending? (Y/N): ";
                            getline(cin, confirmDelete);
                            confirmDelete = convertUpperCase(confirmDelete);

                            if (confirmDelete == "Y" || confirmDelete == "YES") {
                                int deletedCount = 0;
                                // Xóa tất cả vé trong danh sách pending
                                while (listTicketsPending.getSize() != 0) {
                                    Ve veTemp = listTicketsPending.deQueue();
                                    deletedCount++;
                                    cout << "\t\t\t\t\t";
                                    cout << "Da huy ve: " << veTemp.getMaVe() << endl;
                                }

                                // Cập nhật file sau khi xóa tất cả
                                listTicketsPending.updateFile();

                                cout << "\n\t\t\t\t\t";
                                setColor(10);
                                cout << "Da huy thanh cong " << deletedCount << " ve pending!" << endl;
                                setColor(7);
                            }
                            else {
                                setColor(14);
                                cout << "\t\t\t\t\tHuy bo xoa tat ca ve pending." << endl;
                                setColor(7);
                            }

                            cout << setfill('*');
                            cout << "\t\t\t\t";
                            cout << setw(50) << "*" << endl;
                            cout << setfill(' ');
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

                        cout << "\n\t\t\t";
                        cout << "Nhan phim bat ky de tiep tuc...";
                        system("pause");
  
                    }
                    break; // Chỉ break khi continueProcessing = false
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
                            bool continueStatistics = true;
                            while (continueStatistics) {
                                system("cls");
                                listFlights.ShowListNoSearch();
                                setColor(4);
                                cout << "-> ";
                                setColor(7);
                                cout << "3.1. Thong ke theo ma chuyen bay." << endl;
                                cout << "\t\t\t";
                                cout << "Nhap ma chuyen bay ";
                                setColor(14);
                                cout << "(hoac 'EXIT' de thoat)";
                                setColor(7);
                                cout << ": ";
                                string maChuyenBay;

                                if (cin.peek() == '\n') cin.ignore();

                                while (getline(cin, maChuyenBay)) {
                                    //Kiem tra neu nguoi dung muon thoat
                                    string temp = convertUpperCase(maChuyenBay);
                                    if (temp == "EXIT") {
                                        continueStatistics = false;
                                        break;
                                    }

                                    //Kiem tra Ma chuyen bay co chua khoang trang hay khong
                                    if (checkContainsSpacing(maChuyenBay)) {
                                        setColor(4);
                                        cout << "\t\t\t";
                                        cout << "Ma chuyen bay chua khoang trang, vui long nhap lai!" << endl;
                                        setColor(7);
                                        cout << "\t\t\t";
                                        cout << "Nhap ma chuyen bay ";
                                        setColor(14);
                                        cout << "(hoac 'EXIT' de thoat)";
                                        setColor(7);
                                        cout << ": ";
                                        continue;
                                    }
                                    if (maChuyenBay.length() == 0) {
                                        setColor(4);
                                        cout << "\t\t\t";
                                        cout << "Ma chuyen bay khong hop le, vui long nhap lai!" << endl;
                                        setColor(7);
                                        cout << "\t\t\t";
                                        cout << "Nhap ma chuyen bay ";
                                        setColor(14);
                                        cout << "(hoac 'EXIT' de thoat)";
                                        setColor(7);
                                        cout << ": ";
                                        continue;
                                    }
                                    break;
                                }

                                if (!continueStatistics) break;

                                //Chuyen tu chu thuong thanh chu hoa
                                maChuyenBay = convertUpperCase(maChuyenBay);
                                system("cls");

                                int iSearchChuyenBay = listFlights.timKiemChuyenBay(maChuyenBay);
                                if (iSearchChuyenBay == -1) {
                                    setColor(4);
                                    cout << "\t\t\t";
                                    cout << "Ma chuyen bay khong ton tai trong he thong." << endl;
                                    setColor(7);
                                }
                                else {
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

                                cout << "\n\t\t\t";
                                cout << "Nhan phim bat ky de tiep tuc xem chuyen bay khac...";
                                system("pause");
                            }
                            break;
                        }

                        case 2: {
                            //THONG KE SO LAN THUC HIEN CHUYEN BAY THEO MAY BAY
                            bool continueStatistics = true;
                            while (continueStatistics) {
                                system("cls");
                                listPlanes.showAll();
                                setColor(4);
                                cout << "-> ";
                                setColor(7);
                                cout << "3.2. Thong ke so lan thuc hien chuyen bay theo may bay." << endl;
                                cout << "\t\t\t";
                                cout << "Nhap so hieu may bay ";
                                setColor(14);
                                cout << "(hoac 'EXIT' de thoat)";
                                setColor(7);
                                cout << ": ";
                                string soHieuMayBay;

                                if (cin.peek() == '\n') cin.ignore();

                                while (getline(cin, soHieuMayBay)) {
                                    //Kiem tra neu nguoi dung muon thoat
                                    string temp = convertUpperCase(soHieuMayBay);
                                    if (temp == "EXIT") {
                                        continueStatistics = false;
                                        break;
                                    }

                                    //Kiem tra Ma chuyen bay co chua khoang trang hay khong
                                    if (checkContainsSpacing(soHieuMayBay)) {
                                        setColor(4);
                                        cout << "\t\t\t";
                                        cout << "So hieu may bay chua khoang trang, vui long nhap lai!" << endl;
                                        setColor(7);
                                        cout << "\t\t\t";
                                        cout << "Nhap so hieu may bay ";
                                        setColor(14);
                                        cout << "(hoac 'EXIT' de thoat)";
                                        setColor(7);
                                        cout << ": ";
                                        continue;
                                    }
                                    if (soHieuMayBay.length() == 0) {
                                        setColor(4);
                                        cout << "\t\t\t";
                                        cout << "So hieu may bay khong hop le, vui long nhap lai!" << endl;
                                        setColor(7);
                                        cout << "\t\t\t";
                                        cout << "Nhap so hieu may bay ";
                                        setColor(14);
                                        cout << "(hoac 'EXIT' de thoat)";
                                        setColor(7);
                                        cout << ": ";
                                        continue;
                                    }
                                    break;
                                }

                                if (!continueStatistics) break;

                                //Chuyen tu chu thuong thanh chu hoa
                                soHieuMayBay = convertUpperCase(soHieuMayBay);
                                system("cls");

                                MayBay* timKiemMayBay = listPlanes.timKiemMayBay(soHieuMayBay);
                                if (timKiemMayBay == NULL) {
                                    setColor(4);
                                    cout << "\t\t\t";
                                    cout << "So hieu may bay khong ton tai trong he thong." << endl;
                                    setColor(7);
                                }
                                else {
                                    //update lai trang thai cac chuyen bay
                                    listFlights.updateTrangThai();
                                    //cap nhat lai file danh sach cac chuyen bay
                                    listFlights.updateFile();
                                    listFlights.hienThiSoLanBay(soHieuMayBay);
                                }

                                cout << "\n\t\t\t";
                                cout << "Nhan phim bat ky de tiep tuc xem may bay khac...";
                                system("pause");
                            }
                            break;
                        }
                        
                        case 3: {
                            // HIEN THI DANH SACH KHACH HANG
                            while (true) {  // Vòng lặp chính để có thể xem nhiều khách hàng
                                system("cls");
                                setColor(4);
                                cout << "-> ";
                                setColor(7);
                                cout << "3. Danh sach khach hang." << endl << endl;

                                if (listCustomers.getSize() == 0) {
                                    setColor(4);
                                    cout << "\t\t\t";
                                    cout << "Danh sach khach hang trong!" << endl;
                                    setColor(7);
                                    break; // Thoát nếu không có khách hàng
                                }
                                else {
                                    setColor(6);
                                    cout << "\t\t\t\t\tDANH SACH KHACH HANG" << endl;
                                    cout << "\t\t====================================================================" << endl;
                                    cout << "\t\t| STT |        Ho Ten        |             CMND/CCCD          | Ve |" << endl;
                                    cout << "\t\t====================================================================" << endl;

                                    Node<KhachHang>* pWalker = listCustomers.getHead();
                                    int stt = 1;

                                    while (pWalker != NULL) {
                                        KhachHang& kh = pWalker->getData();

                                        // Đếm vé bằng cách duyệt qua LinkedList
                                        LinkedList<Ve> vePending = listTicketsPending.layTatCaVeTheoCMND(kh.getCMND());
                                        LinkedList<Ve> veSuccess = listTicketsSuccess.layTatCaVeTheoCMND(kh.getCMND());
                                        int tongVe = vePending.getSize() + veSuccess.getSize();

                                        setColor(6); cout << "\t\t| ";
                                        setColor(7); cout.width(3);  cout << left << stt;
                                        setColor(6); cout << " | ";
                                        setColor(7); cout.width(20); cout << left << kh.getHoTen();
                                        setColor(6); cout << " | ";
                                        setColor(7); cout.width(30); cout << left << kh.getCMND();
                                        setColor(6); cout << " | ";
                                        setColor(7); cout.width(2); cout << left << tongVe;
                                        setColor(6); cout << " |" << endl;

                                        pWalker = pWalker->getNext();
                                        stt++;
                                    }
                                    cout << "\t\t====================================================================" << endl;
                                    setColor(7);
                                    cout << "\t\t\tTong so khach hang: " << listCustomers.getSize() << endl;
                                    setColor(7);

                                    cout << endl;
                                    setColor(3);
                                    cout << "\t\tNhap CMND/CCCD de xem chi tiet ve (hoac nhap 'B' de thoat): ";
                                    setColor(7);

                                    string input;
                                    /*cin.ignore(1000, '\n');*/
                                    getline(cin, input);

                                    // Kiểm tra nếu người dùng muốn thoát
                                    if (toUpperCase(input) == "B" || input.empty()) {
                                        break; // Thoát khỏi vòng lặp chính
                                    }

                                    // Tìm kiếm khách hàng
                                    Node<KhachHang>* khachHang = listCustomers.getHead();
                                    bool found = false;

                                    while (khachHang != NULL) {
                                        if (toUpperCase(khachHang->getData().getCMND()) == toUpperCase(input)) {
                                            found = true;
                                            break;
                                        }
                                        khachHang = khachHang->getNext();
                                    }

                                    if (found) {
                                        system("cls");
                                        KhachHang& kh = khachHang->getData();

                                        setColor(2);
                                        cout << "\t\t\tCHI TIET VE CUA KHACH HANG: " << kh.getHoTen() << endl;
                                        cout << "\t\t\tCMND/CCCD: " << kh.getCMND() << endl;
                                        cout << "\t\t=================================================================" << endl;

                                        // Lấy danh sách vé pending bằng LinkedList
                                        LinkedList<Ve> vePending = listTicketsPending.layTatCaVeTheoCMND(kh.getCMND());
                                        if (vePending.getSize() > 0) {
                                            setColor(14);
                                            cout << "\t\t\tVE DANG CHO XU LY (" << vePending.getSize() << " ve):" << endl;
                                            setColor(6);
                                            cout << "\t\t| STT |    Ma Ve    | Ma Chuyen Bay |  Ghe  |    Ngay    |" << endl;
                                            cout << "\t\t=============================================================" << endl;

                                            Node<Ve>* pVeWalker = vePending.getHead();
                                            int sttVe = 1;
                                            while (pVeWalker != NULL) {
                                                Ve& ve = pVeWalker->getData();

                                                setColor(6); cout << "\t\t| ";
                                                setColor(7); cout.width(3); cout << left << sttVe;
                                                setColor(6); cout << " | ";
                                                setColor(7); cout.width(11); cout << left << ve.getMaVe();
                                                setColor(6); cout << " | ";
                                                setColor(7); cout.width(13); cout << left << ve.getMaChuyenBay();
                                                setColor(6); cout << " | ";
                                                setColor(7); cout.width(5); cout << left << ve.getSoGhe();
                                                setColor(6); cout << " | ";
                                                setColor(7); cout.width(10); cout << left << ve.getDate();
                                                setColor(6); cout << " |" << endl;

                                                pVeWalker = pVeWalker->getNext();
                                                sttVe++;
                                            }
                                            cout << "\t\t=============================================================" << endl;
                                            cout << endl;
                                        }

                                        // Lấy danh sách vé success bằng LinkedList
                                        LinkedList<Ve> veSuccess = listTicketsSuccess.layTatCaVeTheoCMND(kh.getCMND());
                                        if (veSuccess.getSize() > 0) {
                                            setColor(10); // Green
                                            cout << "\t\t\tVE DA HOAN THANH (" << veSuccess.getSize() << " ve):" << endl;
                                            setColor(6);
                                            cout << "\t\t| STT |    Ma Ve    | Ma Chuyen Bay |  Ghe  |    Ngay    |" << endl;
                                            cout << "\t\t=============================================================" << endl;

                                            Node<Ve>* pVeWalker = veSuccess.getHead();
                                            int sttVe = 1;
                                            while (pVeWalker != NULL) {
                                                Ve& ve = pVeWalker->getData();

                                                setColor(6); cout << "\t\t| ";
                                                setColor(7); cout.width(3); cout << left << sttVe;
                                                setColor(6); cout << " | ";
                                                setColor(7); cout.width(11); cout << left << ve.getMaVe();
                                                setColor(6); cout << " | ";
                                                setColor(7); cout.width(13); cout << left << ve.getMaChuyenBay();
                                                setColor(6); cout << " | ";
                                                setColor(7); cout.width(5); cout << left << ve.getSoGhe();
                                                setColor(6); cout << " | ";
                                                setColor(7); cout.width(10); cout << left << ve.getDate();
                                                setColor(6); cout << " |" << endl;

                                                pVeWalker = pVeWalker->getNext();
                                                sttVe++;
                                            }
                                            cout << "\t\t=============================================================" << endl;
                                            cout << endl;
                                        }

                                        if (vePending.getSize() == 0 && veSuccess.getSize() == 0) {
                                            setColor(4);
                                            cout << "\t\t\tKhach hang nay chua co ve nao!" << endl;
                                            setColor(7);
                                        }

                                        setColor(7);
                                        cout << "\t\tTong so ve: " << (vePending.getSize() + veSuccess.getSize()) << endl;
                                        cout << "\t\t- Ve dang cho: " << vePending.getSize() << endl;
                                        cout << "\t\t- Ve da hoan thanh: " << veSuccess.getSize() << endl;
                                        cout << endl;

                                        setColor(11);
                                        cout << "\t\tNhan phim bat ky de quay lai danh sach khach hang...";
                                        setColor(7);
                                        string temp;
                                        getline(cin, temp);
                                        // Sau khi nhấn phím, sẽ quay lại đầu vòng lặp để hiển thị lại danh sách
                                    }
                                    else {
                                        setColor(4);
                                        cout << "\t\tKhong tim thay khach hang voi CMND/CCCD: " << input << endl;
                                        setColor(7);
                                        cout << endl;
                                        setColor(11);
                                        cout << "\t\tNhan phim bat ky de tiep tuc...";
                                        setColor(7);
                                        string temp;
                                        getline(cin, temp);
                                        // Sau khi nhấn phím, sẽ quay lại đầu vòng lặp
                                    }
                                }
                            }
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
