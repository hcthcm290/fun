#pragma once
#include <iostream>
#include "CVector.h"

class CMatrix {
private:
	int row;
	int column;
	int **a;
public:
	CMatrix(int nrow, int ncolumn);
	CMatrix(const CMatrix &x);
	CMatrix();
	~CMatrix();
	CMatrix operator +(CMatrix& y);
	CMatrix operator=(const CMatrix& x);
	friend std::istream &operator>>(std::istream &input, CMatrix &x);
	friend std::ostream &operator<<(std::ostream &output, CMatrix &x);
	friend CMatrix multiply(const CMatrix &m, const CVector &v);
};
