#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

class temp
{
private:
	friend class dataBass;
	char name[10];
	int value;
public:
	void input();
	void print();
};

class dataBass
{
private:
	int number = 0;
	temp info[100];

public:
	void input();
};

int main()
{
	dataBass a;
	a.input();
	return 0;
}

void temp::input()
{
	cout << "Enter name: ";
	gets_s(this->name, 10);
	cout << "Enter value: ";
	cin >> this->value;
	cin.ignore(256, '\n');
}

void temp::print()
{
	cout << this->name << "\t" << "|";
	for (int i = 0; i < this->value; i++)
	{
		cout << "=";
	}
	cout << endl;
}

void dataBass::input()
{
	while (true)
	{
		cout << "(l)oad (s)ave (a)dd (q)uit ot (p)rint ?";
		char temp;
		do
		{
			temp = _getch();
		} while (temp != 'l' && temp != 's' && temp != 'a' && temp != 'q' && temp != 'p');

		cout << endl;
		if (temp == 'a')
		{
			int i = this->number;
			this->info[i].input();
			this->number += 1;
		}
		else if (temp == 'p')
		{
			for (int i = 0; i < this->number; i++)
			{
				this->info[i].print();
			}
		}
		else if (temp == 'q')
		{
			break;
		}
		else if (temp == 's')
		{
			string s;
			cout << "Enter the file name: ";
			getline(cin, s);
			ofstream file(s.c_str(), ios::binary);
			for (int i = 0; i < this->number; i++)
			{
				file.write(this->info[i].name, sizeof(this->info[i].name));
				file.write(reinterpret_cast<const char*>(&(this->info[i].value)), sizeof(int));
			}
		}
		else if (temp == 'l')
		{
			string line;
			getline(cin, line);
			ifstream file(line.c_str(), ios::binary);
			int temp = 0;
			while(file.good())
			{
				if (temp % 2 == 0)
				{
					char p[10];
					file.read(p, sizeof(p));
					if (file.good())
					{
						cout << p << " ";
						temp += 1;
					}
				}
				else if (temp % 2 != 0)
				{
					int data;
					file.read(reinterpret_cast<char*>(&data), sizeof(int));
					if (file.good())
					{
						cout << data;
						temp += 1;
						cout << endl;
					}
				}
			}
		}
	}
}