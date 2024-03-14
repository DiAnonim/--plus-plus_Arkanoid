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
#include "Image.h"
using namespace std;

class Ball : virtual public Image
{
protected:
	Image ball;
	bool left, right, up, down;
	bool Is_Move;
public:
	Ball() : up(false), left(false), right(false), down(false), Is_Move(false)
	{
		ball.setSym('o');
	}
	virtual ~Ball() {}

	virtual bool getLeft() const { return left; }
	virtual bool getRight() const { return right; }
	virtual bool getUp() const { return up; }
	virtual bool getDown() const { return down; }
	virtual bool getIs_Move() const { return Is_Move; }

	virtual void Draw(int r, int c);
	virtual bool move(int& center);
	virtual void isMove(bool I_M, int& center);

};

