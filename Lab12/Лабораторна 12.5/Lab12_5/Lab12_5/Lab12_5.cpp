#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;

struct Node
{
	Node* link;
	int data;
	Node(int _data) { data = _data; }
};
struct Stack
{
private:
	Node* top;
	int count;
public:
	Stack()
	{
		count = 0;
		top = nullptr;
	}

	Node* Top() { return top; }
	int size() { return count; }
	void push(int val)
	{
		Node* tmp = new Node(val);
		tmp->link = top;
		top = tmp;
		count++;
	}
	int pop()
	{
		Node* tmp = top->link;
		int value = top->data;
		delete top;
		top = tmp;
		--count;
		return value;
	}
};
Stack create(int size)
{
	Stack out;
	for (size_t i = 0; i < size; i++)
		out.push(rand() % 10);

	return out;
}
Stack userinput()
{
	Stack out;
	char ch;
	do
	{
		cout << "Value: ";
		int val; cin >> val;
		out.push(val);
		cout << "Continue?(y/n): ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');

	return out;
}
Stack getfromfile()
{
	Stack out;
	string filename;
	cout << "Filename: "; cin >> filename;
	ifstream fin(filename);
	string str;
	while (getline(fin, str))
	{
		out.push(atoi(str.c_str()));
	}
	fin.close();
	return out;
}
void print(Stack lst)
{
	int size = lst.size();
	for (size_t i = 0; i < size; i++)
	{
		cout << lst.pop() << "  ";
	}
	cout << endl;
}
void task(Stack lst)
{
	Stack inversed, original, temporary;
	int count = lst.size();
	for (size_t i = 0; i < count; i++)
	{
		int t = lst.pop();
		temporary.push(t);
		inversed.push(t);
	}
	count = temporary.size();
	for (size_t i = 0; i < count; i++)
	{
		int t = temporary.pop();
		original.push(t);
	}
	print(original);
	print(inversed);
}
void main()
{
	srand(time(NULL));
	char ch;
	bool initialized = false;
	Stack st;
	bool continue_ = true;
	do
	{
		cout << "==============Menu==============" << endl;
		cout << "1.Create a stack automatically." << endl;
		cout << "2.Create a stack by user input." << endl;
		cout << "3.Get data for a stack from file." << endl;
		cout << "4.Print the stack" << endl;
		cout << "5.Task." << endl;
		cout << "6.Clear screen" << endl;
		cout << "Any else key. Exit" << endl;
		cout << "================================" << endl;
		cout << "Ur choice: "; cin >> ch;
		switch (ch)
		{
		case '1': {
			initialized = true;
			cout << "Enter size: ";
			int size; cin >> size;
			st = create(size);
			break;
		}case '2': {
			initialized = true;
			st = userinput();
			break;
		}case '3': {
			initialized = true;
			st = getfromfile();
			break;
		}case '4': {
			if (!initialized)
				cout << "You try to do operations with a not initialized stack!" << endl;
			else
				print(st);
			break;
		}case '5': {
			if (!initialized)
				cout << "You try to do operations with a not initialized stack!" << endl;
			else
				task(st);
			break;
		}case '6': {
			system("cls");
			break;
		}
		default:
		{
			continue_ = false;
			break;
		}
		}
	} while (continue_);
	system("pause");
}
