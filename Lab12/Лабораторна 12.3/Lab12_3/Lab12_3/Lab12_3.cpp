// Lab_12_3.cpp
// < Юлія Лазарів >
// Лабораторна робота № 12.3
// Опрацювання лінійного двонаправленого списку
// Варіант 15

#include <iostream>
#include <cmath>

using namespace std;

typedef int Info;

struct Elem
{
	Elem *next,
		*prev;
	Info info;
};

void push(Elem* &top);
int Count(Elem* &top, int count);
void Print(Elem *&top);
void printList_Rec(Elem* h);
void createList_Rec(int n, Elem* &h);
int CountRec(Elem*top, int count);

int main()
{
	Elem *top = NULL;
	int N;
	cout << "Vvedit kilkist: "; cin >> N;
	cout << "Iteration" << endl;
	for (int i = 1; i <= N; i++)
		push(top);
	cout << endl;
	Print(top);
	cout << endl;
	int count = 1;
	cout << " Count: " << Count(top, count) << endl << endl;

	cout << "Recursion" << endl;
	createList_Rec(N, top);
	cout << "List: ";
	printList_Rec(top);
	cout << "Count: " << CountRec(top, 0) << endl;
	system("pause");
	return 0;
}

void push(Elem* &top)
{
	int value;
	cout << "Value = "; cin >> value;
	Elem *tmp = new Elem;
	tmp->info = value;
	tmp->next = top;
	tmp->prev = top;
	top = tmp;
}

void enqueue(Elem* &first, Elem* &last, Info value)
{
	Elem *tmp = new Elem;
	tmp->info = value; 
	tmp->next = NULL; 
	if (last != NULL)
		last->next = tmp; 
	tmp->prev = last; 
	last = tmp; 
	if (first == NULL)
		first = tmp; 
}

Info dequeue(Elem* &first, Elem* &last)
{
	Elem *tmp = first->next; 
	Info value = first->info; 
	delete first; 
	first = tmp; 
	if (first == NULL)
		last = NULL; 
	else
		first->prev = NULL; 
	return value; 
}

int Count(Elem* &top, int count)
{
	Elem *p = top;
	while (p)
	{
		if (p->info % 2 != 0)
			count++;
		p = p->next;
	}
	return count - 1;
}

void Print(Elem *&top)
{
	Elem *tmp = top;
	cout << "List: ";
	while (tmp)
	{
		cout << tmp->info << " ";
		tmp = tmp->prev;
	}
}

// Recursion version	
void createList_Rec(int n, Elem* &h)
{
	if (n > 0) {
		h = new Elem;
		cout << "Value = ";
		cin >> h->info;
		h->prev = NULL;
		createList_Rec(n - 1, h->prev);
	}
}

void printList_Rec(Elem* h)
{
	if (h) {
		cout << h->info << " ";
		printList_Rec(h->prev);
	}
	else cout << endl;
}


int CountRec(Elem *top, int count)
{
	if (top)
		if (top->info % 2 != 0)
		{
			count++;
			CountRec(top->prev, count);
		}
		else
			CountRec(top->prev, count);
	else
		return count;
}