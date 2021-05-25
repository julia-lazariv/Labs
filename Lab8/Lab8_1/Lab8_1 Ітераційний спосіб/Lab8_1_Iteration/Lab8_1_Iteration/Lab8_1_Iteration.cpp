// Lab_8_1.cpp
// < Юлія Лазарів >
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку ітераційним способом
// Варіант 15

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

bool Search(char* str, bool k)
{
	if (strlen(str) < 3)
		return 0;

	for (int i = 1; str[i + 1] != 0; i++)
		if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*')
			k = true;
	return k;
}

char* Change(char* str)
{
	size_t len = strlen(str);
	if (len < 3)
		return str;

	char* tmp = new char[len];
	char* t = tmp;
	tmp[0] = '\0';
	size_t i = 0;
	while (i < len && str[i + 1] != 0)
	{
		if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*')
		{
			strcat(t, "!!");
			t += 2;
			i += 3;
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
		}
	}
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy(str, tmp);
	return tmp;
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
	cout << "String contained " << " groups of '***' - " << Search(str, k) << endl;
	cout << endl;

	cout << "Modified string (param) : " << str << endl;

	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (result): " << dest << endl;

	return 0;
}