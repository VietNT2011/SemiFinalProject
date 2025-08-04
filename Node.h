#pragma once
template <class DataType>
class Queue;
template <class DataType>
class LinkedList;
template <class DataType>
class DanhSachMayBay;
template <class DataType>
class DanhSachVeSuccess;
template <class DataType>
class DanhSachKhachHang;
template <class DataType>
class DanhSachNhanVien;
template <class DataType>
class Node {
    friend Queue<DataType>;
    friend LinkedList<DataType>;
    friend DanhSachMayBay<DataType>;
    friend DanhSachVeSuccess<DataType>;
    friend DanhSachKhachHang<DataType>;
    friend DanhSachNhanVien<DataType>;
    DataType _data;
    Node* _pNext;
public:
    Node(DataType data);
    void display();
    void displayDetail();

};