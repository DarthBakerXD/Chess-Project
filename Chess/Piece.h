#pragma once
#include "Board.h"

enum moveResult {moveValid, moveValidCheck, moveInvalidStartPiece, moveInvalidEndPiece, moveInvalidCauseCheck, moveInvalidIndex, moveInvalidIllegalMove, moveInvalidSameSpace, moveValidCheckmate, movePawnUpgrade};
enum colors {white, black};

class Piece // Abstract Class
{
public:
	Piece(boardLetters x, int y, colors color);
	virtual moveResult check_move(boardLetters new_x, int new_y, Board &board) = 0;
	boardLetters getX();
	int getY();
	void setNewX(boardLetters new_x);
	void setNewY(int new_y);
	colors getColor();
protected:
	boardLetters _x;
	int _y;
	colors _color;
};