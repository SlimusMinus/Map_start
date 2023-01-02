#include "Header.h"


int main()
{
	map <string, vector <string>> ctr;

	vector<string> fr{ "Paris", "Marseilles", "Lyon", "Toulouse", "Nice" };
	ctr.emplace("France", fr);
	vector<string> sp{ "Madrid", "Barcelona" };
	ctr.emplace("Spain", sp);
	vector<string> it{ "Rome", "Florence", "Naples", "Palermo" };
	ctr.emplace("Italy", it);
	vector<string> ger{ "Berlin", "Hamburg  ", "Munich", "Stuttgart" };
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
					Capital(ctr);
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
	int size = town.size();
	for (int i = 0; i < size; i++)
		cout << town[i] << "\t";
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
	int size;
	cout << "Enter the town" << endl;
	cin >> word;
	auto iter = ctr.begin();
	for (int i = 0; i != ctr.size(); i++)
	{
		size = iter->second.size();
		for (int j = 0; j < size; j++)
		{
			if (ctr[iter->first][j] == word)
				cout << "Country is " << iter->first << endl;
		}
		iter++;
	}
}

void Capital(map <string, vector <string>> ctr)
{
	string country;
	cout << "Enter country" << endl;
	cin >> country;
	for (auto iter = ctr.begin(); iter != ctr.upper_bound(country); iter++)
	{
		if (iter->first == country)
			cout << "Capital " << country << " is " << iter->second[0] << endl;
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
