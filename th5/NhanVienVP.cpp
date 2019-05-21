#include "NhanVienVP.h"
#include <string>
#include <iostream>
using namespace std;

NhanVienVP::NhanVienVP()
{
	cout << "Nhap vao so ngay lam viec: ";
	cin >> soNgay;
}

double NhanVienVP::tinhLuong()
{
	cout << hoTen << ": " << bDay << ": ";
	luong = soNgay*100000;
	return luong;
}
