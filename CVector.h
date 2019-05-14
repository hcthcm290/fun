#pragma once
#include<iostream>

class CMatrix;

class CVector
{
private:
	int n;
	int *a;
public:
	CVector();
	~CVector();
	CVector(int x, int y, int z);
	CVector(const CVector& b);
	CVector operator+(const CVector &x);
	CVector operator=(const CVector &x);
	friend std::istream &operator>>(std::istream &input, CVector &x);
	friend std::ostream &operator<<(std::ostream &output, CVector x);
	friend CMatrix multiply(const CMatrix &m, const CVector &v);
};
