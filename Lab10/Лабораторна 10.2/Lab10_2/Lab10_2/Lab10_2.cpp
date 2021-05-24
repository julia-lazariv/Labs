// Lab_10_2.cpp
// < Юлія Лазарів >
// Лабораторна робота № 10.2
// Пошук слів у текстовому файлі
// Варіант 15

#include <iomanip>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void createtext(string filename)
{
	char ch;
	string s;
	ofstream fout;
	fout.open(filename);
	cin.sync();
	do
	{
		cin.ignore();
		cin.sync();
		cout << "enter line: ";
		cin.sync();
		getline(cin, s);
		fout << s << endl;
		cout << "continue? (y/n): ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
	fout.close();
}

void printttext(string filename)
{
	ifstream fin;
	fin.open(filename);
	string str;
	while (getline(fin, str))
	{
		cout << str << endl;
	}
	cout << endl << "Readind ended." << endl;
	fin.close();
}

void task(string filename)
{
	ifstream fin;
	fin.open(filename);
	string str;
	filename.insert((filename.size() - 4), "2");
	ofstream fout;
	fout.open(filename);
	bool canwrite = true;
	bool os = false;
	while (getline(fin, str))
	{
		cout << str << endl;
		if (!os)
		{
			int pos = str.find(" ", 0);
			if (pos != -1)
			{
				os = true;
				canwrite = false;

				for (int i = str.size() - 1; i >= 0; i--) {
					if (!isalpha(str[i]))
					{
						str.erase(i, 1);
					}
				}

				fout << str.substr(pos) << endl;
				continue;
			}
		}
		
		if (canwrite)
		{
			fout << str << endl;
		}
		else fout << "";
	}
	fin.close();
	fout.close();
	cout << "Done.Changed text has beem written in " << filename << endl;
	cout << endl << endl;
	ifstream fin2;
	fin2.open(filename);
	cout << "Resulting file: " << endl;
	string str2;
	while (getline(fin2, str2))
	{
		cout << str2 << endl;
	}
	cout << "Done" << endl;
}

void main()
{
	srand(time(NULL));
	string filename;
	cout << "Enter filename: ";
	cin.sync();
	getline(cin, filename);
	cout << "Menu\n1.Enter some text\n2.print text\n3.task" << endl;
	int ch; cin >> ch;
	switch (ch)
	{
	case 1:
	{
		createtext(filename);
		break;
	}
	case 2:
	{
		printttext(filename);
		break;
	}
	case 3:
	{
		task(filename);
		break;
	}
	default:
		break;
	}
	system("pause");
}