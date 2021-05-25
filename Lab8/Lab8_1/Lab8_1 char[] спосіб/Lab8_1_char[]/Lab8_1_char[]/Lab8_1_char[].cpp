// Lab_8_1_char[].cpp
// < Юлія Лазарів >
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку char[] способом
// Варіант 15

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

bool Search(char* s)
{
	int pos = 0;
	bool k = false;
	char* t;

	while (t = strchr(s + pos, '*'))
	{
		pos = t - s + 1;
		if (s[pos] == '*' && s[pos + 1] == '*')
			k = true;
	}
	return k;
}

char* Change(char* s)
{
	char* t = new char[strlen(s)];
	char* p;
	int pos1 = 0, 
		pos2 = 0;
	*t = 0;

	while (p = strchr(s + pos1, '*'))
	{
		if (s[p - s] == '*' && s[p - s + 1] == '*')
		{
			pos2 = p - s + 3;
			strncat(t, s + pos1, pos2 - pos1 - 3);
			strcat(t, "!!");
			pos1 = pos2;
		}
	}
	strcat(t, s + pos1);
	strcpy(s, t);
	return t;
}

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cout << endl;
	cin.getline(str, 100);

	cout << endl;
	cout << "0 - false, 1 - true " << endl;
	cout << "String contained " << " groups of '***' - " << Search(str) << endl;
	cout << endl;

	cout << "Modified string (param) : " << str << endl;

	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (result): " << dest << endl;

	return 0;
}