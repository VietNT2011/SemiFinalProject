#include "Header.h"
#include "ChuyenBay.h"
#include "DanhSachVeSuccess.h"
#include "Ve.h"
#include <string>

/********************************************
* @Description Hàm khởi tạo Chuyến Bay mới có timestamp: 0, trạng thái: còn vé,
* số lượng vé: 0, số chỗ của chuyến bay: MAX_SO_LUONG_VE, số lượng ghế trống: MAX_SO_LUONG_VE,
danh sách vé là một mảng trống bao gồm "số chỗ" phần tử.
********************************************/

template <class DataType>
ChuyenBay<DataType>::ChuyenBay() {
    _lTimestamp = 0;
    _iTrangThai = 1;
    _iSoLuongVe = 0;
    _iSoCho = MAX_SO_LUONG_VE;
    _iSoLuongGheTrong = MAX_SO_LUONG_VE;
    _danhSachVe = new Ve[_iSoCho];
}

/********************************************
* @Description Hàm khởi tạo Chuyến Bay mới với mã chuyến bay, số hiệu máy bay,
* ngày khởi hành, sân bay đến.
* @parameter Mã chuyến bay, số hiệu máy bay, ngày khởi hành, sân bay đến.
********************************************/

template <class DataType>
ChuyenBay<DataType>::ChuyenBay(string maChuyenBay, string soHieuMayBay, string ngayKhoiHanh, string sanBayDen) {
    _strMaChuyenBay = maChuyenBay;
    _strSoHieuMayBay = soHieuMayBay;
    _strNgayKhoiHanh = ngayKhoiHanh;
    _strSanBayDen = sanBayDen;
    _lTimestamp = 0;
    _iTrangThai = 1;
    _iSoLuongVe = 0;
    _iSoCho = MAX_SO_LUONG_VE;
    _iSoLuongGheTrong = MAX_SO_LUONG_VE;
    _danhSachVe = new Ve[_iSoCho];
}

/********************************************
* @Description Hàm hiển thị thông tin của chuyến bay
********************************************/

template <class DataType>
void ChuyenBay<DataType>::display() {
    cout << setw(18) << left << _strMaChuyenBay;
    cout << setw(22) << left << _strNgayKhoiHanh;
    cout << setw(22) << left << _strSanBayDen;
    cout << setw(22) << left;
    switch (_iTrangThai)
    {
    case 0:
        cout << "HUY CHUYEN";
        break;
    case 1:
        cout << "CON VE    ";
        break;
    case 2:
        cout << "HET VE    ";
        break;
    case 3:
        cout << "HOAN TAT  ";
        break;
    default:
        break;
    }
    cout << setw(100);
    string result = "";
    for (int i = 0; i < _iSoLuongVe; i++) {
        stringstream ss;
        ss << _danhSachVe[i].getSoGhe();
        string temp;
        ss >> temp;
        if (i != _iSoLuongVe - 1) {
            temp = temp + ",";
        }
        result += temp;
    }
    cout << left << result << endl;
}

template <class DataType>
void ChuyenBay<DataType>::hienThiSoDoGhe() {
    const int soCot = 5;
    int tongGhe = _iSoCho;
    int ghe = 1;

    cout << "\n\tSODO GHE - CHUYEN BAY " << _strMaChuyenBay << "\n\n";

    while (ghe <= tongGhe) {
        // Viền trên
        cout << "\t";
        for (int i = 0; i < soCot && ghe + i <= tongGhe; ++i) {
            cout << "+----";
        }
        cout << "+\n";

        // Số ghế
        cout << "\t";
        for (int i = 0; i < soCot && ghe <= tongGhe; ++i, ++ghe) {
            bool daDat = false;
            for (int j = 0; j < _iSoLuongVe; ++j) {
                if (_danhSachVe[j].getSoGhe() == ghe) {
                    daDat = true;
                    break;
                }
            }

            if (daDat)
                setColor(12); // Đỏ
            else
                setColor(10); // Xanh

            cout << "| ";
            if (ghe < 10) cout << "0"; // In số 1 chữ số có thêm 0
            cout << ghe << " ";

            setColor(15); // Reset về trắng
        }
        cout << "|\n";
    }

    // Viền dưới cùng
    cout << "\t";
    int soGheCuoiHang = ((tongGhe - 1) % soCot) + 1;
    if (soGheCuoiHang == 0) soGheCuoiHang = soCot;
    for (int i = 0; i < soGheCuoiHang; ++i) {
        cout << "+----";
    }
    cout << "+\n";
}

/********************************************
* @Description Hàm hiển thị thông tin chi tiết của chuyến bay
********************************************/

template <class DataType>
void ChuyenBay<DataType>::displayDetail() {
    cout << setw(10) << left << _strSoHieuMayBay;
    cout << setw(15) << left << _strMaChuyenBay;
    cout << setw(20) << left << _strNgayKhoiHanh;
    cout << setw(15) << left << _strSanBayDen;
    cout << setw(20) << left;
    switch (_iTrangThai)
    {
    case 0:
        cout << "HUY CHUYEN";
        break;
    case 1:
        cout << "CON VE    ";
        break;
    case 2:
        cout << "HET VE    ";
        break;
    case 3:
        cout << "HOAN TAT  ";
        break;
    default:
        break;
    }
    cout << setw(17) << left << _iSoCho;
    cout << setw(20) << left << _iSoLuongGheTrong;
    cout << setw(100);
    string result = "";
    for (int i = 0; i < _iSoLuongVe; i++) {
        stringstream ss;
        ss << _danhSachVe[i].getSoGhe();
        string temp;
        ss >> temp;
        if (i != _iSoLuongVe - 1) {
            temp = temp + ",";
        }
        result += temp;
    }
    cout << left << result << endl;
}

/********************************************
* @Description Hàm hiển thị danh sách khách hàng đặt vé của chuyến bay
********************************************/

template <class DataType>
void ChuyenBay<DataType>::hienThiDanhSachKhach() {
    setColor(2);
    cout << "\t\t\t\t\t";
    cout << "DANH SACH VE:" << endl;
    setColor(7);
    if (_iSoLuongVe == 0) {
        cout << "\t\t\t";
        setColor(4);
        cout << "Khong co khach hang nao dat ve." << endl;
        setColor(7);
        return;
    }
    cout << setfill('-');
    setColor(4);
    cout << setw(130) << "-" << endl;
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
    cout << setw(130) << "-" << endl;
    setColor(7);
    cout << setfill(' ');
    for (int i = 0; i < _iSoLuongVe; i++) {
        _danhSachVe[i].displayDetail();
        cout << endl;
    }
    cout << setfill('-');
    setColor(4);
    cout << setw(130) << "-" << endl;
    setColor(7);
    cout << setfill(' ');
}

/********************************************
* @Description Hàm hiển thị danh sách ghế còn trống của chuyến bay
********************************************/

template <class DataType>
void ChuyenBay<DataType>::hienThiDanhSachGheTrong() {
    setColor(2);
    cout << "\t\t\t\t\t";
    cout << "DANH SACH GHE TRONG:" << endl;
    setColor(7);
    if (_iSoLuongGheTrong == 0) {
        setColor(4);
        cout << "\t\t\t";
        cout << "Chuyen bay khong con ghe trong!" << endl;
        setColor(7);
        return;
    }
    cout << setfill('-');
    setColor(4);
    cout << setw(130) << "-" << endl;
    setColor(7);
    cout << setfill(' ');
    for (int i = 0; i < _iSoLuongGheTrong; i++) {
        cout << _danhSachGheTrong[i];
        if (i != _iSoLuongGheTrong - 1) {
            cout << ",";
        }
    }
    cout << endl;
    cout << setfill('-');
    setColor(4);
    cout << setw(130) << "-" << endl;
    setColor(7);
    cout << setfill(' ');

}

/********************************************
* @Description Hàm set số chỗ cho chuyến bay
* @parameter Số chỗ của chuyến bay
* @attention: Tạo một danh sách vé có số chỗ tối đa phần tử sau khi set số chỗ
********************************************/

template <class DataType>
void ChuyenBay<DataType>::setSoCho(int soCho) {
    _iSoCho = soCho;
    _iSoLuongGheTrong = _iSoCho;
    _danhSachVe = new Ve[_iSoCho];
}

/********************************************
* @Description Hàm set trạng thái cho chuyến bay
* @parameter Chuỗi temp: là chuỗi trạng thái, đọc từ file, ví dụ: "0", "1", "2", "3"
* @attention: Chuyển từ chuỗi trạng thái sang số, sau đó set trạng thái cho chuyến bay
********************************************/

template <class DataType>
void ChuyenBay<DataType>::setTrangThai(string temp) {
    stringstream ss(temp);
    int trangThai;
    ss >> trangThai;
    _iTrangThai = trangThai;
}

/********************************************
* @Description Hàm remove ghế trống cho chuyến bay
* @parameter Vị trí index của ghế trống muốn xóa
********************************************/

template <class DataType>
void ChuyenBay<DataType>::removeGhe(int index) {
    for (int i = index; i < _iSoLuongGheTrong - 1; i++) {
        _danhSachGheTrong[i] = _danhSachGheTrong[i + 1];
    }
    _iSoLuongGheTrong--;

}

/********************************************
* @Description Hàm set danh sách ghế trống cho chuyến bay
********************************************/

template <class DataType>
void ChuyenBay<DataType>::setDanhSachGheTrong() {
    //Khởi tạo danh sách ghế trống từ 1 đến số số chỗ
    for (int i = 0; i < _iSoLuongGheTrong; i++) {
        _danhSachGheTrong[i] = i + 1;
    }
    //Xóa các ghế khách đã đặt khỏi danh sách ghế trống
    for (int i = 0; i < _iSoLuongGheTrong; i++) {
        for (int j = 0; j < _iSoLuongVe; j++) {
            if (_danhSachVe[j].getSoGhe() == _danhSachGheTrong[i]) {
                removeGhe(i);
                i--;
                break;
            }
        }
    }
}

/********************************************
* @Description Hàm set danh sách vé khách đặt cho chuyến bay
* @parameter Một chuỗi danhSachVe (ví dụ: 1,2) đọc từ file, Mã chuyến bay đọc từ file,
* Danh sách Vé thành công
********************************************/

template <class DataType>
void ChuyenBay<DataType>::setDanhSachVe(string danhSachVe, string maChuyenBay, DanhSachVeSuccess<DataType> DSVS) {
    stringstream ss(danhSachVe);
    string temp;
    while (getline(ss, temp, ',')) {
        stringstream sss;
        sss << temp;
        int ssss;
        sss >> ssss;
        Ve* timKiemVe = DSVS.timKiemVe(ssss, maChuyenBay);
        if (timKiemVe != NULL) {
            themVeMoi(*timKiemVe);
        }



    }

}

/********************************************
* @Description Hàm thêm vé mới vào danh sách vé cho chuyến bay
* @parameter Đối tượng Vé
********************************************/

template <class DataType>
void ChuyenBay<DataType>::themVeMoi(Ve data) {
    _danhSachVe[_iSoLuongVe] = data;
    _iSoLuongVe++;
}

/********************************************
* @Description Hàm xóa vé khỏi danh sách vé của chuyến bay
* @parameter Số ghế của vé muốn xóa
********************************************/

template <class DataType>
void ChuyenBay<DataType>::removeVe(int soGhe) {
    int pVe = -1;
    //tìm vị trí của vé dựa trên số ghế
    for (int i = 0; i < _iSoLuongVe; i++) {
        if (soGhe == _danhSachVe[i].getSoGhe()) {
            pVe = i;
            break;
        }
    }

    //Xóa vé đó khỏi danh sách vé nếu tìm thấy 
    if (pVe != -1) {
        for (int i = pVe + 1; i < _iSoLuongVe; i++) {
            _danhSachVe[i - 1] = _danhSachVe[i];
        }
        _iSoLuongVe--;
    }
}

/********************************************
* @Description Hàm thêm ghế trống mới vào danh sách ghế trống của chuyến bay
* @parameter Số ghế muốn thêm
********************************************/

template <class DataType>
void ChuyenBay<DataType>::themGheTrongMoi(int soGhe) {
    _danhSachGheTrong[_iSoLuongGheTrong] = soGhe;
    _iSoLuongGheTrong++;
}

/********************************************
* @Description Hàm xóa ghế trống khỏi danh sách ghế trống của chuyến bay
* @parameter Số ghế muốn xóa
********************************************/

template <class DataType>
void ChuyenBay<DataType>::removeGheTrong(int soGhe) {
    for (int i = soGhe - 1; i < _iSoLuongGheTrong; i++) {
        _danhSachGheTrong[i] = _danhSachGheTrong[i + 1];
    }
    _iSoLuongGheTrong--;
}

/********************************************
* @Description Hàm lấy mã chuyến bay của chuyến bay
* @return Mã chuyến bay của chuyến bay
********************************************/

template <class DataType>
string ChuyenBay<DataType>::getMaChuyenBay() {
    return _strMaChuyenBay;
}

/********************************************
* @Description Hàm lấy số hiệu máy bay của chuyến bay
* @return Số hiệu máy bay của chuyến bay
********************************************/

template <class DataType>
string ChuyenBay<DataType>::getSoHieuMayBay() {
    return _strSoHieuMayBay;
}

/********************************************
* @Description Hàm lấy trạng thái hiện tại của chuyến bay
* @return Trạng thái của chuyến bay
********************************************/

template <class DataType>
int ChuyenBay<DataType>::getTrangThai() {
    return _iTrangThai;
}

/********************************************
* @Description Hàm kiểm tra xem chuyến bay đã đầy chỗ chưa
* @return True nếu số lượng ghế trống = 0, ngược lại False
********************************************/

template <class DataType>
bool ChuyenBay<DataType>::isFullSeat() {
    return _iSoLuongGheTrong == 0;
}

/********************************************
* @Description Hàm kiểm tra xem số ghế khách đặt có hợp lệ hay không
* @parameter Mã số ghế khách đặt
* @return 1 nếu mã số ghế không hợp lệ, 2 nếu đã có khách khác đặt, còn lại 3: có thể đặt được
********************************************/

template <class DataType>
// 1: KHONG HOP LE, 2: DA DAT, 3: CHUA DAT
int ChuyenBay<DataType>::isBooked(int maSoGhe) {
    if (maSoGhe > _iSoCho || maSoGhe < 1) {
        return 1;
    }
    for (int i = 0; i < _iSoLuongVe; i++) {
        if (_danhSachVe[i].getSoGhe() == maSoGhe) {
            return 2;
        }
    }
    return 3;
}

/********************************************
* @Description Hàm kiểm tra xem số ghế khách đặt có hợp lệ hay không
* @parameter Mã số ghế khách đặt
* @return 1 nếu mã số ghế không hợp lệ, 2 nếu đã có khách khác đặt, còn lại 3: có thể đặt được
********************************************/

template <class DataType>
// 1: SO GHE KHONG HOP LE, 2: DA DAT, 3: CHUA DAT
int ChuyenBay<DataType>::kiemTraMaSoGhe(int maSoGhe) {
    if (maSoGhe > _iSoCho || maSoGhe < 1) {
        return 1;
    }
    for (int i = 0; i < _iSoLuongVe; i++) {
        if (_danhSachVe[i].getSoGhe() == maSoGhe) {
            return 2;
        }
    }
    return 3;
}

/********************************************
* @Description Hàm lấy Danh Sách Vé của chuyến bay
* @return Mảng danh sách vé
********************************************/

template <class DataType>
DataType* ChuyenBay<DataType>::getDanhSachVe() {
    return _danhSachVe;
}

/********************************************
* @Description Hàm lấy số lượng Vé của chuyến bay
* @return Số lượng vé
********************************************/

template <class DataType>
int ChuyenBay<DataType>::getSoLuongVe() {
    return _iSoLuongVe;
}

/********************************************
* @Description Hàm cập nhật trạng thái cho chuyến bay
* @attention Nếu chuyến bay chưa bị hủy:
* @attention: Nếu thời gian hiện tại đã qua thời gian khởi hành thì cập nhật
* trạng thái hoàn tất cho chuyến bay
* @attention: Nếu số lượng ghế trống = 0 thì cập nhật
* trạng thái hết vé cho chuyến bay
* @attention: Nếu số lượng ghế trống > 0 thì cập nhật
* trạng thái còn vé cho chuyến bay
********************************************/

template <class DataType>
void ChuyenBay<DataType>::updateTrangThai() {
    if (_iTrangThai != 0) {
        if (getCurrentTimestamp() >= _lTimestamp) {
            _iTrangThai = 3;
        }
        else if (_iSoLuongGheTrong == 0) {
            _iTrangThai = 2;
        }
        else if (_iSoLuongGheTrong > 0) {
            _iTrangThai = 1;
        }
    }
}

/********************************************
* @Description Hàm set Timestamp cho chuyến bay
* @attention Lấy thời gian khởi hành của chuyến bay, chuyển thành timestamp,
* sau đó cập nhật timestamp cho chuyến bay
********************************************/

template <class DataType>
void ChuyenBay<DataType>::setTimestamp() {
    string temp;
    stringstream s(_strNgayKhoiHanh);
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
        int convertTimestamp = convertDateToTimestamp(result[0], result[1], result[2], result[3], result[4], 0);
        _lTimestamp = convertTimestamp;
    }
}

/********************************************
* @Description Hàm get Timestamp của chuyến bay
********************************************/

template <class DataType>
long ChuyenBay<DataType>::getTimestamp() {
    return _lTimestamp;
}

/********************************************
* @Description Hàm sắp xếp danh sách vé của chuyến bay theo số ghế
* @parameter Loại muốn sắp xếp (type): 1 nếu tăng dần, -1 nếu giảm dần
********************************************/

template <class DataType>
void ChuyenBay<DataType>::sapXepDanhSachVe(int type) {
    if (type == -1) {
        //Giam Dan
        for (int i = 0; i < _iSoLuongVe - 1; i++) {
            for (int j = i + 1; j < _iSoLuongVe; j++) {
                if (_danhSachVe[j].getSoGhe() > _danhSachVe[i].getSoGhe()) {
                    swap(_danhSachVe[j], _danhSachVe[i]);
                }
            }
        }
    }
    else if (type == 1) {
        //Tang Dan
        for (int i = 0; i < _iSoLuongVe - 1; i++) {
            for (int j = i + 1; j < _iSoLuongVe; j++) {
                if (_danhSachVe[j].getSoGhe() < _danhSachVe[i].getSoGhe()) {
                    swap(_danhSachVe[j], _danhSachVe[i]);
                }
            }
        }
    }
}

/********************************************
* @Description Hàm sắp xếp danh sách ghế trống của chuyến bay theo số ghế
* @parameter Loại muốn sắp xếp (type): 1 nếu tăng dần, -1 nếu giảm dần
********************************************/

template <class DataType>
void ChuyenBay<DataType>::sapXepDanhSachGheTrong(int type) {
    if (type == 1) {
        //Tang Dan
        for (int i = 0; i < _iSoLuongGheTrong - 1; i++) {
            for (int j = i + 1; j < _iSoLuongGheTrong; j++) {
                if (_danhSachGheTrong[j] < _danhSachGheTrong[i]) {
                    swap(_danhSachGheTrong[j], _danhSachGheTrong[i]);
                }
            }
        }
    }
    else if (type == -1) {
        //Giam Dan
        for (int i = 0; i < _iSoLuongGheTrong - 1; i++) {
            for (int j = i + 1; j < _iSoLuongGheTrong; j++) {
                if (_danhSachGheTrong[j] > _danhSachGheTrong[i]) {
                    swap(_danhSachGheTrong[j], _danhSachGheTrong[i]);
                }
            }
        }
    }
}

/********************************************
* @Description Hàm chuyển thông tin của chuyến bay thành một chuỗi để ghi ra file
* @return Chuỗi thông tin của chuyến bay, ngăn cách bởi dấu "|" để chuẩn bị ghi file
********************************************/

template <class DataType>
string ChuyenBay<DataType>::thongTinFile() {
    string result = "";
    stringstream ss;
    ss << _iTrangThai;
    string trangThaiString;
    ss >> trangThaiString;
    string danhSachVeString = "";
    for (int i = 0; i < _iSoLuongVe; i++) {
        stringstream ss;
        ss << _danhSachVe[i].getSoGhe();
        string veString;
        ss >> veString;
        danhSachVeString = danhSachVeString + veString;
        if (i != _iSoLuongVe - 1) {
            danhSachVeString = danhSachVeString + ",";
        }
    }
    string danhSachGheTrongString = "";
    for (int i = 0; i < _iSoLuongGheTrong; i++) {
        stringstream ss;
        ss << _danhSachGheTrong[i];
        string gheTrongString;
        ss >> gheTrongString;
        danhSachGheTrongString = danhSachGheTrongString + gheTrongString;
        if (i != _iSoLuongGheTrong - 1) {
            danhSachGheTrongString = danhSachGheTrongString + ",";
        }
    }
    result = _strMaChuyenBay + "|" + _strSoHieuMayBay + "|" + _strNgayKhoiHanh + "|" + _strSanBayDen + "|" + trangThaiString + "|" + danhSachVeString + "|" + danhSachGheTrongString;
    return result;
}