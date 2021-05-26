// Lab_11_1.cpp
// < ��� ������ >
// ����������� ������ � 11.1
// ������ �����
// ������ 15

#include <iostream>
#include <fstream> 
#include <string> 
#include <Windows.h>

using namespace std;

void CreateBIN(string filename)
{
	ofstream fout(filename, ios::binary);
	char ch;
	string s;
	do {
		cin.sync();
		cout << "enter line: "; cin.ignore(); getline(cin, s);
		for (unsigned i = 0; i < s.length(); i++)
			fout.write((char*)&s[i], sizeof(s[i]));
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void PrintBIN(string filename)
{
	ifstream fin(filename, ios::binary);
	char c;
	cout << "==========" << filename << "==========" << endl << endl;
	while (fin.read((char*)&c, sizeof(c)))
	{
		cout << c << " ";
	}
	cout << endl;
	cout << endl << "============================" << endl;
}

void ProcessBIN1(string filename)
{
	ifstream fin(filename, ios::binary);
	filename.insert(filename.end() - 4, '2');
	ofstream fout(filename, ios::binary);

	char  c;
	while (fin.read((char*)&c, sizeof(c)))
	{
		if (c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�')
			fout.write((char*)&c, sizeof(c));
	}
	fin.close();
	fout.close();
	PrintBIN(filename);
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string filename;
	cout << "Enter file name: "; cin >> filename;;
	cout << "1.Create a file and process\n2.Only file processing" << endl;
	int ch; cin >> ch;
	switch (ch)
	{
	case 1:
	{
		CreateBIN(filename);
		PrintBIN(filename);
		ProcessBIN1(filename);
		break;
	}
	case 2:
	{
		PrintBIN(filename);
		ProcessBIN1(filename);
		break;
	}
	default:
		break;
	}
	system("pause");
}