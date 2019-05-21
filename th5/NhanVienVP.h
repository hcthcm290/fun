#pragma once
#include "NhanVien.h"

class NhanVienVP: public NhanVien
{
protected:
	int soNgay;
public:
	NhanVienVP();
	double tinhLuong();
};