#pragma once
#include "Header.h"
class NhanVien {
    string _strUsername;
    string _strPassword;
public:
    NhanVien();
    NhanVien(string username, string password);
    void display();
    string getUsername();
    string getPassword();
};

