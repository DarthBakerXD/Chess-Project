#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(boardLetters x, int y, colors color);
	virtual moveResult check_move(boardLetters new_x, int new_y, Board &board);
};

