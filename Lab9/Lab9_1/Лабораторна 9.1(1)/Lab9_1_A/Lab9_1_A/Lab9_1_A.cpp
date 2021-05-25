// Lab_9_1_�.cpp
// < ��� ������ >
// ����������� ������ � 9.1(A)
// ���������� ����� � ����� ��������
// ������ 15

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Spec { MM, IH, TT, KH };
string specStr[] = { "����������", "�����������", "������� ��������", "����'����� �����" };

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
		cout << " ������������ (0 - ����������, 1 - �����������, 2 - ������� ��������, 3 - ����'����� �����): ";
		cin >> spec;
		p[i].spec = (Spec)spec;
		cout << " ������ � ������: "; cin >> p[i].mark1;
		cout << " ������ � ����������: "; cin >> p[i].mark2;
		cout << " ������ � �����������: "; cin >> p[i].mark3;
	}
}

void Print(Student *p, const int N)
{
	cout <<
		"===================================================================================================================="
		<< endl;
	cout <<
		"| � | ������� �������� |  ���� |   ������������  | ������ � ������ | ������ � ���������� | ������ � ����������� |"
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