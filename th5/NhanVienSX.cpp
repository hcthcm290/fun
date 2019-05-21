#include "NhanVienSX.h"
#include <iostream>
#include <string>
using namespace std;

NhanVienSX::NhanVienSX()
{
	cout << "Nhap vao luong can ban: ";
	cin >> luongCB;
	cout << "Nhap vao so san pham: ";
	cin >> soSP;
}

double NhanVienSX::tinhLuong()
{
	cout << hoTen << ": " << bDay << ": ";
	luong = luongCB + soSP*5000;
	return luong;
}