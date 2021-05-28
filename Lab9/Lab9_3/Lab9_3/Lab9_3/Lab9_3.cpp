// Lab_9_3.cpp
// < Юлія Лазарів >
// Лабораторна робота № 9_3
// Опрацювання масиву структур
// Варіант 15

#include <iomanip>
#include <iostream>
#include <ctime>
#include <string>

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

void create(room* rooms, int &size);
void autocreate(room* rooms, int &size);
void StartMenu(room*rooms, int &size);
void print(room* rooms, int &size);
void change(room* rooms, int &size);
room* remove(room* rooms, int &size);
void find(room* rooms, int& size);

void main()
{
	srand(time(NULL));
	room* rooms = new room[15];
	int size = 15;
	StartMenu(rooms, size);
	system("pause");
}

void create(room* rooms, int &size)
{
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
}

void autocreate(room* rooms, int &size)//for debug
{
	string InitialVector[] = { "I.I","T.K","P.Y","M.O","J.Z","X,Y",
							"O.E","V.I","K.I","K,I","V.V" };//for debug
	string LastNames[] = { "Petrenko","Senechko","Tsymbala"
		,"Nykolyak","Tkachenko","Nuchepura",
		"Lesyn","Matskiv","Makovetska","Marchyshyn","Palyvoda" };//im too lazy to fill the array by hands every debug iteration
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
}

void StartMenu(room* rooms, int &size)
{
	bool initialized = false;
	int choice;
	do
	{
		cout << "==============Menu==============" << endl;
		cout << "1.Create a list of dwellers." << endl;
		cout << "2.Print array" << endl;
		cout << "3.Change a dweller list." << endl;
		cout << "4.Remove a dweller." << endl;
		cout << "5.Find a dweller." << endl;
		cout << "6.Clear screen" << endl;
		cout << "0.Exit." << endl;
		cout << "================================" << endl;
		cout << endl;
		cout << "Enter your choice: "; cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
		{
			initialized = true;
			//create(rooms,size);
			autocreate(rooms, size);
			cout << "done" << endl;
			break;
		}
		case 2:
		{
			if (!initialized)   cout << "You try to do operatons with a not initialized arra!" << endl;
			else  print(rooms, size);
			break;
		}
		case 3:
		{
			if (!initialized)   cout << "You try to do operatons with a not initialized arra!" << endl;
			else  change(rooms, size);
			break;
		}
		case 4:
		{
			if (!initialized)   cout << "You try to do operatons with a not initialized arra!" << endl;
			else 	rooms = remove(rooms, size);
			break;
		}
		case 5:
		{
			if (!initialized)   cout << "You try to do operatons with a not initialized arra!" << endl;
			else 	find(rooms, size);
			break;
		}
		case 6:
		{
			system("cls");
			break;
		}
		default:
		{
			choice = 0;
			break;
		}
		}
	} while (choice != 0);
}

void print(room* rooms, int &size)
{
	cout << "===============================================" << endl;
	cout << "N\t|Room\t|Init\t|Last name            |" << endl;
	cout << "===============================================" << endl;
	for (size_t i = 0; i < size; i++)
	{
		switch (rooms[i].RoomType)
		{
		case ODNO:
		{
			cout << i << "\t| " << rooomtypearr[(int)rooms[i].RoomType - 1];
			cout << " |" << rooms[i].dwellers[0].Initials;
			cout << "\t|" << rooms[i].dwellers[0].LastName;
			cout << endl << "----------------------------------------------|";
			break;
		}
		case DVO:
		{
			cout << i << "\t| " << rooomtypearr[(int)rooms[i].RoomType - 1];
			cout << " |" << rooms[i].dwellers[0].Initials;
			cout << "\t|" << rooms[i].dwellers[0].LastName;
			cout << endl;
			cout << "        |       |" << rooms[i].dwellers[1].Initials;
			cout << "\t|" << rooms[i].dwellers[1].LastName;
			cout << endl << "----------------------------------------------|";
			break;
		}
		}
		cout << endl;
	}
	cout << "===============================================" << endl;
}

void change(room* rooms, int &size)
{
	print(rooms, size);
	cout << "Enter the index of a dweller(s) which you want to change: ";
	int index = 0; cin >> index;
	cout << "N\t|Room\t|Init\t|" << endl;
	cout << "===============================================================" << endl;
	if (index < 15)
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
	else cout << "There is no dweller with the number " << index << endl;
}

room* remove(room* rooms, int &size)
{
	print(rooms, size);
	room* rooms2 = new room[size - 1];
	cout << "Enter the index of a dweller(s) which you want to remove: ";
	int index = 0; cin >> index;
	cout << "N\t|Room\t|Init\t|" << endl;
	cout << "===============================================================" << endl;
	if (index < 15)
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
	else cout << "There is no dweller with the number " << index << endl;
	bool moved = false;
	for (size_t i = 0; i < size; i++)
	{

		if (i == index)  	moved = true;
		if (moved)	rooms2[i] = rooms[i + 1];
		else	rooms2[i] = rooms[i];
	}
	size--;
	return rooms2;
}

void find(room* rooms, int& size)
{
	string ln, ini;
	cout << endl << "Enter Last name:"; cin >> ln;
	int counter = 0;
	int index = -1;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < (int)rooms[i].RoomType; j++)
		{
			if (ln == rooms[i].dwellers[j].LastName)
			{
				index = i;
				counter++;
			}
		}
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
	for (size_t i = 0; i < size; i++)
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