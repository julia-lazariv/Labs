// Lab_9_1_А.cpp
// < Юлія Лазарів >
// Лабораторна робота № 9.1(A)
// Послідовний пошук в масиві структур
// Варіант 15

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Spec { MM, IH, TT, KH };
string specStr[] = { "математика", "інформатика", "трудове навчання", "комп'ютерні науки" };

struct Student
{
	string prizv;
	unsigned kyrs;
	int mark1,
		mark2,
		mark3;
	Spec spec;
};

void Create(Student *p, const int N);
void Print(Student *p, const int N);
int AverageMark(Student *p, const int N, int i);
int MaxAverageMark(Student *p, const int N);
int Proc(Student *p, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int i = 0, N;
	cout << "Введіть N: "; cin >> N;
	Student *p = new Student[N];
	Create(p, N);
	Print(p, N);

	for (int i = 0; i < N; i++)
	{
		cout << "Середній бал для " << i << " студента: " << AverageMark(p, N, i) << endl;
	}
	cout << endl;
	cout << "Найбільший середній бал: " << MaxAverageMark(p, N) << endl;
	cout << endl << "Процент студентів, які отримали з фізики оцінки 4 або 5: " << Proc(p, N) << "%" << endl;
	cout << endl;

	system("pause");
	return 0;
}

void Create(Student *p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.sync();
		cout << " Прізвище студента: "; cin >> p[i].prizv;
		cout << " Курс: "; cin >> p[i].kyrs;
		cout << " спеціальність (0 - математика, 1 - інформатика, 2 - трудове навчання, 3 - комп'ютерні науки): ";
		cin >> spec;
		p[i].spec = (Spec)spec;
		cout << " Оцінки з фізики: "; cin >> p[i].mark1;
		cout << " Оцінки з математики: "; cin >> p[i].mark2;
		cout << " Оцінки з інформатики: "; cin >> p[i].mark3;
	}
}

void Print(Student *p, const int N)
{
	cout <<
		"===================================================================================================================="
		<< endl;
	cout <<
		"| № | Прізвище студента |  Курс |   Спеціальність  | Оцінка з фізики | Оцінка з математики | Оцінка з інформатики |"
		<< endl;
	cout <<
		"--------------------------------------------------------------------------------------------------------------------"
		<< endl;

	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(18) << left << p[i].prizv
			<< "| " << setw(5) << right << p[i].kyrs << " "
			<< "| " << setw(12) << right << specStr[p[i].spec]
			<< "| " << setw(16) << right << p[i].mark1
			<< "| " << setw(20) << right << p[i].mark2
			<< "| " << setw(21) << right << p[i].mark3
			<< "|" << setw(1) << right << endl;
	}
	cout <<
		"===================================================================================================================="
		<< endl;
	cout << endl;
}

int AverageMark(Student *p, const int N, int i)
{
	int average = 0,
		sum = 0;
	sum = p[i].mark1 + p[i].mark2 + p[i].mark3;
	average = sum / 3;

	return average;
}

int MaxAverageMark(Student *p, const int N)
{
	int average = 0,
		sum = 0,
		max = 0;
	for (int i = 0; i < N; i++)
	{
		sum = p[i].mark1 + p[i].mark2 + p[i].mark3;
		average = sum / 3;

		if (average > max)
			max = average;
	}
	return max;
}

int Proc(Student *p, const int N)
{
	int kilk = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].mark1 == 4 || p[i].mark1 == 5)
			kilk++;
	}
	kilk = (kilk * 100) / N;
	return kilk;
}