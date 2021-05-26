// Lab_10_4.cpp
// < Юлія Лазарів >
// Лабораторна робота № 10.4
// Опрацювання рядків текстового файлу
// Варіант 15

#include <iomanip>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void printfile(string filename);
string getbiggestword(string str);
string getstrtowrite(string);
void task(string);

void main()
{
	srand(time(NULL));
	string filename;
	cout << "Enter filename: "; cin >> filename;
	printfile(filename);
	task(filename);

	system("pause");
}

void printfile(string filename)
{
	ifstream fin;
	fin.open(filename);
	cout << "===============" << filename << "===============" << endl << endl;
	string str;
	while (getline(fin, str))
	{
		cout << str << endl;
	}
	cout << endl << "======================================" << endl << endl;
	fin.close();
}

string getbiggestword(string str)
{
	int prevsize, size;
	string word;
	string longestword = "";
	for (size_t i = 0; i < str.size(); i++)
	{
		int j = str.find(" ", i);
		if (j != -1)
		{
			word = str.substr(i, j - i);
			if (word.size() > longestword.size())
				longestword = word;
			i = j;
		}
		else
		{
			word = str.substr(i, str.size() - i);
			if (word.size() > longestword.size())
				longestword = word;
			cout << word << endl;
			break;
		}
	}
	return longestword;
}

void task(string filename)
{
	cout << "Processing..." << endl;
	string str;
	ifstream fin;
	fin.open(filename);
	filename.insert(filename.end() - 4, '2');
	ofstream fout;
	fout.open(filename);
	int iter = 0;
	string wordtowrite;

	while (getline(fin, str))
	{
		if (iter % 2 == 0)
		{
			wordtowrite = getbiggestword(str);
			fout << str << endl;
		}
		else
		{
			fout << str + wordtowrite << endl;
		}
		iter++;
	}
	fin.close();
	fout.close();
	cout << "Done." << endl;
	cout << "Result:" << endl;
	printfile(filename);
}