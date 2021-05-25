// Lab_8_1.cpp
// < Юлія Лазарів >
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку String способом
// Варіант 15

#include <iostream>
#include <string>

using namespace std;

bool Search(const string s)
{
	size_t pos = 0;
	while ((pos = s.find('*', pos)) != -1)
		if (s[pos + 1] == '*' && s[pos + 2] == '*')
			return true;
	return false;
}

string Change(string& s)
{
	size_t pos = 0;
	while ((pos = s.find('*', pos)) != -1)
		if (s[pos] == '*' && s[pos + 1] == '*')
			s.replace(pos, 3, "!!");
	return s;
}

int main()
{
	string str;
	cout << "Enter string:" << endl;
	cout << endl;
    getline(cin, str);

	cout << endl;
	cout << "0 - false, 1 - true " << endl;
	cout << "String contained " << " groups of '***' - " << Search(str) << endl;
	cout << endl;

	cout << "Modified string (param) : " << str << endl;

	string dest = Change(str);
	cout << "Modified string (result): " << dest << endl;

	return 0;
}