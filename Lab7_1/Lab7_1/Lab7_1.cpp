// Lab_7_1.cpp
// < Юлія Лазарів >
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 15
#include <iostream>
#include <iomanip>
#include <time.h>
#include "windows.h"
#include <string>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{
	// для виводу і зчитування української мови
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));

	int Low = -34;
	int High = 26;

	int rowCount = 8;
	int colCount = 6;

	int **a = new int*[rowCount];

	for (int i = 0; i < rowCount; i++)
	{
		a[i] = new int[colCount];
	}
	Create(a, rowCount, colCount, Low, High);
	cout << endl;
	cout << "-------- Початкова матриця -------- " << endl;
	Print(a, rowCount, colCount);

	cout << "-------- Посортована матриця -------- " << endl;
	Sort(a, rowCount, colCount);
	Print(a, rowCount, colCount);

	int S = 0;
	int k = 0;
	Calc(a, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	cout << "-------- Макриця критеріїв -------- " << endl;
	Print(a, rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
	{
		delete[] a[i];
	}

	delete[] a;

	string str;
	getline(cin, str);

	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			a[i][j] = Low + rand() % (High - Low + 1);
		}
	}
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Sort(int** a, const int rowCount, const int colCount)
{
	for (int j0 = 0; j0 < colCount - 1; j0++)
	{
		for (int j1 = 0; j1 < colCount - j0 - 1; j1++)
		{
			if ((a[j1][0] < a[j1 + 1][0]) // 1 умова
				||
				(a[j1][0] == a[j1 + 1][0] &&
					a[j1][1] < a[j1 + 1][1]) // 2 умова
				||
				(a[j1][0] == a[j1 + 1][0] &&
					a[j1][1] == a[j1 + 1][1] &&
					a[j1][2] < a[j1 + 1][2])) // 3 умова
			{
				Change(a, j1, j1 + 1, rowCount);
			}
		}
	}
}

void Change(int** a, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = a[row1][j];
		a[row1][j] = a[row2][j];
		a[row2][j] = tmp;
	}
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			if (a[i][j] > 0 || !(a[i][j] % 2 != 0))
			{
				S += a[i][j];
				k++;
				a[i][j] = 0;
			}
		}
	}
}