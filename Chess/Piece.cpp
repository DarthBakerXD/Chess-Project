#include "Piece.h"

Piece::Piece(boardLetters x, int y, colors color)
{
	_x = x;
	_y = y;
	_color = color;
}

boardLetters Piece::getX()
{
	return _x;
}
int Piece::getY()
{
	return _y;
}
colors Piece::getColor()
{
	return _color;
}


void Piece::setNewX(boardLetters new_x)
{
	_x = new_x;
}


void Piece::setNewY(int new_y)
{
	_y = new_y;
}