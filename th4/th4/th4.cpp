#include "pch.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

class temp
{
private:
	friend class dataBass;
	string name;
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
	char *string;
	string = new char[256];
	cin >> string;
	cout << string;
	return 0;
}

void temp::input()
{
	cout << "Enter name: ";
	getline(cin, this->name);
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
			ofstream file(s.c_str(),ios::binary);
			for (int i = 0; i < this->number; i++)
			{
				for (int f = 0; this->info[i].name[f]; f++)
				{
					file.put(this->info[i].name[f]);
				}
				file.put('\n');
				file.write(reinterpret_cast<const char*>(&(this->info[i].value)), sizeof(int));
				file.put('\n');
			}
		}
		else if (temp == 'l')
		{
			string line;
			getline(cin, line);
			ifstream file(line.c_str(),ios::binary);
			int temp = 0;
			for (char c = file.get(); file.good(); c=file.get())
			{
				if (c == '\n')
				{
					temp += 1;
					cout << endl;
				} 
				else if (temp % 2 == 0)
				{
					cout << c;
				}
				else if (temp % 2 != 0)
				{
					int data;
					file.read(reinterpret_cast<char*>(&data), sizeof(int));
					cout << data;
					cout << endl;
				}
			}
		}
	}
}
