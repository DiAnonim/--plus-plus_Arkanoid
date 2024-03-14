#pragma once

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
//#include "Image.h"
#include "Block.h"
#include "Ball.h"
#include "Platform.h"
using namespace std;

class Game
{
protected:
    char wall;
	vector<Block> block;
	Ball ball;
	Platform plat;
	int rowG, colG;
	bool GameOver;
public:
	Game() : wall(char(219)), ball(), plat(), rowG(2), colG(4) { block.resize(100); }
	virtual ~Game() {}

	virtual void MovePlatform(bool& st);
	virtual void isMovePlatform(int& center);
	virtual void gameStart(bool& start);
	virtual void Create();
	virtual void DrawBorder();
	virtual void DrawBlock();
	virtual void DrawBall(int r, int c);
	virtual void DrawPlatform(int center);
	virtual bool MoveBall(int& center);



};

