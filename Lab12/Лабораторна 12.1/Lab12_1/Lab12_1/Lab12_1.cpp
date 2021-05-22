// Lab_12_1.cpp
// < Юлія Лазарів >
// Лабораторна робота № 12.1
// Формування і знищення динамічної мережної структури даних
// Варіант 15

#include <iostream>

struct Elem
{
	Elem *link1,
		 *link2;
	int info;
};

int main()
{ 
	p = new Elem;                        // 1
	p->info = 1;                         // 2
	p->link2 = 0;                        // 3
	p->link1 = new Elem;                 // 4
	p->link1->info = 2;                  // 5
	p->link1->link1 = new Elem;          // 6
	p->link1->link1->info = 4;           // 7
	p->link1->link1->link1 = new Elem;   // 8
	p->link1->link1->link1->info = 3;    // 9
	p->link1->link1->link1->link2 = 0;   // 10
	p->link1->link1->link1 = p->link1;   // 11
	p->link1 = p;                        // 12
	p->link1->link1 = p;                 // 13

	delete p->link1->link1->link1;       // 14
	delete p->link1->link1;              // 15
	delete p->link1;                     // 16
	delete p;                            // 17

	return 0;
}