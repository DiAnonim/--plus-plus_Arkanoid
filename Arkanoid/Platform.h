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


class Platform
{
protected:
	vector<Image> plat;
	bool left;// Движение платформы влево
	bool right; //Движение платформы вправо
public:
	Platform() :left(false), right(false) 
	{
		setPlat(100);		
	}
	virtual ~Platform() {}

	virtual void setPlat(int size);

	virtual bool getLeft() const { return left; }
	virtual bool getRight() const { return right; }

	virtual void move(bool& st);
	virtual void isMove(int& center);
	virtual void Draw(int r, int c);

};

