// Lab_12_7.cpp
// < Юлія Лазарів >
// Лабораторна робота № 12_7
// Однозв’язні списки
// Варіант 3

#include <iostream>

struct slist {
	slist* next;
	char   ch;
};

void slist_fill(slist*& lst);
void slist_rev(slist*& lst);
void slist_clear(slist* lst);
void slist_print(std::ostream& _out, const slist* p);

int main(void) {
	slist* lst = NULL;
	slist_fill(lst);
	slist_print(std::cout, lst);

	slist_rev(lst);
	slist_print(std::cout, lst);

	slist_clear(lst);
	return 0;
}

void slist_fill(slist*& lst) {
	slist* p, *t = NULL;
	for (char c = '1'; c <= '5'; ++c) {
		p = new (std::nothrow) slist();
		if (p == NULL)
			break;

		p->ch = c;
		p->next = NULL;

		if (t == NULL)
			lst = t = p;
		else
			t = t->next = p;
	}
}

void slist_rev(slist*& lst) {
	slist* t, *p = lst, *h = NULL;
	while (p != NULL) {
		t = p;
		p = p->next;

		t->next = h;
		h = t;
	}
	lst = h;
}

void slist_clear(slist* lst) {
	slist* t;
	while (lst != NULL) {
		t = lst;
		lst = lst->next;
		delete t;
	}
}

void slist_print(std::ostream& _out, const slist* p) {
	for (; p != NULL; p = p->next)
		_out << p->ch;
	_out << std::endl;
}