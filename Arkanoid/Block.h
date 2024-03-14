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


class Block : virtual public Image
{
protected:
	Image bl;
	int cntSym;
public:
	Block() : cntSym(100) { bl.setSym('=');}
	virtual ~Block() {}

	virtual void setCntSym(int val) { cntSym = val; }
		virtual const int getCntSym() const { return cntSym; }

	virtual void Draw();
	//virtual void isLive();
};

