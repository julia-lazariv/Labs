// Lab_7_3_1.cpp
// < Юлія Лазарів >
// Лабораторна робота № 7.3.1
// Опрацювання динамічних багатовимірних масивів
// Варіант 15

#include<iostream>
#include<iomanip>
#include<time.h>

using namespace std;

void Input(int** a, const int rowCount, const int colCount);
void Create(int** a, const int n, const int k, const int Low, const int High);
void Print(int** a, const int n, const int k);
int NumberNull(int** a, const int k, const int n);

int main() {
	srand((unsigned)time(NULL));
	int Low = -10;
	int High = 10;
	int k, n;

	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;

	int **a = new int * [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	Input(a, k, n);
	Print(a, n, k);

	NumberNull(a, k, n);
	cout << "N = " << NumberNull(a, k, n) << endl;

	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;

	system("pause");
	return 0;
}

void Create(int** a, const int n, const int k, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n, const int k)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void Input(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}

int NumberNull(int** a, const int k, const int n)
{
	int result = 0;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 0)
			{
				if (j < result) 
					result = j;
			}
		}
	}
	return result;
}