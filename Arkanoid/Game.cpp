#include "Game.h"

void Game::gameStart(bool& start)
{
	ball.setRow(POLE_H - 2);
	ball.setCol(CENTER_W);
	CLS;
	static int center = CENTER_W;
	SetPos(15, 18);
	SETLOCAL_RU;
	cout << "Нажмите на любую клавишу что бы начать игру\n";
	SETLOCAL_EN;
	CursorHide();
	Create();
	DrawBorder();
	DrawBlock();
	DrawBall(ball.getRow(), ball.getCol());
	DrawPlatform(center);
	PAUSE;
	CLS;
	DrawBorder();
	while (start || GameOver)
	{
		DrawBlock();
		DrawBall(ball.getRow(), ball.getCol());
		DrawPlatform(center);
		GameOver = MoveBall(center);
		MovePlatform(start);
		isMovePlatform(center);
		start = GameOver;
	}
}


void Game::DrawBorder()
{
	SetPos(rowG - 1, colG - 1);
	SetColor(black, light_blue);
	for (size_t i = 0; i < POLE_W + 2; i++)
	{
		cout << wall;
	}
	for (size_t i = 0; i < POLE_H; i++)
	{
		SetPos(rowG + i, colG - 1);
		cout << wall;
		SetPos(rowG + i, colG + POLE_W);
		cout << wall;
	}
	SetPos(rowG + POLE_H, colG - 1);
	for (size_t i = 0; i < POLE_W + 2; i++)
	{
		cout << wall;
	}
}

void Game::DrawBlock()
{
	for (int i = 0; i < 100; i++) //отвечает за отрисовку по колонкам
	{
		SetColor(black, light_yellow);
		block[i].Draw();

	}
}

void Game::DrawPlatform(int center)
{
	for (size_t i = 0; i < five; i++)
	{
		SetColor(black, red);
		plat.Draw(POLE_H - 1, center - five);
	}
	Sleep(1.0);
}


void Game::DrawBall(int r, int c)
{
	for (int i = 0; i <= POLE_H; i++) //отвечает за отрисовку по колонкам
	{
		SetColor(black, green);
		ball.Draw(r, c);
	}
	Sleep(3.5);
}

void Game::MovePlatform(bool& st)
{
	plat.move(st);
}

void Game::isMovePlatform(int& center)
{
	plat.isMove(center);
}

bool Game::MoveBall(int& center)
{
	return GameOver = ball.move(center);
}


void Game::Create()
{
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		block[i].setRow(RAND(3, 5));
		block[i].setCol(RAND(5, 75));
	}
}