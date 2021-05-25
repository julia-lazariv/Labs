// Lab_9_2(3).cpp
// < Юлія Лазарів >
// Лабораторна робота № 9.2(3)
// Бінарний пошук у впорядкованому масиві структур
// Варіант 15

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Cpes { KOMP, INFORM, MATANEKONOM, FIZIKA, TRUDOVE };
string posadaStr[] = { "КН", "Інформатикa", "Математика економіка" ,"Фізикa" ,"Трудове навчання" };

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
int BinSearch(Pracivnyk *p, const int N, const string prizv, const int posada, int ser);
int serbal1(Pracivnyk *p, const int N, int i);
double func(Pracivnyk *p, const int N, int i);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть N: "; cin >> N;

	Pracivnyk *p = new Pracivnyk[N];
	int menuItem;

	int matem = 0;
	string prizv;
	int found;	int ser;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - бінарний пошук студента" << endl << endl;
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
			cout << "Введіть ключі пошуку:" << endl;

			cout << "прізвище: " << endl;
			cin >> prizv;

			cout << "Середній бал: " << endl;
			cin >> ser;

			cout << "Оцінка з математики: " << endl;
			cin >> matem;

			if ((found = BinSearch(p, N, prizv, ser, matem)) != -1)
				cout << "Знайдено студента в позиції " << found + 1 << endl;
			else
				cout << "Шуканого студента не знайдено" << endl;
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
		cout << " спеціальність (0 - КН, 1 - Інформатика , 2 - Математика): ";
		cin >> posada;
		p[i].cpes = (Cpes)posada;
		switch (p[i].cpes)
		{
		case KOMP:
			cout << "програмування: "; cin >> p[i].prog;
			break;
		case INFORM:
			cout << "інформатика: "; cin >> p[i].chiselniMetod;
			break;
		case MATANEKONOM:
		case FIZIKA:
		case TRUDOVE:
			cout << "педагогіка: "; cin >> p[i].pedagogic;
			break;
		}
		cout << "фізика: "; cin >> p[i].fizik;
		cout << "математика: "; cin >> p[i].matem;
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
		"| № | Прізвище        | Рік.нар. | Курс | спеціальність       | програмування | чисельні методи | педагогіка | фізика | математика |"
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
}int BinSearch(Pracivnyk *p, const int N, const string prizv, int ser, int matem)
{
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (p[m].prizv == prizv && serbal1(p, N, m) == ser && p[m].matem == matem)
			return m;

		if ((p[m].prizv < prizv)
			||
			(p[m].prizv == prizv &&
				serbal1(p, N, m) < ser)
			|| (p[m].prizv == prizv &&
				serbal1(p, N, m) == ser &&
				p[m].matem < matem))
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
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

double func(Pracivnyk *p, const int N, int i)
{
	int k = 0;
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