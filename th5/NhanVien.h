#pragma once
#include <string>
using namespace std;

class NhanVien
{
protected:
	string hoTen;
	string bDay;
	double luong;
public:
	NhanVien();
	virtual double tinhLuong() = 0;
};