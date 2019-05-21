#include "NhanVien.h"
#include <iostream>

NhanVien::NhanVien()
{
	cout << "Nhap ho ten nhan vien: ";
	getline(cin,hoTen);
	cout << "Nhap ngay thang nam sinh: ";
	getline(cin,bDay);
	luong = 0;
}