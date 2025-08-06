#include "Ve.h"

/********************************************
* @Description Hàm kh?i t?o Vé m?i
********************************************/

Ve::Ve() {
    _strMaVe = "";
    _strMaChuyenBay = "";
    _iSoGhe = 0;
    _lTimestamp = 0;
    _strDate = "";
}

/********************************************
* @Description Hàm kh?i t?o Vé m?i
* @parameter Chu?i mã vé, chu?i mã chuy?n bay, chu?i CMND/CCCD, chu?i H? Tên
********************************************/

Ve::Ve(string maVe, string maChuyenBay, string CMND, string hoTen) {
    _strMaVe = maVe;
    _strMaChuyenBay = maChuyenBay;
    _strCMND = CMND;
    _strHoTen = hoTen;
    _lTimestamp = 0;
    _strDate = "";
}

/********************************************
* @Description Hàm kh?i t?o Vé m?i
* @parameter Chu?i mã vé, chu?i mã chuy?n bay, chu?i CMND/CCCD, chu?i H? Tên, s? gh?
********************************************/

Ve::Ve(string maVe, string maChuyenBay, string CMND, string hoTen, int soGhe) {
    _strMaVe = maVe;
    _strMaChuyenBay = maChuyenBay;
    _strCMND = CMND;
    _strHoTen = hoTen;
    _iSoGhe = soGhe;
    _lTimestamp = 0;
    _strDate = "";
}

/********************************************
* @Description Hàm kh?i t?o Vé m?i
* @parameter Chu?i mã vé, chu?i mã chuy?n bay, chu?i CMND/CCCD, chu?i H? Tên, s? gh?, ngày t?o
********************************************/

Ve::Ve(string maVe, string maChuyenBay, string CMND, string hoTen, int soGhe, string date) {
    _strMaVe = maVe;
    _strMaChuyenBay = maChuyenBay;
    _strCMND = CMND;
    _strHoTen = hoTen;
    _iSoGhe = soGhe;
    _lTimestamp = 0;
    _strDate = date;
}

/********************************************
* @Description Hàm set s? gh? cho Vé
* @parameter Chu?i s? gh?
* @attention Chuy?n t? chu?i s? gh? thành s? gh?, sau ?ó c?p nh?t cho Vé
********************************************/

void Ve::setSoGhe(string temp) {
    stringstream ss(temp);
    int soGhe;
    ss >> soGhe;
    _iSoGhe = soGhe;
}

/********************************************
* @Description Hàm l?y thông tin c?a Vé ?? chu?n b? ghi file
* @return Chu?i thông tin c?a Vé, ng?n cách b?i "|"
********************************************/

string Ve::thongTinFile() {
    string result = "";
    stringstream ss;
    ss << _iSoGhe;
    string soGheString;
    ss >> soGheString;
    result = _strMaVe + "|" + _strMaChuyenBay + "|" + _strCMND + "|" + _strHoTen + "|" + soGheString + "|" + _strDate;
    return result;
}

/********************************************
* @Description Hàm hi?n th? thông tin c?a Vé
********************************************/

void Ve::display() {
    cout << _strMaVe << "|" << _strMaChuyenBay << "|" << _strCMND << "|" << _strHoTen << "|" << _iSoGhe << "|" << _strDate;
}

/********************************************
* @Description Hàm hi?n th? thông tin chi ti?t c?a Vé
********************************************/

void Ve::displayDetail() {
    cout << setw(20) << left << _strMaVe;
    cout << setw(20) << left << _strMaChuyenBay;
    cout << setw(20) << left << _strCMND;
    cout << setw(20) << left << _strHoTen;
    cout << setw(20) << left << _iSoGhe;
    cout << setw(50) << left << _strDate << endl;
}

/********************************************
* @Description Hàm l?y thông tin mã chuy?n bay c?a Vé
* @return Chu?i mã chuy?n bay c?a Vé
********************************************/

string Ve::getMaChuyenBay() {
    return _strMaChuyenBay;
}

/********************************************
* @Description Hàm l?y thông tin mã vé c?a Vé
* @return Chu?i mã vé c?a Vé
********************************************/

string Ve::getMaVe() {
    return _strMaVe;
}

/********************************************
* @Description Hàm l?y thông tin s? gh? c?a Vé
* @return S? gh? c?a Vé
********************************************/

int Ve::getSoGhe() {
    return _iSoGhe;
}

/********************************************
* @Description Hàm l?y thông tin h? tên c?a Vé
* @return Chu?i h? tên c?a Vé
********************************************/

string Ve::getHoTen() {
    return _strHoTen;
}

/********************************************
* @Description Hàm l?y thông tin ngày t?o c?a Vé
* @return Chu?i ngày t?o c?a Vé
********************************************/

string Ve::getDate() {
    return _strDate;
}

/********************************************
* @Description Hàm lấy thông tin CMND của Vé
* @return Chuỗi CMND của khách hàng sở hữu vé
********************************************/
string Ve::getCMND() {
    return _strCMND;
}

/********************************************
* @Description Hàm t?o file m?i v?i tên là Mã vé c?a Vé
********************************************/

void Ve::createFile() {
    char* fileName;
    ofstream ofile;
    string strFile = _strMaVe + ".txt";
    fileName = new char[strFile.length() + 1];
    strcpy(fileName, strFile.c_str());
    if (fileName != NULL)
    {
        ofile.open(fileName, ios_base::out);
        ofile << thongTinFile();
        ofile.close();
    }
    delete[] fileName;
}

/********************************************
* @Description Hàm xóa file vé ?ã ???c t?o v?i tên là Mã vé c?a Vé
********************************************/

void Ve::deleteFile() {
    string strFile = _strMaVe + ".txt";
    char* fileName;
    fileName = new char[strFile.length() + 1];
    strcpy(fileName, strFile.c_str());
    int status = remove(fileName);
    if (status != 0) {
        cout << "Error delete file." << endl;
    }
}

/********************************************
* @Description Hàm set ngày t?o cho Vé
* @parameter Chu?i ngày tháng
********************************************/

void Ve::setDate(string date) {
    _strDate = date;
}

/********************************************
* @Description Hàm set timestamp cho Vé
********************************************/

void Ve::setTimestamp() {
    string temp;
    stringstream s(_strDate);
    vector<string> separateData;
    vector<int> result;
    while (getline(s, temp, ' ')) {
        separateData.push_back(temp);
    }
    if (separateData.size() == 2) {
        stringstream ss;
        ss << (separateData[0]);
        while (getline(ss, temp, '/')) {
            stringstream sss(temp);
            int data;
            sss >> data;
            result.push_back(data);
        }
        stringstream ssss;
        ssss << (separateData[1]);
        while (getline(ssss, temp, ':')) {
            stringstream sssss(temp);
            int data;
            sssss >> data;
            result.push_back(data);
        }
        long convertTimestamp = convertDateToTimestamp(result[0], result[1], result[2], result[3], result[4], 0);
        _lTimestamp = convertTimestamp;
    }
}


