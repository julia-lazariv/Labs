// Lab_9_2(2).cpp
// < ��� ������ >
// ����������� ������ � 9.2(2)
// �������������(��������) ������ ��������
// ������ 15

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Cpes { KOMP, INFORM, MATANEKONOM, FIZIKA, TRUDOVE };
string posadaStr[] = { "��", "����������a", "���������� ��������" ,"Գ���a" ,"������� ��������" };

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
int *IndexSort(Pracivnyk *p, const int N);
void PrintIndexSorted(Pracivnyk *p, int *I, const int N);
int serbal1(Pracivnyk *p, const int N, int i);
double func(Pracivnyk *p, const int N, int i);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "������ N: "; cin >> N;

	Pracivnyk *p = new Pracivnyk[N];
	int menuItem;

	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - �������� ������������� �� ���� �����"
			<< endl << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
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
			PrintIndexSorted(p, IndexSort(p, N), N);
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);

	return 0;
}

void Create(Pracivnyk *p, const int N)
{
	int posada;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.sync();
		cout << " �������: "; cin >> p[i].prizv;
		cout << " �� ����������: "; cin >> p[i].rik_nar;
		cout << " ����: "; cin >> p[i].kurs;
		cout << " ������������ (0 - ��, 1 - ����������� , 2 - ����������): ";
		cin >> posada;
		p[i].cpes = (Cpes)posada;
		switch (p[i].cpes)
		{
		case KOMP:
			cout << "�������������: "; cin >> p[i].prog;
			break;
		case INFORM:
			cout << "�����������: "; cin >> p[i].chiselniMetod;
			break;
		case MATANEKONOM:
		case FIZIKA:
		case TRUDOVE:
			cout << "���������: "; cin >> p[i].pedagogic;
			break;
		}
		cout << "������: "; cin >> p[i].fizik;
		cout << "����������: "; cin >> p[i].matem;
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
		"| � | �������        | г�.���. | ���� | ������������       | ������������� | ������� ������ | ��������� | ������ | ���������� |"
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
int *IndexSort(Pracivnyk *p, const int N)
{
	int *I = new int[N];
	for (int i = 0; i < N; i++)
		I[i] = i;
	int i, j, value;
	for (i = 1; i < N; i++)
	{
		value = I[i];
		for (j = i - 1;
			j >= 0 &&
			(p[I[j]].serbal < p[value].serbal
				||
				(p[I[j]].serbal == p[value].serbal && 
					p[I[j]].matem < p[value].matem)
				||
				(p[I[j]].serbal == p[value].serbal && 
					p[I[j]].matem == p[value].matem && 
					p[I[j]].prizv > p[value].prizv));
			j--)
		{
			I[j + 1] = I[j];
		}
		I[j + 1] = value;
	}
	return I;
}void PrintIndexSorted(Pracivnyk *p, int *I, const int N)
{
	cout <<
		"===================================================================================================================================="
		<< endl;
	cout <<
		"| � | �������        | г�.���. | ���� | ������������       | ������������� | ������� ������ | ��������� | ������ | ���������� |"
		<< endl;
	cout <<
		"------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(16) << left << p[I[i]].prizv
			<< "| " << setw(8) << right << p[I[i]].rik_nar << " "
			<< "| " << setw(5) << left << p[I[i]].kurs
			<< "| " << setw(19) << left << posadaStr[p[I[i]].cpes];
		switch (p[I[i]].cpes)
		{

		case KOMP:
			cout << " | " << setw(14) << setprecision(2) << fixed << right << p[I[i]].prog << "| " << setw(17) << " |" << setw(13) << " |";
			break;

		case INFORM:

			cout << setw(16) << " |" << setw(8) << " |" << setw(10) << setprecision(2) << fixed << right << p[I[i]].chiselniMetod << " |" << setw(13) << " |";
			break;

		case MATANEKONOM:
			cout << setw(15) << "|" << setw(18) << " |" << setw(5) << " |" << setw(9) << setprecision(1) << fixed << right << p[I[i]].pedagogic << "|";
			break;
		case FIZIKA:
		case TRUDOVE:
			cout << setw(16) << " |" << setw(18) << " |" << setw(5) << " |" << setw(9) << setprecision(1) << fixed << right << p[I[i]].pedagogic << "|";
			break;
		}
		cout << setw(8) << right << p[I[i]].fizik

			<< "| " << setw(10) << right << p[I[i]].matem << " |" << endl;

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