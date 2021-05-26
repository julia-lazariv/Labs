// Lab_7_3_2.cpp
// < Юлія Лазарів >
// Лабораторна робота № 7.3.2
// Опрацювання динамічних багатовимірних масивів
// Варіант 15

#include<iostream>
#include<iomanip>
#include<time.h>

using namespace std;

void Input(int** a, const int rowCount, const int colCount);
void Create(int** a, const int n, const int k, const int Low, const int High);
void Print(int** a, const int n, const int k);
void Change(int** a, const int n, const int k);

int main()
{
	srand((unsigned)time(NULL));
	int Low = 0;
	int High = 5;
	int k, n;

	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;

	int** a = new int*[k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	Create(a, n, k, Low, High);
	Print(a, n, k);

	Change(a, n, k);
	Print(a, n, k);

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

void Change(int** a, const int n, const int k)
{
	int sum = 0, min = 0, temp;
	for (int i = 0; i < n; i++)
	{
		for (int l = 0; l < k; l++) {
			min += a[i][l];
		}
		for (int k = i + 1; k < n; k++)
		{
			for (int j = 0; j < k; j++)
			{
				sum += a[k][j];
			}
			if (sum < min)
			{
				min = sum;
				for (int j = 0; j < n; j++)
				{
					temp = a[i][j];
					a[i][j] = a[k][j];
					a[k][j] = temp;
				}
			}
			sum = 0;
		}
	}
}