// Lab_12_6.cpp
// < Юлія Лазарів >
// Лабораторна робота № 12.6
// Черги
// Варіант 3

#include <iostream>
#include <iomanip>

using namespace std;

typedef int Info;

struct Elem
{
	Elem *link;
	Info info;
};

void enqueue(Elem* &first, Elem* &last, Info value);
Info dequeue(Elem* &first, Elem* &last);

int main()
{
	Elem *first = NULL,
		*last = NULL;
	int N, i = 0;
	cout << "Kilkist: "; cin >> N;
	for (int i = 1; i <= N * 2; i++)		
		enqueue(first, last, i);

	while (first != NULL) {				
		if (i < N && (first->info % 2 == 0 || first->info % 3 == 0 || first->info % 5 == 0))
		{
			cout << setw(2) << i + 1 << ") " << dequeue(first, last) << setw(2) << endl;
			i++;
		}
		else
			dequeue(first, last);
	}
	cout << endl;

	system("pause");
	return 0;
}

void enqueue(Elem* &first, Elem* &last, Info value)
{
	Elem *tmp = new Elem; 
	tmp->info = value;
	tmp->link = NULL; 
	if (last != NULL)
		last->link = tmp; 
	last = tmp;
	if (first == NULL)
		first = tmp;
}

Info dequeue(Elem* &first, Elem* &last)
{
	Elem *tmp = first->link; 
	Info value = first->info; 
	delete first; 
	first = tmp;
	if (first == NULL)
		last = NULL; 
	return value; 
}