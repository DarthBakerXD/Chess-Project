#pragma once

#include "Piece.h"


class Rook : public Piece
{
public:
	Rook(boardLetters  x, int y, colors color);
	virtual moveResult check_move(boardLetters new_x, int new_y, Board &board);
};