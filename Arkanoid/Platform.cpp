#include "Platform.h"


void Platform::Draw(int r, int c)
{
	SetPos(r, c);
	for (size_t i = 0; i < eleven; i++)
	{
		cout << plat[i].getSym();
	}
}

void Platform::move(bool& st)
{
	if (_kbhit()) //- ��������� ������ �� ����� ������ ������� �� ����������
	{
		switch (_getch()) //- ���������� ��� ������� �������
		{
		case LEFT: //Key left ������� ������� �����
			left = true;
			right = false;
			st = true;
			break;
		case RIGHT: //Key right ������� ������� ������
			left = false;
			right = true;
			st = true;
			break;
		case ESC:
			st = false;
			break;
		}

	}
}

void Platform::isMove(int& center)
{
	if (left) //�����
	{
		if (center > five + four)
		{
			center--;
			SetPos(POLE_H - 1, center + six);
			cout << ' ';
		}
	}
	else if (right) //������
	{
		if (center < POLE_W - two)
		{
			center++;
			SetPos(POLE_H - 1, center - six);
			cout << ' ';
		}
	}
}

void Platform::setPlat(int size)
{
	plat.resize(size);
	for (size_t i = 0; i < eleven; i++)
	{
		plat[i].setSym(char(223));
		plat[i].setRow(0);
		plat[i].setCol(0 + i);
	}
}
