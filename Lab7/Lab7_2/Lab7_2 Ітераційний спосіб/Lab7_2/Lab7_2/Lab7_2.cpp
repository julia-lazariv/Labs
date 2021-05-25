// Lab_7_2.cpp
// < Юлія Лазарів >
// Лабораторна робота № 7.2(1).
// Опрацювання багатовимірних масивів ітераційним способом
// Варіант 15

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void swap(int** a, const int rowCount, const int colCount);

int main()
{
	srand((unsigned)time(NULL));
	int Low = 1;
	int High = 20;

	int rowCount;
	int colCount;

	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	cout << endl;

	int **a = new int*[rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	cout << "Start matrix = " << endl;
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);

	cout << "Swap matrix = " << endl;
	swap(a, rowCount, colCount);
	Print(a, rowCount, colCount);

	system("pause");
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void swap(int** a, const int rowCount, const int colCount)
{
	int i, j, c, max, min;
	for (i = 0; i < rowCount; i += 2)
	{
		c = 0;
		max = 0;
		min = 0;
		for (j = 0; j < colCount; ++j)
		{
			if (a[i][min] > a[i][j])
			{
				min = j;
			}
			else if (a[i][max] < a[i][j])
			{
				max = j;
			}
		}
		c = a[i][min];
		a[i][min] = a[i][max];
		a[i][max] = c;
	}
}