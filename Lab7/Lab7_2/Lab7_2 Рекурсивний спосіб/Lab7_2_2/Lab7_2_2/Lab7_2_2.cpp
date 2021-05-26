// Lab_7_2_2.cpp
// < Юлія Лазарів >
// Лабораторна робота № 7.2.2
// Опрацювання багатовимірних масивів рекурсивним способом
// Варіант 15

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void s1(int** a, int *min, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void s2(int** a, int *min, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
int sum(int *min, int size, int s, int i);


int main()
{
	srand((unsigned)time(NULL));
	int Low = 1;
	int High = 20;

	int rowCount;
	int colCount;

	cout << "rowCount="; cin >> rowCount;
	cout << "colCount="; cin >> colCount;

	int **a = new int*[rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);

	int*min = new int[rowCount];
	s1(a, min, rowCount, colCount, Low, High, 0, 0);

	int s = sum(min, rowCount, 0, 0);

	cout << "s=" << s << endl;
	system("pause");
	return 0;
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void s1(int** a, int *min, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	min[i] = a[i][0];
	s2(a, min, rowCount, colCount, Low, High, i, j);
	if (i < rowCount - 1)
	{
		s1(a, min, rowCount, colCount, Low, High, i + 1, j);
	}
}

void s2(int** a, int *min, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	if (a[i][j] < min[i])
	{
		min[i] = a[i][j];
	}
	if (j < colCount - 1)
	{
		s2(a, min, rowCount, colCount, Low, High, i, j + 1);
	}
}

int sum(int *min, int size, int s, int i)
{
	s = s + min[i];
	if (i < size - 1)
	{
		sum(min, size, s, i + 1);
	}
	else
		return s;
}