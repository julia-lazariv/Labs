// Lab_12_2.cpp
// < Юлія Лазарів >
// Лабораторна робота № 12.2
// Опрацювання лінійного однонаправленого списку
// Варіант 15

#include <iostream>
#include <cmath>

using namespace std;

typedef int Info;
struct Elem
{
	Elem *link;
	Info info;
};

void push(Elem* &top);
bool CheckDuplicates(Elem* &top, bool r);
void Print(Elem *&top);
void printList_Rec(Elem* h);
void createList_Rec(int n, Elem* &h);
bool CheckRec(Elem*top, bool r);

int main()
{
	Elem *top = NULL;
	int N;
	cout << "Vvedit kilkist: "; cin >> N;
	cout << endl;
	cout << "Iteration" << endl;
	for (int i = 1; i <= N; i++) //create
		push(top);
	cout << endl;
	Print(top);
	cout << endl;
	bool r = false;
	cout << "Duplicates(0 - false, 1 - true): " << CheckDuplicates(top, r) << endl << endl;

	cout << "Recursion" << endl;
	createList_Rec(N, top);
	cout << "List: ";
	printList_Rec(top);
	cout << endl;
	cout << "Duplicates(0 - false, 1 - true): " << CheckRec(top, false) << endl;
	system("pause");
	return 0;
}
void push(Elem* &top)
{
	int value;
	cout << "Value = "; cin >> value;
	Elem *tmp = new Elem;
	tmp->info = value;
	tmp->link = top;
	top = tmp;
}

bool CheckDuplicates(Elem* &top, bool r)
{
	Elem *p = top;
	Elem *q = top->link;
	while (p)
	{
		while (q)
		{
			if (p->info = q->info)
			{
				return r = true;
				break;
			}
		}
	}
	return r;
}

void Print(Elem *&top)
{
	Elem *tmp = top;
	cout << "List: ";
	while (tmp)
	{
		cout << tmp->info << " ";
		tmp = tmp->link;
	}
}

// recursion	
void createList_Rec(int n, Elem* &h)
{
	if (n > 0) {
		h = new Elem;
		cout << "Value = ";
		cin >> h->info;
		h->link = NULL;
		createList_Rec(n - 1, h->link);
	}
}

void printList_Rec(Elem* h)
{
	if (h) {
		cout << h->info << " ";
		printList_Rec(h->link);
	}
	else cout << endl;
}

bool CheckRec(Elem *top, bool r)
{
	if (top)
		if (top->info == top->info) 
		{
			r = true;
			CheckRec(top->link, r);
		}
		else
			CheckRec(top->link, r);
	else
		return r;
}