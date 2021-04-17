// Lab_10_1.cpp
// < Юлія Лазарів >
// Лабораторна робота № 10.1
// Пошук символів у текстовому файлі
// Варіант 15

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CreateTXT(char* fname) 
{
	ofstream fout(fname);
	char ch; 
	string s; 
	cout << endl;
	do
	{
		cin.get(); 
		cin.sync();
		cout << "enter line: "; getline(cin, s); 
		fout << s << endl; 
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void PrintTXT(char* fname) 
{
	ifstream fin(fname);
	string s;
	while (getline(fin, s))
	{
		cout << s << endl;
	}
	cout << endl;
}

bool Search(char* fname)
{
	ifstream fin(fname);
	string s;
	bool k = false;
	while (getline(fin, s))
	{
		for (unsigned i = 0; i < s.length(); i++)
		{
			if (s[i] == '*' && s[i + 1] == '*' && s[i + 2] == '*')
				k = true;
		}
	}
	return k;
}

int main()
{
	char fname[100];
	cout << "enter file name: "; cin >> fname;

	CreateTXT(fname); 
	PrintTXT(fname);

	cout << "0 - false, 1 - true " << endl;
	cout << "Group of three '*' in this file: " << Search(fname) << endl;
	cout << endl;

	system("pause");
	return 0;
}