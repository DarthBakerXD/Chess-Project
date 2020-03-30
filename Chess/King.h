#pragma once
#include "Piece.h"


class King : public Piece
{
public:
	King(boardLetters  x, int y, colors color);
	virtual moveResult check_move(boardLetters new_x, int new_y, Board &board);
	bool check_check(Board &board);
};
