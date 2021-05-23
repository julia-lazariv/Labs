// Lab_12_4.cpp
// < Юлія Лазарів >
// Лабораторна робота № 12.4
// Опрацювання кільцевого однонаправленого списку
// Варіант 15

#include <iostream>
#include <iomanip>

using namespace std;

typedef int Info;
struct Elem
{
	Elem *link;
	Info info;
};

void Insert(Elem* &L, Info value)
{
	Elem *tmp = new Elem;
	tmp->info = value; 
	if (L != NULL)
	{
		Elem *T = L;
		while (T->link != L)
			T = T->link; 
		T->link = tmp; 
	}
	else
	{
		L = tmp; 
	}
	tmp->link = L; 
}

Info Remove(Elem* &L)
{
	Elem *T = L;
	while (T->link != L) T = T->link;

	Info value = L->info; 
	if (T != L)
	{
		Elem *tmp = L->link;
		delete L;
		L = tmp; 
		T->link = L;
	}
	else
	{
		delete L; 
		L = NULL; 
	}
	return value; 
}

int Count(Elem* L) {
	if (L == NULL) return 0;
	Elem *first = L;
	int k = 1;
	while (L->link != first)
	{
		k++;
		L = L->link;
	}
	return k;
}

void Print(Elem* L) {
	if (L == NULL) return;
	Elem *first = L;
	cout << setw(4) << L->info;
	while (L->link != first)
	{
		L = L->link;
		cout << setw(4) << L->info;
	}
	cout << endl;
}

void insertDupl(Elem* &L, Info value)
{
	Elem* tmp_copy = new Elem;

	tmp_copy->info = value;
	tmp_copy->link = L->link;
	L->link = tmp_copy;
}

int main()
{
	Elem *L = NULL;
	for (int i = 0; i < 15; i++) 
		Insert(L, i);
	cout << Count(L) << endl;
	Print(L);

	int N;
	cout << "Vvedit number: "; cin >> N;
	insertDupl(L, N);

	while (L != NULL)
		cout << setw(4) << Remove(L);
	cout << endl;
	return 0;
}