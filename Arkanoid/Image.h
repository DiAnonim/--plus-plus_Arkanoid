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
using namespace std;


#define CENTER_H POLE_H / 2
#define CENTER_W POLE_W / 2
#define POLE_H 30
#define POLE_W 80

class Image
{
protected:
	char sym;
	int row, col;
public:
	Image() : sym(), row(), col() {}
	Image(int r, int c) : sym(), row(r), col(c) {}
	Image(char s, int r, int c) : sym(s), row(r), col(c) {}
	virtual ~Image() {}

	virtual void setSym(char val) { sym = val; }
	virtual void setRow(int val) { row = val; }
	virtual void setCol(int val) { col = val; }

	virtual char getSym() const { return sym; }
	virtual int getRow() { return row; }
	virtual int getCol()  { return col; }

	virtual void Draw(Image& val, int r, int c);


};

enum number { zero = 0, one, two, tree, four, five, six, seven, eight, nine, ten, eleven};


