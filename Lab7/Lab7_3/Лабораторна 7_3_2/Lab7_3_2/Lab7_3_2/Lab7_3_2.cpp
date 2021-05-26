// Lab_7_3_2.cpp
// < Юлія Лазарів >
// Лабораторна робота № 7.3.2
// Опрацювання динамічних багатовимірних масивів
// Варіант 15

#include<iostream>
#include<iomanip>
#include<time.h>

using namespace std;

void InputRow(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << "a[" << rowNo << "][" << colNo << "] = ";
	cin >> a[rowNo][colNo];
	if (colNo < colCount - 1)
		InputRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}

void InputRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	InputRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		InputRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}

void Create(int** a, const int k, const int n, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < n - 1)
		Create(a, k, n, Low, High, i, j + 1);
	else
		if (i < k - 1)
			Create(a, k, n, Low, High, i + 1, 0);
}

void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < colCount - 1)
		PrintRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}

void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	PrintRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		PrintRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}

int Nul(int** a, const int k, const int colCount, int j, int result, int I)
{
	if (a[j][k] == 0)
		result = j;
	if (j < colCount - 1)
		Nul(a, k, colCount, j + 1, result, I);
	else
		return 0;
}

int NumberNull(int** a, const int k, const int n, int S, int i)
{
	int result = 0;
	if (Nul(a, i, k, 0, result, 0) > 0)
		S++;
	if (i < n - 1)
		NumberNull(a, k, n, S, i + 1);
	else
		return S;
}

int main()
{
	srand((unsigned)time(NULL));
	int Low = -9;
	int High = 9;
	int k, n;

	cout << "rowCount = "; cin >> k;
	cout << "colCount = "; cin >> n;

	int **a = new int * [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	InputRows(a, k, n, 0);
	PrintRows(a, k, n, 0);

	int S = 0;
	cout << "N = " << NumberNull(a, k, n, S, 0) << endl;

	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;

	system("pause");
	return 0;
}