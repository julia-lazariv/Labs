// Lab_12_9.cpp
// < Юлія Лазарів >
// Лабораторна робота № 12.9
// Опрацювання бінарних дерев
// Варіант 3

#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string>

using namespace std;

typedef int Data;

typedef struct tag_tree {
	Data data;
	int k = 1;
	struct tag_tree* left, *right;
} TREE;

void CreateTree(TREE* &root);
void BalanceHeight(TREE* &root);
void InsertNode(TREE* root);
void Print_Tree(TREE* Tree);
void DisplayTree(TREE* root, int level);
void DeleteNodeOfTree(TREE* Tree);
void DeleteBranchOfTree(TREE* &Tree);
void DestroyTree(TREE *Root);
int Height(TREE *Root);
int Leaves(TREE *Root);
void readFile(TREE* &root);
int Count(TREE* root);
void PrintTree(TREE *root, int level);

int main(int argc, TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	TREE* root = NULL;
	int i = 0;
	readFile(root);

	while (true) {
		cout << "Виберiть значення:" << endl << endl;
		cout << "1  - Створення дерева" << endl;
		cout << "2  - Вивід дерева" << endl;
		cout << "3  - Побудова збалансованого дерева" << endl;
		cout << "4  - Вилучення вузла дерева" << endl;
		cout << "5  - Вилучення гілки дерева" << endl;
		cout << "6  - Виведення тільки структура дерева" << endl;
		cout << "7  - Вставка вузла" << endl;
		cout << "8  - Кількість елементів" << endl;
		cout << "0  - Завершити роботу" << endl;
		cout << "Введіть значення - ";
		cin >> i;
		switch (i) {
		case 1: CreateTree(root); break;
		case 2: PrintTree(root, 0); cout << endl; Print_Tree(root); break;
		case 3: BalanceHeight(root); break;
		case 4: DeleteNodeOfTree(root); break;
		case 5: DeleteBranchOfTree(root); break;
		case 6: DisplayTree(root, 0); break;
		case 7: InsertNode(root); break;
		case 8: cout << "Знайдено елементів:" << Count(root) << endl; break;
		case 0: DestroyTree(root);
			return 0;
		}
	}
	system("pause");
	return 0;
}

void Include(TREE* &R, Data value) {
	if (R == NULL) {
		R = new TREE;
		R->data = value;
		R->left = R->right = NULL;
	}
	else  if (value == R->data) R->k++; else {
		if (value < R->data)  Include(R->left, value);
		else if (value > R->data) Include(R->right, value);
	}
}

void CreateTree(TREE* &root) {
	int n;
	Data data;
	DestroyTree(root);
	root = NULL;
	cout << "Вкажіть кількість елементів - ";
	cin >> n;
	if (n < 1) return;
	for (int i = 1; i <= n; i++) {
		cout << "Введіть елемент -" << i << "  ";
		cin >> data;
		Include(root, data);
	}
}

void InsertNode(TREE* root) {
	Data data;
	cout << endl;
	cout << "Введіть елемент ";
	cin >> data;
	Include(root, data);
	cout << endl << endl;
	cout << "Кількість листків в дереві: " << Leaves(root) << endl;
	cout << "Висота дерева: " << Height(root) << endl << endl;
}

void Backpass(TREE* T) {
	if (T != NULL) {
		Backpass(T->left);
		cout << T->data << "   ";
		Backpass(T->right);
	}
}

void PrefixBackpass(TREE* T) {
	if (T != NULL) {
		cout << T->data << "   ";
		PrefixBackpass(T->left);
		PrefixBackpass(T->right);
	}
}

void  PostfixBackpass(TREE* T) {
	if (T != NULL) {
		PostfixBackpass(T->left); PostfixBackpass(T->right);
		cout << T->data << "   ";
	}
}

void BackpassCount(TREE* T, int &k) {
	if (T != NULL) {
		BackpassCount(T->left, k); k++;
		BackpassCount(T->right, k);
	}
}

void Print_Tree(TREE* Tree) {
	if (Tree == NULL) { cout << "Дерева не існує!!!"; return; }
	cout << "Інфіксний обхід  : ";
	Backpass(Tree);
	cout << endl;
	cout << "Префіксний обхід : ";
	PrefixBackpass(Tree);
	cout << endl;
	cout << "Постфіксний обхід: ";
	PostfixBackpass(Tree);
	cout << endl;
	cout << "Кількість листків: " << Leaves(Tree) << endl;
	cout << "Висота дерева    : " << Height(Tree) << endl << endl;
}

void DestroyTree(TREE* Root) {
	TREE *L, *R;
	if (Root == NULL) return; L = Root->left;
	R = Root->right;
	delete Root; DestroyTree(L); DestroyTree(R);
}

int Leaves(TREE* Root) {
	if (Root == NULL) return 0;
	else if ((Root->left == NULL) && (Root->right == NULL)) return 1;
	else return(Leaves(Root->left) + Leaves(Root->right));
}

int Max(int x, int y) {
	if (x > y) return x;
	else return y;
}

int Height(TREE* Root) {
	int hL, hR;
	if (Root == NULL) return 0;
	hL = Height(Root->left);
	hR = Height(Root->right); return (1 + Max(hL, hR));
}

void RightRotation(TREE* &root) {
	TREE* tmp1 = root->left; TREE* tmp2 = tmp1->right;
	tmp1->right = root; root->left = tmp2; root = tmp1;
}

void LeftRotation(TREE* &root) {
	TREE* tmp1 = root->right; TREE* tmp2 = tmp1->left;
	tmp1->left = root; root->right = tmp2; root = tmp1;
}

int Height_(TREE* root) {
	if (root == NULL) return 0;
	int hL = Height_(root->left);
	int hR = Height_(root->right);
	if (hL > hR) return hL + 1;
	else return hR + 1;
}

int BFactor(TREE* root) {
	return Height_(root->right) - Height_(root->left);
}

void BalanceHeight(TREE* &root) {
	if (root != NULL) {
		BalanceHeight(root->left);
		BalanceHeight(root->right);
		if (BFactor(root) == 2) {
			if (BFactor(root->right) < 0)
				RightRotation(root->right);
			LeftRotation(root);
		}
		if (BFactor(root) == -2) {
			if (BFactor(root->left) > 0)
				LeftRotation(root->left);
			RightRotation(root);
		}
	}
}

int NodeCount(TREE* T) {
	int k = 0;
	if (T != NULL) {
		NodeCount(T->left);
		if ((T->left != NULL) && (T->right != NULL)) k++;
		NodeCount(T->right);
	}
	return k;
}

int rightmost(TREE* root) {
	while (root->right != NULL)
		root = root->right;
	return root->data;
}

TREE* DeleteNode(TREE* root, Data val)
{
	if (NULL == root) return NULL;
	if (root->data == val) {
		if (NULL == root->left && NULL == root->right) {
			free(root); return NULL;
		}
		if (NULL == root->right && root->left != NULL) {
			TREE *temp = root->left; free(root); return temp;
		}
		if (NULL == root->left && root->right != NULL) {
			TREE* temp = root->right;
			free(root);
			return temp;
		}
		root->data = rightmost(root->left);
		root->left = DeleteNode(root->left, root->data); return root;
	}
	if (val < root->data) {
		root->left = DeleteNode(root->left, val); return root;
	}
	if (val > root->data) {
		root->right = DeleteNode(root->right, val); return root;
	}
	return root;
}

void DeleteNodeOfTree(TREE* Tree) {
	Data data;
	cout << endl << endl;
	cout << "Задайте число, вузол з яким будете вилучати: ";
	cin >> data;
	Tree = DeleteNode(Tree, data);
}

void RemoveBranch(TREE* &root, int X, TREE* V, BOOL B) {
	if (root != NULL)
		if (X < root->data) {
			V = root; B = true; RemoveBranch(root->left, X, V, B);
		}
		else if (X > root->data) {
			V = root; B = false; RemoveBranch(root->right, X, V, B);
		}
		else {
			DestroyTree(root);
			if (B) V->left = NULL;
			else V->right = NULL; return;
		}
	return;
}

void DeleteBranchOfTree(TREE* &Tree) {
	Data data;
	cout << endl << endl;
	cout << "Задайте число, гілку з яким будете вилучати: ";
	cin >> data;
	if (data == Tree->data) {
		DestroyTree(Tree); Tree = NULL; return;
	}
	else RemoveBranch(Tree, data, NULL, true);
}

void DisplayTree(TREE* root, int level)
{
	if (root != NULL)
	{
		DisplayTree(root->right, level + 1);
		for (int i = 1; i <= level; i++) cout << "  ";
		cout << root->data << endl;
		DisplayTree(root->left, level + 1);
	}
}

void readFile(TREE* &root) {
	ifstream text_file("test.txt");
	if (!text_file) {
		cout << "Помилка створення файлу";
		return;
	}int M;
	while (text_file >> M) {
		Include(root, M);
	}
	text_file.close();
}

int Count(TREE* root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + Count(root->left) + Count(root->right);
}

void PrintTree(TREE *p, int level)
{
	if (p != NULL)
	{
		PrintTree(p->right, level + 1);
		for (int i = 1; i <= level; i++)
			cout << "   ";
		cout << p->data << endl;
		PrintTree(p->left, level + 1);
	}
}