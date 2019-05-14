#include "pch.h"
#include "CMatrix.h"
#include<iostream>

CMatrix::CMatrix(int nrow, int ncolumn) {
	this->row = nrow;
	this->column = ncolumn;

	a = new int*[row];

	for (int i = 0; i < row; ++i)
		a[i] = new int[column];

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < column; j++)
		{
			if (i == j) {
				a[i][j] = 1;
			}
			else {
				a[i][j] = 0;
			}
		}
	}
}

CMatrix::CMatrix()
{
	row = 0;
	column = 0;
}


CMatrix::~CMatrix()
{
	for (int i = 0; i < row; ++i)
		delete[]a[i];
	delete[]a;
}
std::istream &operator>>(std::istream &input, CMatrix &x) 
{
	std::cout << "n = "; input >> x.row;
	std::cout << "m = "; input >> x.column;
	x.a = new int*[x.row];
	for (int i = 0; i < x.row; ++i)
		x.a[i] = new int[x.column];
	for (int i = 0; i < x.row; i++)
	{
		for (int j = 0; j < x.column; j++)
		{
			std::cout << "a[" << i << "]" << "[" << j << "] = ";
			input >> x.a[i][j];
		}
	}
	return input;
}
std::ostream &operator<<(std::ostream &output, CMatrix &x) {
	for (int i = 0; i < x.row; i++)
	{
		for (int j = 0; j < x.column; j++)
		{
			std::cout << "a[" << i << "]" << "[" << j << "] = ";

			output << x.a[i][j];
			std::cout << "\n";

		}
	}
	return output;
}

CMatrix CMatrix::operator+(CMatrix& y)
{
	CMatrix x;
	x.row = row;
	x.column = column;
	x.a = new int*[x.row];
	for (int i = 0; i < x.row; i++)
		x.a[i] = new int[x.column];
	for (int i = 0; i < x.row; i++)
	{
		for (int j = 0; j < x.column; j++)
		{
			x.a[i][j] = a[i][j] + y.a[i][j];
		}
	}
	return x;
}
CMatrix CMatrix::operator=(const CMatrix & x)
{
	// delete old matrix this //
	for (int i = 0; i < row; i++)
		delete[]a[i];
	delete[]a;

	// make a new matrix //
	this->column = x.column;
	this->row = x.row;
	a = new int*[row];
	for (int i = 0; i < row; i++)
		a[i] = new int[column];

	// copy from x to this //
	for(int i=0; i< row; i++)
		for (int j = 0; j < column; j++)
		{
			this->a[i][j] = x.a[i][j];
		}
	return *this;
}
CMatrix::CMatrix(const CMatrix &x) 
{
	this->row = x.row;
	this->column = x.column;
	this->a = new int*[this->row];
	for (int i = 0; i < this->row; i++)
		this->a[i] = new int[this->column];
	for (int i = 0; i < x.row; i++)
	{
		for (int j = 0; j < x.column; j++)
		{
			a[i][j] = x.a[i][j];
		}
	}
}

CMatrix multiply(const CMatrix & m, const CVector & v)
{
	CMatrix c;
	c.a = new int *[m.row];
	for (int i = 0; i < m.column; i++)
		c.a[i] = new int[m.row];
	for (int i = 0; i < m.row; i++)
	{
		for (int j = 0; j < m.row; j++)
			c.a[i][j] = m.a[i][j] * v.a[j];
	}
	return c;
}