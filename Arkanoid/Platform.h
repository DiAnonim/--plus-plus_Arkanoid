#pragma once

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
#include "Image.h"
using namespace std;


class Platform
{
protected:
	vector<Image> plat;
	bool left;// �������� ��������� �����
	bool right; //�������� ��������� ������
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

