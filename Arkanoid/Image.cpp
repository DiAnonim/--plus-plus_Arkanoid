#include "Image.h"


//void Image::Draw(Image val)
//{
//	cout << val.getSym();
//}

void Image::Draw(Image& val, int newRow, int newCol)
{
	SetPos(newRow, newCol);
	cout << val.sym;
	val.row = newRow;
	val.col = newCol;

}
