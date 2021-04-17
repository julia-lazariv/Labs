// Lab_9_1_B.cpp
// < Юлія Лазарів >
// Лабораторна робота № 9.1(B)
// Послідовний пошук в масиві структур
// Варіант 15

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Spec { KN, IH, MM, FI, TT };
string specStr[] = { "Комп'ютерні науки", "Інформатика", "Математика та економіка", "Фізика та інформатика", "Трудове навчання" };

struct Student
{
	string prizv;
	unsigned kyrs;
	int mark1, mark2;
	Spec spec;
	union
	{
		int mark3, mark4, mark5;
	};
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
		cout << " спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): "; cin >> spec;
		cout << " Оцінки з фізики: "; cin >> p[i].mark1;
		cout << " Оцінки з математики: "; cin >> p[i].mark2;

		p[i].spec = (Spec)spec;
		switch (p[i].spec)
		{
		case KN:
			cout << " Оцінки з програмування: "; cin >> p[i].mark3;
			break;
		case IH:
			cout << " Оцінки з чисельних методів: "; cin >> p[i].mark4;
			break;
		case MM:
			cout << " Оцінки з педагогіки: "; cin >> p[i].mark5;
			break;
		case FI:
			cout << " Оцінки з педагогіки: "; cin >> p[i].mark5;
			break;
		case TT:
			cout << " Оцінки з педагогіки: "; cin >> p[i].mark5;
			break;
		}
		cout << endl;
	}
}

void Print(Student *p, const int N)
{
	cout <<
		"======================================================================================================================================================================================="
		<< endl;
	cout <<
		"| № | Прізвище студента |  Курс |      Спеціальність     |  Оцінка з фізики  |  Оцінка з математики  |  Оцінка з програмування  |  Оцінка з чисельних методів  |  Оцінка з педагогіки |"
		<< endl;
	cout <<
		"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;

	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(18) << left << p[i].prizv
			<< "| " << setw(5) << right << p[i].kyrs << " "
			<< "| " << setw(23) << right << specStr[p[i].spec]
			<< "| " << setw(18) << right << p[i].mark1
			<< "| " << setw(22) << right << p[i].mark2;
		switch (p[i].spec)
		{
		case KN:
			cout << "| " << setw(25) << right << p[i].mark3 << "|" << endl;
			break;
		case IH:
			cout << "| " << setw(56) << right << p[i].mark4 << "|" << endl;
			break;
		case MM:
			cout << "| " << setw(79) << right << p[i].mark5 << "|" << endl;
			break;
		case FI:
			cout << "| " << setw(79) << right << p[i].mark5 << "|" << endl;
			break;
		case TT:
			cout << "| " << setw(79) << right << p[i].mark5 << "|" << endl;
			break;
		}
	}
	cout <<
		"======================================================================================================================================================================================="
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