#include "Ve.h"

/********************************************
* @Description H�m kh?i t?o V� m?i
********************************************/

Ve::Ve() {
    _strMaVe = "";
    _strMaChuyenBay = "";
    _iSoGhe = 0;
    _lTimestamp = 0;
    _strDate = "";
}

/********************************************
* @Description H�m kh?i t?o V� m?i
* @parameter Chu?i m� v�, chu?i m� chuy?n bay, chu?i CMND/CCCD, chu?i H? T�n
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
* @Description H�m kh?i t?o V� m?i
* @parameter Chu?i m� v�, chu?i m� chuy?n bay, chu?i CMND/CCCD, chu?i H? T�n, s? gh?
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
* @Description H�m kh?i t?o V� m?i
* @parameter Chu?i m� v�, chu?i m� chuy?n bay, chu?i CMND/CCCD, chu?i H? T�n, s? gh?, ng�y t?o
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
* @Description H�m set s? gh? cho V�
* @parameter Chu?i s? gh?
* @attention Chuy?n t? chu?i s? gh? th�nh s? gh?, sau ?� c?p nh?t cho V�
********************************************/

void Ve::setSoGhe(string temp) {
    stringstream ss(temp);
    int soGhe;
    ss >> soGhe;
    _iSoGhe = soGhe;
}

/********************************************
* @Description H�m l?y th�ng tin c?a V� ?? chu?n b? ghi file
* @return Chu?i th�ng tin c?a V�, ng?n c�ch b?i "|"
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
* @Description H�m hi?n th? th�ng tin c?a V�
********************************************/

void Ve::display() {
    cout << _strMaVe << "|" << _strMaChuyenBay << "|" << _strCMND << "|" << _strHoTen << "|" << _iSoGhe << "|" << _strDate;
}

/********************************************
* @Description H�m hi?n th? th�ng tin chi ti?t c?a V�
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
* @Description H�m l?y th�ng tin m� chuy?n bay c?a V�
* @return Chu?i m� chuy?n bay c?a V�
********************************************/

string Ve::getMaChuyenBay() {
    return _strMaChuyenBay;
}

/********************************************
* @Description H�m l?y th�ng tin m� v� c?a V�
* @return Chu?i m� v� c?a V�
********************************************/

string Ve::getMaVe() {
    return _strMaVe;
}

/********************************************
* @Description H�m l?y th�ng tin s? gh? c?a V�
* @return S? gh? c?a V�
********************************************/

int Ve::getSoGhe() {
    return _iSoGhe;
}

/********************************************
* @Description H�m l?y th�ng tin h? t�n c?a V�
* @return Chu?i h? t�n c?a V�
********************************************/

string Ve::getHoTen() {
    return _strHoTen;
}

/********************************************
* @Description H�m l?y th�ng tin ng�y t?o c?a V�
* @return Chu?i ng�y t?o c?a V�
********************************************/

string Ve::getDate() {
    return _strDate;
}

/********************************************
* @Description H�m t?o file m?i v?i t�n l� M� v� c?a V�
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
* @Description H�m x�a file v� ?� ???c t?o v?i t�n l� M� v� c?a V�
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
* @Description H�m set ng�y t?o cho V�
* @parameter Chu?i ng�y th�ng
********************************************/

void Ve::setDate(string date) {
    _strDate = date;
}

/********************************************
* @Description H�m set timestamp cho V�
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


