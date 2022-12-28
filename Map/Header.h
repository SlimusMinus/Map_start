#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <Windows.h>
#include <conio.h>
using namespace std;

ostream& operator<<(ostream& os, vector <string>& town);
void Show(map <string, vector <string>> col);
void Search(map <string, vector <string>> ctr);
void Capital(vector<string> fr, vector<string> sp, vector<string> it, vector<string> ger, vector<string> grc);
void gotoxy(short x, short y);
void show_menu();