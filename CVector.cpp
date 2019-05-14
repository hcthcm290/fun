#include "pch.h"
#include "CVector.h"
#include "CMatrix.h"
//#include<iostream>

CVector::CVector()
{
	this->n = 2;
	this->a = new int[2];
	this->a[0] = 0;
	this->a[1] = 0;
}

CVector::CVector(int x, int y, int z)
{
	this->n = 3;
	this->a = new int[3];
	this->a[0] = x;
	this->a[1] = y;
	this->a[2] = z;
}

CVector::CVector(const CVector& b) {
	this->n = b.n;
	this->a = new int[this->n];
	for (size_t i = 0; i < this->n; i++)
	{
		this->a[i] = b.a[i];
	}
}

CVector::~CVector()
{
	delete[]a;
}

std::istream &operator>>(std::istream &input, CVector &x)
{
	std::cout << "so chieu = ";
	input >> x.n;
	std::cout << "nhap gia tri tung chieu " << std::endl;
	for (int i = 0; i < x.n; i++)
	{
		input >> x.a[i];
	}
	return input;
}

std::ostream &operator <<(std::ostream &output, CVector x)
{
	for (int i = 0; i < x.n; i++)
	{
		output << x.a[i];
		std::cout << "\t";
	}
	return output;
}

CVector CVector::operator+(const  CVector &x)
{
	CVector y;
	y.a = new int[x.n];
	y.n = x.n;
	for (int i = 0; i < n; i++)
	{
		y.a[i] = a[i] + x.a[i];
	}
	return y;
}

CVector CVector::operator=(const CVector &x)
{
	delete[]a;
	a = new int[x.n];
	n = x.n;
	for (int i = 0; i < n; i++)
	{
		a[i] = x.a[i];
	}
	return*this;
}
