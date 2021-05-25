// Lab_11_3_2.cpp
// < Юлія Лазарів >
// Лабораторна робота № 11.3.3
// Впорядкування та бінарний пошук у бінарному файлі
// Варіант 15

#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

enum Spec { KN, In, ME, FI, TN };
string specStr[] = { "KN", "IN", "ME", "FI", "TN" };
struct Student {
	char LastName[64] = "Peter";
	int kurs;
	Spec spec;
	int Math, Physics;
	union
	{
		int	Programming;
		int NumericMethods;
		int Pedagigica;
	};
};

void ThirdSubjInit(Student& st, int mark)
{
	switch (st.spec)
	{
	case Spec::KN:
	{
		st.Programming = mark;
		break;
	}
	case Spec::In:
	{
		st.NumericMethods = mark;;
		break;
	}
	default:
	{
		st.Pedagigica = mark;
		break;
	}
	}
}

int GetThirdMark(Student st)
{
	switch (st.spec)
	{
	case Spec::KN:
		return st.Programming;
	case Spec::In:
		return st.NumericMethods;
	default:
		return st.Pedagigica;
	}
}

void Create(string filename)
{
	ofstream f(filename, ios::binary);
	int spec;
	char key;
	if (!f)
	{
		cerr << "Error opening file '" << filename << "'" << endl;
		return;
	}

	Student student;
	do
	{
		cout << endl;
		cout << "LastName:"; cin >> student.LastName;
		cout << "Kurs:"; cin >> student.kurs;
		cout << "Spec (KN - 0, In - 1, ME - 2, FI - 3, TN - 4): ";
		cin >> spec;
		student.spec = (Spec)spec;
		cout << "Math: "; cin >> student.Math;
		cout << "Physics: "; cin >> student.Physics;
		cout << "IT: "; int m; cin >> m;
		ThirdSubjInit(student, m);
		f.write((char*)&student, sizeof(student));
		cout << "Continue? (Y/N) "; cin >> key;

	} while (key == 'y' || key == 'Y');
}

void Print()
{
	string filename;
	cout << "Enter filename: "; cin >> filename;
	ifstream fin;
	fin.open(filename, ios::binary);

	cout << endl;
	cout << "==========================================================================" << endl;
	cout << "Number \t|Name          |Course   |\tSpec\t | Phys|Math |Progr.|Numer.|Pedag|" << endl;
	cout << "==========================================================================" << endl;

	int i = 0;
	Student st;
	while (fin.read((char*)&st, sizeof(Student)))
	{

		cout << i << "\t| " << st.LastName << setw(15 - strlen(st.LastName));
		cout << "|\t" << st.kurs;
		cout << " |\t" << specStr[(int)st.spec] << "\t";
		cout << " |" << setw(3) << st.Physics << setw(3);
		cout << " |" << setw(3) << st.Math << setw(3);
		switch (st.spec)
		{
		case Spec::KN:
		{
			cout << "|" << setw(4) << GetThirdMark(st) << setw(3) << "|" << setw(7) << "|" << setw(6) << "|";
			break;
		}
		case Spec::In:
		{
			cout << "|" << setw(7) << "|" << setw(4) << GetThirdMark(st) << setw(3) << "|" << setw(6) << "|";
			break;
		}
		default:
		{
			cout << "|" << setw(7) << "|" << setw(7) << "|" << setw(3) << GetThirdMark(st) << setw(3) << "|";
			break;
		}
		}
		cout << endl;
		i++;
	}
	cout << "==========================================================================" << endl;
	cout << endl << endl;
	fin.close();
}
void autoCreate(string filename)
{
	cout << "Enter size:";
	int size; cin >> size;
	ofstream fs(filename, ios::binary);
	for (size_t i = 0; i < size; i++)
	{
		Student st;
		cin >> st.LastName;
		st.spec = (Spec)(rand() % 5);
		ThirdSubjInit(st, rand() % 5 + 1);
		st.Math = rand() % 5 + 1;
		st.Physics = rand() % 5 + 1;
		st.kurs = rand() % 3 + 1;
		st.spec = (Spec)(rand() % 5);
		fs.write((char*)&st, sizeof(st));
	}
	fs.close();
}

void fWrite(fstream& f, int i, Student x)
{
	f.seekp(i * (long)sizeof(Student));
	f.write((char*)&x, sizeof(Student));
}

Student fRead(fstream& f, const int i)
{
	Student x;
	f.seekg(i * sizeof(Student));
	f.read((char*)&x, sizeof(Student));
	return x;
}

void fChange(fstream& f, int i, int j)
{
	Student x = fRead(f, i);
	Student y = fRead(f, j);
	fWrite(f, i, y);
	fWrite(f, j, x);
}

void SortFiz(string FileName)
{
	fstream f(FileName, ios::binary | ios::in | ios::out | ios::ate);
	double ser, ser2;
	int size = f.tellg();
	int k = sizeof(Student);
	f.seekg(0, ios::beg);
	for (int i = 1; i < size / k; i++)
	{
		for (int j = 0; j < size / k - 1; j++)
		{
			Student a = fRead(f, j);
			Student b = fRead(f, j + 1);
			ser = (a.Math + a.Physics + (GetThirdMark(a))) / 3.0;
			ser2 = (b.Physics + b.Physics + (GetThirdMark(b))) / 3.0;
			if ((ser > ser2)
				||
				(ser == ser2 && a.Math < b.Math)
				||
				(ser == ser2 && a.Math == b.Math && a.LastName > b.LastName))
				fChange(f, j, j + 1);
		}
	}
}

int BinSearch(string FileName, string iprizv, Spec ispec)
{
	fstream f(FileName, ios::binary | ios::in | ios::out | ios::ate);
	int size = f.tellg();
	int k = sizeof(Student);
	f.seekg(0, ios::beg);
	double  ser, ser2;
	cout << "Ser = "; cin >> ser2;
	int L = 0;
	int R = size / k - 1;
	int n;
	Student m;
	Student p;
	do {
		n = (L + R) / 2;
		m = fRead(f, n);
		ser = (m.Math + m.Physics + GetThirdMark(m)) / 3.0;
		ser2 = (p.Physics + p.Physics + GetThirdMark(m)) / 3.0;

		if ((ser > ser2)
			||
			(ser == ser2 && m.Math > p.Math)
			||
			(ser == ser2 && m.Math == p.Math && m.LastName < iprizv))	L = n + 1;
		else
		{
			R = n - 1;
		}
	} while (L <= R);
	return -1;
}

int r(fstream& FI, int i)
{
	int value;
	FI.seekg(i * sizeof(i));
	FI.read((char*)&value, sizeof(int));
	return value;
}
void w(fstream& FI, int i, int j)
{
	FI.seekg(i * sizeof(i));
	FI.write((char*)&j, sizeof(int));
}

void indexSort(string FileName, string FileNameI)
{
	fstream f(FileName, ios::binary | ios::in | ios::out);
	fstream FI(FileNameI, ios::binary | ios::in | ios::out | ios::trunc);

	f.seekg(0, ios::end);
	int size = f.tellg();
	int k = sizeof(Student);
	f.seekg(0, ios::beg);

	for (int i = 0; i < size / k; i++) {
		w(FI, i, i);
	}
	int i, j, value;
	double ser, ser2;
	for (i = 1; i < size / k; i++)
	{
		value = r(FI, i);
		ser = (fRead(f, r(FI, i)).Math + fRead(f, r(FI, i)).Physics + GetThirdMark(fRead(f, r(FI, i)))) / 3.0;
		ser2 = (fRead(f, value).Math + fRead(f, value).Physics + GetThirdMark(fRead(f, value))) / 3.0;
		
		for (j = i - 1; j >= 0 && ((ser > ser2) ||
			((ser > ser2) && (fRead(f, r(FI, j)).Math == fRead(f, value).Math)) ||
			((ser = ser2) && (fRead(f, r(FI, j)).Math == fRead(f, value).Math) && (fRead(f, r(FI, j)).LastName > fRead(f, value).LastName))); j--)
		{
			w(FI, j + 1, r(FI, j));
		}
		w(FI, j + 1, value);
	}
	for (int i = 0; i < size / k; i++)
		cout << r(FI, i) << endl;
}

void printIndexSort(string FileName, string FileNameI)
{
	fstream f(FileName, ios::binary | ios::in | ios::out);
	fstream FI(FileNameI, ios::binary | ios::in | ios::out);
	f.seekg(0, ios::end);
	int size = f.tellg();
	int k = sizeof(Student);
	f.seekg(0, ios::beg);
	cout << endl;
	cout << "==========================================================================" << endl;
	cout << "Number \t|Name\t|Course   |\tSpec\t | Phys|Math |Progr.|Numer.|Pedag|" << endl;
	cout << "==========================================================================" << endl;
	for (int i = 0; i < size / k; i++)
	{

		cout << i << "\t| " << fRead(f, r(FI, i)).LastName << setw(15 - strlen(fRead(f, r(FI, i)).LastName));
		cout << " |\t" << fRead(f, r(FI, i)).kurs;
		cout << " |\t" << specStr[(int)fRead(f, r(FI, i)).spec] << "\t";
		cout << " |" << setw(3) << fRead(f, r(FI, i)).Physics << setw(3);
		cout << " |" << setw(3) << fRead(f, r(FI, i)).Math << setw(3);
		switch (fRead(f, r(FI, i)).spec)
		{
		case Spec::KN:
		{
			cout << "|" << setw(4) << GetThirdMark(fRead(f, r(FI, i))) << setw(3) << "|" << setw(7) << "|" << setw(6) << "|";
			break;
		}
		case Spec::In:
		{
			cout << "|" << setw(7) << "|" << setw(4) << GetThirdMark(fRead(f, r(FI, i))) << setw(3) << "|" << setw(6) << "|";
			break;
		}
		default:
		{
			cout << "|" << setw(7) << "|" << setw(7) << "|" << setw(3) << GetThirdMark(fRead(f, r(FI, i))) << setw(3) << "|";
			break;
		}
		}
		cout << endl;
		i++;
	}
	cout << endl;
}

int main()
{
	string filename;
	string filenameI;
	Student student;
	int ikurs;
	string iLastName;
	int ispec;
	int iMath;
	int menuItem;
	do
	{
		cout << endl;
		cout << "====Menu=====" << endl;
		cout << "1.Create" << endl;
		cout << "2.Print file" << endl;
		cout << "3.Physics sort" << endl;
		cout << "4.Binary find" << endl;
		cout << "5.Index sort " << endl;
		cout << "=============" << endl;
		cout << endl;
		cout << "0.Exit" << endl;
		cout << "Slected value: "; cin >> menuItem;
		cout << endl;
		switch (menuItem)
		{
		case 1:
		{
			cout << "enter file name : "; cin >> filename; cout << endl;
			Create(filename);
			break;

		}
		case 2:
		{
			Print();
			break;

		}
		case 3:
		{
			cout << "enter file name : "; cin >> filename; cout << endl;
			SortFiz(filename);
			break;
		}
		case 4:
		{
			cout << "enter file name : "; cin >> filename;
			cin.sync();
			cout << " LastName: "; cin >> iLastName; cin.sync();
			cout << "    Spec (KN - 0, In - 1, ME - 2, FI - 3, TN - 4): "; cin >> ispec;
			student.spec = (Spec)ispec;
			cin.sync();
			cout << endl;
			cout << "Number = " << BinSearch(filename, iLastName, student.spec) << endl;
			break;
		}
		case 5:
		{
			cout << "enter file name : "; cin >> filename; cout << endl;
			cout << "enter Index file name : "; cin >> filenameI; cout << endl;
			indexSort(filename, filenameI);
			printIndexSort(filename, filenameI);
			break;
		}
		case 0:
			break;
		default:
			cout << "ERROR!!!" << endl;
		}

	} while (menuItem != '0');
	system("pause");
	return 0;
}