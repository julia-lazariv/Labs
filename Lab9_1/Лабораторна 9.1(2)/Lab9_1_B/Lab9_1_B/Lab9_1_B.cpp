// Lab_9_1_B.cpp
// < ��� ������ >
// ����������� ������ � 9.1(B)
// ���������� ����� � ����� ��������
// ������ 15

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Spec { KN, IH, MM, FI, TT };
string specStr[] = { "����'����� �����", "�����������", "���������� �� ��������", "Գ���� �� �����������", "������� ��������" };

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
	cout << "������ N: "; cin >> N;
	Student *p = new Student[N];

	Create(p, N);
	Print(p, N);

	for (int i = 0; i < N; i++)
	{
		cout << "������� ��� ��� " << i << " ��������: " << AverageMark(p, N, i) << endl;
	}

	cout << endl;
	cout << "��������� ������� ���: " << MaxAverageMark(p, N) << endl;
	cout << endl << "������� ��������, �� �������� � ������ ������ 4 ��� 5: " << Proc(p, N) << "%" << endl;
	cout << endl;

	system("pause");
	return 0;
}

void Create(Student *p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.sync();
		cout << " ������� ��������: "; cin >> p[i].prizv;
		cout << " ����: "; cin >> p[i].kyrs;
		cout << " ������������ (0 - ����'����� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): "; cin >> spec;
		cout << " ������ � ������: "; cin >> p[i].mark1;
		cout << " ������ � ����������: "; cin >> p[i].mark2;

		p[i].spec = (Spec)spec;
		switch (p[i].spec)
		{
		case KN:
			cout << " ������ � �������������: "; cin >> p[i].mark3;
			break;
		case IH:
			cout << " ������ � ��������� ������: "; cin >> p[i].mark4;
			break;
		case MM:
			cout << " ������ � ���������: "; cin >> p[i].mark5;
			break;
		case FI:
			cout << " ������ � ���������: "; cin >> p[i].mark5;
			break;
		case TT:
			cout << " ������ � ���������: "; cin >> p[i].mark5;
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
		"| � | ������� �������� |  ���� |      ������������     |  ������ � ������  |  ������ � ����������  |  ������ � �������������  |  ������ � ��������� ������  |  ������ � ��������� |"
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