// Lab_12_11_1.cpp
// < ��� ������ >
// ����������� ������ � 12.11.1
// ����������� ������� �����
// ������ 3

#include <iostream>
#include <string>
#include <iomanip>
#include "windows.h"
using namespace std;

struct Node
{
	char point[20];   
	int reis;        
	char name[20];    
	char surname[20];   
	char patr[20];    
	char date[12];  
	Node * next;  
};

int Menu();
void addNode(Node *first); 
Node *deleteNode(Node *first);
void outNode(Node *first); 
void outNodeNum(Node *first); 
void outNodeNum1(Node *first);
void Delet(Node *first);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Node *first = new Node;
	int n = 1;
	cout << "-------��� ��� ������-------\n\n";
	cout << "������ ����� ����������� > ";
	cin >> first->point;
	cout << "������ ����� ����� > ";
	cin >> first->reis;
	cout << "������ ������� ��������� > ";
	cin >> first->name;
	cout << "������ ��� �������� > ";
	cin >> first->surname;
	cout << "������ ��-������� ��������� > ";
	cin >> first->patr;
	cout << "������ ���� ������� > ";
	cin >> first->date;
	cout << "\n";
	first->next = NULL;

	int k;
	while ((k = Menu()) != 0)
	{
		switch (k)
		{
		case 1: addNode(first); break;
		case 2: outNode(first); break;
		case 3:	outNodeNum(first); break;
		case 4: first = deleteNode(first); break;
		case 5: Delet(first); return 0;
		default: cout << "������ ����� �� 1 �� 5 ";
		}
	}
	getchar();
	return 0;
}

int Menu()
{
	cout << "\n";
	cout << "1 - ���������� ������ \n";
	cout << "2 - ������� �� ������ \n";
	cout << "3 - ������� ������ �� ������ ����� � ��� ������� \n";
	cout << "4 - �������� ������ \n";
	cout << "5 - ����� � ��������� ������ \n";
	cout << "\n";
	cout << "������ �������� �����: ";
	short k;
	cin >> k;
	cout << "\n";
	return k;
}

void addNode(Node *first)
{
	Node *pv = new Node;
	cout << "\n��� ��� ������ \n";
	cout << "������ ����� ����������� > ";
	cin >> pv->point;
	cout << "������ ����� ����� > ";
	cin >> pv->reis;
	cout << "������ ������� ��������� > ";
	cin >> pv->name;
	cout << "������ ��� �������� > ";
	cin >> pv->surname;
	cout << "������ ��-������� ��������� > ";
	cin >> pv->patr;
	cout << "������ ���� ������� > ";
	cin >> pv->date;
	cout << "\n";
	pv->next = NULL;

	Node *p = first;
	if (first == NULL)
	{
		first = pv;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = pv;
	}
}

void outNode(Node *first)
{
	cout << setiosflags(ios::right);
	cout << "��� ��� ������ \n";
	cout << "-----------------------------------------------------------------------\n";
	cout << "       ����� | ����� | ----------��� ���������--------- |      ����  |\n";
	cout << " ����������� | ����� |   �������    ���    ��-�������  |   �������  |\n";
	cout << "-----------------------------------------------------------------------\n";

	Node *pv = first;
	while (pv)
	{
		cout << setw(12) << pv->point << " |" << setw(7) << pv->reis << "|" << setw(11) << pv->name;
		cout << setw(10) << pv->surname << setw(14) << pv->patr << "|" << setw(12) << pv->date << "|" << endl;
		pv = pv->next;
	}
	cout << "-----------------------------------------------------------------------\n";
}

void outNodeNum1(Node *first)
{
	cout << setiosflags(ios::right);
	cout << "��� ��� ������ \n";
	cout << "-----------------------------------------------------------------------\n";
	cout << "       ����� | ����� | -----------��� ���������-------- |      ����  |\n";
	cout << " ����������� | ����� |   �������    ���    ��-�������  |   �������  |\n";
	cout << "-----------------------------------------------------------------------\n";

	Node *pv = first;
	cout << setw(12) << pv->point << " |" << setw(7) << pv->reis << "|" << setw(11) << pv->name;
	cout << setw(10) << pv->surname << setw(14) << pv->patr << "|" << setw(12) << pv->date << "|" << endl;
	pv = pv->next;
	cout << "-----------------------------------------------------------------------\n";
}

void outNodeNum(Node *first)
{
	int num;
	string dat;
	Node *pv = first;
	cout << "������ ����� �����: ";
	cin >> num;
	cout << "������ ����: ";
	cin >> dat;
	int n = 1, fl = 0;
	while (pv)
	{
		if (pv->reis == num && pv->date == dat)
		{
			outNodeNum1(pv);
			break;
		}
		pv = pv->next;
	}
}

void Delet(Node *first) {

	while (first->next != NULL)
	{
		Node *tmp = first->next->next;
		delete first->next;
		first->next = tmp;
	}
	delete first;
}

Node *deleteNode(Node *first)
{
	cout << "����� �����, ������ �� ����� ������� ��������: ";
	int num;
	cin >> num;

	Node *temp = first;
	int k = -1;
	int N = 0;
	while (temp)
	{
		if (temp->reis == num)
		{
			k = N;
		}
		temp = temp->next;
		N++;
	}
	N--;
	if (k != -1)
	{
		temp = first;
		if (k == 0 && N == 0)
		{
			delete first;
			cout << "  ��������� ������� ������!\n";
			return NULL;
		}
		if (k == 0 && N > 0)
		{
			temp = temp->next;
			delete first;
			cout << "  ��������� ������� ������!\n";
			return temp;
		}
		Node *el = first;
		temp = first->next;
		while (temp->next)
		{
			if (temp->reis == num)
			{
				el->next = temp->next;
				delete temp;
				cout << "  ��������� ������� ������!\n";
				return first;
			}
			el = el->next;
			temp = temp->next;
		}
		// ������� �����
		el->next = NULL;
		delete temp;
		cout << "  ��������� ������� ������!\n";
		return first;
	}
	else
	{
		cout << "  ������ ����� ���� ��� ������ ������!\n";
		return first;
	}
}