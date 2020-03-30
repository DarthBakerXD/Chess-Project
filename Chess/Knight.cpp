#include "Knight.h"

#define MAX_LEN 7

Knight::Knight(boardLetters x, int y, colors color) : Piece(x, y, color)
{}
moveResult Knight::check_move(boardLetters new_x, int new_y, Board &board)
{
	if (_x < 0 || new_x < 0 || _y < 0 || new_y < 0 || _x > MAX_LEN || new_x > MAX_LEN || _y > MAX_LEN || new_y > MAX_LEN)
	{
		return moveResult::moveInvalidIndex;
	}
	if (_x == new_x && _y == new_y)
	{
		return moveResult::moveInvalidSameSpace;
	}
	if (new_x == _x || new_y == _y)
	{
		return moveResult::moveInvalidIllegalMove;
	}
	if ((new_x - _x != 2 || new_y - _y != 1) && (new_x - _x != 1 || new_y - _y != 2) && (new_x - _x != -2 || new_y - _y != 1) && (new_x - _x != 1 || new_y - _y != -2)
		&& (new_x - _x != 2 || new_y - _y != -1) && (new_x - _x != -1 || new_y - _y != 2) && (new_x - _x != -2 || new_y - _y != -1) && (new_x - _x != -1 || new_y - _y != -2))
	{
		return moveResult::moveInvalidIllegalMove;
	}
	if (board[new_y][new_x] != nullptr && board[new_y][new_x]->getColor() == _color)
	{
		return moveResult::moveInvalidEndPiece;
	}

	return moveResult::moveValid;
}