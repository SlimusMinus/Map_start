#include "Header.h"


int main()
{
	map <string, vector <string>> ctr;

	vector<string> fr{ "Paris", "Marseilles", "Lyon", "Toulouse", "Nice" };
	ctr.emplace("France", fr);
	vector<string> sp{ "Madrid", "Barcelona", "Malaga", "Sevilla", "Tarrasa" };
	ctr.emplace("Spain", sp);
	vector<string> it{ "Rome", "Florence", "Naples", "Turin  ", "Palermo" };
	ctr.emplace("Italy", it);
	vector<string> ger{ "Berlin", "Hamburg  ", "Munich", "Koln   ", "Stuttgart" };
	ctr.emplace("Germany", ger);
	vector<string> grc{ "Athens", "Thessaloniki", "Patras", "Heraklion", "Acharnes" };
	ctr.emplace("Greece", grc);
	
	system("color F0");
	const int num_menu = 3;
	int ch = 0, active_menu = 0;
	bool q;
	do
	{
		bool exit = false;
		while (!exit)
		{

			show_menu();
			gotoxy(0, active_menu);
			ch = _getch();
			if (ch == 224) ch = _getch();
			switch (ch)
			{

			case 27: exit = true; break;
			case 72: active_menu--; break;
			case 80: active_menu++; break;
			case 13:

				if (active_menu == 0)
				{
					system("cls");
					Show(ctr);
					system("pause");
				}
				else if (active_menu == 1)
				{
					system("cls");
					Show(ctr);
					Capital(fr, sp, it, ger, grc);
					system("pause");

				}
				else if (active_menu == 2)
				{
					system("cls");
					Show(ctr);
					Search(ctr);
					system("pause");

				}
				break;
			}
			if (active_menu < 0) active_menu = num_menu - 1;
			if (active_menu > num_menu - 1) active_menu = 0;

		}
		system("cls");
		cout << "If you wanna continue press 1, no 0" << endl;
		cin >> q;
		system("cls");
	} while (q == 1);
	system("cls");
		
}


ostream& operator<<(ostream& os, vector <string>& town)
{
	if (town.size() == 4)
		os << town[0] << "\t" << town[1] << "\t" << town[2] << "\t " << town[3];
	else
		os << town[0] << "\t" << town[1] << "\t" << town[2] << "\t " << town[3] << "\t" << town[4];
	return os;
}

void Show(map <string, vector <string>> col)
{
	for (auto i = col.begin(); i != col.end(); ++i)
	{
		cout << i->first << "\t\t" << i->second << endl;
	}
	cout << endl;
}

void Search(map<string, vector<string>> ctr)
{
	string word;
	cout << "Enter the town" << endl;
	cin >> word;
	auto iter = ctr.begin();
	for (int i = 0; i != ctr.size(); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (ctr[iter->first][j] == word)
				cout << "Country is " << iter->first << endl;
		}
		iter++;
	}
}

void Capital(vector<string> fr, vector<string> sp, vector<string> it, vector<string> ger, vector<string> grc)
{
	cout << "Countrie 1 - France, 2 - Spain, 3 - Italy, 4 - Germany, 5 - Greece" << endl;
	cout << "Enter the country number and find out its capital" << endl;
	int key;
	cin >> key;
	switch (key)
	{
	case 1:
		cout << "capital is " << fr[0] << endl;
		break;
	case 2:
		cout << "capital is " << sp[0] << endl;
		break;
	case 3:
		cout << "capital is " << it[0] << endl;
		break;
	case 4:
		cout << "capital is " << ger[0] << endl;
		break;
	case 5:
		cout << "capital is " << grc[0] << endl;
		break;
	default:
		cout << "number is error" << endl;
	}
}

void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}

void show_menu()
{
	system("cls");
	cout << "Show" << endl;
	cout << "Capital" << endl;
	cout << "Search" << endl;
	cout << "****************" << endl;
	cout << "Press ESC to exit" << endl;
}
