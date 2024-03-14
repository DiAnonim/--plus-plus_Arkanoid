#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>
#include <list>   // std::list<> - шаблон двусвязанного списка
#include <vector> // std::vector<> - шаблон динамического массива
#include <iterator> // класс итератора для работы с контейнерами
#include <algorithm> // шаблоны алгоритмических ф-ций STL C++

#include "Win10.h"
#include "Game.h"
using namespace std;

int MenuShow(string* Items, int cntItems, int Row, int Col, int Select);
void MenuKey(int key);
void AutorShow();
void TitleStart(int time);
void TitleEnd(int time);
void game_overShow();

// цвета для активного пункта меню
int clSelFon = COLOR::light_red; // для фона
int clSelSym = COLOR::black; // для символов

// цвета для неактивных пунктов меню
int clUnselFon = COLOR::light_aqua;         // для фона
int clUnselSym = COLOR::black; // для символов

// цвет консоли по умолчанию
int clDefFon = COLOR::black; // черный фон
int clDefSym = COLOR::white; // белые буквы

bool st = false;


string Menu[]
{
	"Start Game",
	"Continue Game",
	"Autor",
	"Exit",
};

string Autor[]
{
	"",
	"    /\\     | /   |---| |---\\  \\    /     /\\     |\\   |        |---\\   -------      /\\     |\\   |    /\\ ",
	"   /  \\    |/    |   | |   |   \\  /     /  \\    | \\  |        |    |     |        /  \\    | \\  |   /  \\ ",
	"  /____\\   |\\    |   | |---/    \\/     /____\\   |  \\ |        |    |     |       /____\\   |  \\ |  /____\\",
	" /      \\  | \\   |   | |   \\     |    /      \\  |   \\|        |    |     |      /      \\  |   \\| /      \\",
	"/        \\ |  \\  |___| |___/     |   /        \\ |    |        |___/   ___|___  /        \\ |    |/        \\",
};

string Arkanoid[]
{
	"",
	"    /\\     |--\\   | /      /\\       |\\   |   |---|  -------  |---\\",
	"   /  \\    |   |  |/      /  \\      | \\  |   |   |     |     |    |",
	"  /____\\   |__/   |\\     /____\\     |  \\ |   |   |     |     |    | ",
	" /      \\  | \\    | \\   /      \\    |   \\|   |   |     |     |    |",
	"/        \\ |  \\   |  \\ /        \\   |    |   |___|  ___|___  |___/",
};

string gameOver[]
{
	"",
	"/----\\     /\\     |\\    /| |---|      |---| \\        / |---| |--\\ ",
	"|     |   /  \\    | \\  / | |          |   |  \\      /  |     |   | ",
	"|  ____  /____\\   |  \\/  | |___       |   |   \\    /   |___  |__/  ",
	"| |   | /      \\  |      | |          |   |    \\  /    |     | \\  ",
	"\\____/ /        \\ |      | |___|      |___|     \\/     |___| |  \\ ",
};


const int MenuHeight = sizeof(Menu) / sizeof(Menu[0]); // Высота меню
int  menuRow = 10, menuCol = 50; // координаты меню
int Select = 0;

int main()
{
	CursorHide();
	TitleStart(10000);
	do
	{
		CLS;
		Select = MenuShow(Menu, MenuHeight, menuRow, menuCol, Select);
		CLS;
		MenuKey(Select);
	} while (Select >= 0 && Select < 3);
	TitleEnd(10000);

	CLS;

}


void MenuKey(int key)
{
	switch (key)
	{
	case 0://Start Game
	{
		st = true;
		Game A;
		A.gameStart(st);
		if (st == false)
		{
			CLS;
			game_overShow();
			PAUSE;
			return;
		}
		break;
	}
	case 1://Continue Game
	{
		break;
	}
	case 2://Autor
	{
		AutorShow();
		PAUSE;
		break;
	}
	case 3://Exit
	case -1://Exit
	{
		CLS;
		break;
	}
	}
}

int MenuShow(string* Items, int cntItems, int Row, int Col, int Select)
{
	CursorHide(); // ==> CursorHide(FALSE, 10);
	while (true) // цикл работы меню
	{
		// 1) вывод пунктов меню
		for (int i = 0; i < cntItems; i++)
		{
			SetPos(Row + i, Col); // координаты для i-го пункта меню
			if (i == Select) { SetColor(clSelFon, clSelSym); }
			else { SetColor(clUnselFon, clUnselSym); }
			cout << Items[i]; // вывод i-го пункта меню
		} // for();

		// Восстанавливаем цвет вывода на консоль по умолчанию
		SetColor(clDefFon, clDefSym);

		// 2) обработка нажатий клавиш
		//if (_kbhit()) // проверка на нажатие клавиши
		{
			int key = _getch(); // получить код нажатой клавиши
			switch (key)
			{
			case _KEY::UP:  case _KEY::LEFT: // вверх
				if (Select > 0) { Select--; }
				else { Select = cntItems - 1; }
				break;

			case _KEY::DOWN:
			case _KEY::RIGHT: // вниз
				if (Select < cntItems - 1) { Select++; }
				else { Select = 0; }
				break;

			case _KEY::ENTER: // выбор
				return Select; // вернуть индекс выбранного пункта

			case _KEY::ESC: // отказ от выбора
				return -1; // вернутьф несущ. индекс

			}
		}
	}
	CursorHide(true);
}

void AutorShow()
{
	SetPos(10, 25);
	for (int i = 0; i < sizeof(Autor) / sizeof(Autor[0]); i++)
	{
		SetColor(black, light_blue);
		cout << Autor[i] << endl;
	}
	SetColor(clDefFon, clDefSym);
}

void TitleStart(int time)
{
	int t2 = 0;
	SetColor(black, light_blue);
	SetPos(7, 45);
	cout << "New Game";
	SetPos(10, 20);
	for (int i = 0; i < 6; i++)
	{
		cout << Arkanoid[i] << endl;
	}
	do
	{
		Sleep(100);
		t2 += 100;
		if (_kbhit()) break;

	} while (time > t2);
	while (_kbhit()) { _getch(); }
	SetColor(black, white);
	CLS;
}

void TitleEnd(int time)
{
	SetColor(black, light_purple);
	int t2 = 0;
	SetPos(7, 45);
	cout << "End Game";
	SetPos(10, 20);
	for (int i = 0; i < 6; i++)
	{
		cout << Arkanoid[i] << endl;
	}
	do
	{
		Sleep(100);
		t2 += 100;
		if (_kbhit()) break;

	} while (time > t2);
	while (_kbhit()) { _getch(); }

	SetColor(black, white);
	CLS;
}

void game_overShow()
{
	SetPos(10, 20);
	for (int i = 0; i < six; i++)
	{
		SetColor(black, light_red);
		cout << gameOver[i] << endl;
	}
	SetColor(black, white);
}

