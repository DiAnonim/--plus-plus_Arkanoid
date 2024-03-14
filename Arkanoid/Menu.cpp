#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>
#include <list>   // std::list<> - ������ ������������� ������
#include <vector> // std::vector<> - ������ ������������� �������
#include <iterator> // ����� ��������� ��� ������ � ������������
#include <algorithm> // ������� ��������������� �-��� STL C++

#include "Win10.h"
#include "Game.h"
using namespace std;

int MenuShow(string* Items, int cntItems, int Row, int Col, int Select);
void MenuKey(int key);
void AutorShow();
void TitleStart(int time);
void TitleEnd(int time);
void game_overShow();

// ����� ��� ��������� ������ ����
int clSelFon = COLOR::light_red; // ��� ����
int clSelSym = COLOR::black; // ��� ��������

// ����� ��� ���������� ������� ����
int clUnselFon = COLOR::light_aqua;         // ��� ����
int clUnselSym = COLOR::black; // ��� ��������

// ���� ������� �� ���������
int clDefFon = COLOR::black; // ������ ���
int clDefSym = COLOR::white; // ����� �����

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


const int MenuHeight = sizeof(Menu) / sizeof(Menu[0]); // ������ ����
int  menuRow = 10, menuCol = 50; // ���������� ����
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
	while (true) // ���� ������ ����
	{
		// 1) ����� ������� ����
		for (int i = 0; i < cntItems; i++)
		{
			SetPos(Row + i, Col); // ���������� ��� i-�� ������ ����
			if (i == Select) { SetColor(clSelFon, clSelSym); }
			else { SetColor(clUnselFon, clUnselSym); }
			cout << Items[i]; // ����� i-�� ������ ����
		} // for();

		// ��������������� ���� ������ �� ������� �� ���������
		SetColor(clDefFon, clDefSym);

		// 2) ��������� ������� ������
		//if (_kbhit()) // �������� �� ������� �������
		{
			int key = _getch(); // �������� ��� ������� �������
			switch (key)
			{
			case _KEY::UP:  case _KEY::LEFT: // �����
				if (Select > 0) { Select--; }
				else { Select = cntItems - 1; }
				break;

			case _KEY::DOWN:
			case _KEY::RIGHT: // ����
				if (Select < cntItems - 1) { Select++; }
				else { Select = 0; }
				break;

			case _KEY::ENTER: // �����
				return Select; // ������� ������ ���������� ������

			case _KEY::ESC: // ����� �� ������
				return -1; // �������� �����. ������

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

