#pragma once
#include "NhanVien.h"

class NhanVienSX: public NhanVien
{
protected:
	int luongCB;
	int soSP;
public:
	NhanVienSX();
	double tinhLuong();
};