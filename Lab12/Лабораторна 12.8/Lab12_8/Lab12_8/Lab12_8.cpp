// Lab_12_8.cpp
// < Юлія Лазарів >
// Лабораторна робота № 12.8
// Двозв’язні списки
// Варіант 3

#include <iostream> 
#include <fstream> 
#include <stdlib.h> 
#include <windows.h> 
#include <string.h>

using namespace std;

struct elem {
	char word[21];
	elem* prev;
	elem* next;
};

void CreateDoubleList(elem* &first, elem* &last);
void Print_Double_List(elem* h, elem* first);
void deleteList(elem* h);
void Search(elem* h, elem* first);
void dequeue(elem* &L);

int main(int argc, CHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	elem* head = NULL;
	elem* last = NULL;
	elem* Head = NULL;
	elem* Last = NULL;

	CreateDoubleList(head, last);
	cout << endl << "Початковий список: " << endl;
	Print_Double_List(head, head);
	cout << endl;
	cout << "Знайдено такі однакові «сусіди»: " << endl;
	Search(head, head);
	cout << "Відредагований список: " << endl;
	Print_Double_List(head, head);

	cout << endl;

	system("pause");
	return 0;
}

void addElem(char* data, elem* &first, elem* &last) {
	elem* tmp = new elem;
	strcpy_s(tmp->word, 20, data);
	tmp->next = NULL;
	if (last != NULL)
		last->next = tmp;
	tmp->prev = last;
	last = tmp;
	if (first == NULL)
		first = tmp;
}

void CreateDoubleList(elem* &first, elem* &last) {
	char data[21];
	char S[20];
	cout << "Введіть ім'я текстового файлу: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(S, 10);
	ifstream T(S);
	if (!T) {
		cout << "Помилка відкриття файлу";
		return;
	}
	while (T >> data) {
		addElem(data, first, last);
	} T.close();
	last->next = first;
	first->prev = last;
}

void Print_Double_List(elem* h, elem* first) {
	while (h->next != first) {
		cout << h->word << " ";
		h = h->next;
	} cout << endl;
}

void deleteList(elem* h) {
	elem* p = NULL;
	while (h != NULL) {
		p = h; h = h->next;
		delete p;
	}
}

void Search(elem* h, elem* first) {
	while (h->next != first) {
		int x = strcmp(h->word, h->next->word);
		if (x == 0)
		{
			cout << h->word << " ";
			dequeue(h);
			dequeue(h);
		}
		h = h->next;
	}
	cout << endl << endl;
}

void dequeue(elem* &L)
{
	elem *next = L->next; 
	elem *prev = L->prev;
	delete L; 
	next->prev = prev; 
	prev->next = next;
	L = next;
}