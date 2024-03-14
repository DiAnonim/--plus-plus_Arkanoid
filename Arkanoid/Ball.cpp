#include "Ball.h"

void Ball::Draw(int r, int c)
{
	Image::Draw(ball, r, c);
}

bool Ball::move(int& center)
{
	if (ball.getRow() == POLE_H + 1)
	{
		Is_Move = false;
		return Is_Move;
	}
	if (ball.getRow() == POLE_H - 2 && ball.getCol() == CENTER_W)
	{
		Is_Move = true;
		int numb = RAND(1, 2);
		if (numb == 1)
			right = true;
		else
			up = true;
	}
	isMove(Is_Move, center);

}


void Ball::isMove(bool I_M, int& center)
{
	Coord b = { ball.getRow(),  ball.getCol() };

	if (b.row == POLE_H - 1 && b.col >= center - six && b.col <= center + six) //ќтскок м€ча от платформы
	{
		if (down)
		{
			down = false;
			right = true;

		}
		else if (left)
		{
			left = false;
			up = true;
		}
	}
	//if (b.row == 2)  //ќтскок м€ча от потолка(верха игрового пол€)
	//{
	//	if (right)
	//	{
	//		right = false;
	//		down = true;
	//	}
	//	else if (up)
	//	{
	//		up = false;
	//		left = true;
	//	}
	//}
	//if (b.col == 4) //ќтскок м€ча от левой стены
	//{
	//	if (left)
	//	{
	//		left = false;
	//		down = true;
	//	}
	//	else if (up)
	//	{
	//		up = false;
	//		right = true;
	//	}
	//}
	//if (b.col == POLE_W + 3)
	//{
	//	if (right)
	//	{
	//		right = false;
	//		up = true;
	//	}
	//	else if (down)
	//	{
	//		down = false;
	//		left = true;
	//	}
	//}
	if (up)//Ћево вверх
	{

		if (b.row != 2 && b.col != POLE_W + 3 && b.col != 4)
		{
			SetPos(b.row, b.col);
			cout << ' ';
			b.row--;
			b.col--;
			setRow(b.row);
			setCol(b.col);
		}
		else
		{
			if (right)
			{
				right = false;
				down = true;
			}
			else if (up)
			{
				up = false;
				left = true;
			}
		}
	}
	if (down)//¬право вниз
	{
		if (b.col != POLE_W + 3)
		{
			SetPos(b.row, b.col);
			cout << ' ';
			b.row++;
			b.col++;
			setRow(b.row);
			setCol(b.col);
		}
		else
		{
			if (right)
			{
				right = false;
				up = true;
			}
			else if (down)
			{
				down = false;
				left = true;
			}
		}
	}
	if (left)//Ћево вниз
	{
		if (b.col != 4)
		{
			SetPos(b.row, b.col);
			cout << ' ';
			b.row++;
			b.col--;
			setRow(b.row);
			setCol(b.col);
		}
		else
		{
			if (up)
			{
				up = false;
				right = true;
			}
			else if (left)
			{
				left = false;
				down = true;
			}
		}
	}
	if (right)//¬право верх
	{
		if (b.row != 2 && b.col != POLE_W + 3 && b.col != 4)
		{

			SetPos(b.row, b.col);
			cout << ' ';
			b.row--;
			b.col++;
			setRow(b.row);
			setCol(b.col);
		}
		else if (b.row == 2)
		{
			if (right)
			{
				right = false;
				down = true;
			}
		}
		else
		{
			if (right)
			{
				right = false;
				up = true;
			}
		}
	}

}

