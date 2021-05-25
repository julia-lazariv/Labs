// Lab_8_2.cpp
// < Юлія Лазарів >
// Лабораторна робота № 8.2
// Опрацювання літерних рядків
// Варіант 15

#include <iostream>
#include <string>

using namespace std;

string FirstSpace(string str)
{
	int pos = 0;
	while ((pos = str.find(" ", 0)) != -1)
	{
		for (int i = str.size() - 1; i >= 0; i--) {
			if (!isalpha(str[i]))
			{
				str.erase(i, 1);
			}
		}
		str = str.substr(pos);
	}
	return str;
}

int main()
{
	string str;
	cout << "Enter string:" << endl;
	getline(cin, str);
	cout << endl;

	cout << "New string: " << FirstSpace(str) << endl;

	return 0;
}