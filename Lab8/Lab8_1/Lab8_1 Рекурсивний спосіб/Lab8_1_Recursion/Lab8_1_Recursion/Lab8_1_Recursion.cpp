// Lab_8_1.cpp
// < Юлія Лазарів >
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку рекурсивним способом
// Варіант 15

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

bool Search(char* str, bool k, int i)
{
	if (strlen(str) < 3)
		return 0;

	if (str[i + 1] != 0)
		if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*')
			return 1 + Search(str, k = true, i + 1);
		else
			return Search(str, k = false, i + 1);
	else
		return 0;
}

char* Change(char* dest, const char* str, char* t, int i)
{
	if (str[i + 2] != 0)
	{
		if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*')
		{
			strcat(t, "!!");
			return Change(dest, str, t + 2, i + 3);
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
			return Change(dest, str, t, i);
		}
	}
	else
	{
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
}

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cout << endl;
	cin.getline(str, 100);

	bool k = false;
	cout << endl;
	cout << "0 - false, 1 - true " << endl;
	cout << "String contained " << " groups of '***' - " << Search(str, k, 1) << endl;
	cout << endl;

	cout << "Modified string (param) : " << str << endl;

	char* dest1 = new char[151];
	dest1[0] = '\0';
	char* dest2;
	dest2 = Change(dest1, str, dest1, 0);
	cout << "Modified string (result): " << dest2 << endl;

	return 0;
}