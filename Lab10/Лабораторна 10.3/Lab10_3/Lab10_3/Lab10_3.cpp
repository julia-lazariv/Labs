// Lab_10_3.cpp
// < Юлія Лазарів >
// Лабораторна робота № 10.3
// Опрацювання текстового файлу
// Варіант 15

#include <iomanip>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

enum roomtype
{
	ODNO = 1, DVO = 2
};
string rooomtypearr[] = { "1 bed", "2 bed" };

struct dweller
{
	string LastName;
	string Initials;
};

struct room
{
	roomtype RoomType = roomtype::DVO;
	dweller* dwellers;
	room()
	{
		dwellers = new dweller[(int)RoomType];

	}
	room(roomtype rt)
	{
		this->RoomType = rt;
		this->dwellers = new dweller[(int)rt];
	}
};

room parse(string str);
void add();
void save(room* rooms, int& size, string filename);
void create();
void autocreate();
void StartMenu();
void print(string filename);
void change();
void remove();
void find();

void main()
{
	srand(time(NULL));
	StartMenu();
	system("pause");
}

void create()
{
	int size = 15;
	room* rooms = new room[15];
	int roomcounter = 0;
	for (size_t i = 0; i < 15; i++)
	{
		cout << "Room type(1 - odnomisniy,2 - dvomisniy):"; int t; cin >> t;
		switch (t)
		{
		case 1:
		{
			if (roomcounter < 5)
			{
				roomcounter++;
				rooms[i].RoomType = roomtype::ODNO;
				cout << "Last name: "; cin >> rooms[i].dwellers[0].LastName;
				cout << "Initials: "; cin >> rooms[i].dwellers[0].Initials;
				break;
			}
			else
			{
				cout << "Sorry,there is no free one room apartments in our hotel.\n" << endl;
				break;
			}
		}
		case 2:
		{
			rooms[i].RoomType = roomtype::DVO;
			cout << "Last name: "; cin >> rooms[i].dwellers[0].LastName;
			cout << "Initials: "; cin >> rooms[i].dwellers[0].Initials;
			cout << "Last name: "; cin >> rooms[i].dwellers[1].LastName;
			cout << "Initials: "; cin >> rooms[i].dwellers[1].Initials;
			break;
		}
		default:
		{
			cout << "Error.You Entered the incorrect code." << endl;
		}
		}
	}
	string filename;
	cout << "Enter the filename where you want to save the data in: "; cin >> filename;
	save(rooms, size, filename);
}

void autocreate()
{
	int size = 15;
	room* rooms = new room[15];
	string InitialVector[] = { "I.I","T.K","P.Y","M.O","J.Z","X,Y",
							"O.E","V.I","K.I","K,I","V.V" };
	string LastNames[] = { "Petrenko","Senechko","Tsymbala"
		,"Nykolyak","Tkachenko","Nuchepura",
		"Lesyn","Matskiv","Makovetska","Marchyshyn","Palyvoda" };
	for (size_t i = 0; i < 15; i++)
	{
		if (i < 5)
		{
			rooms[i].RoomType = roomtype::ODNO;
			rooms[i].dwellers[0].LastName = LastNames[rand() % 11];
			rooms[i].dwellers[0].Initials = InitialVector[rand() % 11];
		}
		else
		{
			rooms[i].RoomType = roomtype::DVO;
			rooms[i].dwellers[0].LastName = LastNames[rand() % 11];
			rooms[i].dwellers[0].Initials = InitialVector[rand() % 11];
			rooms[i].dwellers[1].LastName = LastNames[rand() % 11];
			rooms[i].dwellers[1].Initials = InitialVector[rand() % 11];
		}
	}
	string filename;
	cout << "Enter the filename: "; cin >> filename;
	save(rooms, size, filename);
}

void StartMenu()
{
	int choice;
	do
	{
		cout << "==============Menu==============" << endl;
		cout << "0.Add a dweller" << endl;
		cout << "1.Create a list of dwellers." << endl;
		cout << "2.Print array" << endl;
		cout << "3.Change a dweller list." << endl;
		cout << "4.Remove a dweller." << endl;
		cout << "5.Find a dweller." << endl;
		cout << "6.Clear screen" << endl;
		cout << "7.Exit." << endl;
		cout << "================================" << endl;
		cout << endl;
		cout << "Enter your choice: "; cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 0:
		{
			add();
			break;
		}
		case 1:
		{
			autocreate();
			cout << "done" << endl;
			break;
		}
		case 2:
		{
			print("");
			break;
		}
		case 3:
		{
			change();
			break;
		}
		case 4:
		{
			remove();
			break;
		}
		case 5:
		{
			find();
			break;
		}
		case 6:
		{
			system("cls");
			break;
		}
		default:
		{
			break;
		}
		}
	} while (choice != 10);
}

void print(string filename = "")
{
	int i = 0;
	ifstream fin;
	if (filename == "")
	{
		cout << "Enter filename:"; cin >> filename;
	}
	fin.open(filename);
	string str;
	cout << "===============================================" << endl;
	cout << "N\t|Room\t|Init\t|Last name            |" << endl;
	cout << "===============================================" << endl;
	while (getline(fin, str))
	{
		room rm = parse(str);
		switch (rm.RoomType)
		{
		case ODNO:
		{
			cout << i << "\t| " << rooomtypearr[(int)rm.RoomType - 1];
			cout << " |" << rm.dwellers[0].Initials;
			cout << "\t|" << rm.dwellers[0].LastName;
			cout << endl << "----------------------------------------------|";
			break;
		}
		case DVO:
		{
			cout << i << "\t| " << rooomtypearr[(int)rm.RoomType - 1];
			cout << " |" << rm.dwellers[0].Initials;
			cout << "\t|" << rm.dwellers[0].LastName;
			cout << endl;
			cout << "        |       |" << rm.dwellers[1].Initials;
			cout << "\t|" << rm.dwellers[1].LastName;
			cout << endl << "----------------------------------------------|";
			break;
		}
		}
		cout << endl;
		i++;
	}
	cout << "===============================================" << endl;
}

void change()
{
	string filename;
	cin.sync();
	cout << "Enter filename:"; cin >> filename;
	ifstream fin;
	fin.open(filename);
	string str;
	room* rooms = new room[15];
	int size = 15;
	print(filename);
	cout << "Enter the index of a dweller(s) which you want to change: ";
	int index = 0; cin >> index;
	cout << "N\t|Room\t|Init\t|" << endl;
	cout << "===============================================================" << endl;
	int i = 0;
	if (index < size)
	{
		while (getline(fin, str))
		{
			rooms[i] = parse(str);
			if (index == i)
			{


				if (index < 5)
				{
					cout << index << "\t| " << rooomtypearr[(int)rooms[index].RoomType - 1];
					cout << " |" << rooms[index].dwellers[0].Initials;
					cout << "\t|" << rooms[index].dwellers[0].LastName;
					cout << endl << "------------------------------- --------------|";
					cout << endl << "Enter Last name:"; cin >> rooms[index].dwellers[0].LastName;
					cout << "Enter Initials::"; cin >> rooms[index].dwellers[0].Initials;
				}
				else
				{
					cout << index << "\t| " << rooomtypearr[(int)rooms[index].RoomType - 1];
					cout << " |" << rooms[index].dwellers[0].Initials;
					cout << "\t|" << rooms[index].dwellers[0].LastName;
					cout << endl;
					cout << "        |       |" << rooms[index].dwellers[1].Initials;
					cout << "\t|" << rooms[index].dwellers[1].LastName;
					cout << endl << "----------------------------------------------|";
					cout << endl << "Enter Last name:"; cin >> rooms[index].dwellers[0].LastName;
					cout << "Enter Initials::"; cin >> rooms[index].dwellers[0].Initials;
					cout << "Enter Last name:"; cin >> rooms[index].dwellers[1].LastName;
					cout << "Enter Initials::"; cin >> rooms[index].dwellers[1].Initials;
				}
				cout << endl << endl;
			}
			i++;
		}
		save(rooms, size, filename);
	}
	else cout << "There is no dweller with the number " << index << endl;
}

void remove()
{
	string filename;
	cout << "Filename: "; cin >> filename;
	ifstream fin;
	fin.open(filename);
	print(filename);
	int size = 15;
	room* rooms = new room[size];
	room* rooms2 = new room[size - 1];
	cout << "Enter the index of a dweller(s) which you want to remove: ";
	int index = 0; cin >> index;
	cout << "N\t|Room\t|Init\t|" << endl;
	cout << "===============================================================" << endl;
	string str;
	int I = 0;
	while (getline(fin, str))
	{
		rooms[I] = parse(str);
		if (index == I)
		{
			if (index < 5)
			{
				cout << index << "\t| " << rooomtypearr[(int)rooms[index].RoomType - 1];
				cout << " |" << rooms[index].dwellers[0].Initials;
				cout << "\t|" << rooms[index].dwellers[0].LastName;
				cout << endl << "------------------------------- --------------|";
			}
			else
			{
				cout << index << "\t| " << rooomtypearr[(int)rooms[index].RoomType - 1];
				cout << " |" << rooms[index].dwellers[0].Initials;
				cout << "\t|" << rooms[index].dwellers[0].LastName;
				cout << endl;
				cout << "        |       |" << rooms[index].dwellers[1].Initials;
				cout << "\t|" << rooms[index].dwellers[1].LastName;
				cout << endl << "----------------------------------------------|";

			}
			cout << endl << endl;
		}
		I++;
	}
	bool moved = false;
	for (size_t i = 0; i < I; i++)
	{

		if (i == index)  	moved = true;
		if (moved)	rooms2[i] = rooms[i + 1];
		else	rooms2[i] = rooms[i];
	}
	size--;
	save(rooms, size, filename);
}

void find()
{
	int size = 15;
	room* rooms = new room[15];
	string ln, ini;
	cout << endl << "Enter Last name:"; cin >> ln;
	int counter = 0;
	int index = -1;
	string filename;
	cin.sync();
	cout << "Enter filename:"; cin >> filename;
	ifstream fin;
	fin.open(filename);
	string str;
	int I = 0;
	while (getline(fin, str))
	{
		rooms[I] = parse(str);
		for (size_t j = 0; j < (int)rooms[I].RoomType; j++)
		{
			if (ln == rooms[I].dwellers[j].LastName)
			{
				index = I;
				counter++;
			}
		}
		I++;
	}
	if (index == -1)
	{
		cout << "There is no dwellers with the last name " << ln << endl;
		return;
	}
	if (counter > 1)
	{
		cout << "There is more than 1 dweller with the  last name " << ln << endl;
		cout << "Enter initials: "; cin >> ini;
	}
	for (size_t i = 0; i < I; i++)
	{
		for (size_t j = 0; j < (int)rooms[i].RoomType; j++)
		{
			if (ln == rooms[i].dwellers[j].LastName && rooms[i].dwellers[j].Initials == ini)
			{
				index = i;
				break;
			}
		}
	}
	if (index == -1)
	{
		cout << "There is no dwellers with the last name " << ln + " " + ini << endl;
		return;
	}
	else
	{
		cout << "N\t|Room\t|Init\t|" << endl;
		cout << "===============================================================" << endl;
		if (index < 5)
		{
			cout << index << "\t| " << rooomtypearr[(int)rooms[index].RoomType - 1];
			cout << " |" << rooms[index].dwellers[0].Initials;
			cout << "\t|" << rooms[index].dwellers[0].LastName;
			cout << endl << "------------------------------- --------------|";
		}
		else
		{
			cout << index << "\t| " << rooomtypearr[(int)rooms[index].RoomType - 1];
			cout << " |" << rooms[index].dwellers[0].Initials;
			cout << "\t|" << rooms[index].dwellers[0].LastName;
			cout << endl;
			cout << "        |       |" << rooms[index].dwellers[1].Initials;
			cout << "\t|" << rooms[index].dwellers[1].LastName;
			cout << endl << "----------------------------------------------|";

		}
		cout << endl << endl;
	}
}

room parse(string str)
{
	room rm((roomtype)str[0]);
	if (str[0] == '1')
	{
		rm.dwellers = new dweller[1];
		string initials = str.substr(2, str.find_first_of("^") - 2);
		rm.RoomType = roomtype::ODNO;
		rm.dwellers[0].Initials = initials;
		string lastname = str.substr(str.find_first_of("^") + 1, str.find_first_of("}"));
		lastname.erase(lastname.size() - 1);
		rm.dwellers[0].LastName = lastname;
	}
	if (str[0] == '2')
	{
		rm.dwellers = new dweller[2];
		string initials = str.substr(2, str.find_first_of("^") - 2);
		rm.RoomType = roomtype::DVO;
		rm.dwellers[0].Initials = initials;
		int iter = 0;
		string lastname = str.substr((iter = str.find_first_of("^")), str.find("}", iter) - iter); lastname.erase(0, 1);
		rm.dwellers[0].LastName = lastname;
		string in2 = str.substr((iter = str.find("{", iter)), str.find("^", iter) - iter); in2.erase(0, 1);
		rm.dwellers[1].Initials = in2;
		string ln2 = str.substr((iter = str.find("^", iter)), str.size() - 1 - iter); ln2.erase(0, 1);
		rm.dwellers[1].LastName = ln2;
	}
	return rm;
}

void add()
{
	string filename;
	cin.sync();
	cout << "Enter filename:"; cin >> filename;
	ifstream fin;
	fin.open(filename);
	string str;
	int iter = 0;
	int OneRC = 0, TwoRC = 0;
	while (getline(fin, str))
	{
		room rm = parse(str);
		iter++;
		if (rm.RoomType == ODNO)
			OneRC++;
		else
			TwoRC++;
	}
	if (iter >= 15)
	{
		cout << "Sorry,but you cant add a new dweller because the hotel has no free apartments" << endl;
		return;
	}
	cout << "Room type(1 - odnomisniy,2 - dvomisniy):"; int t; cin >> t;
	room rm;
	switch (t)
	{
	case 1:
	{
		if (OneRC < 5)
		{

			rm.RoomType = roomtype::ODNO;
			cin.sync();
			cout << "Last name: "; cin >> rm.dwellers[0].LastName;
			cin.sync();
			cout << "Initials: "; cin >> rm.dwellers[0].Initials;
			break;
		}
		else
		{
			cout << "Sorry,there is no free one room apartments in our hotel.\n" << endl;
			break;
		}
	}
	case 2:
	{
		cin.sync();
		rm.RoomType = roomtype::DVO;
		cout << "Last name: "; cin >> rm.dwellers[0].LastName;
		cin.sync();
		cout << "Initials: "; cin >> rm.dwellers[0].Initials;
		cin.sync();
		cout << "Last name: "; cin >> rm.dwellers[1].LastName;
		cin.sync();
		cout << "Initials: "; cin >> rm.dwellers[1].Initials;
		cin.sync();
		break;
	}
	default:
	{
		cout << "Error.You Entered the incorrect code." << endl;
	}
	}
	fstream fout;
	fout.open(filename);
	switch (rm.RoomType)
	{
	case ODNO:
	{
		fout << (int)rm.RoomType;
		fout << "{" << rm.dwellers[0].Initials;
		fout << "^" << rm.dwellers[0].LastName << "}";
		break;
	}
	case DVO:
	{
		fout << (int)rm.RoomType;
		fout << "{" << rm.dwellers[0].Initials;
		fout << "^" << rm.dwellers[0].LastName;
		fout << "}";
		fout << "{" << rm.dwellers[1].Initials;
		fout << "^" << rm.dwellers[1].LastName << "}";
		break;
	}
	}
	fout << endl;

	fout.close();
}

void save(room* rooms, int& size, string filename)
{
	ofstream fout;
	fout.open(filename);
	for (size_t i = 0; i < size; i++)
	{
		switch (rooms[i].RoomType)
		{
		case ODNO:
		{
			fout << (int)rooms[i].RoomType;
			fout << "{" << rooms[i].dwellers[0].Initials;
			fout << "^" << rooms[i].dwellers[0].LastName << "}";
			break;
		}
		case DVO:
		{
			fout << (int)rooms[i].RoomType;
			fout << "{" << rooms[i].dwellers[0].Initials;
			fout << "^" << rooms[i].dwellers[0].LastName;
			fout << "}";
			fout << "{" << rooms[i].dwellers[1].Initials;
			fout << "^" << rooms[i].dwellers[1].LastName << "}";
			break;
		}
		}
		fout << endl;
	}
	fout.close();
}