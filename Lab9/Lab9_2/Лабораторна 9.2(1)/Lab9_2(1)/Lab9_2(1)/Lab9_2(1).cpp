// Lab_9_2_1.cpp
// < Юлія Лазарів >
// Лабораторна робота № 9.2(1)
// Впорядкування(фізичне) та бінарний пошук в масиві структур
// Варіант 15

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Cpes { KOMP, INFORM, MATANEKONOM, FIZIKA, TRUDOVE };
string posadaStr[] = { "Кn", "Інформатиka", "Математика економіка" ,"Фізикa" ,"Трудове навчання" };

struct Pracivnyk
{
	string prizv;
	unsigned rik_nar;
	int kurs;
	Cpes cpes;
	union
	{
		int prog;
		int chiselniMetod;
		int pedagogic;
	};
	int fizik;
	int matem;
	int serbal;
	int func;
};

void Create(Pracivnyk *p, const int N);
void Print(Pracivnyk *p, const int N);
void Sort(Pracivnyk *p, const int N);
void PrintSort(Pracivnyk *p, const int N);
int serbal1(Pracivnyk *p, const int N, int i);
int func(Pracivnyk *p, const int N, int i);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть N: "; cin >> N;

	Pracivnyk *p = new Pracivnyk[N];
	int menuItem;

	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - фізичне впорядкування даних" << endl << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			Sort(p, N);
			PrintSort(p, N);
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);

	return 0;
}

void Create(Pracivnyk *p, const int N)
{
	int posada;
	for (int i = 0; i < N; i++)
	{
		cout << "студент № " << i + 1 << ":" << endl;
		cin.sync();
		cout << " прізвище: "; cin >> p[i].prizv;
		cout << " рік народження: "; cin >> p[i].rik_nar;
		cout << " курс: "; cin >> p[i].kurs;
		cout << " спеціальність (0 - kn,1 - inform , 3 - matan): ";
		cin >> posada;
		p[i].cpes = (Cpes)posada;
		switch (p[i].cpes)
		{
		case KOMP:
			cout << " ПРОГРАМУВАННЯ : "; cin >> p[i].prog;
			break;
		case INFORM:
			cout << "informatika  : "; cin >> p[i].chiselniMetod;
			break;
		case MATANEKONOM:
		case FIZIKA:
		case TRUDOVE:
			cout << " педагогіка : "; cin >> p[i].pedagogic;
			break;
		}
		cout << " фізика : "; cin >> p[i].fizik;
		cout << " матан : "; cin >> p[i].matem;
		p[i].serbal = serbal1(p, N, i);
		p[i].func = func(p, N, i);
		cout << endl;
	}
}

void Print(Pracivnyk *p, const int N)
{
	cout <<
		"===================================================================================================================================="
		<< endl;
	cout <<
		"| № | Прізвище        | Рік.нар. | Курс | спеціальність       | Програмування | Чисельні методи | педагогіка | фізика | Математика |"
		<< endl;
	cout <<
		"------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(16) << left << p[i].prizv
			<< "| " << setw(8) << right << p[i].rik_nar << " "
			<< "| " << setw(5) << left << p[i].kurs
			<< "| " << setw(19) << left << posadaStr[p[i].cpes];
		switch (p[i].cpes)
		{

		case KOMP:
			cout << " | " << setw(14) << setprecision(2) << fixed << right << p[i].prog << "| " << setw(17) << " |" << setw(13) << " |";
			break;

		case INFORM:

			cout << setw(16) << " |" << setw(8) << " |" << setw(10) << setprecision(2) << fixed << right << p[i].chiselniMetod << " |" << setw(13) << " |";
			break;

		case MATANEKONOM:
			cout << setw(15) << "|" << setw(18) << " |" << setw(5) << " |" << setw(9) << setprecision(1) << fixed << right << p[i].pedagogic << "|";
			break;
		case FIZIKA:
		case TRUDOVE:
			cout << setw(16) << " |" << setw(18) << " |" << setw(5) << " |" << setw(9) << setprecision(1) << fixed << right << p[i].pedagogic << "|";
			break;
		}
		cout << setw(8) << right << p[i].fizik

			<< "| " << setw(10) << right << p[i].matem << " |" << endl;

	}
	cout <<
		"====================================================================================================================================";
	cout << endl;
}
int serbal1(Pracivnyk *p, const int N, int i)
{
	int k = 0;
	k = p[i].fizik + p[i].matem;
	if (p[i].cpes == KOMP)
	{
		k = k + p[i].prog;
	}
	if (p[i].cpes == INFORM)
	{
		k = k + p[i].chiselniMetod;
	}
	if (p[i].cpes == MATANEKONOM || p[i].cpes == FIZIKA || p[i].cpes == TRUDOVE)
	{
		k = k + p[i].pedagogic;
	}
	return k / 3;
}

int func(Pracivnyk *p, const int N, int i)
{
	if (p[i].cpes == KOMP)
	{
		return p[i].prog;
	}
	if (p[i].cpes == INFORM)
	{
		return p[i].chiselniMetod;

	}
	if (p[i].cpes == MATANEKONOM || p[i].cpes == FIZIKA || p[i].cpes == TRUDOVE)
	{
		return p[i].pedagogic;
	}
	return 0;
}

void Sort(Pracivnyk *p, const int N)
{
	Pracivnyk tmp;
	for (int i0 = 0; i0 < N - 1; i0++)
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((serbal1(p, N, i1) < serbal1(p, N, i1 + 1))
				||
				(serbal1(p, N, i1) == serbal1(p, N, i1 + 1)) &&
				(p[i1].matem < p[i1 + 1].matem)
				||
				(serbal1(p, N, i1) == serbal1(p, N, i1 + 1)) &&
				(p[i1].matem == p[i1 + 1].matem) &&
				p[i1].prizv > p[i1 + 1].prizv)

			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}void PrintSort(Pracivnyk *p, const int N)
{
	cout <<
		"===================================================================================================================================="
		<< endl;
	cout <<
		"| № | Прізвище        | Рік.нар. | Курс | спеціальність       | Програмування | Чисельні методи | педагогіка | фізика | Математика |"
		<< endl;
	cout <<
		"------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(16) << left << p[i].prizv
			<< "| " << setw(8) << right << p[i].rik_nar << " "
			<< "| " << setw(5) << left << p[i].kurs
			<< "| " << setw(19) << left << posadaStr[p[i].cpes];
		switch (p[i].cpes)
		{

		case KOMP:
			cout << " | " << setw(14) << setprecision(2) << fixed << right << p[i].prog << "| " << setw(17) << " |" << setw(13) << " |";
			break;

		case INFORM:

			cout << setw(16) << " |" << setw(8) << " |" << setw(10) << setprecision(2) << fixed << right << p[i].chiselniMetod << " |" << setw(13) << " |";
			break;

		case MATANEKONOM:
			cout << setw(15) << "|" << setw(18) << " |" << setw(5) << " |" << setw(9) << setprecision(1) << fixed << right << p[i].pedagogic << "|";
			break;
		case FIZIKA:
		case TRUDOVE:
			cout << setw(16) << " |" << setw(18) << " |" << setw(5) << " |" << setw(9) << setprecision(1) << fixed << right << p[i].pedagogic << "|";
			break;
		}
		cout << setw(8) << right << p[i].fizik

			<< "| " << setw(10) << right << p[i].matem << " |" << endl;
	}
	cout <<
		"====================================================================================================================================";
	cout << endl;
}